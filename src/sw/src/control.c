
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





void set_fpleds(u32 msgVal)  {
	Xil_Out32(XPAR_M_AXI_BASEADDR + FP_LEDS_REG, msgVal);
}






void set_eventno(u32 msgVal) {
	//Xil_Out32(XPAR_M_AXI_BASEADDR + EVR_TRIGNUM_REG, msgVal);
}


void reg_settings(void *msg) {

	u32 *msgptr = (u32 *)msg;
	u32 addr;
    u32 rdval, regAddr, regVal;

	typedef union {
	    u32 u;
	    float f;
	    s32 i;
	} MsgUnion;

	MsgUnion data;


    addr = htonl(msgptr[0]);
    data.u = htonl(msgptr[1]);

    xil_printf("Addr: %d    Data: %d\r\n",addr,data.u);


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






