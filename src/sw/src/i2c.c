#include "xparameters.h"
#include "xiicps.h"
#include <sleep.h>
#include "xil_printf.h"
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

#include "pl_regs.h"
#include "local.h"


extern XIicPs IicPsInstance0;			/* Instance of the IIC Device */
extern XIicPs IicPsInstance1;			/* Instance of the IIC Device */

extern float CONVVOLTSTODACBITS;
extern float CONVDACBITSTOVOLTS;

#define IIC0_DEVICE_ID    XPAR_XIICPS_0_DEVICE_ID



// Registers to program LMK61E2 to 312.3MHz
static const u32 lmk61e2_values [] = {
		0x0010, 0x010B, 0x0233, 0x08B0, 0x0901, 0x1000, 0x1180, 0x1502,
		0x1600, 0x170F, 0x1900, 0x1A2E, 0x1B00, 0x1C00, 0x1DA9, 0x1E00,
		0x1F00, 0x20C8, 0x2103, 0x2224, 0x2327, 0x2422, 0x2502, 0x2600,
		0x2707, 0x2F00, 0x3000, 0x3110, 0x3200, 0x3300, 0x3400, 0x3500,
		0x3800, 0x4802,
};


// Registers to program si570 to 312.3MHz.
static const uint8_t si570_values[][2] = {
	{137, 0x10}, //Freeze DCO
	{7, 0x00},
    {8, 0xC2},
    {9, 0xBB},
    {10, 0xBE},
    {11, 0x6E},
    {12, 0x69},
    {137, 0x0},  //Unfreeze DCO
	{135, 0x40}  //Enable New Frequency
};






void init_i2c() {
    s32 Status;
    XIicPs_Config *ConfigPtr;


    // Look up the configuration in the config table
    ConfigPtr = XIicPs_LookupConfig(0);
    if(ConfigPtr == NULL) {
    	xil_printf("I2C Bus 0 Lookup failed!\r\n");
    	//return XST_FAILURE;
    }

    // Initialize the I2C driver configuration
    Status = XIicPs_CfgInitialize(&IicPsInstance0, ConfigPtr, ConfigPtr->BaseAddress);
    if(Status != XST_SUCCESS) {
    	xil_printf("I2C Bus 0 initialization failed!\r\n");
    	//return XST_FAILURE;
    }


    // Look up the configuration in the config table
    ConfigPtr = XIicPs_LookupConfig(1);
    if(ConfigPtr == NULL) {
    	xil_printf("I2C Bus 1 Lookup failed!\r\n");
    	//return XST_FAILURE;
    }

    Status = XIicPs_CfgInitialize(&IicPsInstance1, ConfigPtr, ConfigPtr->BaseAddress);
     if(Status != XST_SUCCESS) {
     	xil_printf("I2C Bus 1 initialization failed!\r\n");
     	//return XST_FAILURE;
     }

    //set i2c clock rate to 100KHz
    XIicPs_SetSClk(&IicPsInstance0, 100000);
    XIicPs_SetSClk(&IicPsInstance1, 100000);
}



s32 i2c0_write(u8 *buf, u8 len, u8 addr) {

	s32 status;

	while (XIicPs_BusIsBusy(&IicPsInstance0));
	status = XIicPs_MasterSendPolled(&IicPsInstance0, buf, len, addr);
	return status;
}

s32 i2c0_read(u8 *buf, u8 len, u8 addr) {

	s32 status;

    while (XIicPs_BusIsBusy(&IicPsInstance0)) {};
    status = XIicPs_MasterRecvPolled(&IicPsInstance0, buf, len, addr);
    return status;
}


s32 i2c1_write(u8 *buf, u8 len, u8 addr) {

	s32 status;

	while (XIicPs_BusIsBusy(&IicPsInstance1));
	status = XIicPs_MasterSendPolled(&IicPsInstance1, buf, len, addr);
	return status;
}

s32 i2c1_read(u8 *buf, u8 len, u8 addr) {

	s32 status;

    while (XIicPs_BusIsBusy(&IicPsInstance1)) {};
    status = XIicPs_MasterRecvPolled(&IicPsInstance1, buf, len, addr);
    return status;
}




void write_lmk61e2()
{
   u8 buf[4] = {0};
   u32 regval, i;

   u32 num_values = sizeof(lmk61e2_values) / sizeof(lmk61e2_values[0]);  // Get the number of elements in the array
   for (i=0; i<num_values; i++) {
	  regval = lmk61e2_values[i];
      buf[0] = (char) ((regval & 0x00FF00) >> 8);
      buf[1] = (char) (regval & 0xFF);
      //xil_printf("Writing I2c\r\n");
      i2c0_write(buf,2,0x5A);
      xil_printf("LMK61e2 Write = 0x%x\t    B0 = %x    B1 = %x\r\n",regval, buf[0], buf[1]);
   }
}






void read_si570() {
   u8 i, buf[2], stat;

   xil_printf("Read si570 registers\r\n");
   for (i=0;i<6;i++) {
       buf[0] = i+7;
       i2c0_write(buf,1,0x5D);
       stat = i2c0_read(buf, 1, 0x5D);
       xil_printf("Stat: %d:   val0:%x  \r\n",stat, buf[0]);
	}
	xil_printf("\r\n");
}



void prog_si570() {
	u8 buf[2];

	xil_printf("Si570 Registers before re-programming...\r\n");
	read_si570();
	//Program New Registers
	for (size_t i = 0; i < sizeof(si570_values) / sizeof(si570_values[0]); i++) {
	    buf[0] = si570_values[i][0];
	    buf[1] = si570_values[i][1];
	    i2c0_write(buf, 2, 0x5D);
	}
	xil_printf("Si570 Registers after re-programming...\r\n");
    read_si570();
}



// INA226 on AFE board

#define INA226_ADDR          0x40  // A0=A1=0
#define INA226_REG_CONFIG    0x00
#define INA226_REG_SHUNTV    0x01
#define INA226_REG_BUSV      0x02
#define INA226_REG_POWER     0x03
#define INA226_REG_CURRENT   0x04
#define INA226_REG_CALIB     0x05

// Scaling for Rshunt = 0.02 Ω
#define INA226_CALIB_VALUE   0x0800                  // computed above
#define INA226_VOLTAGE_LSB   0.00125f                // 1.25 mV/LSB
#define INA226_CURRENT_LSB_A 0.000125f               // 125 µA/LSB
#define INA226_POWER_LSB_W   (25.0f * INA226_CURRENT_LSB_A) // 3.125 mW/LSB




// Write 16-bit word to INA226 register
s32 ina226_write_reg(u8 reg, u16 value) {
    u8 buf[3];
    buf[0] = reg;
    buf[1] = (u8)(value >> 8);   // MSB
    buf[2] = (u8)(value & 0xFF); // LSB
    return i2c1_write(buf, 3, INA226_ADDR);
}


// Read 16-bit word from INA226 register
s32 ina226_read_reg(u8 reg, u16 *value) {
    u8 buf[2];
    s32 status;

    // Write register pointer first
    status = i2c1_write(&reg, 1, INA226_ADDR);
    //xil_printf("status: %d\n",status);
    if (status != 0) return status;

    // Now read 2 bytes
    status = i2c1_read(buf, 2, INA226_ADDR);
    if (status != 0) return status;

    *value = ((u16)buf[0] << 8) | buf[1];  // MSB first
    return 0;
}


// Optional: configure averaging and conversion times (example: defaults)
void ina226_init(void) {
    // Program calibration (must be set before reading CURRENT/POWER)
    ina226_write_reg(INA226_REG_CALIB, INA226_CALIB_VALUE);
    // (Optional) Set CONFIG if you want specific averaging/ct:
    // u16 cfg = 0x4127; // example: defaults; set as needed
    // ina226_write_reg(INA226_REG_CONFIG, cfg);
}

// Returns bus voltage in volts
float ina226_read_bus_voltage(void) {
    u16 raw;
    if (ina226_read_reg(INA226_REG_BUSV, &raw)) return -1.0f;
    // Bus voltage LSB = 1.25 mV
    float volts = (float)raw * INA226_VOLTAGE_LSB;
    return volts;

}

// Returns current in amps (uses calibration above)
float ina226_read_current(void) {
    u16 raw;
    if (ina226_read_reg(INA226_REG_CURRENT, &raw)) return -1.0f;
    int16_t s = (int16_t)raw;  // signed
    return (float)s * INA226_CURRENT_LSB_A;
}

// (Optional) Returns power in watts
float ina226_read_power(void) {
    u16 raw;
    if (ina226_read_reg(INA226_REG_POWER, &raw)) return -1.0f;
    return (float)raw * INA226_POWER_LSB_W;
}











