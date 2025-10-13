
#include <stdio.h>
#include <string.h>
#include <sleep.h>
#include "xil_cache.h"

#include "lwip/sockets.h"
#include "netif/xadapter.h"
#include "lwipopts.h"
#include "xil_printf.h"
#include "FreeRTOS.h"
#include "task.h"

/* Hardware support includes */
#include "../inc/zubpm_defs.h"
#include "../inc/pl_regs.h"
#include "../inc/psc_msg.h"





#define PORT  7



void set_fpleds(u32 msgVal)  {
	Xil_Out32(XPAR_M_AXI_BASEADDR + FP_LEDS_REG, msgVal);
}



void set_eventno(u32 msgVal) {
	Xil_Out32(XPAR_M_AXI_BASEADDR + EVR_FE_TRIGNUM_REG, msgVal);
}


void set_eventdly(u32 msgVal) {
	Xil_Out32(XPAR_M_AXI_BASEADDR + EVR_FE_TRIGDLY_REG, msgVal);
}


void set_fp_trig_dly(u32 msgVal)
{
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_DATA, msgVal);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_ADDR, 0x41);  //see Artix SPI register address map
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x1);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x0);

}

void reset_accum()
{
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_DATA, 0x1);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_ADDR, 0x51);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x1);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x0);
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



void write_eeprom(u32 msgAddr, s32 msgData)
{
	u32 spi_addr, spi_data;
	u32 eeprom_data, eeprom_addr;

	//subtract PSC offset address of 256 to get EEPROM address
	eeprom_addr = msgAddr - 256;

	//Put EEPROM in write mode
	spi_data = EEPROM_OPCODE_WREN << 24;
    spi_addr = EEPROM_WRDATA;
    xil_printf("EEPROM: spi_addr=%8x  spi_data=%8x\r\n",spi_addr, spi_data);
    write_artix_eeprom(spi_addr, spi_data);
    //Write 1st byte
    eeprom_data = (msgData & 0xFF000000) >> 24;
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
    eeprom_data = (msgData & 0x00FF0000) >> 16;
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
    eeprom_data = (msgData & 0x0000FF00) >> 8;
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
    eeprom_data = (msgData & 0x000000FF);
    spi_data = (EEPROM_OPCODE_WRITE<<24) | (eeprom_addr++<<8) | eeprom_data;
    spi_addr = EEPROM_WRDATA;
    xil_printf("EEPROM: spi_addr=%8x  spi_data=%8x\r\n",spi_addr, spi_data);
    write_artix_eeprom(spi_addr, spi_data);


    //Read in new EEPROM settings
    read_artix_eeprom_settings();




}









void psc_control_thread()
{
	int sockfd, newsockfd;
	int clilen;
	struct sockaddr_in serv_addr, cli_addr;
	int RECV_BUF_SIZE = 1024;
	char buffer[RECV_BUF_SIZE];
	int n, *bufptr, numpackets=0;
    u32 MsgAddr, MsgData;




    xil_printf("Starting PSC Control Server...\r\n");

	// Initialize socket structure
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

    // First call to socket() function
	if ((sockfd = lwip_socket(AF_INET, SOCK_STREAM, 0)) < 0)
		xil_printf("PSC Control : Error Creating Socket\r\n");

    // Bind to the host address using bind()
	if (lwip_bind(sockfd, (struct sockaddr *)&serv_addr, sizeof (serv_addr)) < 0)
		xil_printf("PSC Control : Error Creating Socket\r\n");

    // Now start listening for the clients
	lwip_listen(sockfd, 0);


    xil_printf("PSC Control: Server listening on port %d...\r\n",PORT);


reconnect:

	clilen = sizeof(cli_addr);

	newsockfd = lwip_accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen);
	if (newsockfd < 0) {
	    xil_printf("PSC Control: ERROR on accept\r\n");

	}
	/* If connection is established then start communicating */
	xil_printf("PSC Control: Connected Accepted...\r\n");

	while (1) {
		/* read a max of RECV_BUF_SIZE bytes from socket */
		n = read(newsockfd, buffer, RECV_BUF_SIZE);
        if (n <= 0) {
            xil_printf("PSC Control: ERROR reading from socket..  Reconnecting...\r\n");
            close(newsockfd);
	        goto reconnect;
        }

        bufptr = (int *) buffer;
        xil_printf("\nPacket %d Received : NumBytes = %d\r\n",++numpackets,n);
        xil_printf("Header: %c%c \t",buffer[0],buffer[1]);
        xil_printf("Message ID : %d\t",(ntohl(*bufptr++)&0xFFFF));
        xil_printf("Body Length : %d\t",ntohl(*bufptr++));
        MsgAddr = ntohl(*bufptr++);
        xil_printf("Msg Addr : %d\t",MsgAddr);
	    MsgData = ntohl(*bufptr);
        xil_printf("Data : %d\r\n",MsgData);
        //blink fp_led on message received
        set_fpleds(1);
        set_fpleds(0);

        if ((MsgAddr >= 256) && (MsgAddr <= 452)) {
              xil_printf("Writing Artix EEPROM...\r\n");
              write_eeprom(MsgAddr,MsgData);
        }

        switch(MsgAddr) {

            case EVENT_NO_MSG1:
            	xil_printf("Set Event Number Message:   Value=%d\r\n",MsgData);
                set_eventno(MsgData);
                break;

            case EVENT_DLY_MSG1:
            	xil_printf("Set Event Delay Message:   Value=%d\r\n",MsgData);
            	set_eventdly(MsgData);
                break;

            case FP_TRIG_DLY_MSG1:
            	xil_printf("Set FP LEMO Trigger Delay Message:   Value=%d\r\n",MsgData);
            	set_fp_trig_dly(MsgData);
                break;

            case FP_LED_MSG1:
            	xil_printf("Setting FP LED:   Value=%d\r\n",MsgData);
            	set_fpleds(MsgData);
            	break;

            case ACCUM_RESET_MSG1:
            	xil_printf("Resetting Accumulator:   Value=%d\r\n",MsgData);
            	reset_accum(MsgData);
            	break;

            case EVENT_SRC_SEL_MSG1:
              	xil_printf("Setting Event Source:   Value=%d\r\n",MsgData);
              	Xil_Out32(XPAR_M_AXI_BASEADDR + EVENT_SRC_SEL_REG, MsgData);
              	break;

            case GTX_RESET_MSG1:
               	xil_printf("Resetting GTX links:   Value=%d\r\n",MsgData);
               	Xil_Out32(XPAR_M_AXI_BASEADDR + EVR_RST_REG, MsgData);
               	break;


            default:
            	xil_printf("Msg not supported yet...\r\n");
            	break;
        }

	}

	/* close connection */
	close(newsockfd);
	vTaskDelete(NULL);
}


