/******************************************************************************
 * @file:    adi_spi_config_2156x.h
 * @brief:   SPI driver static configuration
 * @version: $Revision: 68342 $
 * @date:    $Date: 2022-09-20 06:27:14 -0400 (Tue, 20 Sep 2022) $
 *****************************************************************************

 Copyright (c) 2020-2021 Analog Devices.  All Rights Reserved.

 This software is proprietary.  By using this software you agree
 to the terms of the associated Analog Devices License Agreement.
 
*******************************************************************************/

/*
 * @file      adi_spi_config_2156x.h
 *
 * @brief     SPI driver static configuration
 *
 * @details   Header File which has the static configuration for SPI instances.
 *
 */

/** @addtogroup SPI_Driver SPI Device Driver
 *  @{
 */

/** @addtogroup SPI_Driver_Static_Configuration SPI Device Driver Static Configuration
 *  @{

  Static Configuration: Using this configuration application can configure the control register
  parameters upfront which can be set to default before SPI data transfer starts. This configuration
  has macros which can be configured through adi_spi_config_2156x.h file which by default is available
  with SPI driver. Example project can maintain a copy of it locally for custom configuration.

  Default Static Configuration for SPI(0/1/2):
  The default configuration for SPI using preload:
        SPI clock rate : 12.50 MHz
        SPI0 - Master, SPI1 - Slave, SPI2 - Master.
        Rest of the values are power on reset values.

  Specifies the SPI(X)_CLK register Divisor\n
    ADI_SPI(X)_CFG_CLK_BAUD                   (9ul)-----SPI Clock - 12.5 MHz\n

  Specifies the SPI(X)_Control register Configuration\n
    ADI_SPI(0)_CFG_SLAVE_MASTER               (0x1ul)---SPI 0 Master\n
    ADI_SPI(1)_CFG_SLAVE_MASTER               (0x0ul)---SPI 1 Slave\n
    ADI_SPI(2)_CFG_SLAVE_MASTER               (0x1ul)---SPI 2 Master\n
    ADI_SPI(X)_CFG_CLK_PHASE                  (0x1ul)---power on reset value\n
    ADI_SPI(X)_CFG_CLK_POLARITY               (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_HW_SLAVE_SELECT            (0x1ul)---power on reset value\n
    ADI_SPI(X)_CFG_TRANSFER_SIZE              (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_MSB_LSB                    (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_RXFIFO_REG_WATERMARK       (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_TXFIFO_REG_WATERMARK       (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_OPEN_DRAIN_MODE            (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_SLAVE_SELECT_POLARITY      (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_FLOW_CONTROL               (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_FLOW_CONTROL_WATERMARK     (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_FLOW_CONTROL_POLARITY      (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_FLOW_CONTROL_CHANNEL       (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_FASTMODE                   (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_MULTIPLE_I0_MODE           (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_START_ON_MOSI              (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_PROTECTED_SLV_SELECT_EN    (0x0ul)---power on reset value\n
    ADI_SPI(X)_CFG_ENABLE_MISO                (0x0ul)---power on reset value\n
*/

#ifndef __ADI_SPI_CONFIG_2156x_H__
#define __ADI_SPI_CONFIG_2156x_H__

#include <sys/platform.h>
#include <stdint.h>

/*! Number of SPI instances that are enabled */
#define ADI_SPI_CFG_INSTANCES                         3ul

/*! select/unselect SPI0 Instance */
#define ADI_SPI0_INSTANCE                             1ul

/*! select/unselect SPI1 Instance */
#define ADI_SPI1_INSTANCE                             1ul

/*! select/unselect SPI2 Instance */
#define ADI_SPI2_INSTANCE                             1ul

/**************************************************************************************************************/
/*! This configuration sets the baud rate for the SPI data transfers\n
    Baud can be calculated as BAUD = (SCLK0_0/SPI_Clock) - 1\n */
#define ADI_SPI0_CFG_CLK_BAUD                         9ul
/**************************************************************************************************************/

/**************************************************************************************************************/
/*! Master or Slave mode of operation\n
    SPI Control Register: Bit[1]\n
    (0) - Slave mode\n
    (1) - Master mode\n*/
#define ADI_SPI0_CFG_SLAVE_MASTER                     0x1ul

/*! Configures whether the SPI starts toggling the signal for the SPI clock\n
    from the start of the first data bit or from the middle of the first data bit\n
    SPI Control Register: Bit[4]\n
    (0) - Serial clock pulses at the end of each serial bit transfer\n
    (1) - Serial clock pulses at the beginning of each serial bit transfer\n*/
#define ADI_SPI0_CFG_CLK_PHASE                        0x1ul

/*! Configures whether the SPI uses an active-low or active-high signal for the SPI clock\n
    SPI Control Register: Bit[5]\n
    (0) - Active-high SPI Clock\n
    (1) - Active-low  SPI Clock\n*/
#define ADI_SPI0_CFG_CLK_POLARITY                     0x0ul

/*! Configures the SPI to control the assertion/de-assertion of the slave select signal\n
    SPI Control Register: Bit[6]\n
    (0) - Slave select controlled by software\n
    (1) - Slave select controlled by hardware\n*/
#define ADI_SPI0_CFG_HW_SLAVE_SELECT                  0x1ul

/*! SPI transfer size\n
    SPI Control Register: Bit[10:9]\n
    (0)  -  8  bit word\n
    (1)  -  16 bit word\n
    (2)  -  32 bit word\n*/
#define ADI_SPI0_CFG_TRANSFER_SIZE                    0x0ul

/*! SPI transmits/receives LSB or MSB First\n
    SPI Control Register: Bit[12]\n
    (0) - MSB transmitted first\n
    (1) - LSB transmitted first\n*/
#define ADI_SPI0_CFG_MSB_LSB                          0x0ul

/*! Configure SPI MOSI and MISO pins to behave as open drain outputs\n
    to prevent bus contention\n
    SPI Control Register: Bit[3]\n
    (0) -  Disable\n
    (1) -  Enable\n*/
#define ADI_SPI0_CFG_OPEN_DRAIN_MODE                  0x0ul

/*! Configures slave select polarity between transfers\n
    SPI Control Register: Bit[7]\n
    (0) - De-assert slave select (high)\n
    (1) - Assert slave select (low)\n*/
#define ADI_SPI0_CFG_SLAVE_SELECT_POLARITY            0x0ul

/*! Configures the flow control bit to communicate with slow devices\n
    SPI Control Register: Bit[13]\n
    (0) - Disable\n
    (1) - Enable\n*/
#define ADI_SPI0_CFG_FLOW_CONTROL                     0x0ul

/*! Configures the watermark for flow control\n
    SPI Control Register: Bits[17:16]\n
    (0) - TFIFO empty or RFIFO full\n
    (1) - TFIFO 75% or more empty, or RFIFO 75% or more full\n
    (2) - TFIFO 50% or more empty, or RFIFO 50% or more full\n*/
#define ADI_SPI0_CFG_FLOW_CONTROL_WATERMARK           0x0ul

/*! Configure the polarity of the ready pin\n
    SPI Control Register: Bit[15]\n
    (0) - Active low ready\n
    (1) - Active High ready\n*/
#define ADI_SPI0_CFG_FLOW_CONTROL_POLARITY            0x0ul

/*! Configures Flow control for Transmit or Receive channel\n
    SPI Control Register: Bit[14]\n
    (0) - Flow control on Rx channel\n
    (1) - Flow control on Tx channel\n*/
#define ADI_SPI0_CFG_FLOW_CONTROL_CHANNEL             0x0ul

/*! Enable/Disable fast mode\n
    SPI Control Register: Bit[18]\n
    (0) - Disable\n
    (1) - Enable\n*/
#define ADI_SPI0_CFG_FASTMODE                         0x0ul

/*! Configure in Default or Dual I/O or Quad I/O mode\n
    SPI Control Register: Bits[21:20]\n
    (0) - SPI with MOSI and MISO, single I/O mode\n
    (1) - Dual I/O mode\n
    (2) - Quad I/O mode.(Not applicable for SPI0)\n*/
#define ADI_SPI0_CFG_MULTIPLE_I0_MODE                 0x0ul
 
/*! configure start on MOSI\n
    SPI Control Register: Bit[22]\n
    (0) - Bit 0 on MOSI (for both DIOM and QIOM)\n
    (1) - Bit 0 on MISO(DIOM) or on D3(QIOM)\n*/
#define ADI_SPI0_CFG_START_ON_MOSI                    0x0ul

/*! Enables error detection in case of multi master\n
    environment when SPI is configured as master\n
    SPI Control Register: Bit[2]\n
    (0) - Disable\n
    (1) - Enable\n*/
#define ADI_SPI0_CFG_PROTECTED_SLV_SELECT_EN          0x0ul

/*! Enable SPI MISO mode. This mode is only applicable for SPI as a slave\n
    SPI Control Register: Bit[8]\n
    (0) - Disable\n
    (1) - Enable\n*/
#define ADI_SPI0_CFG_ENABLE_MISO                      0x0ul

/* Specifies the SPI0 Control register Configuration\n*/
#define ADI_SPI0_CTL                                  ((ADI_SPI0_CFG_SLAVE_MASTER << BITP_SPI_CTL_MSTR)|\
                                                       (ADI_SPI0_CFG_PROTECTED_SLV_SELECT_EN<<BITP_SPI_CTL_PSSE)|\
                                                       (ADI_SPI0_CFG_OPEN_DRAIN_MODE<<BITP_SPI_CTL_ODM)|\
                                                       (ADI_SPI0_CFG_CLK_PHASE<<BITP_SPI_CTL_CPHA)|\
                                                       (ADI_SPI0_CFG_CLK_POLARITY<<BITP_SPI_CTL_CPOL)|\
                                                       (ADI_SPI0_CFG_HW_SLAVE_SELECT<<BITP_SPI_CTL_ASSEL)|\
                                                       (ADI_SPI0_CFG_SLAVE_SELECT_POLARITY<<BITP_SPI_CTL_SELST)|\
                                                       (ADI_SPI0_CFG_ENABLE_MISO<<BITP_SPI_CTL_EMISO)|\
                                                       (ADI_SPI0_CFG_TRANSFER_SIZE<<BITP_SPI_CTL_SIZE)|\
                                                       (ADI_SPI0_CFG_MSB_LSB<<BITP_SPI_CTL_LSBF)|\
                                                       (ADI_SPI0_CFG_FLOW_CONTROL<<BITP_SPI_CTL_FCEN)|\
                                                       (ADI_SPI0_CFG_FLOW_CONTROL_CHANNEL<<BITP_SPI_CTL_FCCH)|\
                                                       (ADI_SPI0_CFG_FLOW_CONTROL_POLARITY<<BITP_SPI_CTL_FCPL)|\
                                                       (ADI_SPI0_CFG_FLOW_CONTROL_WATERMARK<<BITP_SPI_CTL_FCWM)|\
                                                       (ADI_SPI0_CFG_FASTMODE<<BITP_SPI_CTL_FMODE)|\
                                                       (ADI_SPI0_CFG_MULTIPLE_I0_MODE<<BITP_SPI_CTL_MIOM)|\
                                                       (ADI_SPI0_CFG_START_ON_MOSI<<BITP_SPI_CTL_SOSI))
/**************************************************************************************************************/

/**************************************************************************************************************/
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 1\n
    (1) - enables the slave select 1\n*/
#define ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_1            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 2\n
    (1) - enables the slave select 2\n*/
#define ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_2            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 3\n
    (1) - enables the slave select 3\n*/
#define ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_3            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 4\n
    (1) - enables the slave select 4\n*/
#define ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_4            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 5\n
    (1) - enables the slave select 5\n*/
#define ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_5            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 6\n
    (1) - enables the slave select 6\n*/
#define ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_6            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 7\n
    (1) - enables the slave select 7\n*/
#define ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_7            0x0ul

/* Specifies the SPI0 Slave select Control register Configuration\n*/
#define ADI_SPI0_CTL_SLAVE_SELECT_ENABLE              ((ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_7<<BITP_SPI_SLVSEL_SSE7)|\
                                                       (ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_6<<BITP_SPI_SLVSEL_SSE6)|\
                                                       (ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_5<<BITP_SPI_SLVSEL_SSE5)|\
                                                       (ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_4<<BITP_SPI_SLVSEL_SSE4)|\
                                                       (ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_3<<BITP_SPI_SLVSEL_SSE3)|\
                                                       (ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_2<<BITP_SPI_SLVSEL_SSE2)|\
                                                       (ADI_SPI0_CTL_SLAVE_SELECT_ENABLE_1<<BITP_SPI_SLVSEL_SSE1))
/*****************************************************************************************************************/

/**************************************************************************************************************/
/*! This configuration sets the baud rate for the SPI data transfers\n
    Baud can be calculated as BAUD = (SCLK0_0/SPI_Clock) - 1\n */
#define ADI_SPI1_CFG_CLK_BAUD                         9ul
/**************************************************************************************************************/

/**************************************************************************************************************/
/*! Master or Slave mode of operation\n
    SPI Control Register: Bit[1]\n
    (0) - Slave mode\n
    (1) - Master mode\n*/
#define ADI_SPI1_CFG_SLAVE_MASTER                     0x0ul

/*! Configures whether the SPI starts toggling the signal for the SPI clock\n
    from the start of the first data bit or from the middle of the first data bit\n
    SPI Control Register: Bit[4]\n
    (0) - Serial clock pulses at the end of each serial bit transfer\n
    (1) - Serial clock pulses at the beginning of each serial bit transfer\n*/
#define ADI_SPI1_CFG_CLK_PHASE                        0x1ul

/*! Configures whether the SPI uses an active-low or active-high signal for the SPI clock\n
    SPI Control Register: Bit[5]\n
    (0) - Active-high SPI Clock\n
    (1) - Active-low  SPI Clock\n*/
#define ADI_SPI1_CFG_CLK_POLARITY                     0x0ul

/*! Configures the SPI to control the assertion/de-assertion of the slave select signal\n
    SPI Control Register: Bit[6]\n
    (0) - Slave select controlled by software\n
    (1) - Slave select controlled by hardware\n*/
#define ADI_SPI1_CFG_HW_SLAVE_SELECT                  0x1ul

/*! SPI transfer size\n
    SPI Control Register: Bit[10:9]\n
    (0)  -  8  bit word\n
    (1)  -  16 bit word\n
    (2)  -  32 bit word\n*/
#define ADI_SPI1_CFG_TRANSFER_SIZE                    0x0ul

/*! SPI transmits/receives LSB or MSB First\n
    SPI Control Register: Bit[12]\n
    (0) - MSB transmitted first\n
    (1) - LSB transmitted first\n*/
#define ADI_SPI1_CFG_MSB_LSB                          0x0ul

/*! Configure SPI MOSI and MISO pins to behave as open drain outputs\n
    to prevent bus contention\n
    SPI Control Register: Bit[3]\n
    (0) -  Disable\n
    (1) -  Enable\n*/
#define ADI_SPI1_CFG_OPEN_DRAIN_MODE                  0x0ul

/*! Configures slave select polarity between transfers\n
    SPI Control Register: Bit[7]\n
    (0) - De-assert slave select (high)\n
    (1) - Assert slave select (low)\n*/
#define ADI_SPI1_CFG_SLAVE_SELECT_POLARITY            0x0ul

/*! Configures the flow control bit to communicate with slow devices\n
    SPI Control Register: Bit[13]\n
    (0) - Disable\n
    (1) - Enable\n*/
#define ADI_SPI1_CFG_FLOW_CONTROL                     0x0ul

/*! Configures the watermark for flow control\n
    SPI Control Register: Bits[17:16]\n
    (0) - TFIFO empty or RFIFO full\n
    (1) - TFIFO 75% or more empty, or RFIFO 75% or more full\n
    (2) - TFIFO 50% or more empty, or RFIFO 50% or more full\n*/
#define ADI_SPI1_CFG_FLOW_CONTROL_WATERMARK           0x0ul

/*! Configure the polarity of the ready pin\n
    SPI Control Register: Bit[15]\n
    (0) - Active low ready\n
    (1) - Active High ready\n*/
#define ADI_SPI1_CFG_FLOW_CONTROL_POLARITY            0x0ul

/*! Configures Flow control for Transmit or Receive channel\n
    SPI Control Register: Bit[14]\n
    (0) - Flow control on Rx channel\n
    (1) - Flow control on Tx channel\n*/
#define ADI_SPI1_CFG_FLOW_CONTROL_CHANNEL             0x0ul

/*! Enable/Disable fast mode\n
    SPI Control Register: Bit[18]\n
    (0) - Disable\n
    (1) - Enable\n*/
#define ADI_SPI1_CFG_FASTMODE                         0x0ul

/*! Configure in Default or Dual I/O or Quad I/O mode\n
    SPI Control Register: Bits[21:20]\n
    (0) - SPI with MOSI and MISO, single I/O mode\n
    (1) - Dual I/O mode\n
    (2) - Quad I/O mode.(Not applicable for SPI0)\n*/
#define ADI_SPI1_CFG_MULTIPLE_I0_MODE                 0x0ul
 
/*! configure start on MOSI\n
    SPI Control Register: Bit[22]\n
    (0) - Bit 0 on MOSI (for both DIOM and QIOM)\n
    (1) - Bit 0 on MISO(DIOM) or on D3(QIOM)\n*/
#define ADI_SPI1_CFG_START_ON_MOSI                    0x0ul

/*! Enables error detection in case of multi master\n
    environment when SPI is configured as master\n
    SPI Control Register: Bit[2]\n
    (0) - Disable\n
    (1) - Enable\n*/
#define ADI_SPI1_CFG_PROTECTED_SLV_SELECT_EN          0x0ul

/*! Enable SPI MISO mode. This mode is only applicable for SPI as a slave\n
    SPI Control Register: Bit[8]\n
    (0) - Disable\n
    (1) - Enable\n*/
#define ADI_SPI1_CFG_ENABLE_MISO                      0x0ul

/* Specifies the SPI1 Control register Configuration\n*/
#define ADI_SPI1_CTL                                  ((ADI_SPI1_CFG_SLAVE_MASTER << BITP_SPI_CTL_MSTR)|\
                                                       (ADI_SPI1_CFG_PROTECTED_SLV_SELECT_EN<<BITP_SPI_CTL_PSSE)|\
                                                       (ADI_SPI1_CFG_OPEN_DRAIN_MODE<<BITP_SPI_CTL_ODM)|\
                                                       (ADI_SPI1_CFG_CLK_PHASE<<BITP_SPI_CTL_CPHA)|\
                                                       (ADI_SPI1_CFG_CLK_POLARITY<<BITP_SPI_CTL_CPOL)|\
                                                       (ADI_SPI1_CFG_HW_SLAVE_SELECT<<BITP_SPI_CTL_ASSEL)|\
                                                       (ADI_SPI1_CFG_SLAVE_SELECT_POLARITY<<BITP_SPI_CTL_SELST)|\
                                                       (ADI_SPI1_CFG_ENABLE_MISO<<BITP_SPI_CTL_EMISO)|\
                                                       (ADI_SPI1_CFG_TRANSFER_SIZE<<BITP_SPI_CTL_SIZE)|\
                                                       (ADI_SPI1_CFG_MSB_LSB<<BITP_SPI_CTL_LSBF)|\
                                                       (ADI_SPI1_CFG_FLOW_CONTROL<<BITP_SPI_CTL_FCEN)|\
                                                       (ADI_SPI1_CFG_FLOW_CONTROL_CHANNEL<<BITP_SPI_CTL_FCCH)|\
                                                       (ADI_SPI1_CFG_FLOW_CONTROL_POLARITY<<BITP_SPI_CTL_FCPL)|\
                                                       (ADI_SPI1_CFG_FLOW_CONTROL_WATERMARK<<BITP_SPI_CTL_FCWM)|\
                                                       (ADI_SPI1_CFG_FASTMODE<<BITP_SPI_CTL_FMODE)|\
                                                       (ADI_SPI1_CFG_MULTIPLE_I0_MODE<<BITP_SPI_CTL_MIOM)|\
                                                       (ADI_SPI1_CFG_START_ON_MOSI<<BITP_SPI_CTL_SOSI))
/**************************************************************************************************************/

/**************************************************************************************************************/
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 1\n
    (1) - enables the slave select 1\n*/
#define ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_1            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 2\n
    (1) - enables the slave select 2\n*/
#define ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_2            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 3\n
    (1) - enables the slave select 3\n*/
#define ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_3            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 4\n
    (1) - enables the slave select 4\n*/
#define ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_4            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 5\n
    (1) - enables the slave select 5\n*/
#define ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_5            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 6\n
    (1) - enables the slave select 6\n*/
#define ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_6            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 7\n
    (1) - enables the slave select 7\n*/
#define ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_7            0x0ul

/* Specifies the SPI1 Slave select Control register Configuration\n*/
#define ADI_SPI1_CTL_SLAVE_SELECT_ENABLE              ((ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_7<<BITP_SPI_SLVSEL_SSE7)|\
                                                       (ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_6<<BITP_SPI_SLVSEL_SSE6)|\
                                                       (ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_5<<BITP_SPI_SLVSEL_SSE5)|\
                                                       (ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_4<<BITP_SPI_SLVSEL_SSE4)|\
                                                       (ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_3<<BITP_SPI_SLVSEL_SSE3)|\
                                                       (ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_2<<BITP_SPI_SLVSEL_SSE2)|\
                                                       (ADI_SPI1_CTL_SLAVE_SELECT_ENABLE_1<<BITP_SPI_SLVSEL_SSE1))
/*****************************************************************************************************************/

/**************************************************************************************************************/
/*! This configuration sets the baud rate for the SPI data transfers\n
    Baud can be calculated as BAUD = (SCLK0_0/SPI_Clock) - 1\n */
#define ADI_SPI2_CFG_CLK_BAUD                         9ul
/**************************************************************************************************************/

/**************************************************************************************************************/
/*! Master or Slave mode of operation\n
    SPI Control Register: Bit[1]\n
    (0) - Slave mode\n
    (1) - Master mode\n*/
#define ADI_SPI2_CFG_SLAVE_MASTER                     0x1ul

/*! Configures whether the SPI starts toggling the signal for the SPI clock\n
    from the start of the first data bit or from the middle of the first data bit\n
    SPI Control Register: Bit[4]\n
    (0) - Serial clock pulses at the end of each serial bit transfer\n
    (1) - Serial clock pulses at the beginning of each serial bit transfer\n*/
#define ADI_SPI2_CFG_CLK_PHASE                        0x1ul

/*! Configures whether the SPI uses an active-low or active-high signal for the SPI clock\n
    SPI Control Register: Bit[5]\n
    (0) - Active-high SPI Clock\n
    (1) - Active-low  SPI Clock\n*/
#define ADI_SPI2_CFG_CLK_POLARITY                     0x0ul

/*! Configures the SPI to control the assertion/de-assertion of the slave select signal\n
    SPI Control Register: Bit[6]\n
    (0) - Slave select controlled by software\n
    (1) - Slave select controlled by hardware\n*/
#define ADI_SPI2_CFG_HW_SLAVE_SELECT                  0x1ul

/*! SPI transfer size\n
    SPI Control Register: Bit[10:9]\n
    (0)  -  8  bit word\n
    (1)  -  16 bit word\n
    (2)  -  32 bit word\n*/
#define ADI_SPI2_CFG_TRANSFER_SIZE                    0x0ul

/*! SPI transmits/receives LSB or MSB First\n
    SPI Control Register: Bit[12]\n
    (0) - MSB transmitted first\n
    (1) - LSB transmitted first\n*/
#define ADI_SPI2_CFG_MSB_LSB                          0x0ul

/*! Configure SPI MOSI and MISO pins to behave as open drain outputs\n
    to prevent bus contention\n
    SPI Control Register: Bit[3]\n
    (0) -  Disable\n
    (1) -  Enable\n*/
#define ADI_SPI2_CFG_OPEN_DRAIN_MODE                  0x0ul

/*! Configures slave select polarity between transfers\n
    SPI Control Register: Bit[7]\n
    (0) - De-assert slave select (high)\n
    (1) - Assert slave select (low)\n*/
#define ADI_SPI2_CFG_SLAVE_SELECT_POLARITY            0x0ul

/*! Configures the flow control bit to communicate with slow devices\n
    SPI Control Register: Bit[13]\n
    (0) - Disable\n
    (1) - Enable\n*/
#define ADI_SPI2_CFG_FLOW_CONTROL                     0x0ul

/*! Configures the watermark for flow control\n
    SPI Control Register: Bits[17:16]\n
    (0) - TFIFO empty or RFIFO full\n
    (1) - TFIFO 75% or more empty, or RFIFO 75% or more full\n
    (2) - TFIFO 50% or more empty, or RFIFO 50% or more full\n*/
#define ADI_SPI2_CFG_FLOW_CONTROL_WATERMARK           0x0ul

/*! Configure the polarity of the ready pin\n
    SPI Control Register: Bit[15]\n
    (0) - Active low ready\n
    (1) - Active High ready\n*/
#define ADI_SPI2_CFG_FLOW_CONTROL_POLARITY            0x0ul

/*! Configures Flow control for Transmit or Receive channel\n
    SPI Control Register: Bit[14]\n
    (0) - Flow control on Rx channel\n
    (1) - Flow control on Tx channel\n*/
#define ADI_SPI2_CFG_FLOW_CONTROL_CHANNEL             0x0ul

/*! Enable/Disable fast mode\n
    SPI Control Register: Bit[18]\n
    (0) - Disable\n
    (1) - Enable\n*/
#define ADI_SPI2_CFG_FASTMODE                         0x0ul

/*! Configure in Default or Dual I/O or Quad I/O mode\n
    SPI Control Register: Bits[21:20]\n
    (0) - SPI with MOSI and MISO, single I/O mode\n
    (1) - Dual I/O mode\n
    (2) - Quad I/O mode.(Not applicable for SPI0)\n*/
#define ADI_SPI2_CFG_MULTIPLE_I0_MODE                 0x0ul
 
/*! configure start on MOSI\n
    SPI Control Register: Bit[22]\n
    (0) - Bit 0 on MOSI (for both DIOM and QIOM)\n
    (1) - Bit 0 on MISO(DIOM) or on D3(QIOM)\n*/
#define ADI_SPI2_CFG_START_ON_MOSI                    0x0ul

/*! Enables error detection in case of multi master\n
    environment when SPI is configured as master\n
    SPI Control Register: Bit[2]\n
    (0) - Disable\n
    (1) - Enable\n*/
#define ADI_SPI2_CFG_PROTECTED_SLV_SELECT_EN          0x0ul

/*! Enable SPI MISO mode. This mode is only applicable for SPI as a slave\n
    SPI Control Register: Bit[8]\n
    (0) - Disable\n
    (1) - Enable\n*/
#define ADI_SPI2_CFG_ENABLE_MISO                      0x0ul

/* Specifies the SPI2 Control register Configuration\n*/
#define ADI_SPI2_CTL                                  ((ADI_SPI2_CFG_SLAVE_MASTER << BITP_SPI_CTL_MSTR)|\
                                                       (ADI_SPI2_CFG_PROTECTED_SLV_SELECT_EN<<BITP_SPI_CTL_PSSE)|\
                                                       (ADI_SPI2_CFG_OPEN_DRAIN_MODE<<BITP_SPI_CTL_ODM)|\
                                                       (ADI_SPI2_CFG_CLK_PHASE<<BITP_SPI_CTL_CPHA)|\
                                                       (ADI_SPI2_CFG_CLK_POLARITY<<BITP_SPI_CTL_CPOL)|\
                                                       (ADI_SPI2_CFG_HW_SLAVE_SELECT<<BITP_SPI_CTL_ASSEL)|\
                                                       (ADI_SPI2_CFG_SLAVE_SELECT_POLARITY<<BITP_SPI_CTL_SELST)|\
                                                       (ADI_SPI2_CFG_ENABLE_MISO<<BITP_SPI_CTL_EMISO)|\
                                                       (ADI_SPI2_CFG_TRANSFER_SIZE<<BITP_SPI_CTL_SIZE)|\
                                                       (ADI_SPI2_CFG_MSB_LSB<<BITP_SPI_CTL_LSBF)|\
                                                       (ADI_SPI2_CFG_FLOW_CONTROL<<BITP_SPI_CTL_FCEN)|\
                                                       (ADI_SPI2_CFG_FLOW_CONTROL_CHANNEL<<BITP_SPI_CTL_FCCH)|\
                                                       (ADI_SPI2_CFG_FLOW_CONTROL_POLARITY<<BITP_SPI_CTL_FCPL)|\
                                                       (ADI_SPI2_CFG_FLOW_CONTROL_WATERMARK<<BITP_SPI_CTL_FCWM)|\
                                                       (ADI_SPI2_CFG_FASTMODE<<BITP_SPI_CTL_FMODE)|\
                                                       (ADI_SPI2_CFG_MULTIPLE_I0_MODE<<BITP_SPI_CTL_MIOM)|\
                                                       (ADI_SPI2_CFG_START_ON_MOSI<<BITP_SPI_CTL_SOSI))
/**************************************************************************************************************/

/**************************************************************************************************************/
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 1\n
    (1) - enables the slave select 1\n*/
#define ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_1            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 2\n
    (1) - enables the slave select 2\n*/
#define ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_2            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 3\n
    (1) - enables the slave select 3\n*/
#define ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_3            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 4\n
    (1) - enables the slave select 4\n*/
#define ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_4            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 5\n
    (1) - enables the slave select 5\n*/
#define ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_5            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 6\n
    (1) - enables the slave select 6\n*/
#define ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_6            0x0ul
/*! SPI Slave select register \n
    This allows a slave select to be enabled/disabled\n
    (0) - disables the slave select 7\n
    (1) - enables the slave select 7\n*/
#define ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_7            0x0ul

/* Specifies the SPI2 Slave select Control register Configuration\n*/
#define ADI_SPI2_CTL_SLAVE_SELECT_ENABLE              ((ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_7<<BITP_SPI_SLVSEL_SSE7)|\
                                                       (ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_6<<BITP_SPI_SLVSEL_SSE6)|\
                                                       (ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_5<<BITP_SPI_SLVSEL_SSE5)|\
                                                       (ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_4<<BITP_SPI_SLVSEL_SSE4)|\
                                                       (ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_3<<BITP_SPI_SLVSEL_SSE3)|\
                                                       (ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_2<<BITP_SPI_SLVSEL_SSE2)|\
                                                       (ADI_SPI2_CTL_SLAVE_SELECT_ENABLE_1<<BITP_SPI_SLVSEL_SSE1))
/*****************************************************************************************************************/

#endif /* __ADI_SPI_CONFIG_2156x_H__ */

/*@}*/

/*@}*/
