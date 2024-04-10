/*
 * FreeRTOSUserApplication.h : Header providing definitions for FreeRTOSUserApplication.c
 *
 * File generated on ËÄÔÂ 3, 2024 at 09:59:24
 * by the FreeRTOS Add-In for CrossCore Embedded Studio.
 *
 * This file will only be generated when adding the FreeRTOS Add-In to your project,
 * or if the project is opened and the file is not found.
 * It is otherwise safe to modify this file without risk of the changes being lost.
 */

#ifndef _FREERTOS_USER_APPLICATION_H_
#define _FREERTOS_USER_APPLICATION_H_

#ifdef __cplusplus
extern "C" {
#endif

void userStartupTask( void* );
void LED_Blink_Task( void* );
void Loc_Task( void* );

extern TaskHandle_t LocTask_Handle;

#ifdef __cplusplus
}
#endif
#endif /* _FREERTOS_USER_APPLICATION_H_ */

