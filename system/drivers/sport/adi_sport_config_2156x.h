/******************************************************************************

Copyright (c) 2010-2018 Analog Devices.  All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.
*******************************************************************************/

/*!
* @file      adi_sport_config_2156x.h
*
* @brief     SPORT driver static configuration Header file
*
* @details
*            SPORT driver static configuration Header file
*/

/** @addtogroup SPORT_Driver SPORT Device Driver
 *  @{
 */

#include <sys/platform.h>
#include <stdint.h>

/*! Specifies the number of active SPORT devices accordingly the memory allotted will be optimized */
#define ADI_SPORT_STATIC_INSTANCES             1ul

/**********************************************************************************************
 *					       SPORT 0A
 **********************************************************************************************/
/*!SPORT0A Instance*/
#define ADI_SPORT0A_INSTANCE                   1ul

/*! Enables the half SPORT to perform 16- to 32-bit packing on received data 
 * 	and to perform 32- to 16-bit unpacking on transmitted data. 
 * 	Configured as : 
 * 			0 : Disable
 * 			1 : Enable				*/
#define ADI_SPORT0A_CTL_PACK                  0ul
/*! Selects the transfer direction (receive or transmit)for the half SPORT's primary and secondary channels.
 * Configured as :
 *  0 : Receive
 *  1 : Transmit */
#define ADI_SPORT0A_CTL_SPTRAN                1ul
/*! Selects whether the half SPORT operates in DSP standard/multichannel mode or operates in I2S/packed/left-justified mode.
 * Configured as :
 * 			0 :	DSP Serial/Multi-channel(TDM) mode
 * 			1 :	I2S/packed/left-justified/Right Justified mode   */
#define ADI_SPORT0A_CTL_OPMODE				   1ul
/*! Selects word length in bits for the Half-SPORT's data transfers. */
#define ADI_SPORT0A_CTL_SLEN                  24ul

/*! DMA MSIZE and PSIZE will be selected/generated on the the basis of word length(slen).
 * 	The MSIZE and PSIZE is selected as follows:
 *     	for (wordlength <= 7 bits)    -----> MSIZE = 1 Byte , PSIZE = 1 Byte.
 *  	for (wordlength <= 15 bits)   -----> MSIZE = 2 Bytes , PSIZE = 2 Bytes.
 *  	for (wordlength <= 15 bits) and (DMA packing is enabled) -----> MSIZE = 4 Bytes , PSIZE = 4 Bytes.
 *  	for (wordlength <= 31 bits)   -----> MSIZE = 4 Bytes , PSIZE = 4 Bytes.
 * */
#define ADI_SPORT0A_DMA_MSIZE  		 		ENUM_DMA_CFG_MSIZE04 /* 4  bytes transfer (32  bits) */
#define ADI_SPORT0A_DMA_PSIZE 		 		ENUM_DMA_CFG_PSIZE04 /* 4  bytes transfer (32  bits) */

/*! Selects whether the Half-SPORT uses an internal or external clock.
 * Configured as : 
 * 			0 : External clock
 * 			1 : Internal clock*/
/*! Selects the rising or falling edge of the SPORT_CLK for the Half-SPORT to sample received data and frame sync.*/
#define ADI_SPORT0A_CTL_ICLK                   0ul
/*! Selects the rising or falling edge of the SPORT_CLK for the Half-SPORT to sample received data and frame sync.*/
/* Configured as:
 * 			0 : Clock falling edge
 * 			1 : Clock rising edge*/ 
#define ADI_SPORT0A_CTL_CKRE                   0ul
/*! Enables gated clock operation for the Half-SPORT.
 *  Configurable for DSP serial mode or left-justified stereo modes.
 *  This bit is ignored when the half SPORT is in right-justified mode or multichannel mode
 *  Configured as : 
 * 			0 : Disable
 * 			1 : Enable*/
#define ADI_SPORT0A_CTL_GCLKEN                 0ul
/*! Selects whether the Half-SPORT uses an internal frame sync or uses an external frame sync. 
 * Configured as :
 * 		0 : External frame sync
 * 		1 : Internal frame sync*/  
 #define ADI_SPORT0A_CTL_IFS                    0ul
/*! Selects whether the Half-SPORT uses a data-independent or data-dependent frame sync.
 * Configurable for DSP Serial/I2S/Left Justified/Right justified mode. 
 * Configured as :
 * 		0 : Data-dependent frame sync
 * 		1 : Data-independent frame sync*/ 
#define ADI_SPORT0A_CTL_DIFS                   1ul   

/*! When the Half-SPORT is in DSP standard mode and multichannel mode,
* the LFS bit selects whether the Half SPORT uses active low or active high frame sync. 
* When the half SPORT is in I2S / packed / left-justified mode, 
* the LFS bit acts as L_FIRST, selecting whether the half SPORT transfers data first for the left or right channel. 
* Configured as :
* 		0 : Active high frame sync (DSP standard mode) or rising
* 			edge frame sync (multichannel mode)
* 			or right channel first (I2S/packed mode)
* 			or left channel first (left-justified mode)
* 		1 : Active low frame sync (DSP standard mode) or falling
* 			edge frame sync (multichannel mode)
* 			or left channel first (I2S/packed mode)
* 			or right channel first (left-justified mode)*/  
#define ADI_SPORT0A_CTL_LFS                    1ul
/*! When the Half-SPORT is in DSP standard mode  or in right-justified mode,
* the LAFS bit selects whether the half SPORT generates a late frame sync or generates an early frame sync signal.
* When the Half-SPORT is in I2S / left-justified mode, the LAFS bit acts as OPMODE2, 
* selecting whether the Half-SPORT is in left-justified mode or I2S mode.
* When the Half-SPORT is in multichannel mode, the LAFS bit is reserved. 
* Configured as:
* 		0 : Early frame sync (or I2S mode)
* 		1 : Late frame sync (or left-justified mode)*/   
#define ADI_SPORT0A_CTL_LAFS                   0ul

/*! Specifies the SPORT0A_Control register Configuration*/
#define ADI_SPORT_0A_CTL   ((ADI_SPORT0A_CTL_SLEN<<BITP_SPORT_CTL_A_SLEN)|(ADI_SPORT0A_CTL_PACK<<BITP_SPORT_CTL_A_PACK)|(ADI_SPORT0A_CTL_ICLK<<BITP_SPORT_CTL_A_ICLK)|(ADI_SPORT0A_CTL_CKRE<<BITP_SPORT_CTL_A_CKRE)|(ADI_SPORT0A_CTL_IFS<<BITP_SPORT_CTL_A_IFS)|(ADI_SPORT0A_CTL_DIFS<<BITP_SPORT_CTL_A_DIFS)|(ADI_SPORT0A_CTL_LFS<<BITP_SPORT_CTL_A_LFS)|(ADI_SPORT0A_CTL_LAFS<<BITP_SPORT_CTL_A_LAFS)|(ADI_SPORT0A_CTL_GCLKEN<<BITP_SPORT_CTL_A_GCLKEN)|(ADI_SPORT0A_CTL_SPTRAN<<BITP_SPORT_CTL_A_SPTRAN)|(ADI_SPORT0A_CTL_OPMODE<<BITP_SPORT_CTL_A_OPMODE))


/*! Select the clock divisor that the Half-SPORT uses to calculate the sport clock from the processor system clock. 
* CLKDIV = ( SCLK / SPORT_ACLK) - 1 */
#define ADI_SPORT0A_DIV_CLKDIV                0ul      
/*! Select the number of transmit or receive clock cycles that the Half-SPORT counts before generating a frame sync pulse. 
* FSDIV = (SPORT_ACLK / SPORT_AFS) - 1 */
#define ADI_SPORT0A_DIV_FSDIV                 31ul          

/*! Specifies the SPORT0A_Divisor register Configuration*/
#define ADI_SPORT_0A_DIV  ((ADI_SPORT0A_DIV_CLKDIV<<BITP_SPORT_DIV_A_CLKDIV)|(ADI_SPORT0A_DIV_FSDIV<<BITP_SPORT_DIV_A_FSDIV))

/*! Multi-Channel (TDM) Mode : Selects the start location for the Half-SPORT's active window of channels within the 1024-channel range.
 *  For Right Justified Mode : The least significant 6 bits of WOFFSET serve as the delay count (DCNT) field*/
#define ADI_SPORT0A_MCTL_WOFFSET 				 0ul
/*! Selects the window size for the Half-SPORT's active window of channels.
* WSIZE = (number of channel slots) -1 */ 
#define ADI_SPORT0A_MCTL_WSIZE 				     0ul
/*! Selects the delay (in serial clock cycles) between the Half-SPORT's multichannel frame sync pulse and channel 0 */
#define ADI_SPORT0A_MCTL_MFD					 0ul
/*! Enables DMA data packing for transmit and enables DMA data unpacking for the Half-SPORT's multichannel data transfers. 
 * Configured as:
 * 		0 : Disable
 * 		1 : Enable*/
#define ADI_SPORT0A_MCTL_MCPDE 				     0ul
/*! Enables multichannel operations for the Half-SPORT. 
 *  * Configured as:
 * 		0 : Disable
 * 		1 : Enable*/
#define ADI_SPORT0A_MCTL_MCE 					 0ul

/*! Specifies the SPORT0A_Multichannel Control register Configuration*/
#define ADI_SPORT_0A_MCTL  ((ADI_SPORT0A_MCTL_MCE<<BITP_SPORT_MCTL_A_MCE)|(ADI_SPORT0A_MCTL_MCPDE<<BITP_SPORT_MCTL_A_MCPDE)|(ADI_SPORT0A_MCTL_MFD<<BITP_SPORT_MCTL_A_MFD)|(ADI_SPORT0A_MCTL_WSIZE<<BITP_SPORT_MCTL_A_WSIZE)|(ADI_SPORT0A_MCTL_WOFFSET<<BITP_SPORT_MCTL_A_WOFFSET))

/*! Specifies the SPORT0A_Multichannel Control register Configuration*/
#define ADI_SPORT_0A_CS0                         0x0
#define ADI_SPORT_0A_CS1						 0x0
#define ADI_SPORT_0A_CS2		        		 0x0
#define ADI_SPORT_0A_CS3						 0x0


/**********************************************************************************************
 *						       SPORT 0B
 **********************************************************************************************/
/*!SPORT0B Instance*/
#define ADI_SPORT0B_INSTANCE                   0ul


/**********************************************************************************************
 *						      SPORT 1A
 **********************************************************************************************/
/*!SPORT1A Instance*/
#define ADI_SPORT1A_INSTANCE                   0ul


/**********************************************************************************************
 *						       SPORT 1B
 **********************************************************************************************/
/*!SPORT1B Instance*/
#define ADI_SPORT1B_INSTANCE                   0ul


/**********************************************************************************************
 *						       SPORT 2A
 **********************************************************************************************/

/*!SPORT2A Instance*/
#define ADI_SPORT2A_INSTANCE                   0ul


/**********************************************************************************************
 *						       SPORT 2B
 **********************************************************************************************/
/*!SPORT2B Instance*/
#define ADI_SPORT2B_INSTANCE                   0ul



/**********************************************************************************************
 *						       SPORT 3A
 **********************************************************************************************/
/*!SPORT3A Instance*/
#define ADI_SPORT3A_INSTANCE                   0ul


/**********************************************************************************************
 *						      SPORT 3B
 **********************************************************************************************/
/*!SPORT3B Instance*/
#define ADI_SPORT3B_INSTANCE                   0ul


/**********************************************************************************************
 *						       SPORT 4A
 **********************************************************************************************/
/*!SPORT4A Instance*/
#define ADI_SPORT4A_INSTANCE                   0ul


/**********************************************************************************************
 *						      SPORT 4B
 **********************************************************************************************/
/*!SPORT4B Instance*/
#define ADI_SPORT4B_INSTANCE                   0ul

/**********************************************************************************************
 *						      SPORT 5A
 **********************************************************************************************/
/*!SPORT5A Instance*/
#define ADI_SPORT5A_INSTANCE                   0ul


/**********************************************************************************************
 *						          SPORT 5B
 **********************************************************************************************/
/*!SPORT5B Instance*/
#define ADI_SPORT5B_INSTANCE                   0ul

/**********************************************************************************************
 *						       SPORT 6A
 **********************************************************************************************/
/*!SPORT6A Instance*/
#define ADI_SPORT6A_INSTANCE                   0ul


/**********************************************************************************************
 *						        SPORT 6B
 **********************************************************************************************/
/*!SPORT6B Instance*/
#define ADI_SPORT6B_INSTANCE                   0ul


/**********************************************************************************************
 *						         SPORT 7A
 **********************************************************************************************/
/*!SPORT7A Instance*/
#define ADI_SPORT7A_INSTANCE                   0ul


/**********************************************************************************************
 *						        SPORT 7B
 **********************************************************************************************/
/*!SPORT7B Instance*/
#define ADI_SPORT7B_INSTANCE                   0ul





/** @}*/

