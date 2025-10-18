#include <stdlib.h>
#include <unistd.h>


#include <FreeRTOS.h>
#include <xil_cache_l.h>
#include <xil_io.h>

#include <lwip/init.h>
#include <lwip/sockets.h>
#include <lwip/sys.h>
#include <netif/xadapter.h>
#include <xparameters_ps.h>

#include "xqspips.h"
#include "xiicps.h"

#include "local.h"
#include "control.h"
#include "pl_regs.h"

#include "xuartps.h"

psc_key* the_server;


XQspiPs QspiInstance;
XIicPs IicPsInstance0;	    // si570


uint32_t git_hash;




static void client_event(void *pvt, psc_event evt, psc_client *ckey)
{
    if(evt!=PSC_CONN)
        return;
    // send some "static" information once when a new client connects.
    struct {
        uint32_t git_hash;
        uint32_t serial;
    } msg = {
        .git_hash = htonl(git_hash),
        .serial = 0, // TODO: read from EEPROM
    };
    (void)pvt;

    psc_send_one(ckey, 0x100, sizeof(msg), &msg);
}



static void client_msg(void *pvt, psc_client *ckey, uint16_t msgid, uint32_t msglen, void *msg)
{
    (void)pvt;

	//xil_printf("In Client_Msg:  MsgID=%d   MsgLen=%d\r\n",msgid,msglen);

    //blink front panel LED
    //Xil_Out32(XPAR_M_AXI_BASEADDR + IOC_ACCESS_REG, 1);
    //Xil_Out32(XPAR_M_AXI_BASEADDR + IOC_ACCESS_REG, 0);

    switch(msgid) {
        case 1: //register settings
        	reg_settings(msg);
        	break;
        case 2: //eeprom settings
        	eeprom_settings(msg);
        case 5: //ping event
            break;
    }
}



static void on_startup(void *pvt, psc_key *key)
{
    (void)pvt;
    (void)key;
    lstats_setup();
    wvfmdata_setup();
    //sadata_setup();
    //snapshot_setup();
    console_setup();
}

static void realmain(void *arg)
{
    (void)arg;

    printf("Main thread running\n");

    {
        net_config conf = {};
        sdcard_handle(&conf);
        //InitSettingsfromQspi();
        net_setup(&conf);

    }

    discover_setup();
    //tftp_setup();

    const psc_config conf = {
        .port = 3000,
        .start = on_startup,
        .conn = client_event,
        .recv = client_msg,
    };
    
    psc_run(&the_server, &conf);
    while(1) {
        fprintf(stderr, "ERROR: PSC server loop returns!\n");
        sys_msleep(1000);
    }
}


void print_firmware_version()
{

    time_t epoch_time;
    struct tm *human_time;
    char timebuf[80];




    xil_printf("Module ID Number: %x\r\n", Xil_In32(XPAR_M_AXI_BASEADDR + MOD_ID_NUM));
    xil_printf("Module Version Number: %x\r\n", Xil_In32(XPAR_M_AXI_BASEADDR + MOD_ID_VER));
    xil_printf("Project ID Number: %x\r\n", Xil_In32(XPAR_M_AXI_BASEADDR + PROJ_ID_NUM));
    xil_printf("Project Version Number: %x\r\n", Xil_In32(XPAR_M_AXI_BASEADDR + PROJ_ID_VER));
    //compare to git commit with command: git rev-parse --short HEAD
    xil_printf("Git Checksum: %x\r\n", Xil_In32(XPAR_M_AXI_BASEADDR + GIT_SHASUM));
    epoch_time = Xil_In32(XPAR_M_AXI_BASEADDR + COMPILE_TIMESTAMP);
    human_time = localtime(&epoch_time);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", human_time);
    xil_printf("Project Compilation Timestamp: %s\r\n", timebuf);
}









int main(void) {

	u32 i, base;

    xil_printf("ACMI2.... \r\n");
    print_firmware_version();


	init_i2c();
	xil_printf("i2c init done...\r\n");
	usleep(1000);
	//prog_si570();

	//while (1) {
	   //write_lmk61e2();
	   sleep(1);
	//}


	//EVR reset
    xil_printf("Resetting EVR GTX...\r\n");
	Xil_Out32(XPAR_M_AXI_BASEADDR + 0x30, 0xFF);
	usleep(100);
	Xil_Out32(XPAR_M_AXI_BASEADDR + 0x30, 0);


    sys_thread_new("main", realmain, NULL, THREAD_STACKSIZE, DEFAULT_THREAD_PRIO);

    // Run threads.  Does not return.
    vTaskStartScheduler();
    // never reached
    return 42;
}
