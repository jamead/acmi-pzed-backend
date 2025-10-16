
#include <stdio.h>
#include <string.h>
#include <sleep.h>
#include "xil_cache.h"
#include "math.h"


#include "lwip/sockets.h"
//#include "netif/xadapter.h"
//#include "lwipopts.h"
#include "xil_printf.h"
#include "FreeRTOS.h"
#include "task.h"

/* Hardware support includes */
#include "control.h"
#include "pl_regs.h"
#include "local.h"


#define EEPROM_WRDATA  0x51
#define EEPROM_TRIG    0x50
#define EEPROM_READALL 0x52

// opcodes for CAT25320 EEPROM
#define EEPROM_OPCODE_RDSR 5
#define EEPROM_OPCODE_WRSR 1
#define EEPROM_OPCODE_WREN 6
#define EEPROM_OPCODE_WRDI 4
#define EEPROM_OPCODE_READ 3
#define EEPROM_OPCODE_WRITE 2



void set_fpleds(u32 msgVal)  {
	Xil_Out32(XPAR_M_AXI_BASEADDR + FP_LEDS_REG, msgVal);
}






void set_eventno(u32 msgVal) {
	//Xil_Out32(XPAR_M_AXI_BASEADDR + EVR_TRIGNUM_REG, msgVal);
}


void read_artix_eeprom_settings()
{

	u32 spi_addr, spi_data;

    spi_data = 1;
    spi_addr = EEPROM_READALL;
    xil_printf("EEPROM: spi_addr=%8x  spi_data=%8x\r\n",spi_addr, spi_data);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_DATA, spi_data);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_ADDR, spi_addr);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x1);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x0);
	usleep(5000);

}



void write_artix_eeprom(u32 addr, s32 data)
{

	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_DATA, data);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_ADDR, addr);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x1);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x0);
	usleep(5000);
	//write the EEPROM Trig Artix SPI register to initiate EEPROM transaction
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_DATA, 1);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_ADDR, EEPROM_TRIG);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x1);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x0);
	usleep(10000);


}








void eeprom_settings(void *msg) {

	u32 *msgptr = (u32 *)msg;
	u32 spi_addr, spi_data;
	u32 eeprom_addr;
	s32 msg_data, eeprom_data;

    eeprom_addr = htonl(msgptr[0]);
    msg_data = htonl(msgptr[1]);

    xil_printf("EEPROM:  Addr: %d    Data: %d\r\n",eeprom_addr,msg_data);

    //Put EEPROM in write mode
    spi_data = EEPROM_OPCODE_WREN << 24;
    spi_addr = EEPROM_WRDATA;
    xil_printf("EEPROM: spi_addr=%8x  spi_data=%8x\r\n",spi_addr, spi_data);
    write_artix_eeprom(spi_addr, spi_data);
    //Write 1st byte
    eeprom_data = (msg_data & 0xFF000000) >> 24;
    spi_data = (EEPROM_OPCODE_WRITE<<24) | (eeprom_addr++<<8) | eeprom_data;
    spi_addr = EEPROM_WRDATA;
    xil_printf("EEPROM: spi_addr=%8x  spi_data=%8x\r\n",spi_addr, spi_data);
    write_artix_eeprom(spi_addr, spi_data);

    //Put EEPROM in write mode
    spi_data = EEPROM_OPCODE_WREN << 24;
    spi_addr = EEPROM_WRDATA;
    xil_printf("EEPROM: spi_addr=%8x  spi_data=%8x\r\n",spi_addr, spi_data);
    write_artix_eeprom(spi_addr, spi_data);
    //Write 2nd byte
    eeprom_data = (msg_data & 0x00FF0000) >> 16;
    spi_data = (EEPROM_OPCODE_WRITE<<24) | (eeprom_addr++<<8) | eeprom_data;
    spi_addr = EEPROM_WRDATA;
    xil_printf("EEPROM: spi_addr=%8x  spi_data=%8x\r\n",spi_addr, spi_data);
    write_artix_eeprom(spi_addr, spi_data);

    //Put EEPROM in write mode
    spi_data = EEPROM_OPCODE_WREN << 24;
    spi_addr = EEPROM_WRDATA;
    xil_printf("EEPROM: spi_addr=%8x  spi_data=%8x\r\n",spi_addr, spi_data);
    write_artix_eeprom(spi_addr, spi_data);
    //Write 3nd byte
    eeprom_data = (msg_data & 0x0000FF00) >> 8;
    spi_data = (EEPROM_OPCODE_WRITE<<24) | (eeprom_addr++<<8) | eeprom_data;
    spi_addr = EEPROM_WRDATA;
    xil_printf("EEPROM: spi_addr=%8x  spi_data=%8x\r\n",spi_addr, spi_data);
    write_artix_eeprom(spi_addr, spi_data);

    //Put EEPROM in write mode
    spi_data = EEPROM_OPCODE_WREN << 24;
    spi_addr = EEPROM_WRDATA;
    xil_printf("EEPROM: spi_addr=%8x  spi_data=%8x\r\n",spi_addr, spi_data);
    write_artix_eeprom(spi_addr, spi_data);
    //Write 4th byte
    eeprom_data = (msg_data & 0x000000FF);
    spi_data = (EEPROM_OPCODE_WRITE<<24) | (eeprom_addr++<<8) | eeprom_data;
    spi_addr = EEPROM_WRDATA;
    xil_printf("EEPROM: spi_addr=%8x  spi_data=%8x\r\n",spi_addr, spi_data);
    write_artix_eeprom(spi_addr, spi_data);


    //Read in new EEPROM settings
    read_artix_eeprom_settings();


}






void reg_settings(void *msg) {

	u32 *msgptr = (u32 *)msg;
	u32 addr;


	typedef union {
	    u32 u;
	    float f;
	    s32 i;
	} MsgUnion;

	MsgUnion data;


    addr = htonl(msgptr[0]);
    data.u = htonl(msgptr[1]);

    xil_printf("REG:  Addr: %d    Data: %d\r\n",addr,data.u);


    switch(addr) {

        case FP_LED_MSG:
          	xil_printf("Setting FP LED:   Value=%d\r\n",data.u);
          	set_fpleds(data.u);
          	break;



        default:
          	xil_printf("Msg not supported yet...\r\n");
           	break;
        }

}






