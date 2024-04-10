/*
 * UART.c
 *
 *  Created on: 2023Äê7ÔÂ31ÈÕ
 *      Author: zengming
 */


#include "UART.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

bool TestResult = true;

/* UART Buffers for Tx and Rx */

static uint8_t TxBuffer[BUFF_SIZE];
static uint8_t RxBuffer[BUFF_SIZE];

static char uart0_init_info[]="UART_0 INIT FINISH \n";

/* Driver memory required for UART */
static uint8_t UARTMemory0[ADI_UART_BIDIR_MEMORY_SIZE];
static uint8_t UARTMemory1[ADI_UART_BIDIR_MEMORY_SIZE];
static uint8_t UARTMemory2[ADI_UART_BIDIR_MEMORY_SIZE];

ADI_CACHE_ALIGN static uint8_t Received_Data_0;
ADI_CACHE_ALIGN static uint8_t Received_Data_1;
ADI_CACHE_ALIGN static uint8_t Received_Data_2;

ADI_CACHE_ALIGN ADI_PDMA_DESC_LIST Rec0_DMA_List;
ADI_CACHE_ALIGN ADI_PDMA_DESC_LIST Rec1_DMA_List;
ADI_CACHE_ALIGN ADI_PDMA_DESC_LIST Rec2_DMA_List;

ADI_CACHE_ALIGN ADI_PDMA_DESC_LIST Trans0_DMA_List;
ADI_CACHE_ALIGN ADI_PDMA_DESC_LIST Trans1_DMA_List;
ADI_CACHE_ALIGN ADI_PDMA_DESC_LIST Trans2_DMA_List;


/* UART Handles */
//external pointer as used in other files
static ADI_UART_HANDLE hUART_0;
static ADI_UART_HANDLE hUART_1;
static ADI_UART_HANDLE hUART_2;

/*
 * UART configuration
 * Baudrate     312500
 * Parity       NAN
 * Stop_bit     1
 * Flow_control NAN
 */

static void CheckResult(ADI_UART_RESULT Result)
{
    if (Result != ADI_UART_SUCCESS) {
        REPORT_ERROR("Failed with error code 0x%08X\n", Result);
    }
}

/* UART callback function */
void UART0Callback(void *pCBParam, uint32_t nEvent, void *pArg)
{
	static int count = 0;
    if(nEvent == (uint32_t)ADI_UART_EVENT_TX_PROCESSED)
    {
    	printf("tx int \n");
    }
    if(nEvent == (uint32_t)ADI_UART_EVENT_RX_PROCESSED)
    {
    	count++;
    	printf("rx0 int %d %c \n",count,Received_Data_0);
    }
}
//
void UART1Callback(void *pCBParam, uint32_t nEvent, void *pArg)
{
	static int count = 0;
    if(nEvent == (uint32_t)ADI_UART_EVENT_TX_PROCESSED)
    {
    	printf("tx int \n");
    }
    if(nEvent == (uint32_t)ADI_UART_EVENT_RX_PROCESSED)
    {
    	count++;
    	printf("rx1 int %d %c \n",count,Received_Data_1);
    }
}

//
void UART2Callback(void *pCBParam, uint32_t nEvent, void *pArg)
{
	static int count = 0;
    if(nEvent == (uint32_t)ADI_UART_EVENT_TX_PROCESSED)
    {
    	printf("tx int \n");
    }
    if(nEvent == (uint32_t)ADI_UART_EVENT_RX_PROCESSED)
    {
    	count++;
    	printf("rx2 int %d %c \n",count,Received_Data_2);
    }
}

int UART0_init(void)
{

    ADI_UART_RESULT   eResult;
    /* Open UART */
    //Open a desired UART device instance and set the default configuration.
    eResult = adi_uart_Open(ADI_UART_0, ADI_UART_DIR_BIDIRECTION, UARTMemory0, ADI_UART_BIDIR_MEMORY_SIZE, &hUART_0);
    CheckResult(eResult);

    eResult = adi_uart_Open(ADI_UART_1, ADI_UART_DIR_BIDIRECTION, UARTMemory1, ADI_UART_BIDIR_MEMORY_SIZE, &hUART_1);
    CheckResult(eResult);

    eResult = adi_uart_Open(ADI_UART_2, ADI_UART_DIR_BIDIRECTION, UARTMemory2, ADI_UART_BIDIR_MEMORY_SIZE, &hUART_2);
    CheckResult(eResult);


    // By default, SCLK0_0 is 93.75MHz and if a preload code is added SCLK0_0 is 125 MHz
    // Baud rate = (SCLK0_0 / (pow(16,(1-Edbo))*Divisor))
    // for 9600 baudrate, edbo = 1, divisor = 13020, actual 9600.614 ,error rate = 0.06%
    // for 312500 baudrate, edbo = 0, divisor = 25 , actual 312500   ,error rate = 0%
    // Use UART_CLK.EDBO mode only when bit rate accuracy is not acceptable in the UART_CLK.EDBO=0 mode.
    // Normally, the receiver samples every incoming bit at exactly the 7th, 8th and 9th sample clock. If, however, the
    // UART_CLK.EDBO bit is set to 1, the receiver samples bits roughly at 7/16th, 8/16th, and 9/16th of their period.
    /* Set prescaler */
    bool Edbo = 0u;
    /* Divisor value set such that Baud rate is set to 9600 for SCLK0_0 = 125 MHz*/
    uint32_t Divisor = 25;
    /* Configure UART baud rate */
    eResult = adi_uart_ConfigBaudRate(hUART_0, Edbo, Divisor);
    CheckResult(eResult);
    eResult = adi_uart_ConfigBaudRate(hUART_1, Edbo, Divisor);
    CheckResult(eResult);
    eResult = adi_uart_ConfigBaudRate(hUART_2, Edbo, Divisor);
    CheckResult(eResult);
    /* Register UART Callback function for DMA mode */
    eResult = adi_uart_RegisterCallback(hUART_0,&UART0Callback, NULL);
    CheckResult(eResult);
    eResult = adi_uart_RegisterCallback(hUART_1,&UART1Callback, NULL);
    CheckResult(eResult);
    eResult = adi_uart_RegisterCallback(hUART_2,&UART2Callback, NULL);
    CheckResult(eResult);

    /*
     * The "adi_int_InstallHandler()" API can be used to install an interrupt handler for a given processor interrupt.

		The API takes the following arguments: (iid, pfHandler, pCBParam, bEnable)
		    iid         -    Interrupt ID.
		    pfHandler   -   Handler which handles the interrupt.
		    pCBParam    -   Application-provided callback parameter, which is passed back when the given handler is called.
		    bEnable     -   Flag, which indicates whether to enable or disable the given interrupt, after the interrupt handler installation.

		For more information, please refer the below mentioned CCES help path.
		CCES Help : CrossCore Embedded Studio 2.11.1 > System Run-Time Documentation > Interrupt Support > Interrupt Handler Header File and Functions >  adi_int_InstallHandler
    */

    /*
     * in hardware reference, it's possible to using interrupts without DMA in UART section
     * but also in hardware reference, UART interrupts are all involved with DMA
     * it's conflict
     */
    List_init();

    /* Read UART data to Rx buffer */
    eResult = adi_uart_DMARead(hUART_0, &Rec0_DMA_List, 1, ADI_PDMA_AUTOBUFFER_MODE);
    CheckResult(eResult);
    eResult = adi_uart_DMARead(hUART_1, &Rec1_DMA_List, 1, ADI_PDMA_AUTOBUFFER_MODE);
    CheckResult(eResult);
    eResult = adi_uart_DMARead(hUART_2, &Rec2_DMA_List, 1, ADI_PDMA_AUTOBUFFER_MODE);
    CheckResult(eResult);

    //bug£º even it is set to autobuffer mode, it is still stop_mode under debug supervise
    //bug 2: after resume is pressed, program still stuck at breakpoint unless it's removed
    /* 2023.8.9
     * tried 1:using rx interrupt with core mode writing and not work, but it's invalid for core writing/read with a call back registered
     * 	     2:core read will jam program so cannot be used
     * 	     3:for DMA auto buffer mode, receive interrupt can only occur once "it is observed although ePDMAMode is set autobuffer in debug
     * 	       ,it's not chenged and still STOP_MODE. tried several method and cannot be solved
     * 	     4:for now ,just using core wirte functionality is fine
     * using core write
     */

    /* Write Tx buffer to UART */
    //core mode requires no callback registered, and have critical situation processing in RTOS environment
    //eResult = adi_uart_CoreWrite(hUART_0, &uart0_init_info, sizeof(uart0_init_info));
    //CheckResult(eResult);


    /* Close the UART device */
    //dont close
    /*
    eResult = adi_uart_Close(hUART_0);
    CheckResult(eResult);
	*/
    return eResult;

}

// uart0 core write
void UART0_corewrite(void* pTxBuffer, uint32_t nTxSize)
{
	adi_uart_CoreWrite(hUART_0, pTxBuffer, nTxSize);;
}

//receive DMA description list
inline void List_init(void)
{

	Rec0_DMA_List.pStartAddr            = &Received_Data_0;
	Rec0_DMA_List.XCount                = DMA_MSIZE_IN_BYTES;
	Rec0_DMA_List.XModify               = DMA_MSIZE_IN_BYTES;
	Rec0_DMA_List.Config                = ENUM_DMA_CFG_XCNT_INT;
	Rec0_DMA_List.pNxtDscp              = NULL;

	Rec1_DMA_List.pStartAddr            = &Received_Data_1;
	Rec1_DMA_List.XCount                = DMA_MSIZE_IN_BYTES;
	Rec1_DMA_List.XModify               = DMA_MSIZE_IN_BYTES;
	Rec1_DMA_List.Config                = ENUM_DMA_CFG_XCNT_INT;
	Rec1_DMA_List.pNxtDscp              = NULL;

	Rec2_DMA_List.pStartAddr            = &Received_Data_2;
	Rec2_DMA_List.XCount                = DMA_MSIZE_IN_BYTES;
	Rec2_DMA_List.XModify               = DMA_MSIZE_IN_BYTES;
	Rec2_DMA_List.Config                = ENUM_DMA_CFG_XCNT_INT;
	Rec2_DMA_List.pNxtDscp              = NULL;

}


void UART0_DMA_Write(void* pTxBuffer, uint32_t nTxSize)
{
	Trans0_DMA_List.pStartAddr            = pTxBuffer;
	Trans0_DMA_List.XCount                = nTxSize;
	Trans0_DMA_List.XModify               = DMA_MSIZE_IN_BYTES;
	//Trans0_DMA_List.Config                = ENUM_DMA_CFG_XCNT_INT;
	Trans0_DMA_List.pNxtDscp              = NULL;
	//wait for last transmission complete
	while(adi_uart_IsTxComplete(hUART_0) != ADI_UART_SUCCESS);
	adi_uart_DMAWrite(hUART_0,&Trans0_DMA_List,(1),ADI_PDMA_STOP_MODE);
}

void UART1_DMA_Write(void* pTxBuffer, uint32_t nTxSize)
{
	Trans1_DMA_List.pStartAddr            = pTxBuffer;
	Trans1_DMA_List.XCount                = nTxSize;
	Trans1_DMA_List.XModify               = DMA_MSIZE_IN_BYTES;
	//Trans0_DMA_List.Config                = ENUM_DMA_CFG_XCNT_INT;
	Trans1_DMA_List.pNxtDscp              = NULL;
	//wait for last transmission complete
	while(adi_uart_IsTxComplete(hUART_1) != ADI_UART_SUCCESS);
	adi_uart_DMAWrite(hUART_1,&Trans1_DMA_List,(1),ADI_PDMA_STOP_MODE);
}

void UART2_DMA_Write(void* pTxBuffer, uint32_t nTxSize)
{
	Trans2_DMA_List.pStartAddr            = pTxBuffer;
	Trans2_DMA_List.XCount                = nTxSize;
	Trans2_DMA_List.XModify               = DMA_MSIZE_IN_BYTES;
	//Trans0_DMA_List.Config                = ENUM_DMA_CFG_XCNT_INT;
	Trans2_DMA_List.pNxtDscp              = NULL;
	//wait for last transmission complete
	while(adi_uart_IsTxComplete(hUART_2) != ADI_UART_SUCCESS);
	adi_uart_DMAWrite(hUART_2,&Trans2_DMA_List,(1),ADI_PDMA_STOP_MODE);
}
