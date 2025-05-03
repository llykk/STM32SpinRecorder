#include "stm32l4xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"

extern I2C_HandleTypeDef hi2c1;

int32_t LSM6DSO_Bus_Init(void)
{
	return HAL_OK;					// Инициализация шины происходит в функции MX_I2C1_Init()
}

int32_t LSM6DSO_Bus_DeInit(void)
{
	return HAL_OK;
}

int32_t LSM6DSO_Bus_GetTick(void)
{
	return HAL_GetTick();
}

void  LSM6DSO_Bus_Delay(uint32_t ms)
{
	vTaskDelay(ms / portTICK_RATE_MS);
}

int32_t LSM6DSO_Bus_WriteReg(uint16_t addrDev, uint16_t addrReg, uint8_t *data, uint16_t len)
{
	return HAL_I2C_Mem_Write(&hi2c1, addrDev, addrReg, I2C_MEMADD_SIZE_8BIT, data, len, 100);
}

int32_t LSM6DSO_Bus_ReadReg(uint16_t addrDev, uint16_t addrReg, uint8_t *data, uint16_t len)
{
	return HAL_I2C_Mem_Read(&hi2c1, addrDev, addrReg, I2C_MEMADD_SIZE_8BIT, data, len, 100);
}
