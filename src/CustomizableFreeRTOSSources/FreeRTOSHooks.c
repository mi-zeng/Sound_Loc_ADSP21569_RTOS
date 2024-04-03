/*
 * FreeRTOSHooks.c : Hook functions for FreeRTOS
 *
 * File generated on ËÄÔÂ 3, 2024 at 09:59:23
 * by the FreeRTOS Add-In for CrossCore Embedded Studio.
 *
 * This file will only be generated when adding the FreeRTOS Add-In to your project,
 * or if the project is opened and the file is not found.
 * It is otherwise safe to modify this file without risk of the changes being lost.
 */
 
/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <builtins.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/*-----------------------------------------------------------*/
/*
 * Standard FreeRTOS callback/hook functions:
 */

/* Standard malloc failed hook function. */
#if (configUSE_MALLOC_FAILED_HOOK == 1)
void vApplicationMallocFailedHook( void )
{
	/**
	* Called if a call to pvPortMalloc() fails because there is insufficient
	* free memory available in the FreeRTOS heap.  pvPortMalloc() is called
	* internally by FreeRTOS API functions that create tasks, queues, software
	* timers, and semaphores.  The size of the FreeRTOS heap is set by the
	* configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h.
	* The default behavior on a failure is to call abort.
	*/
	taskDISABLE_INTERRUPTS();
	abort();
}
#endif
/*-----------------------------------------------------------*/

/* Standard check stackOverflow hook function. */
#if(  configCHECK_FOR_STACK_OVERFLOW > 0 )
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	/**
	* Run time stack overflow checking is performed if
	* configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	* function is called if a stack overflow is detected.
	*/
	taskDISABLE_INTERRUPTS();
	abort();
}
#endif
/*-----------------------------------------------------------*/

/* Standard idle hook function. */
#if ( configUSE_IDLE_HOOK == 1 )
void vApplicationIdleHook( void )
{
	/**
 	* This is just a trivial example of an idle hook.  It is called on each
	* cycle of the idle task.  It must *NOT* attempt to block.  In this case the
	* idle task just queries the amount of FreeRTOS heap that remains.  See the
	* memory management section on the http://www.FreeRTOS.org web site for memory
	* management options.  If there is a lot of heap memory free then the
	* configTOTAL_HEAP_SIZE value in FreeRTOSConfig.h can be reduced to free up	RAM.
 	*/
	volatile size_t xFreeHeapSpace = xPortGetFreeHeapSize();
}
#endif
/*-----------------------------------------------------------*/

/* Standard tick hook function. Called by the scheduler for each tick */
#if ( configUSE_TICK_HOOK == 1 )
void vApplicationTickHook( void )
{

}
#endif
/*-----------------------------------------------------------*/

/* Standard daemon task startup hook function. */
#if( configUSE_DAEMON_TASK_STARTUP_HOOK == 1 )
void vApplicationDaemonTaskStartupHook( void )
{
	 /** 
	 * This function is called by the scheduler before any tasks are started.
	 * This is the recommended location to initialize any SSL/DD peripherals.
	 */
}
#endif
/*-----------------------------------------------------------*/

 /**
 * vAssertCalled is a hook function that is called when an kernel assertion
 * check fails.
 */
void vAssertCalled( const char * pcFile, unsigned long ulLine )
{
	taskDISABLE_INTERRUPTS();
	abort();
}

