
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __I2C_H__
#define __I2C_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"



extern I2C_HandleTypeDef hi2c1;


uint8_t RxBuffer[96];
uint8_t TxBuffer[96];

uint8_t rxcount;
uint8_t txcount;

void HAL_I2C_ListenCpltCallback (I2C_HandleTypeDef *hi2c);
void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode);
void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c);
void MX_I2C1_Init(void);



#ifdef __cplusplus
}
#endif

#endif /* __I2C_H__ */

