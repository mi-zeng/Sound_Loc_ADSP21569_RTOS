/*
 * SPU.h
 *
 *  Created on: 2023Äê8ÔÂ8ÈÕ
 *      Author: zengming
 */

#ifndef SPU_INIT_H_
#define SPU_INIT_H_
/*  Possible UART instances are ADI_UART_0,ADI_UART_1 and ADI_UART_2  */

#define SPORT_0A_SPU  			  (49)
#define SPORT_0B_SPU   			  (50)
#define SPORT_1A_SPU   			  (51)
#define SPORT_1B_SPU   			  (52)
#define SPORT_2A_SPU   			  (53)
#define SPORT_2B_SPU   			  (54)
#define SPORT_3A_SPU   			  (55)
#define SPORT_3B_SPU   			  (56)
#define SPORT_4A_SPU  			  (57)
#define SPORT_4B_SPU   			  (58)
#define SPORT_5A_SPU   			  (59)
#define SPORT_5B_SPU   			  (60)
#define SPORT_6A_SPU   			  (61)
#define SPORT_6B_SPU   			  (62)
#define SPORT_7A_SPU   			  (63)
#define SPORT_7B_SPU   			  (64)

#define UART0_SPU_PID             (29)
#define UART1_SPU_PID             (30)
#define UART2_SPU_PID             (31)

#define UART0_TxDMA_SPU_PID       (66)
#define UART0_RxDMA_SPU_PID       (65)

#define UART1_TxDMA_SPU_PID       (68)
#define UART1_RxDMA_SPU_PID       (67)

#define UART2_TxDMA_SPU_PID       (70)
#define UART2_RxDMA_SPU_PID       (69)


int SPU_init(void);

#endif /* SPU_INIT_H_ */
