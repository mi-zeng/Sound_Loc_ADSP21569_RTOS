/*****************************************************************************
 * Sound_Loc_RTOS.h
 *****************************************************************************/

#ifndef __SOUND_LOC_RTOS_H__
#define __SOUND_LOC_RTOS_H__

/* Add your custom header content here */
#define SUCCESS   0
#define FAILED   -1

#define TRUE  1
#define FALSE 0

#define REPORT_ERROR        	 printf
#define DEBUG_INFORMATION        printf


#define CHECK_RESULT(eResult) \
        if(eResult != 0)\
		{\
			return (1);\
        }


#endif /* __SOUND_LOC_RTOS_H__ */
