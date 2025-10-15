
// get waveform data from Artix and send to IOC

#include <stdio.h>


#include <xparameters.h>

#include <FreeRTOS.h>
#include <lwip/sys.h>
#include <lwip/stats.h>

#include "local.h"

#include "pl_regs.h"


void soft_trig_artix()
{
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_DATA, 0x1);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_ADDR, 0x0);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x1);
	Xil_Out32(XPAR_M_AXI_BASEADDR + ARTIX_SPI_WE, 0x0);

}






static void wvfmdata_push(void *unused)
{
    (void)unused;

    u32 wvfm_debug = 1;
    u32 wordcnt, pollcnt;
    u32 i;


    static s32 wvfm[18000];





    while(1) {

        vTaskDelay(pdMS_TO_TICKS(1000));
        xil_printf("Triggering Artix...\r\n");
        soft_trig_artix();

        pollcnt = 0;
        do {
        	wordcnt = Xil_In32(XPAR_M_AXI_BASEADDR + FIFO_CNT_REG);
        	vTaskDelay(pdMS_TO_TICKS(1));
           if (wvfm_debug) xil_printf("PollCnt: %d\r\n", pollcnt);
        	pollcnt++;
        } while ((wordcnt == 0) && (pollcnt < 5000));

        xil_printf("PollCnt: %d     Num FIFO Words: %d\r\n", pollcnt, wordcnt);

        if (wordcnt > 8000) {
          for (i=0;i<16258;i++) {
           //read FIFO
        	wvfm[i] = Xil_In32(XPAR_M_AXI_BASEADDR + FIFO_DATA_REG);
        	if ((i<128) && (wvfm_debug))
        	  xil_printf("%d:  %x\r\n", i,wvfm[i]);
        	if (i==37)  //over write word #37 from Artix with EVR Timestamp sec
        	   wvfm[i] = 0; //ts_s;
        	if (i==38) //overwrite word #38 from Artix with EVR Timestamp ns
        	   wvfm[i] = 0; //ts_ns;

          }
        }

        if (wvfm_debug) xil_printf("Resetting FIFO...\r\n");
        Xil_Out32(XPAR_M_AXI_BASEADDR + FIFO_RST_REG, 1);
        usleep(1);
        Xil_Out32(XPAR_M_AXI_BASEADDR + FIFO_RST_REG, 0);
        usleep(10);

        wordcnt = Xil_In32(XPAR_M_AXI_BASEADDR + FIFO_CNT_REG);
        if (wvfm_debug) xil_printf("Num FIFO Words: %d\r\n", wordcnt);

        xil_printf("\r\n\r\n");




        psc_send(the_server, 52, sizeof(wvfm), wvfm);


    }
}

void wvfmdata_setup(void)
{
    printf("INFO: Starting Wvfm Data daemon\n");
    sys_thread_new("wvfmdata", wvfmdata_push, NULL, THREAD_STACKSIZE, DEFAULT_THREAD_PRIO);
}

