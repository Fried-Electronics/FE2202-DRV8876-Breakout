/*
 * DRV8876.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Tom Fry
 */

#include "DRV8876.h"
#include "string.h"

HAL_StatusTypeDef Init_DRV8876 (DRV8876_TypeDef *DRV8876, TIM_HandleTypeDef *Timer_Handle, uint32_t Timer_Channel_IN1, uint32_t Timer_Channel_IN2)
{
	DRV8876->Timer_Handle = Timer_Handle;
	DRV8876->Timer_Channel_IN1 = Timer_Channel_IN1;
	DRV8876->Timer_Channel_IN2 = Timer_Channel_IN2;

	//memset(DRV8876->PWM_Data_IN1, 0, (PWM_DATA_LENGTH * sizeof(DRV8876->PWM_Data_IN1[0])));
	//memset(DRV8876->PWM_Data_IN2, 0, (PWM_DATA_LENGTH * sizeof(DRV8876->PWM_Data_IN1[0])));

	return HAL_OK;
}

HAL_StatusTypeDef Start_DRV8876 (DRV8876_TypeDef *DRV8876)
{
	if (HAL_TIM_PWM_Start_DMA(DRV8876->Timer_Handle, DRV8876->Timer_Channel_IN1, (uint32_t*)&DRV8876->PWM_Data_IN1[0], PWM_DATA_BUFFER_SIZE) == HAL_OK)
	{
		return HAL_TIM_PWM_Start_DMA(DRV8876->Timer_Handle, DRV8876->Timer_Channel_IN2, (uint32_t*)&DRV8876->PWM_Data_IN2[0], PWM_DATA_BUFFER_SIZE);
	} else
	{
		return HAL_ERROR;
	}
}
