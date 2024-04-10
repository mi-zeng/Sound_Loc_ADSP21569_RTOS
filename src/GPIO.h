/*
 * GPIO.h
 *
 *  Created on: 2023Äê7ÔÂ31ÈÕ
 *      Author: zengming
 */


#ifndef GPIO_H_
#define GPIO_H_

#include <services/gpio/adi_gpio.h>
#include <stdio.h>
#include <services\gpio\adi_gpio.h>


#define PIN_CODEC_PD  ADI_GPIO_PIN_0
#define PIN_CODEC_SPK ADI_GPIO_PIN_1

//global variable for process event chosen
extern int SDRAM_TRANS_FLAG;
extern int FILTER_FLAG;

//debug variable
extern int KEY3_FLAG;
extern int KEY5_FLAG;

// LED3,4,5 controlled by MPC23017 IO expender needs to be controlled by I2C
#define GPIO_MEMORY_SIZE (ADI_GPIO_CALLBACK_MEM_SIZE)

int  LED_init(void);

// LED0 = PC_03, LED1=PC_02, LED2 = PC_01
void LED0_ON(void);
void LED0_OFF(void);
void LED1_ON(void);
void LED1_OFF(void);
void LED2_ON(void);
void LED2_OFF(void);
//init key int
int  KEY_init(void);



#endif /* UART_H_ */
