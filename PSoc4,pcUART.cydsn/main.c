/******************************************************************************
* File Name: main.c
*
* Version: 1.10
*
* Description: This example demonstrates the UART transmit and receive 
*              operation using polling.
*
* Related Document: CE224406_PSoC4_UART.pdf
*
* Hardware Dependency: CY8CKIT-042 PSoC 4 PIONEER KIT
*
******************************************************************************
* Copyright (2018-2019), Cypress Semiconductor Corporation.
******************************************************************************
* This software, including source code, documentation and related materials
* ("Software") is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and 
* foreign), United States copyright laws and international treaty provisions. 
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the 
* Cypress source code and derivative works for the sole purpose of creating 
* custom software in support of licensee product, such licensee product to be
* used only in conjunction with Cypress's integrated circuit as specified in the
* applicable agreement. Any reproduction, modification, translation, compilation,
* or representation of this Software except as specified above is prohibited 
* without the express written permission of Cypress.
* 
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes to the Software without notice. 
* Cypress does not assume any liability arising out of the application or use
* of Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use as critical components in any products 
* where a malfunction or failure may reasonably be expected to result in 
* significant injury or death ("ACTIVE Risk Product"). By including Cypress's 
* product in a ACTIVE Risk Product, the manufacturer of such system or application
* assumes all risk of such use and in doing so indemnifies Cypress against all
* liability. Use of this Software may be limited by and subject to the applicable
* Cypress software license agreement.
*****************************************************************************/

#include <project.h>

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  The main function performs the following actions:
*   1. Initializes UART Component.
*   2. UART sends text header into the serial terminal.
*   3. Re-transmits whatever the user types on the console.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
int main(void)
{
    /* Start UART operation */
    UART_Start();
    
    /* Transmit header to the terminal */
    UART_UartPutString("\r\n**********************************************************************************\r\n");
    UART_UartPutString("This example uses polling to demonstrate UART operation\r\n");
    UART_UartPutString("If you see this text the terminal connection is configured correctly.\r\n");
    UART_UartPutString("Start typing to see an echo in the terminal.\r\n");
    UART_UartPutString("\r\n");
    
    for(;;)
    {
        if(UART_SpiUartGetRxBufferSize() != 0ul) {
            uint32 data = UART_SpiUartReadRxData();
            UART_SpiUartWriteTxData(data);
        }
        
        /* Below is an alternative that is simpler, but function used blocks until character is received */
        /* Characters typed on console are transmitted via UART using a low level API function*/
        //uint32 read_character = UART_UartGetChar(); 
        //UART_UartPutChar(read_character);
    }
}

/* [] END OF FILE */
