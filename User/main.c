/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2023/12/25
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*
 *@Note
 *Multiprocessor communication mode routine:
 *Master:USART1_Tx(PD5)\USART1_Rx(PD6).
 *This routine demonstrates that USART1 receives the data sent by CH341 and inverts
 *it and sends it (baud rate 115200).
 *
 *Hardware connection:PD5 -- Rx
 *                     PD6 -- Tx
 *
 */
#include "main.h"
#include "debug.h"
#include "lis2dw12.h"

/* Global define */


/* Global Variable */
vu8 val;

/*********************************************************************
 * @fn      USARTx_CFG
 *
 * @brief   Initializes the USART2 & USART3 peripheral.
 *
 * @return  none
 */
void USARTx_CFG(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1, ENABLE);

    /* USART1 TX-->D.5   RX-->D.6 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_30MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    USART_Init(USART1, &USART_InitStructure);
    USART_Cmd(USART1, ENABLE);
}

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
#if (SDI_PRINT == SDI_PR_OPEN)
    SDI_Printf_Enable();
#else
    USART_Printf_Init(115200);
#endif
    printf("SystemClk:%d\r\n",SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );

    USARTx_CFG();

    // configures GPIOC pin 4 as Output Push/Pull for data out
   Delay_Ms(5);
   init_lis2dw12();

   // Set up CTRL 1
   uint8_t ctrl1 = (LIS2_CTRL1_ODR_400_HZ << LIS2_CTRL1_ODR_POS) | (LIS2_CTRL1_MODE_HIGH_PER << LIS2_CTRL1_MODE_POS) | (LIS2_CTRL1_LP_MODE_1 << LIS2_CTRL1_LP_MODE_POS);
   lis2d_write(LIS2_REG_CTRL1,ctrl1 );

   while (lis2_read(LIS2_REG_STATUS)  & LIS2_STATUS_DRDY != LIS2_STATUS_DRDY);

   uint8_t temp = 0;
   temp = lis2_read(LIS2_REG_OUT_T);

   printf("LIS2 temp (reg 0x26)= %d\n\r",temp);

   // Set up Single Tap
   lis2d_write(LIS2_REG_CTRL6, 0x04);
   lis2d_write(LIS2_REG_TAP_THS_X, 0x0C);
   lis2d_write(LIS2_REG_TAP_THS_Y, 0xEC);
   lis2d_write(LIS2_REG_TAP_THS_Z, LIS2_TAP_THSZ_Z_EN | LIS2_TAP_THSZ_Y_EN | LIS2_TAP_THSZ_Z_EN | 0x0C);
   lis2d_write(LIS2_REG_INT_DUR, 0x06);
   lis2d_write(LIS2_REG_WAKE_UP_THS, LIS2_WAKE_UP_THS_TAP_EN);
   lis2d_write(LIS2_REG_CTRL4_INT1_PAD_CTRL, LIS2_CTRL_4_INT1_SINGLE_TAP | LIS2_CTRL_4_INT1_TAP);
   lis2d_write(LIS2_REG_CTRL7, LIS2_CTRL7_INTS_ENABLE);



   while(1)
   {
       uint8_t status = lis2_read(LIS2_REG_STATUS_DUP);
       if ( (status & LIS2_STATUS_DUP_SINGLE_TAP) == LIS2_STATUS_DUP_SINGLE_TAP)
       {
           printf("Single Tap detected\n\r");

       } else if ( (status & LIS2_STATUS_DUP_DOUBLE_TAP) == LIS2_STATUS_DUP_DOUBLE_TAP)
       {
           printf("DOUBLE Tap detected\n\r");
       }
   }

    while(1)
    {

        while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET)
        {
            /* waiting for receiving finish */
        }
        val = (USART_ReceiveData(USART1));
        USART_SendData(USART1, ~val);
        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
        {
            /* waiting for sending finish */
        }
    }
}
