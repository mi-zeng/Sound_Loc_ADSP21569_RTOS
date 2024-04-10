/*
 * SPORT_driver.h
 *
 *  Created on: 2023Äê7ÔÂ31ÈÕ
 *      Author: zengming
 */



#ifndef INC_SPORT_DRIVER_H_
#define INC_SPORT_DRIVER_H_

#include <stdint.h>
#include <sys/platform.h>
#include "Loc_algo.h"


#define SPORT_DEVICE_0A 			(0u)		/* SPORT device number */
#define SPORT_DEVICE_0B 			(0u)		/* SPORT device number */
#define SPORT_DEVICE_1A 			(1u)
#define SPORT_DEVICE_1B 			(1u)
#define SPORT_DEVICE_2A 			(2u)
#define SPORT_DEVICE_2B 			(2u)
#define SPORT_DEVICE_3A 			(3u)
#define SPORT_DEVICE_3B 			(3u)
#define SPORT_DEVICE_4A 			(4u)
#define SPORT_DEVICE_4B 			(4u)
#define SPORT_DEVICE_5A 			(5u)
#define SPORT_DEVICE_5B 			(5u)
#define SPORT_DEVICE_6A 			(6u)
#define SPORT_DEVICE_6B 			(6u)
#define SPORT_DEVICE_7A 			(7u)
#define SPORT_DEVICE_7B 			(7u)


#define DMA_NUM_DESC 				(2u)

//I2S transfer port
ADI_CACHE_ALIGN extern int RX0B_BUF[2*DATA_LENGTH];
ADI_CACHE_ALIGN extern int RX1B_BUF[2*DATA_LENGTH];
ADI_CACHE_ALIGN extern int RX4B_BUF[2*DATA_LENGTH];
ADI_CACHE_ALIGN extern int RX5B_BUF[2*DATA_LENGTH];

int Sport_Init(void);
int Sport_Stop(void);
static void PrepareDescriptors (void);
#endif /* INC_SPORT_DRIVER_H_ */
