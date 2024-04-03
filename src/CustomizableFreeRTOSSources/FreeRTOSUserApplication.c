/*
 * FreeRTOSUserApplication.h : Default user task for FreeRTOS.
 *
 * File generated on ËÄÔÂ 3, 2024 at 09:59:24
 * by the FreeRTOS Add-In for CrossCore Embedded Studio.
 *
 * This file will only be generated when adding the FreeRTOS Add-In to your project,
 * or if the project is opened and the file is not found.
 * It is otherwise safe to modify this file without risk of the changes being lost.
 */

/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/* User task includes. */
#include "FreeRTOSUserApplication.h"

/*
 * User startup task. This task is created in main() and is
 * called when the scheduler starts.
 */
#if INCLUDE_userStartupTask == 1
void userStartupTask( void *pvParameters )
{
	/*
	 * Add user defined code for your first task here.
	 * This function should never return.
	 * When complete it should call vTaskDelete().
	 */
	for ( ; ; )
	{

	}
}
#endif

