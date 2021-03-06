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
#include "..\glyph_cfg.h"


const uint8_t Renesas_Logo[] = {
    80, 16, // width=80, height=16
    0x08, 0x0c, 0x04, 0x06, 0x02, 0x02, 0x82, 0x82, 0xC6, 0xFE, 0xFE, 0xFE, 0x7C, 0x38, 0x00, 0x00,
    0xE0, 0xF0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,
    0xF0, 0xF0, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0xF0, 0xF0, 0x00, 0x00,
    0xE0, 0xF0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,
    0x60, 0xF0, 0xF0, 0x90, 0x90, 0x90, 0x10, 0x10, 0x10, 0x00,
    0x00, 0x00, 0x00, 0xC0, 0xE0, 0x30, 0x70, 0xF0, 0xC0, 0x00, 0x00, 0x00,
    0x60, 0xF0, 0xF0, 0x90, 0x90, 0x90, 0x10, 0x10, 0x10, 0x00,
    
    0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x01, 0x01, 0x07, 0x0F, 0x1F, 0x1C, 0x30, 0x20, 0x40, 0x40,
    0x0F, 0x0F, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x00,
    0x0F, 0x0F, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0E, 0x0F, 0x0F, 0x00, 0x00,
    0x0F, 0x0F, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x00,
    0x08, 0x08, 0x09, 0x09, 0x09, 0x0B, 0x0B, 0x0F, 0x0F, 0x06,
    0x08, 0x0C, 0x0F, 0x03, 0x00, 0x08, 0x08, 0x09, 0x0F, 0x0F, 0x0E, 0x08,
    0x08, 0x08, 0x09, 0x09, 0x09, 0x0B, 0x0B, 0x0F, 0x0F, 0x06,
};

const uint8_t * Logos_table[256] = {
    Renesas_Logo,
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
