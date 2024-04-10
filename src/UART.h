/*
 * UART.h
 *
 *  Created on: 2023Äê7ÔÂ31ÈÕ
 *      Author: zengming
 */

#ifndef UART_H_
#define UART_H_

#include <drivers/uart/adi_uart.h>

/*  Possible UART instances are ADI_UART_0,ADI_UART_1 and ADI_UART_2  */
// UART0 is used in dev-kit

#define BUFF_SIZE 8u



#define REPORT_ERROR        	 printf
#define DEBUG_INFORMATION        printf

#define DMA_MSIZE_IN_BYTES      1u

int UART0_init(void);
void UART0_corewrite(void* pTxBuffer, uint32_t nTxSize);
inline void List_init(void);
void UART0Callback(void *pCBParam, uint32_t Event, void *pArg);
static void CheckResult(ADI_UART_RESULT Result);


#endif /* UART_H_ */
