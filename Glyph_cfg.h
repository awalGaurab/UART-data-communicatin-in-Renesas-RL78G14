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
 * File:  Config.h
 *-------------------------------------------------------------------------*
 * Description:
 *     Configuration file for The Generic API for Graphics LCD
 *     Glyph
 *-------------------------------------------------------------------------*/
#ifndef __GLYPH__CONFIG_H
#define __GLYPH__CONFIG_H

#include "glyph_types.h"

#define VERSION_MAJOR           1
#define VERSION_MINOR           0
#define VERSION_STRING          "1.00"

/*-------------------------------------------------------------------------*
 *     Glyph API Library FONT USE DEFINES
 * In the first list uncomment any font you would like to choose from
 * In your code that uses the Glyph API.
 *
 * In the second list uncomment the desired DEFAULT FONT.  Comment out
 * the rest.
 *
 * The reason for this is so you can have a smaller build if you would like.
 *-------------------------------------------------------------------------*/
//#define USE_GLYPH_FONT_BITMAP
//#define USE_GLYPH_FONT_HELVR10
//#define USE_GLYPH_FONT_8_BY_16
#define USE_GLYPH_FONT_8_BY_8
//#define USE_GLYPH_FONT_WINFREE
//#define USE_GLYPH_FONT_5_BY_7
//#define USE_GLYPH_FONT_6_BY_13
//#define USE_GLYPH_FONT_LOGOS

//#define USE_DEFAULT_FONT Bitmaps_table
//#define USE_DEFAULT_FONT FontHelvr10_table
//#define USE_DEFAULT_FONT Font8x16_table
#define USE_DEFAULT_FONT Font8x8_table
//#define USE_DEFAULT_FONT FontWinFreeSystem14x16_table
//#define USE_DEFAULT_FONT Fontx5x7_table
//#define USE_DEFAULT_FONT Fontx6x13_table
//#define USE_DEFAULT_FONT FontHelvr10_table

#endif // __GLYPH__CONFIG_H
/*-------------------------------------------------------------------------*
 * End of File:  Config.H
 *-------------------------------------------------------------------------*/

