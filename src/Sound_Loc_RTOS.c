/*****************************************************************************
 * Sound_Loc_RTOS.c
 *****************************************************************************/

/* Standard includes. */
#include <stdlib.h>
#include <sys/platform.h>
#include "adi_initialize.h"

/* Kernel includes. */
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"

/* Application includes. */
#include "FreeRTOSUserApplication.h"
#include "Sound_Loc_RTOS.h"

//
#include "GPIO.h"
#include "SPORT_driver.h"
#include "SPU_init.h"
#include "UART.h"
#include "SRU_init.h"

//static funciton
static void Driver_Init(void);
/** 
 * If you want to use command program arguments, then place them in the following string. 
 */
char __argv_string[] = "";

int main(int argc, char *argv[])
{
	/**
	 * Initialize managed drivers and/or services that have been added to 
	 * the project.
	 * @return zero on success 
	 */
	adi_initComponents();
	/* Begin adding your custom code here */

	Driver_Init();

	/* When using FreeRTOS calls to SSL/DD cannot be made until the scheduler is active.
	To ensure that devices are initialized before tasks are started place your code
	in vApplicationDaemonTaskStartupHook() located in FreeRTOSHooks.c */

	/* Create a FreeRTOS task to run when the scheduler starts if userStartupTask is enabled in system.svc */
#if INCLUDE_userStartupTask == 1
	BaseType_t xReturned;
	TaskHandle_t startupTaskHandle;
	xReturned = xTaskCreate( userStartupTask,
				"Startup Task",
				configMINIMAL_STACK_SIZE,
				NULL,
				tskIDLE_PRIORITY + 2,
				&startupTaskHandle );

	if( xReturned != pdPASS )
	{
		abort();
	}
#endif /* INCLUDE_userStartupTask == 1 */

	/* Start the scheduler. */
	vTaskStartScheduler();

	return 0;
}

static void Driver_Init(void)
{
    /* SPU initialization */
    SPU_init();

	/* SRU Configuration */
    SRU_init();

    /*GPIO init*/
    LED_init();

    /*KEY init*/
    KEY_init();

    /*I2S init*/
    Sport_Init();

    //adding hardware test if possible
}

