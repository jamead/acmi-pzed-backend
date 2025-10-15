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

    //set i2c clock rate to 100KHz
    XIicPs_SetSClk(&IicPsInstance0, 100000);

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














