/*
 * SRU.h
 *
 *  Created on: 2023Äê7ÔÂ31ÈÕ
 *      Author: zengming
 */
#include <sys/platform.h>
#include <sru21569.h>
#include <cdef21569.h>

#include "SRU_init.h"
#include "Sound_Loc_RTOS.h"



int SRU_init(void)
{
	*pREG_PADS0_DAI0_IE=0x1ffffe;
	*pREG_PADS0_DAI1_IE=0x1ffffe;

	/*
	SRU(DAI0_PB19_O,DAI0_PB03_I);
	SRU(DAI0_PB20_O,DAI0_PB04_I);
	*/


	//U4 1777
	SRU(LOW,DAI0_PBEN19_I);
	SRU(LOW,DAI0_PBEN20_I);
	SRU(LOW,DAI0_PBEN09_I);
	SRU(LOW,DAI0_PBEN10_I);
	SRU(HIGH,DAI0_PBEN11_I);

	//
    SRU(DAI0_PB19_O,SPT0_ACLK_I);
    SRU(DAI0_PB19_O,SPT0_BCLK_I);
    SRU(DAI0_PB20_O,SPT0_AFS_I);
    SRU(DAI0_PB20_O,SPT0_BFS_I);
    SRU(DAI0_PB19_O,SPT1_ACLK_I);
    SRU(DAI0_PB20_O,SPT1_AFS_I);
    SRU(DAI0_PB19_O,SPT1_BCLK_I);
    SRU(DAI0_PB20_O,SPT1_BFS_I);

    //data
    SRU(DAI0_PB09_O,SPT0_BD0_I);     //ADC DATA0
    SRU(DAI0_PB10_O,SPT1_BD0_I);	 //ADC DATA1
    SRU(SPT0_AD0_O,DAI0_PB11_I);	 //DAC


    //U8 1777
	SRU2(LOW,DAI1_PBEN19_I);	    //BCLK
	SRU2(LOW,DAI1_PBEN20_I);		//LRCLK
	SRU2(LOW,DAI1_PBEN09_I);		//ADC0
	SRU2(LOW,DAI1_PBEN10_I);		//ADC1
	SRU2(HIGH,DAI1_PBEN11_I);		//DAC

	//clk
    SRU2(DAI1_PB19_O,SPT4_ACLK_I);
    SRU2(DAI1_PB19_O,SPT4_BCLK_I);
    SRU2(DAI1_PB20_O,SPT4_AFS_I);
    SRU2(DAI1_PB20_O,SPT4_BFS_I);
    SRU2(DAI1_PB19_O,SPT5_ACLK_I);
    SRU2(DAI1_PB19_O,SPT5_BCLK_I);
    SRU2(DAI1_PB20_O,SPT5_AFS_I);
    SRU2(DAI1_PB20_O,SPT5_BFS_I);

    //data
    SRU2(DAI1_PB09_O,SPT4_BD0_I);	//ADC DATA0
    SRU2(DAI1_PB10_O,SPT5_BD0_I);	//ADC DATA1
    SRU2(SPT4_AD0_O,DAI1_PB11_I);	//DAC



/*
  * LEGACY SRU CONFIG FOR EVK
    SRU2(LOW,DAI1_PBEN05_I);

    SRU2(DAI1_PB05_O,SPT4_ACLK_I);
    SRU2(DAI1_PB05_O,SPT4_BCLK_I);

    SRU2(DAI1_PB04_O,SPT4_AFS_I);
    SRU2(DAI1_PB04_O,SPT4_BFS_I);
    SRU2(LOW,DAI1_PBEN04_I);

    SRU2(SPT4_AD0_O,DAI1_PB01_I);
    SRU2(HIGH,DAI1_PBEN01_I);

    SRU2(SPT4_AD1_O,DAI1_PB10_I);
    SRU2(HIGH,DAI1_PBEN10_I);


    SRU2(DAI1_PB05_O,DAI1_PB12_I);
    SRU2(HIGH,DAI1_PBEN12_I);

    SRU2(DAI1_PB04_O,DAI1_PB20_I);
    SRU2(HIGH,DAI1_PBEN20_I);

    SRU2(DAI1_PB06_O,SPT4_BD0_I);
    SRU2(LOW,DAI1_PBEN06_I);

    SRU2(DAI1_PB07_O,SPT4_BD1_I);
    SRU2(LOW,DAI1_PBEN07_I);
	*/

    return SUCCESS;
}



/*
 *
 * invalid operation, Signal routing is unavailable according to DAI part of hardware reference manual
 *
 *
 *
 *
 * 1777 U4 and U8
 *
 * BCLK   19
 * LRCLK  20
 * ADC0   9
 * ADC1   10
 *
 * TAKE U4_1777 as CLK master device ,21569 as slave and broker, U8_1777 as slave
 *      U4_BCLK  ->  DAI0_PIN19_O  -> (DAI0_CRSPIN03_I ->  DAI0_CRSPIN03_O) -> (DAI1_PIN19_I -> DAI_PIN19_O)
 *      				           |                                        |
 *                                 |                                        |
 *                                 -> SPT_BCLK_I                            -> SPT_BCLK_I
 *                                 (same implementation for LRCLK)
 *
 *                                 	SRU  DAI0 SPT0-3  CRS_PB3-6_O
 *                                 	SRU2 DAI1 SPT4-7  CRS_PB3-6_O
 *
 * BCLK  can only choose CRS_PB3_O CRS_PB5_O as source for DAI0-DIA1 interconnection
 * LRCLK can only choose CRS_PB4_O CRS_PB6_O as source for DAI0-DIA1 interconnection
 */
