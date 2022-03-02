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
 * File:  preamble.h
 *-------------------------------------------------------------------------*
 * Description:
 *     Basic definitions or all simple types and constants.
 *     Used for compatibility between compilers and hardware.
 *-------------------------------------------------------------------------*/
#ifndef __GLYPH__TYPES_H
#define __GLYPH__TYPES_H

#include "r_cg_macrodriver.h"

/***************************************************************************
 * SECTION:  CONSTANTS
 ***************************************************************************/
#define ON          1
#define OFF         0
#define ENABLE      1
#define DISABLE     0
#define YES         1
#define NO          0
#define TRUE        1
#define FALSE       0
#define GOOD        1
#define BAD         0
#define HIGH        1
#define LOW         0

/***************************************************************************
 * SECTION:  BIT DEFINITIONS
 ***************************************************************************/
#define b0      0x01
#define b1      0x02
#define b2      0x04
#define b3      0x08
#define b4      0x10
#define b5      0x20
#define b6      0x40
#define b7      0x80

#endif  /* __GLYPH__PREAMBLE_H */
/*-------------------------------------------------------------------------*
 * End of File:  Preamble.H
 *-------------------------------------------------------------------------*/


