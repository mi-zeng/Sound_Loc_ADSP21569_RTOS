/*
 * SPORT_driver.c
 *
 *  Created on: 2023Äê7ÔÂ31ÈÕ
 *      Author: zengming
 */


#include <sys/platform.h>
#include <drivers/sport/adi_sport.h>
#include <stdio.h>
#include <stdlib.h>
#include <cdef21569.h>
#include <time.h>

//RTOS header
#include "task.h"

//application header
#include "UART.h"
#include "GPIO.h"
#include "Sound_Loc_RTOS.h"
#include "SPORT_driver.h"
#include "FreeRTOSUserApplication.h"
#include "Loc_algo.h"

/*=============  D A T A  =============*/
/* Buffers */
ADI_CACHE_ALIGN extern int RX0B_BUF[2*DATA_LENGTH] = {0};
ADI_CACHE_ALIGN extern int RX1B_BUF[2*DATA_LENGTH] = {0};
ADI_CACHE_ALIGN extern int RX4B_BUF[2*DATA_LENGTH] = {0};
ADI_CACHE_ALIGN extern int RX5B_BUF[2*DATA_LENGTH] = {0};

//descriptor
ADI_PDMA_DESC_LIST LIST_RX0B;
ADI_PDMA_DESC_LIST LIST_RX1B;
ADI_PDMA_DESC_LIST LIST_RX4B;
ADI_PDMA_DESC_LIST LIST_RX5B;

/* Memory required for SPORT */
static uint8_t SPORTMemory0B[ADI_SPORT_MEMORY_SIZE];
static uint8_t SPORTMemory1B[ADI_SPORT_MEMORY_SIZE];
static uint8_t SPORTMemory4B[ADI_SPORT_MEMORY_SIZE];
static uint8_t SPORTMemory5B[ADI_SPORT_MEMORY_SIZE];

/* SPORT Handle */
//DAI0
static ADI_SPORT_HANDLE hSPORTDev0B;
static ADI_SPORT_HANDLE hSPORTDev1B;
//DAI1
static ADI_SPORT_HANDLE hSPORTDev4B;
static ADI_SPORT_HANDLE hSPORTDev5B;

/*
// performance evaluation parameters
volatile clock_t clock_start;
volatile clock_t clock_stop;
volatile clock_t clock_start_hard;
volatile clock_t clock_stop_hard;
volatile clock_t clock_start_soft;
volatile clock_t clock_stop_soft;
volatile clock_t cycles;
*/

static void RxSPORTCallback(void *pAppHandle,uint32_t nEvent,void *pArg)
{

	ADI_SPORT_RESULT eResult;
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    /* CASEOF (event type) */
    switch (nEvent)
    {
        /* CASE (buffer processed) */
        case ADI_SPORT_EVENT_RX_BUFFER_PROCESSED:
        		//as data DMA finished, send notify to loc task
        		vTaskNotifyGiveFromISR(LocTask_Handle,&xHigherPriorityTaskWoken);

        		//if task is woken from block, call scheduler
        		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

        		break;
        default:
        	 break;
    }

    // return
}



static void PrepareDescriptors (void)
{

	LIST_RX0B.pNxtDscp	    = &LIST_RX0B;
	LIST_RX0B.pStartAddr	= &RX0B_BUF[0];
	LIST_RX0B.Config		= ENUM_DMA_CFG_XCNT_INT;
	LIST_RX0B.XCount		= 2*DATA_LENGTH;   //2 datas
	LIST_RX0B.XModify		= 4;   //4 BYTES/data
	LIST_RX0B.YCount		= 0;
	LIST_RX0B.YModify		= 0;

	LIST_RX1B.pStartAddr	= &RX1B_BUF[0];
	LIST_RX1B.XCount		= 2*DATA_LENGTH;   //2 datas
	LIST_RX1B.XModify		= 4;   //4 BYTES/data

	//LIST_RX4B.pNxtDscp	    = &LIST_TX4A;
	LIST_RX4B.pNxtDscp	    = &LIST_RX4B;
	LIST_RX4B.pStartAddr	= &RX4B_BUF[0];
	LIST_RX4B.Config		= ENUM_DMA_CFG_XCNT_INT;
	//after left channel and right channel dma received transfer finish do a interrupt
	LIST_RX4B.XCount		= 2*DATA_LENGTH;   //2 datas
	LIST_RX4B.XModify		= 4;   //4 BYTES/data
	LIST_RX4B.YCount		= 0;
	LIST_RX4B.YModify		= 0;

	LIST_RX5B.pStartAddr	= &RX5B_BUF[0];
	LIST_RX5B.XCount		= 2*DATA_LENGTH;   //2 datas
	LIST_RX5B.XModify		= 4;   //4 BYTES/data


}

int Sport_Init(void)
{
    /* SPORT return code */
    ADI_SPORT_RESULT    eResult;

	/* Open the SPORT Device 0B*/
	eResult = adi_sport_Open(SPORT_DEVICE_0B,ADI_HALF_SPORT_B,ADI_SPORT_DIR_RX, ADI_SPORT_I2S_MODE, SPORTMemory0B,ADI_SPORT_MEMORY_SIZE,&hSPORTDev0B);
	CHECK_RESULT(eResult);
	/* Open the SPORT Device 1A */
	eResult = adi_sport_Open(SPORT_DEVICE_1B,ADI_HALF_SPORT_B,ADI_SPORT_DIR_RX, ADI_SPORT_I2S_MODE, SPORTMemory1B,ADI_SPORT_MEMORY_SIZE,&hSPORTDev1B);
	CHECK_RESULT(eResult);

	/* Open the SPORT Device 4B*/
	eResult = adi_sport_Open(SPORT_DEVICE_4B,ADI_HALF_SPORT_B,ADI_SPORT_DIR_RX, ADI_SPORT_I2S_MODE, SPORTMemory4B,ADI_SPORT_MEMORY_SIZE,&hSPORTDev4B);
	CHECK_RESULT(eResult);
	/* Open the SPORT Device 5A */
	eResult = adi_sport_Open(SPORT_DEVICE_5B,ADI_HALF_SPORT_B,ADI_SPORT_DIR_RX, ADI_SPORT_I2S_MODE, SPORTMemory5B,ADI_SPORT_MEMORY_SIZE,&hSPORTDev5B);
	CHECK_RESULT(eResult);

	/* Register SPORT Callback function */
	eResult = adi_sport_RegisterCallback(hSPORTDev0B,RxSPORTCallback,NULL);
	CHECK_RESULT(eResult);

	/* Prepare descriptors */
	PrepareDescriptors();

	eResult = adi_sport_DMATransfer(hSPORTDev0B, &LIST_RX0B, (1), ADI_PDMA_AUTOBUFFER_MODE, ADI_SPORT_CHANNEL_PRIM);
	CHECK_RESULT(eResult);
	eResult = adi_sport_DMATransfer(hSPORTDev1B, &LIST_RX1B, (1), ADI_PDMA_AUTOBUFFER_MODE, ADI_SPORT_CHANNEL_PRIM);
	CHECK_RESULT(eResult);

	eResult = adi_sport_DMATransfer(hSPORTDev4B, &LIST_RX4B, (1), ADI_PDMA_AUTOBUFFER_MODE, ADI_SPORT_CHANNEL_PRIM);
	CHECK_RESULT(eResult);
	eResult = adi_sport_DMATransfer(hSPORTDev5B, &LIST_RX5B, (1), ADI_PDMA_AUTOBUFFER_MODE, ADI_SPORT_CHANNEL_PRIM);
	CHECK_RESULT(eResult);


	eResult = adi_sport_Enable(hSPORTDev0B,true);
	CHECK_RESULT(eResult);

	eResult = adi_sport_Enable(hSPORTDev1B,true);
	CHECK_RESULT(eResult);

	eResult = adi_sport_Enable(hSPORTDev4B,true);
	CHECK_RESULT(eResult);

	eResult = adi_sport_Enable(hSPORTDev5B,true);
	CHECK_RESULT(eResult);

	//*SPORT0_CTL_A = 3255834995;
 	//*SPORT0_CTL_B = 6515;
	return eResult;

}


int Sport_Stop(void)
{
    /* SPORT return code */
    ADI_SPORT_RESULT    eResult;

	eResult = adi_sport_StopDMATransfer(hSPORTDev0B);
	CHECK_RESULT(eResult);
	eResult = adi_sport_StopDMATransfer(hSPORTDev1B);
	CHECK_RESULT(eResult);

	eResult = adi_sport_Close(hSPORTDev0B);
	CHECK_RESULT(eResult);
	eResult = adi_sport_Close(hSPORTDev1B);
	CHECK_RESULT(eResult);


	eResult = adi_sport_StopDMATransfer(hSPORTDev4B);
	CHECK_RESULT(eResult);
	eResult = adi_sport_StopDMATransfer(hSPORTDev5B);
	CHECK_RESULT(eResult);

	eResult = adi_sport_Close(hSPORTDev4B);
	CHECK_RESULT(eResult);
	eResult = adi_sport_Close(hSPORTDev5B);
	CHECK_RESULT(eResult);


	return eResult;
}


