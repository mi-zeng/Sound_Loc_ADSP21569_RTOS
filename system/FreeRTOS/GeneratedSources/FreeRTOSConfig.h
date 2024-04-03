/*
 * Source file generated on ËÄÔÂ 3, 2024 at 09:59:23 
 * by the FreeRTOS Add-In for CrossCore Embedded Studio.
 *
 * This file is generated automatically based upon the options selected in 
 * the FreeRTOS configuration dialog. Changes to this configuration should be made by
 * changing the appropriate options in system.svc rather than editing this file.
 *
 * If you need to make manual changes, these can be added to 
 * src\CustomizableFreeRTOSSources\FreeRTOSConfigExtend.h which is included from this file. 
 */

/** FreeRTOS configuration **/

#ifndef _FREERTOS_CFG_H_
#define _FREERTOS_CFG_H_

/**Priorities**/
#define configMAX_PRIORITIES                                      7 
#define configTIMER_TASK_PRIORITY                                 6 
#define configMAX_CO_ROUTINE_PRIORITIES                           2 
#define configMAX_API_CALL_INTERRUPT_PRIORITY                     18 

/**Memory Allocation**/
#define configTOTAL_HEAP_SIZE                                     51200 
#define configAPPLICATION_ALLOCATED_HEAP                          0 
#define configSUPPORT_STATIC_ALLOCATION                           1 
#define configSUPPORT_DYNAMIC_ALLOCATION                          1 

/**Tasks & Synchronization**/
#define configMAX_TASK_NAME_LEN                                   10 
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS                   1 
#define configMINIMAL_STACK_SIZE                                  ( ( unsigned short ) 200 ) 
#define configTASK_RETURN_ADDRESS                                 NULL 
#define configUSE_PORT_OPTIMISED_TASK_SELECTION                   1 
#define configUSE_TASK_NOTIFICATIONS                              1 
#define configTASK_NOTIFICATION_ARRAY_ENTRIES                     1 
#define configUSE_APPLICATION_TASK_TAG                            0 
#define configUSE_QUEUE_SETS                                      1 
#define configQUEUE_REGISTRY_SIZE                                 8 
#define configUSE_COUNTING_SEMAPHORES                             1 
#define configUSE_MUTEXES                                         1 
#define configUSE_RECURSIVE_MUTEXES                               1 

/**Timers & Co-Routines**/
#define configUSE_TIMERS                                          1 
#define configTIMER_QUEUE_LENGTH                                  5 
#define configTIMER_TASK_STACK_DEPTH                              400 
#define configUSE_CO_ROUTINES                                     0 

/**RTOS Behavior**/
#define configUSE_PREEMPTION                                      1 
#define configUSE_TIME_SLICING                                    0 
#define configIDLE_SHOULD_YIELD                                   1 
#define configUSE_TICKLESS_IDLE                                   0 
#define configTICK_RATE_HZ                                        ( ( TickType_t ) 1000 ) 
#define configCPU_CLOCK_HZ                                        ( 1000 * 1000000 ) 

/**Hooks**/
#define configUSE_IDLE_HOOK                                       0 
#define configUSE_TICK_HOOK                                       0 
#define configUSE_MALLOC_FAILED_HOOK                              1 
#define configUSE_DAEMON_TASK_STARTUP_HOOK                        1 
#define configCHECK_FOR_STACK_OVERFLOW                            2 

/**Debugging & Profiling**/
#define configGENERATE_RUN_TIME_STATS                             0 
#define configUSE_TRACE_FACILITY                                  0 
#define configUSE_STATS_FORMATTING_FUNCTIONS                      0 

/**Enabled API Functions - FreeRTOS**/
#define INCLUDE_xResumeFromISR                                    0 
#define INCLUDE_xTaskResumeFromISR                                0 
#define INCLUDE_xEventGroupSetBitFromISR                          0 
#define INCLUDE_vTaskPrioritySet                                  1 
#define INCLUDE_uxTaskPriorityGet                                 1 
#define INCLUDE_vTaskDelete                                       1 
#define INCLUDE_vTaskSuspend                                      1 
#define INCLUDE_xTaskDelayUntil                                   1 
#define INCLUDE_vTaskDelay                                        1 
#define INCLUDE_xTaskGetSchedulerState                            0 
#define INCLUDE_xTaskGetCurrentTaskHandle                         0 
#define INCLUDE_uxTaskGetStackHighWaterMark                       0 
#define INCLUDE_xTaskGetIdleTaskHandle                            0 
#define INCLUDE_eTaskGetState                                     1 
#define INCLUDE_xTaskAbortDelay                                   0 
#define INCLUDE_xTaskGetHandle                                    0 
#define INCLUDE_vTaskCleanUpResources                             1 
#define INCLUDE_xSemaphoreGetMutexHolder                          0 
/**Enabled API Functions - ADI**/
#define INCLUDE_userStartupTask                                   1 
/**Enabled API Functions - Not user configurable**/
#define INCLUDE_xTimerPendFunctionCall                            1 


/**
 * Calls to configASSERT( x ) exist at key points in the FreeRTOS kernel code. 
 * If FreeRTOS is functioning correctly, and is being used correctly, 
 * then the configASSERT() parameter will be non-zero. 
 * If the parameter is found to equal zero, then an error has occurred.
 */
void vAssertCalled( const char * pcFile, unsigned long ulLine );
#define configASSERT( x ) if( (x) == 0 ) vAssertCalled( __FILE__, __LINE__ )

/**User will be able to set this macro outside this file**/
#ifndef configSETUP_TICK_INTERRUPT
void vConfigureTickInterrupt( void );
#define configSETUP_TICK_INTERRUPT()                              vConfigureTickInterrupt(); 
#endif
void vClearTickInterrupt( void );

/**User can add/override macros in the following header**/
#include <FreeRTOSConfigExtend.h>

#endif /* _FREERTOS_CFG_H_ */ 

