/* CA78K0R C Source Converter V1.00.03.01 [10 May 2018] */
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
 * File:  font_bitmap.c
 *-------------------------------------------------------------------------*
 * Description:
 *      Overrides the glyph library bitmap font for custom use
 *-------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
 * Copyright (C) 2011 Future Designs, Inc.
 *--------------------------------------------------------------------------
 *
 *    *===============================================================*
 *    |  Future Designs, Inc. can port uEZ(tm) to your own hardware!  |
 *    |             We can get you up and running fast!               |
 *    |      See http://www.teamfdi.com/uez for more details.         |
 *    *===============================================================*
 *
 *-------------------------------------------------------------------------*/

#include "r_cg_macrodriver.h"

const uint8_t Bitmap_RenesasR[] = {
    16, 16, // width=16, height=16
	0x08, 0x0c, 0x04, 0x06, 0x02, 0x02, 0x82, 0x82, 0xC6, 0xFE, 0xFE, 0xFE, 0x7C, 0x38, 0x00, 0x00,
	0x0F, 0x0F,	0x0F, 0x0F, 0x00, 0x00, 0x01, 0x01, 0x07, 0x0F, 0x1F, 0x1C, 0x30, 0x20, 0x40, 0x40,
};

const uint8_t Bitmap_RenesasE[] = {
    10, 16, // width=10, height=16
	0xE0, 0xF0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,
 	0x0F, 0x0F, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x00,
};

const uint8_t Bitmap_RenesasN[] = {
    12, 16, // width=12, height=16
	0xF0, 0xF0, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0xF0, 0xF0, 0x00, 0x00,
	0x0F, 0x0F, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0E, 0x0F, 0x0F, 0x00, 0x00,
};

const uint8_t Bitmap_RenesasS[] = {
    10, 16, // width=10, height=16
	0x60, 0xF0, 0xF0, 0x90, 0x90, 0x90, 0x10, 0x10, 0x10, 0x00,
	0x08, 0x08, 0x09, 0x09, 0x09, 0x0B, 0x0B, 0x0F, 0x0F, 0x06,
};

const uint8_t Bitmap_RenesasA[] = {
    12, 16, // width=78, height=16
	0x00, 0x00, 0x00, 0xC0, 0xE0, 0x30, 0x70, 0xF0, 0xC0, 0x00, 0x00, 0x00,
	0x08, 0x0C, 0x0F, 0x03, 0x00, 0x08, 0x08, 0x09, 0x0F, 0x0F, 0x0E, 0x08,
};

const uint8_t Bitmap_FDI[] = {
    0x08, 0x08, // width=8, height=8
    0x7E, 0x81, 0x95, 0xB1, 0xB1, 0x95, 0x81, 0x7E, 
};

const uint8_t Bitmap_LoadingBar_Left[] = {
    0x04, 0x08, // width=4, height=8
    0x18, 0x7E, 0xFF, 0x81
};

const uint8_t Bitmap_LoadingBar_Right[] = {
    0x04, 0x08, // width=4, height=8
    0x81, 0xFF, 0x7E, 0x18
};

const uint8_t Bitmap_LoadingBar_Empty[] = {
    0x01, 0x08, // width=1, height=8
    0x81
};

const uint8_t Bitmap_LoadingBar_Fill[] = {
    0x01, 0x08, // width=1, height=8
    0xBD
};

const uint8_t * const Bitmaps_table[256] = {
	0,
	0,
	0,
	0,
	0,
	Bitmap_FDI,
	Bitmap_LoadingBar_Left,
    Bitmap_LoadingBar_Right,
    Bitmap_LoadingBar_Empty,
    Bitmap_LoadingBar_Fill,
    0,
    0,
	0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    Bitmap_RenesasA,
    0,
    0,
    0,
    Bitmap_RenesasE,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    Bitmap_RenesasN,
    0,
    0,
    0,
    Bitmap_RenesasR,
    Bitmap_RenesasS,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
