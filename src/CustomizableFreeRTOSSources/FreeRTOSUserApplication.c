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
#include "GPIO.h"
#include "Loc_algo.h"

//Loc task
static StackType_t Loc_Task_Stack[30*configMINIMAL_STACK_SIZE];
static StaticTask_t Loc_Task_TCB;
extern TaskHandle_t LocTask_Handle = NULL;

//LED task
static StackType_t Led_Task_Stack[configMINIMAL_STACK_SIZE];
static StaticTask_t Led_Task_TCB;
static TaskHandle_t LedTask_Handle = NULL;
/*
 * User startup task. This task is created in main() and is
 * called when the scheduler starts.
 */
#if INCLUDE_userStartupTask == 1
void userStartupTask(void *pvParameters)
{
	/*
	 * Add user defined code for your first task here.
	 * This function should never return.
	 * When complete it should call vTaskDelete().
	 */

	BaseType_t xReturn;
	taskENTER_CRITICAL();

	LocTask_Handle = xTaskCreateStatic(Loc_Task,			//function
										"LocTask",		    //name
										30*configMINIMAL_STACK_SIZE,					//stack depth
										NULL,				//parameter
										2, 				    //priority
										Loc_Task_Stack,	    //stack frame
										&Loc_Task_TCB); 	//TCB

	//create
	xReturn = xTaskCreate(LED_Blink_Task,"LEDtask",configMINIMAL_STACK_SIZE,NULL,1,&LedTask_Handle);

	if(pdPASS!=xReturn)
	{
		printf("LED task create failure \r\n ");
	}

	taskEXIT_CRITICAL();

	//after all task has been created, deleted self
	vTaskDelete(NULL);

	for ( ; ; )
	{

	}
}
#endif

//
void LED_Blink_Task(void *pvParameters)
{
	for ( ; ; )
	{

		LED0_ON();
		LED1_ON();
		vTaskDelay(pdMS_TO_TICKS(500));
		printf("LED on\r\n");
		//block for 500ms

		LED0_OFF();
		LED1_OFF();
		vTaskDelay(pdMS_TO_TICKS(500));
		printf("LED off\r\n");
		//block for 500ms

	}

}

//
void Loc_Task(void *pvParameters)
{
	static int count;
	for ( ; ; )
	{
		//take a notify
		//if no notify has been sent, block self task
		ulTaskNotifyTake(pdTRUE,portMAX_DELAY);

		//calculate for source location
		Source_Loc();

	}
}
