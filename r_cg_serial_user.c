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
* File Name    : r_cg_serial_user.c
* Version      : CodeGenerator for RL78/G14 V2.05.05.01 [25 Nov 2020]
* Device(s)    : R5F104PJ
* Tool-Chain   : CCRL
* Description  : This file implements device driver for Serial module.
* Creation Date: 2/28/2022
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_serial.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_cg_wdt.h"
#include <string.h>
#include <stdarg.h>
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_uart0_interrupt_send(vect=INTST0)
#pragma interrupt r_uart0_interrupt_receive(vect=INTSR0)
#pragma interrupt r_csi21_interrupt(vect=INTCSI21)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t * gp_uart0_tx_address;         /* uart0 send buffer address */
extern volatile uint16_t  g_uart0_tx_count;            /* uart0 send data number */
extern volatile uint8_t * gp_uart0_rx_address;         /* uart0 receive buffer address */
extern volatile uint16_t  g_uart0_rx_count;            /* uart0 receive data number */
extern volatile uint16_t  g_uart0_rx_length;           /* uart0 receive data length */
extern volatile uint8_t * gp_csi21_rx_address;         /* csi21 receive buffer address */
extern volatile uint16_t  g_csi21_rx_length;           /* csi21 receive data length */
extern volatile uint16_t  g_csi21_rx_count;            /* csi21 receive data count */
extern volatile uint8_t * gp_csi21_tx_address;         /* csi21 send buffer address */
extern volatile uint16_t  g_csi21_send_length;         /* csi21 send data length */
extern volatile uint16_t  g_csi21_tx_count;            /* csi21 send data count */
/* Start user code for global. Do not edit comment generated here */
UART_FIFO_M uart0_rxfifo;
volatile uint8_t G_CSI21_SendingData = 0;
volatile uint8_t G_CSI21_ReceivingData = 0;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_uart0_interrupt_receive
* Description  : This function is INTSR0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_uart0_interrupt_receive(void)
{
    volatile uint8_t rx_data;
    volatile uint8_t err_type;
    
    err_type = (uint8_t)(SSR01 & 0x0007U);
    SIR01 = (uint16_t)err_type;

    if (err_type != 0U)
    {
        r_uart0_callback_error(err_type);
    }
    
    rx_data = RXD0;

    if (g_uart0_rx_length > g_uart0_rx_count)
    {
        *gp_uart0_rx_address = rx_data;
        gp_uart0_rx_address++;
        g_uart0_rx_count++;

        if (g_uart0_rx_length == g_uart0_rx_count)
        {
            r_uart0_callback_receiveend();
        }
    }
    else
    {
        r_uart0_callback_softwareoverrun(rx_data);
    }
}

/***********************************************************************************************************************
* Function Name: r_uart0_interrupt_send
* Description  : This function is INTST0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_uart0_interrupt_send(void)
{
    if (g_uart0_tx_count > 0U)
    {
        TXD0 = *gp_uart0_tx_address;
        gp_uart0_tx_address++;
        g_uart0_tx_count--;
    }
    else
    {
        r_uart0_callback_sendend();
    }
}

/***********************************************************************************************************************
* Function Name: r_uart0_callback_receiveend
* Description  : This function is a callback function when UART0 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_uart0_callback_receiveend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_uart0_callback_softwareoverrun
* Description  : This function is a callback function when UART0 receives an overflow data.
* Arguments    : rx_data -
*                    receive data
* Return Value : None
***********************************************************************************************************************/
static void r_uart0_callback_softwareoverrun(uint16_t rx_data)
{
    /* Start user code. Do not edit comment generated here */
    r_uart0_int_recv(rx_data);
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_uart0_callback_sendend
* Description  : This function is a callback function when UART0 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_uart0_callback_sendend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_uart0_callback_error
* Description  : This function is a callback function when UART0 reception error occurs.
* Arguments    : err_type -
*                    error type value
* Return Value : None
***********************************************************************************************************************/
static void r_uart0_callback_error(uint8_t err_type)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_csi21_interrupt
* Description  : This function is INTCSI21 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_csi21_interrupt(void)
{
    volatile uint8_t err_type;
    volatile uint8_t sio_dummy;

    err_type = (uint8_t)(SSR11 & _0001_SAU_OVERRUN_ERROR);
    SIR11 = (uint16_t)err_type;

    if (1U == err_type)
    {
        r_csi21_callback_error(err_type);    /* overrun error occurs */
    }
    else
    {
        if (g_csi21_tx_count > 0U)
        {
            if (0U != gp_csi21_rx_address)
            {
                *gp_csi21_rx_address = SIO21;
                gp_csi21_rx_address++;
            }
            else
            {
                sio_dummy = SIO21;
            }

            if (0U != gp_csi21_tx_address)
            {
                SIO21 = *gp_csi21_tx_address;
                gp_csi21_tx_address++;
            }
            else
            {
                SIO21 = 0xFFU;
            }

            g_csi21_tx_count--;
        }
        else 
        {
            if (0U == g_csi21_tx_count)
            {
                if (0U != gp_csi21_rx_address)
                {
                    *gp_csi21_rx_address = SIO21;
                }
                else
                {
                    sio_dummy = SIO21;
                }
            }

            r_csi21_callback_sendend();    /* complete send */
            r_csi21_callback_receiveend();    /* complete receive */
        }
    }
}

/***********************************************************************************************************************
* Function Name: r_csi21_callback_receiveend
* Description  : This function is a callback function when CSI21 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_csi21_callback_receiveend(void)
{
    /* Start user code. Do not edit comment generated here */
    G_CSI21_ReceivingData = 0;
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_csi21_callback_error
* Description  : This function is a callback function when CSI21 reception error occurs.
* Arguments    : err_type -
*                    error type value
* Return Value : None
***********************************************************************************************************************/
static void r_csi21_callback_error(uint8_t err_type)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_csi21_callback_sendend
* Description  : This function is a callback function when CSI21 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_csi21_callback_sendend(void)
{
    /* Start user code. Do not edit comment generated here */
    G_CSI21_SendingData = 0;
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
void r_uart0_int_recv(uint16_t rx_data)
{
    uint8_t n, i;

    if(((uint8_t)rx_data > 0) && (uint8_t)rx_data < 0x80) {
        n = uart0_rxfifo.count;
        if(n < sizeof(uart0_rxfifo.buff)) {
            uart0_rxfifo.count = ++n;
            i = uart0_rxfifo.idx_w;
            uart0_rxfifo.buff[i++] = (uint8_t)rx_data;
            if(i >= sizeof(uart0_rxfifo.buff))
                i = 0;
            uart0_rxfifo.idx_w = i;
        }
    }
}

uint8_t uart0_getc(void)
{
    uint8_t d, i;

    i = uart0_rxfifo.idx_r;
    while(uart0_rxfifo.count == 0);
    d = uart0_rxfifo.buff[i++];
    DI();
    uart0_rxfifo.count--;
    EI();
    if(i >= sizeof(uart0_rxfifo.buff))
        i = 0;
    uart0_rxfifo.idx_r = i;

    return d;
}

uint8_t uart0_putc(uint8_t data, uint8_t rts)
{
//    if(rts == 1) {
//      HART_RTS = 0;
//        delay_ms(5);
//    }
    while((SSR00 & 0x0020) == 0x0020);
    TXD0 = data;
    while((SSR00 & 0x0020) == 0x0020);
    while((SSR00 & 0x0040) == 0x0040);
        
//    if(rts == 1) {
//      HART_RTS = 1;
//    }
    return(0);
}

uint8_t uart0_puts(int8_t *data, uint8_t rts)
{       
//    if(rts == 1) {
//      HART_RTS = 0; 
//        delay_ms(5);
//    }
    
    while(*data != '\0'){
        while((SSR00 & 0x0020) == 0x0020);
        TXD0 = *data++;
    }
    while((SSR00 & 0x0020) == 0x0020);
    while((SSR00 & 0x0040) == 0x0040);
        
//    if(rts == 1) {
//      HART_RTS = 1;
//        delay_ms(5);
//    }
    return(0);
}

void uart0_printf(int8_t *str, ...)
{
    va_list arp;
    int8_t d, r, w, s, l;
    int8_t *pt;

    va_start(arp, str);

    while ((d = *str++) != 0) {
        if (d != '%') {
            uart0_putc(d, 0); continue;
        }
        d = *str++; w = r = s = l = 0;
        if (d == '0') {
            d = *str++; s = 1;
        }
        while ((d >= '0')&&(d <= '9')) {
            w += (int8_t)(w * 10 + (d - '0'));
            d = *str++;
        }
        if (s) w = (int8_t)(-w);
        if (d == 'l') {
            l = 1;
            d = *str++;
        }
        if (!d) break;
        if (d == 's') {
            pt = va_arg(arp, int8_t*);
            uart0_puts(pt, 0);
            continue;
        }
        if (d == 'c') {
            uart0_putc((char)va_arg(arp, short), 0);
            continue;
        }
        if (d == 'u') r = 10;
        if (d == 'd') r = -10;
        if (d == 'X') r = 16;
        if (d == 'b') r = 2;
        if (d == 'o') r = 8;
        if (!r) break;
        if (l) {
            uart0_itoa((long)va_arg(arp, long), r, w);
        } else {
            if (r > 0)
                uart0_itoa((unsigned long)va_arg(arp, unsigned short), r, w);
            else
                uart0_itoa((long)va_arg(arp, short), r, w);
        }
    }
    va_end(arp);
}

void uart0_itoa (long val, signed char radix, signed char len)
{
    
    uint8_t c, r, sgn = 0, pad = ' ';
    uint8_t s[20], i = 0;
    int32_t value = val;

    if (radix < 0) {
        radix = (int8_t)(-radix);
        if (val < 0) { 
            val = -val;
            sgn = '-';
        }
    }
    r = radix;
    if (len < 0) {
        len = (int8_t)(-len);
        pad = '0';
    }
    if (len > 20) return;
    do {
        c = (unsigned char)(val % r);
        if (c >= 10) c += 7;
        c += '0';
        s[i++] = c;
        val /= r;
    } while (val);

    if (pad ==' ' && sgn) s[i++] = sgn;
    if (pad =='0' && sgn) len--;
    while (i < len) s[i++] = pad;
    if (pad =='0' && sgn) s[i++] = sgn;

    do
        uart0_putc(s[--i], 0);
    while (i);  
}

/* End user code. Do not edit comment generated here */
