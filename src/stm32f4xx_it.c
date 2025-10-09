

/* Includes ------------------------------------------------------------------*/
//#include "main.h"
#include "stm32f4xx_it.h"
#include "stm32f4xx_hal.h"


/* External variables --------------------------------------------------------*/
extern I2C_HandleTypeDef hi2c1;
//extern DMA_HandleTypeDef hdma_tim2_ch2_ch4;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/

/**
  * @brief This function handles I2C1 event interrupt.
  */
void I2C1_EV_IRQHandler(void)
{

  HAL_I2C_EV_IRQHandler(&hi2c1);

}

/**
  * @brief This function handles I2C1 error interrupt.
  */
void I2C1_ER_IRQHandler(void)
{

  HAL_I2C_ER_IRQHandler(&hi2c1);

}