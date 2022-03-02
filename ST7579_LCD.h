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
 * File:  ST7579_LCD.h
 *-------------------------------------------------------------------------*
 * Description:
 *     Prototypes for the LCD Driver in the Glyph API.
 * Manufacturer: OKAYA
 * Microcontroller: ST7579
 * Dimensions: 68 x 102
 * Communications Required: 3-Wire SPI with a 4th Wire independent
 *                          Transmit Only
 *-------------------------------------------------------------------------*/
#ifndef __GLYPH__ST7579_LCD_HEADER_FILE
#define __GLYPH__ST7579_LCD_HEADER_FILE

/******************************************************************************
Includes glyph Include
******************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_port.h"
#include "glyph_api.h"

/******************************************************************************
* Outline : Function Sets
* Description : These sets of defines are used to define the Function Set call
* for every command that is sent to the ST7579 Display controller.  When
* setting the display controller to the 4 different function sets of commands
* to send to the controller, setting the function set also sets the following:
* MX direction: normal or reverse    [0:1]
* MY direction: normal or reverse    [0:1]
* PD controller active or power down [0:1]
*
* If the preprocessor directive #if is set to 1 then every Function Set call
* will produce MY set to the reverse direction.  This is required for Glyph.
*
* Otherwise MY will be set to the normal direction and Glyph will not work.
* Argument : none
* Return Value : none
* Calling Functions : ST7579_Write
******************************************************************************/
#if 1
// MY reverse direction
#define LCD_FUNCTION_ZERO    0X28
#define LCD_FUNCTION_ONE     0X29
#define LCD_FUNCTION_TWO     0X2A
#define LCD_FUNCTION_THREE   0X2B
     // command sets
#define LCD_DISPLAY_REVERSE  0x280D
#define LCD_DISPLAY_NORMAL   0x280C
#else
// MY normal direction
#define LCD_FUNCTION_ZERO    0X20
#define LCD_FUNCTION_ONE     0X21
#define LCD_FUNCTION_TWO     0X22
#define LCD_FUNCTION_THREE   0X23
     // command sets
#define LCD_DISPLAY_REVERSE  0x200D
#define LCD_DISPLAY_NORMAL   0x200C
#endif

/******************************************************************************
Prototypes for the Glyph LCD API
******************************************************************************/
T_glyphError ST7579_Open(T_glyphHandle aHandle, uint16_t aAddress) ;
T_glyphError ST7579_Close(T_glyphHandle aHandle) ;
T_glyphError ST7579_Write(T_glyphHandle aHandle, uint16_t aRegister, uint16_t aValue) ;
T_glyphError ST7579_Read(T_glyphHandle aHandle, uint16_t aRegister, uint16_t *aValue) ;

/******************************************************************************
Prototypes for the LCD API
******************************************************************************/
void ST7579_Config(T_glyphHandle aHandle) ;
void ST7579_SetSystemBiasBooster(T_glyphHandle aHandle, int8_t cValue0To17) ;
void ST7579_SetVO_Range(T_glyphHandle aHandle, int16_t nValue0to254) ;
void ST7579_SetFrameRate(T_glyphHandle aHandle, int16_t nRate55To137) ;
void ST7579_SetPage(T_glyphHandle aHandle,uint8_t cValue0To9);
void ST7579_SetChar(T_glyphHandle aHandle, uint8_t cValue0To101);
void ST7579_SetLine(T_glyphHandle aHandle, int8_t cValue0To66) ;
void ST7579_Send8bitsData(T_glyphHandle aHandle, int8_t cData) ;
void ST7579_Send16bitsCommand(T_glyphHandle aHandle, int16_t nCommand);

int8_t No_Clobber_Axes(uint16_t cmd, uint16_t col, uint16_t line);

#endif /* __GLYPH__ST7579_LCD_HEADER_FILE */

