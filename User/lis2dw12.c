/*
 * lis2dw12.c
 *
 *  Created on: 3 Aug 2024
 *      Author: GraemeGets
 */

#include "main.h"
#include "lis2dw12.h"


// Init LIS2D
void init_lis2dw12()
{

    I2C_InitTypeDef i2c_initStruct;
    GPIO_InitTypeDef GPIO_InitStruct;

    // Initialise the Peripheral clocks
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

    // INIT GPIO for SCL
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStruct.GPIO_Pin = LIS2_SCL_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LIS2_SCL_PORT, &GPIO_InitStruct);

    // INIT GPIO for SDA
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStruct.GPIO_Pin = LIS2_SDA_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LIS2_SDA_PORT, &GPIO_InitStruct);

    // Init SPI
    i2c_initStruct.I2C_ClockSpeed = 100;
    i2c_initStruct.I2C_Ack = I2C_Ack_Enable;
    i2c_initStruct.I2C_OwnAddress1 = LIS2_ADDR;
    i2c_initStruct.I2C_Mode = I2C_Mode_I2C;
    i2c_initStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    i2c_initStruct.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_Init(I2C1, &i2c_initStruct);

    I2C_Cmd(I2C1, ENABLE);
    I2C_AcknowledgeConfig(I2C1, ENABLE);


    /*-----------------------------------------------------------
     * Init Chip
     ------------------------------------------------------------*/

    uint8_t whoami = lis2_read(LIS2_REG_WHO_AM_I);

    printf("Init LIS2DW - Who Am I Responce = 0x%x\n\r",whoami);


}


uint8_t lis2_read(uint8_t readAddr)
{

       while( I2C_GetFlagStatus( I2C1, I2C_FLAG_BUSY ) != RESET );

       I2C_GenerateSTART( I2C1, ENABLE );
       while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_MODE_SELECT ) );

       I2C_Send7bitAddress(I2C1, LIS2_ADDR<<1, I2C_Direction_Transmitter);
       while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );

       I2C_SendData(I2C1,readAddr);
       while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) );

       // Part 2
       I2C_GenerateSTART( I2C1, ENABLE );
       while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_MODE_SELECT ) );

       I2C_Send7bitAddress(I2C1, LIS2_ADDR<<1, I2C_Direction_Receiver);
       while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) );

       while( I2C_GetFlagStatus( I2C1, I2C_FLAG_RXNE ) ==  RESET )
          I2C_AcknowledgeConfig( I2C1, DISABLE );

        uint8_t  data = I2C_ReceiveData( I2C1 );
        I2C_GenerateSTOP( I2C1, ENABLE );

        return data;
}


void lis2d_write(uint8_t addr, uint8_t data)
{
    while( I2C_GetFlagStatus( I2C1, I2C_FLAG_BUSY ) != RESET );
    I2C_GenerateSTART( I2C1, ENABLE );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_MODE_SELECT ) );
    I2C_Send7bitAddress( I2C1, LIS2_ADDR<<1, I2C_Direction_Transmitter );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );

    I2C_SendData( I2C1, (u8)(addr&0x00FF) );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );


    if( I2C_GetFlagStatus( I2C1, I2C_FLAG_TXE ) !=  RESET )
    {
        I2C_SendData( I2C1, data );
    }

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
    I2C_GenerateSTOP( I2C1, ENABLE );
}

