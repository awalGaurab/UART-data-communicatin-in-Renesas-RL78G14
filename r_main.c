/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_main.c
* Version      : CodeGenerator for RL78/G14 V2.05.05.01 [25 Nov 2020]
* Device(s)    : R5F104PJ
* Tool-Chain   : CCRL
* Description  : This file implements main function.
* Creation Date: 2/28/2022
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_serial.h"
#include "r_cg_rtc.h"
#include "r_cg_it.h"
/* Start user code for include. Do not edit comment generated here */
#include "lcd.h"
#include "RDKRL78_spi.h"
#include <stdio.h>
#include <string.h>
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
void monitor(void);

//unsigned char g_uart0_rx_buffer[50];  
//unsigned char read_char[50];

uint8_t c;
//TYPE_CONFIG CFG;	
int8_t uart0_buf[64];	
uint8_t fst_out = 0;	
extern UART_FIFO_M uart0_rxfifo;
static int8_t cmdB_str[30];
static int8_t idx = 0;

extern rtc_counter_value_t stRTC_Data;

/* End user code. Do not edit comment generated here */
void R_MAIN_UserInit(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
    while (1U)
    {
    	//WDT_CLR;  
		monitor();
    }
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    EI();
 	R_UART0_Start();	//UART2(RS-485:AD3072E) ??M?J?n		
	uart0_printf("\r\n\r\nSTART SENSOR\r\n");	//??????pUART1?o??
	
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
void monitor(void)
{
	int8_t *ptr;
	int8_t c;
	
	if(uart0_rxfifo.count == 0) return;
	c = uart0_getc();	
	if((c < 0x01) || (c > 0x7F)) {
		return;
	}
	if ((c == 0x08) && idx) { //BS·°
		idx--;
		uart0_putc(c, 1);
	}
	if ((c >= ' ') && (idx < 29)) {
		cmdB_str[idx++] = c;
		uart0_putc(c, 1);
	}
	if (c == '\r'){	//CR
		cmdB_str[idx] = 0; idx=0;
		uart0_printf("\r\n");
		ptr = cmdB_str;
	
		if((strcmp(cmdB_str,"ver") == 0) || (strcmp(cmdB_str,"VER") == 0))
		{
			uart0_printf("\r\nSoftware Version 1.00\r\n\r\n");
		}
		
	}
	
	/*if((strstr(cmdB_str,"ver")!=0)||(strstr(cmdB_str,"VER")!=0)){
		uart2_printf("\r\nSoftware Version\r\n");
	}*/
	
	
}
/* End user code. Do not edit comment generated here */
