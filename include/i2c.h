
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __I2C_H__
#define __I2C_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"


extern I2C_HandleTypeDef hi2c1;


uint16_t i2c_adc_buffer[48];

uint8_t RxBuffer[96];
uint8_t TxBuffer[96];

void MX_I2C1_Init(void);
void I2C_adc_get(void);
void I2C1_EV_IRQHandler(void);
void I2C1_ER_IRQHandler(void);
void HAL_I2C_MasterRxCpltCallback (I2C_HandleTypeDef * hi2c);


#ifdef __cplusplus
}
#endif

#endif /* __I2C_H__ */

