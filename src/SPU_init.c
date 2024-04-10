/*
 * SPU.c
 *
 *  Created on: 2023Äê8ÔÂ8ÈÕ
 *      Author: zengming
 */


#include "SPU_init.h"
#include "Sound_Loc_RTOS.h"
#include <sys/adi_core.h>
#include <services/spu/adi_spu.h>
#include <stdlib.h>
#include <stdio.h>


/* SPU handle */
static ADI_SPU_HANDLE      ghSpu;

/* Memory required for the SPU operation */
uint8_t             SpuMemory[ADI_SPU_MEMORY_SIZE];

/*
 * Prepares SPU configuration.
 *
 * Parameters
 *  None
 *
 * Returns
 *  None
 *Yes, it's necessary to configure a secure transaction for the SPORTx and Sportx DMA channel.
 *The system protection unit (SPU) provides write-protection against MMRs peripherals and its own write-protect registers.
 *If a write attempt is made to any locked MMR peripheral the SPU has write protected, it blocks the write.
 *The SPU generates a bus error to the master that attempted the write.
 *So, the peripherals which are used in your application need to be configured for the secure privileges on the SPU_SECUREP(n) registers.
 */
int SPU_init(void)
{
	int i;

    if(adi_spu_Init(0, SpuMemory, NULL, NULL, &ghSpu) != ADI_SPU_SUCCESS)
    {
    	REPORT_ERROR("Failed to initialize SPU service\n");
		return FAILED;
    }

    for(i=SPORT_0A_SPU;i<(SPORT_7B_SPU+1);i++)
    {
    	if(adi_spu_EnableMasterSecure(ghSpu, i, true) != ADI_SPU_SUCCESS)
    	{
    		REPORT_ERROR("Failed to enable Master secure for SPORT0A\n");
    		return FAILED;
    	}
    }

    // Make UART0 to generate secure transactions
    if(adi_spu_EnableMasterSecure(ghSpu, UART0_SPU_PID, true) != ADI_SPU_SUCCESS)
    {
        REPORT_ERROR("Failed to enable Master secure for UART0\n");
        return (FAILED);
    }

    // Make UART0 Tx DMA to generate secure transactions
    if(adi_spu_EnableMasterSecure(ghSpu, UART0_TxDMA_SPU_PID, true) != ADI_SPU_SUCCESS)
    {
        REPORT_ERROR("Failed to enable Master secure for UART0 Tx DMA\n");
        return (FAILED);
    }

    // Make UART0 Rx DMA to generate secure transactions
    if(adi_spu_EnableMasterSecure(ghSpu, UART0_RxDMA_SPU_PID, true) != ADI_SPU_SUCCESS)
    {
        REPORT_ERROR("Failed to enable Master secure for UART0 Rx DMA\n");
        return (FAILED);
    }


    return SUCCESS;
}
