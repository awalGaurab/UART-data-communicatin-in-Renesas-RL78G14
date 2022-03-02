/*****************************************************************************
 DISCLAIMER
 This software is supplied by Renesas Electronics Corporation and is only
 intended for use with Renesas products. No other uses are authorized. This
 software is owned by Renesas Electronics Corporation and is protected under
 all applicable laws, including copyright laws.
 THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
 LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
 TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
 ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
 FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
 ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
 BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 Renesas reserves the right, without notice, to make changes to this software
 and to discontinue the availability of this software. By using this software,
 you agree to the additional terms and conditions found by accessing the
 following link:
 http://www.renesas.com/disclaimer
 Copyright (C) 2016-2018 Renesas Electronics Corporation. All rights reserved.
******************************************************************************/

/*-------------------------------------------------------------------------*
 * File:  YRDKRL78_RSPI0.h
 *-------------------------------------------------------------------------*
 * Description:
 *    Y Renesas Development Kit (RDK) for Renesas RL78 Group CPU
 * RSPI Transmitter 0 Operation channel 3.  Routines for RSPI code running
 * on RL78 CPU, RSPI0.  This program uses RSPI0.  The Chip Select for the
 * flash device (LCD) is set to PC_2.  This is the RSPI channel used to
 * communicate with the ST7579 Graphics Display.
 *
 * The RSPI configuration has the baud rate generator set
 * for maximum speed, which is PLCK/2 or 25 MHz.
 *
 * Manufacturer: Renesas
 * Communications Protocol: SPI 3-Wire Transmitt only MASTER SPI
 * Transmitter Number: 0
 * channel: 3
 * Chip Select Port: PC.2
 * SPI Clock Speed: 25MHz
 * Slave Device: OKAYA LCD with ST7579 microprocessor
 *
 *-------------------------------------------------------------------------*/
 
#ifndef __GLYPH__YRDK_RL78_SPI_0_HEADER_FILE
#define __GLYPH__YRDK_RL78_SPI_0_HEADER_FILE

/******************************************************************************
Includes glyph Include
******************************************************************************/
#include "r_cg_macrodriver.h"
#include "glyph_api.h"
 
/******************************************************************************
Prototypes for the Glyph Communications API
******************************************************************************/
void YRDKRL78_CommandSend(int8_t cCommand) ;
void YRDKRL78_DataSend(int8_t cData) ;
T_glyphError YRDKRL78_RSPIOpen(T_glyphHandle aHandle);

#endif /* __GLYPH__YRDK_RL78_SPI_0_HEADER_FILE */
 
 
