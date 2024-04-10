/*
 * GPIO.c
 *
 *  Created on: 2023Äê7ÔÂ31ÈÕ
 *      Author: zengming
 */

#include "UART.h"
#include "SPORT_driver.h"
#include "Sound_Loc_RTOS.h"
#include "GPIO.h"
#include <stdio.h>

static uint8_t gpioMemory[GPIO_MEMORY_SIZE];

static char KEY3_info[] = "KEY 3 PRESSED \n";
static char KEY5_info[] = "KEY 5 PRESSED \n";

extern int SDRAM_TRANS_FLAG = 0;
extern int FILTER_FLAG = 0;
extern int KEY3_FLAG = 0;
extern int KEY5_FLAG = 0;

//KEY Interrupt service function
void gpioCallback(ADI_GPIO_PIN_INTERRUPT ePinInt, uint32_t Data, void *pCBParam)
{
	if (ePinInt == ADI_GPIO_PIN_INTERRUPT_1)
	{

		if (Data & ADI_GPIO_PIN_3)
		{
			printf("Push Button KEY/PB3 pressed \n");
			if(KEY3_FLAG == 0)
			{
				KEY3_FLAG = 1;
				printf("KEY3_FLAG = 1\n");
			}
			else
			{
				KEY3_FLAG = 0;
				printf("KEY3_FLAG = 0\n");
			}

		}
		if (Data & ADI_GPIO_PIN_5)
		{
			printf("Push Button KEY/PB5 pressed \n");
			if(KEY5_FLAG == 0)
			{
				KEY5_FLAG = 1;
				printf("KEY5_FLAG = 1\n");
			}
			else
			{
				KEY5_FLAG = 0;
				printf("KEY5_FLAG = 0\n");
			}

		}
	}
}

int KEY_init(void)
{
	uint32_t gpioMaxCallbacks;

	ADI_GPIO_RESULT Result;
	Result = adi_gpio_Init((void*)gpioMemory,GPIO_MEMORY_SIZE,&gpioMaxCallbacks);
	if(Result != ADI_GPIO_SUCCESS)
	{
		printf("GPIO Initialization failed \n");
	}

	/*Initialize PB_03 as input pin. Also set input enable */
	Result = adi_gpio_PortInit(ADI_GPIO_PORT_B,ADI_GPIO_PIN_3|ADI_GPIO_PIN_5, ADI_GPIO_DIRECTION_INPUT,true);
	if(Result != ADI_GPIO_SUCCESS)
	{
		printf("GPIO Initialization failed \n");
	}

	/*Register a callback */
	Result = adi_gpio_RegisterCallback(ADI_GPIO_PIN_INTERRUPT_1,ADI_GPIO_PIN_3|ADI_GPIO_PIN_5,gpioCallback,(void*)0);
	if(Result != ADI_GPIO_SUCCESS)
	{
		printf("GPIO Initialization failed \n");
	}

	/* Configure the PINT1 interrupt for level ADI_GPIO_SENSE_LEVEL_HIGH*/
	Result =adi_gpio_PinInt(ADI_GPIO_PIN_ASSIGN_PBL_PINT1,ADI_GPIO_PIN_3|ADI_GPIO_PIN_5, ADI_GPIO_PIN_INTERRUPT_1,ADI_GPIO_PIN_ASSIGN_BYTE_0,true,ADI_GPIO_SENSE_RISING_EDGE);
	if(Result != ADI_GPIO_SUCCESS)
	{
		printf("GPIO Initialization failed \n");
	}

	return Result;
}

int LED_init(void)
{

	ADI_GPIO_RESULT Result;

	/*Configure the Port Pin PC_01 as output for LED blink*/
	Result = adi_gpio_SetDirection(ADI_GPIO_PORT_C,ADI_GPIO_PIN_1, ADI_GPIO_DIRECTION_OUTPUT);
	if(Result!= ADI_GPIO_SUCCESS)
	{
		printf("GPIO Initialization failed \n");
	}

	/*Configure the Port Pin PC_02 as output for LED blink*/
	Result = adi_gpio_SetDirection(ADI_GPIO_PORT_C,ADI_GPIO_PIN_2, ADI_GPIO_DIRECTION_OUTPUT);
	if(Result!= ADI_GPIO_SUCCESS)
	{
		printf("GPIO Initialization failed \n");
	}

	/*Configure the Port Pin PC_03 as output for LED blink*/
	//conflict as SPK enable in HIK_ANC
	Result = adi_gpio_SetDirection(ADI_GPIO_PORT_C,ADI_GPIO_PIN_3, ADI_GPIO_DIRECTION_OUTPUT);
	if(Result!= ADI_GPIO_SUCCESS)
	{
		printf("GPIO Initialization failed \n");
	}

	// set SPK on as default
	//adi_gpio_Set(ADI_GPIO_PORT_C,PIN_CODEC_SPK);

	//keep spk disable
	adi_gpio_Clear(ADI_GPIO_PORT_C,PIN_CODEC_SPK);


	return Result;
}

void LED0_ON(void)
{
	adi_gpio_Set(ADI_GPIO_PORT_C,ADI_GPIO_PIN_3);
}

void LED0_OFF(void)
{
	adi_gpio_Clear(ADI_GPIO_PORT_C,ADI_GPIO_PIN_3);
}

void LED1_ON(void)
{
	adi_gpio_Set(ADI_GPIO_PORT_C,ADI_GPIO_PIN_2);
}

void LED1_OFF(void)
{
	adi_gpio_Clear(ADI_GPIO_PORT_C,ADI_GPIO_PIN_2);
}


void LED2_ON(void)
{
	adi_gpio_Set(ADI_GPIO_PORT_C,ADI_GPIO_PIN_1);
}

void LED2_OFF(void)
{
	adi_gpio_Clear(ADI_GPIO_PORT_C,ADI_GPIO_PIN_1);
}


