/********************************************************************
*  PSC Waveform Thread
*  J. Mead
*  4-17-24
*
*  This thread is responsible for sending all waveform data to the IOC.   It does
*  this over to message ID's (51 = ADC Data, 52 = TbT data)
*
*  It starts a listening server on
*  port 600.  Upon establishing a connection with a client, it begins to send out
*  packets.
********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sleep.h>
#include "xil_cache.h"
#include "xparameters.h"

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


#define PORT  20

extern bool wvfm_debug;




void Host2NetworkConvWvfm(char *inbuf, int len) {

    int i;
    u8 temp;
    //Swap bytes to reverse the order within the 4-byte segment
    //Start at byte 8 (skip the PSC Header)
    for (i=8;i<len;i=i+4) {
    	temp = inbuf[i];
    	inbuf[i] = inbuf[i + 3];
    	inbuf[i + 3] = temp;
    	temp = inbuf[i + 1];
    	inbuf[i + 1] = inbuf[i + 2];
    	inbuf[i + 2] = temp;
    }

}


void soft_trig_artix()
{
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_DATA, 0x1);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_ADDR, 0x0);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x1);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x0);

}






void ReadChainA(char *msg) {

    int i;
    u32 *msg_u32ptr;
    u32 regval, wordcnt, pollcnt;
    u32 ts_s, ts_ns;

    //write the PSC Header
     msg_u32ptr = (u32 *)msg;
     msg[0] = 'P';
     msg[1] = 'S';
     msg[2] = 0;
     msg[3] = (short int) MSGID51;
     *++msg_u32ptr = htonl(MSGID51LEN); //body length
     msg_u32ptr++;


     pollcnt = 0;
     //Read latched Timestamp
     //ts_s = Xil_In32(XPAR_M_AXI_BASEADDR + EVR_TS_S_LAT_REG);
     //ts_ns = Xil_In32(XPAR_M_AXI_BASEADDR + EVR_TS_NS_LAT_REG);
     //Read free running timestamp for now, not using EVR quite yet
     ts_s = Xil_In32(XPAR_M_AXI_BASEADDR + EVR_TS_S_REG);
     ts_ns = Xil_In32(XPAR_M_AXI_BASEADDR + EVR_TS_NS_REG);

     if (wvfm_debug) {
    	 xil_printf("ts= %d    %d\r\n",ts_s,ts_ns);
         xil_printf("Read Artix FIFO...\r\n");
     }

     do {
     	wordcnt = Xil_In32(XPAR_M_AXI_BASEADDR + CHAINA_FIFO_CNT_REG);
        usleep(1000);
        if (wvfm_debug) xil_printf("PollCnt: %d\r\n", pollcnt);
     	pollcnt++;
     } while ((wordcnt == 0) && (pollcnt < 5000));

     //xil_printf("PollCnt: %d     Num FIFO Words: %d\r\n", pollcnt, wordcnt);

     if (wordcnt > 16000) {
       for (i=0;i<16258;i++) {
        //read FIFO
     	regval = Xil_In32(XPAR_M_AXI_BASEADDR + CHAINA_FIFO_DATA_REG);
     	if ((i<128) && (wvfm_debug))
     	  xil_printf("%d:  %d\r\n", i*4,regval);
     	if (i==37)  //over write word #37 from Artix with EVR Timestamp sec
     	   *msg_u32ptr++ = ts_s;
     	else if (i==38) //overwrite word #38 from Artix with EVR Timestamp ns
     	   *msg_u32ptr++ = ts_ns;
     	else
     	   *msg_u32ptr++ = regval;
       }
     }

     if (wvfm_debug) xil_printf("Resetting FIFO...\r\n");
     Xil_Out32(XPAR_M_AXI_BASEADDR + CHAINA_FIFO_RST_REG, 1);
     usleep(1);
     Xil_Out32(XPAR_M_AXI_BASEADDR + CHAINA_FIFO_RST_REG, 0);
     usleep(10);

     wordcnt = Xil_In32(XPAR_M_AXI_BASEADDR + CHAINA_FIFO_CNT_REG);
     if (wvfm_debug) xil_printf("Num FIFO Words: %d\r\n", wordcnt);





}






void psc_wvfm_thread()
{

	int sockfd, newsockfd;
	int clilen;
	struct sockaddr_in serv_addr, cli_addr;
    u32 loopcnt=0;
    s32 n;


    xil_printf("Starting PSC Waveform Server...\r\n");

	// Initialize socket structure
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

    // First call to socket() function
	if ((sockfd = lwip_socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		xil_printf("PSC Waveform : Error Creating Socket\r\n");
		//vTaskDelete(NULL);
	}

    // Bind to the host address using bind()
	if (lwip_bind(sockfd, (struct sockaddr *)&serv_addr, sizeof (serv_addr)) < 0) {
		xil_printf("PSC Waveform : Error Creating Socket\r\n");
		//vTaskDelete(NULL);
	}

    // Now start listening for the clients
	lwip_listen(sockfd, 0);

    xil_printf("PSC Waveform:  Server listening on port %d...\r\n",PORT);


reconnect:

	clilen = sizeof(cli_addr);

	newsockfd = lwip_accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen);
	if (newsockfd < 0) {
	    xil_printf("PSC Waveform: ERROR on accept\r\n");
	    //vTaskDelete(NULL);
	}
	/* If connection is established then start communicating */
	xil_printf("PSC Waveform: Connected Accepted...\r\n");
    xil_printf("PSC Waveform: Entering while loop...\r\n");




	while (1) {

		//xil_printf("Wvfm: Triggering Artix...\r\n");
		loopcnt++;
		vTaskDelay(pdMS_TO_TICKS(900));
		soft_trig_artix();


        //xil_printf("Wvfm(%d) Sending Live Data...\r\n",loopcnt);
        ReadChainA(msgid51_buf);
        //write out chainA data (msg51)
        Host2NetworkConvWvfm(msgid51_buf,sizeof(msgid51_buf)+MSGHDRLEN);
        n = write(newsockfd,msgid51_buf,MSGID51LEN+MSGHDRLEN);
        //xil_printf("Wrote Chain A waveform\r\n");
        if (n < 0) {
        	printf("PSC Waveform: ERROR writing MSG 51 - ADC Waveform\n");
        	close(newsockfd);
        	goto reconnect;
        }

	}

	/* close connection */
	close(newsockfd);
	vTaskDelete(NULL);

}


