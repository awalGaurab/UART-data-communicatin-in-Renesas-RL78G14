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
* File Name    : r_cg_serial.c
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
volatile uint8_t * gp_uart0_tx_address;        /* uart0 transmit buffer address */
volatile uint16_t  g_uart0_tx_count;           /* uart0 transmit data number */
volatile uint8_t * gp_uart0_rx_address;        /* uart0 receive buffer address */
volatile uint16_t  g_uart0_rx_count;           /* uart0 receive data number */
volatile uint16_t  g_uart0_rx_length;          /* uart0 receive data length */
volatile uint8_t * gp_csi21_rx_address;        /* csi21 receive buffer address */
volatile uint16_t  g_csi21_rx_length;          /* csi21 receive data length */
volatile uint16_t  g_csi21_rx_count;           /* csi21 receive data count */
volatile uint8_t * gp_csi21_tx_address;        /* csi21 send buffer address */
volatile uint16_t  g_csi21_send_length;        /* csi21 send data length */
volatile uint16_t  g_csi21_tx_count;           /* csi21 send data count */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_SAU0_Create
* Description  : This function initializes the SAU0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU0_Create(void)
{
    SAU0EN = 1U;    /* supply SAU0 clock */
    NOP();
    NOP();
    NOP();
    NOP();
    SPS0 = _0003_SAU_CK00_FCLK_3 | _0030_SAU_CK01_FCLK_3;
    R_UART0_Create();
}

/***********************************************************************************************************************
* Function Name: R_UART0_Create
* Description  : This function initializes the UART0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART0_Create(void)
{
    ST0 |= _0002_SAU_CH1_STOP_TRG_ON | _0001_SAU_CH0_STOP_TRG_ON;    /* disable UART0 receive and transmit */
    STMK0 = 1U;    /* disable INTST0 interrupt */
    STIF0 = 0U;    /* clear INTST0 interrupt flag */
    SRMK0 = 1U;    /* disable INTSR0 interrupt */
    SRIF0 = 0U;    /* clear INTSR0 interrupt flag */
    SREMK0 = 1U;   /* disable INTSRE0 interrupt */
    SREIF0 = 0U;   /* clear INTSRE0 interrupt flag */
    /* Set INTST0 low priority */
    STPR10 = 1U;
    STPR00 = 1U;
    /* Set INTSR0 low priority */
    SRPR10 = 1U;
    SRPR00 = 1U;
    SMR00 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_TRIGGER_SOFTWARE |
            _0002_SAU_MODE_UART | _0000_SAU_TRANSFER_END;
    SCR00 = _8000_SAU_TRANSMISSION | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | _0080_SAU_LSB | _0010_SAU_STOP_1 |
            _0007_SAU_LENGTH_8;
    SDR00 = _9A00_UART0_TRANSMIT_DIVISOR;
    NFEN0 |= _01_SAU_RXD0_FILTER_ON;
    SIR01 = _0004_SAU_SIRMN_FECTMN | _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;    /* clear error flag */
    SMR01 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0100_SAU_TRIGGER_RXD | _0000_SAU_EDGE_FALL |
            _0002_SAU_MODE_UART | _0000_SAU_TRANSFER_END;
    SCR01 = _4000_SAU_RECEPTION | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | _0080_SAU_LSB | _0010_SAU_STOP_1 |
            _0007_SAU_LENGTH_8;
    SDR01 = _9A00_UART0_RECEIVE_DIVISOR;
    SO0 |= _0001_SAU_CH0_DATA_OUTPUT_1;
    SOL0 |= _0000_SAU_CHANNEL0_NORMAL;    /* output level normal */
    SOE0 |= _0001_SAU_CH0_OUTPUT_ENABLE;    /* enable UART0 output */
    /* Set RxD0 pin */
    PM5 |= 0x01U;
    /* Set TxD0 pin */
    P5 |= 0x02U;
    PM5 &= 0xFDU;
}

/***********************************************************************************************************************
* Function Name: R_UART0_Start
* Description  : This function starts the UART0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART0_Start(void)
{
    SO0 |= _0001_SAU_CH0_DATA_OUTPUT_1;    /* output level normal */
    SOE0 |= _0001_SAU_CH0_OUTPUT_ENABLE;    /* enable UART0 output */
    SS0 |= _0002_SAU_CH1_START_TRG_ON | _0001_SAU_CH0_START_TRG_ON;    /* enable UART0 receive and transmit */
    STIF0 = 0U;    /* clear INTST0 interrupt flag */
    SRIF0 = 0U;    /* clear INTSR0 interrupt flag */
    STMK0 = 0U;    /* enable INTST0 interrupt */
    SRMK0 = 0U;    /* enable INTSR0 interrupt */
}

/***********************************************************************************************************************
* Function Name: R_UART0_Stop
* Description  : This function stops the UART0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART0_Stop(void)
{
    STMK0 = 1U;    /* disable INTST0 interrupt */
    SRMK0 = 1U;    /* disable INTSR0 interrupt */
    ST0 |= _0002_SAU_CH1_STOP_TRG_ON | _0001_SAU_CH0_STOP_TRG_ON;    /* disable UART0 receive and transmit */
    SOE0 &= ~_0001_SAU_CH0_OUTPUT_ENABLE;    /* disable UART0 output */
    STIF0 = 0U;    /* clear INTST0 interrupt flag */
    SRIF0 = 0U;    /* clear INTSR0 interrupt flag */
   
}

/***********************************************************************************************************************
* Function Name: R_UART0_Receive
* Description  : This function receives UART0 data.
* Arguments    : rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_UART0_Receive(uint8_t * const rx_buf, uint16_t rx_num)
{
    MD_STATUS status = MD_OK;

    if (rx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_uart0_rx_count = 0U;
        g_uart0_rx_length = rx_num;
        gp_uart0_rx_address = rx_buf;
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_UART0_Send
* Description  : This function sends UART0 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_UART0_Send(uint8_t * const tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        gp_uart0_tx_address = tx_buf;
        g_uart0_tx_count = tx_num;
        STMK0 = 1U;    /* disable INTST0 interrupt */
        TXD0 = *gp_uart0_tx_address;
        gp_uart0_tx_address++;
        g_uart0_tx_count--;
        STMK0 = 0U;    /* enable INTST0 interrupt */
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_SAU1_Create
* Description  : This function initializes the SAU1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU1_Create(void)
{
    SAU1EN = 1U;    /* supply SAU1 clock */
    NOP();
    NOP();
    NOP();
    NOP();
    SPS1 = _0000_SAU_CK00_FCLK_0 | _0000_SAU_CK01_FCLK_0;
    R_CSI21_Create();
}

/***********************************************************************************************************************
* Function Name: R_CSI21_Create
* Description  : This function initializes the CSI21 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CSI21_Create(void)
{
    ST1 |= _0002_SAU_CH1_STOP_TRG_ON;    /* disable CSI21 */
    CSIMK21 = 1U;    /* disable INTCSI21 interrupt */
    CSIIF21 = 0U;    /* clear INTCSI21 interrupt flag */
    /* Set INTCSI21 low priority */
    CSIPR121 = 1U;
    CSIPR021 = 1U;
    SIR11 = _0004_SAU_SIRMN_FECTMN | _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;    /* clear error flag */
    SMR11 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_CLOCK_MODE_CKS |
            _0000_SAU_TRIGGER_SOFTWARE | _0000_SAU_MODE_CSI | _0000_SAU_TRANSFER_END;
    SCR11 = _C000_SAU_RECEPTION_TRANSMISSION | _0000_SAU_TIMING_1 | _0000_SAU_MSB | _0007_SAU_LENGTH_8;
    SDR11 = _0200_CSI21_DIVISOR;
    SO1 |= _0200_SAU_CH1_CLOCK_OUTPUT_1;    /* CSI21 clock initial level */
    SO1 &= ~_0002_SAU_CH1_DATA_OUTPUT_1;    /* CSI21 SO initial level */
    SOE1 |= _0002_SAU_CH1_OUTPUT_ENABLE;    /* enable CSI21 output */
    /* Set SI21 pin */
    PM7 |= 0x02U;
    /* Set SO21 pin */
    P7 |= 0x04U;
    PM7 &= 0xFBU;
    /* Set SCK21 pin */
    P7 |= 0x01U;
    PM7 &= 0xFEU;
}

/***********************************************************************************************************************
* Function Name: R_CSI21_Start
* Description  : This function starts the CSI21 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CSI21_Start(void)
{
    SO1 |= _0200_SAU_CH1_CLOCK_OUTPUT_1;    /* CSI21 clock initial level */
    SO1 &= ~_0002_SAU_CH1_DATA_OUTPUT_1;           /* CSI21 SO initial level */
    SOE1 |= _0002_SAU_CH1_OUTPUT_ENABLE;           /* enable CSI21 output */
    SS1 |= _0002_SAU_CH1_START_TRG_ON;             /* enable CSI21 */
    CSIIF21 = 0U;    /* clear INTCSI21 interrupt flag */
    CSIMK21 = 0U;    /* enable INTCSI21 */
}

/***********************************************************************************************************************
* Function Name: R_CSI21_Stop
* Description  : This function stops the CSI21 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CSI21_Stop(void)
{
    CSIMK21 = 1U;    /* disable INTCSI21 interrupt */
    ST1 |= _0002_SAU_CH1_STOP_TRG_ON;        /* disable CSI21 */
    SOE1 &= ~_0002_SAU_CH1_OUTPUT_ENABLE;    /* disable CSI21 output */
    CSIIF21 = 0U;    /* clear INTCSI21 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_CSI21_Send_Receive
* Description  : This function sends and receives CSI21 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
*                rx_buf -
*                    receive buffer pointer
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_CSI21_Send_Receive(uint8_t * const tx_buf, uint16_t tx_num, uint8_t * const rx_buf)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_csi21_tx_count = tx_num;        /* send data count */
        gp_csi21_tx_address = tx_buf;     /* send buffer pointer */
        gp_csi21_rx_address = rx_buf;     /* receive buffer pointer */
        CSIMK21 = 1U;                     /* disable INTCSI21 interrupt */

        if (0U != gp_csi21_tx_address)
        {
            SIO21 = *gp_csi21_tx_address;    /* started by writing data to SDR[7:0] */
            gp_csi21_tx_address++;
        }
        else
        {
            SIO21 = 0xFFU;
        }

        g_csi21_tx_count--;
        CSIMK21 = 0U;                     /* enable INTCSI21 interrupt */
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
