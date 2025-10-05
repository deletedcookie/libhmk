#include "i2c_slave.h"


extern void HAL_I2C_ListenCpltCallback (I2C_HandleTypeDef *hi2c)
{
	HAL_I2C_EnableListen_IT(hi2c);  // restart listening
}

void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode)
{
    if ((AddrMatchCode && CEC_OWN_ADDRESS_1) && (TransferDirection == I2C_DIRECTION_RECEIVE))   // ADC address 0xE1
    {
        txcount = 0;
        HAL_I2C_Slave_Seq_Transmit_IT(hi2c, adc_values, 48, I2C_NEXT_FRAME);    // send all TxData
    }
	else if ((AddrMatchCode && CEC_OWN_ADDRESS_2) && (TransferDirection == I2C_DIRECTION_TRANSMIT))  // LED address 0xE2
	{
		HAL_I2C_Slave_Seq_Receive_IT(hi2c, RxData, 48, I2C_FIRST_AND_LAST_FRAME);   // recieve all frames
	}
	else
	{
		HAL_I2C_EnableListen_IT(hi2c);  // restart listening
	}
}


void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
    // continue sending TxData
	txcount++;
	HAL_I2C_Slave_Seq_Transmit_IT(hi2c, adc_values+txcount, 1, I2C_NEXT_FRAME);
}


void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{
	HAL_I2C_EnableListen_IT(hi2c);  // restart listening
}