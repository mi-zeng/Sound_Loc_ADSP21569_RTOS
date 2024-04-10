/*
 * Loc_algo.c
 *
 *  Created on: 2024Äê4ÔÂ8ÈÕ
 *      Author: zengming
 */

#include "string.h"
#include "stdio.h"


#include "SPORT_driver.h"

static uint32_t Mic1Data[DATA_LENGTH];
static uint32_t Mic2Data[DATA_LENGTH];
static uint32_t Mic3Data[DATA_LENGTH];
static uint32_t Mic4Data[DATA_LENGTH];
static uint32_t Mic5Data[DATA_LENGTH];
static uint32_t Mic6Data[DATA_LENGTH];
static uint32_t Mic7Data[DATA_LENGTH];
static uint32_t Mic8Data[DATA_LENGTH];

void Source_Loc(void)
{
	int i = 0;
	Data_Update();
	printf("source loc finish\r\n");

	//todo: process algorithm below
}


static void Data_Update(void)
{

	int i;
	for(i=0;i<DATA_LENGTH-1;i++)
	{
		Mic1Data[i] = RX0B_BUF[2*i];
		Mic2Data[i] = RX0B_BUF[2*i + 1];
		Mic3Data[i] = RX1B_BUF[2*i];
		Mic4Data[i] = RX1B_BUF[2*i + 1];
		Mic5Data[i] = RX4B_BUF[2*i];
		Mic6Data[i] = RX4B_BUF[2*i + 1];
		Mic7Data[i] = RX5B_BUF[2*i];
		Mic8Data[i] = RX5B_BUF[2*i + 1];
	}

}


/*
static void Data_Update(void)
{
	//mic data array update

	memmove(&Mic1Data+1,&Mic1Data,DATA_LENGTH-1);
	Mic1Data[0] = RX0B_BUF[0];

	memmove(&Mic2Data+1,&Mic2Data,DATA_LENGTH-1);
	Mic2Data[0] = RX0B_BUF[1];

	memmove(&Mic3Data+1,&Mic3Data,DATA_LENGTH-1);
	Mic3Data[0] = RX1B_BUF[0];

	memmove(&Mic4Data+1,&Mic4Data,DATA_LENGTH-1);
	Mic4Data[0] = RX1B_BUF[1];

	memmove(&Mic5Data+1,&Mic5Data,DATA_LENGTH-1);
	Mic5Data[0] = RX4B_BUF[0];

	memmove(&Mic6Data+1,&Mic6Data,DATA_LENGTH-1);
	Mic6Data[0] = RX4B_BUF[1];

	memmove(&Mic7Data+1,&Mic7Data,DATA_LENGTH-1);
	Mic7Data[0] = RX5B_BUF[0];

	memmove(&Mic8Data+1,&Mic8Data,DATA_LENGTH-1);
	Mic8Data[0] = RX5B_BUF[1];

}
*/

