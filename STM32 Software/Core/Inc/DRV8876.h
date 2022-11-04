/*
 * DRV8876.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Tom Fry
 */

#ifndef INC_DRV8876_H_
#define INC_DRV8876_H_

#include "main.h"

#define ADC_DATA_BUFFER_SIZE	1024
#define PWM_DATA_BUFFER_SIZE	1024

typedef struct _DRV8876_TypeDef
{
	/*			ADC			*/
	ADC_HandleTypeDef *ADC_Handle;

	/*			ADC Data			*/
	uint16_t ADC_Data[ADC_DATA_BUFFER_SIZE];

	/*			PWM Timer			*/
	TIM_HandleTypeDef *Timer_Handle;
	uint32_t Timer_Channel_IN1;
	uint32_t Timer_Channel_IN2;

	/*			PWM Data			*/
	uint16_t PWM_Data_IN1[PWM_DATA_BUFFER_SIZE];
	uint16_t PWM_Data_IN2[PWM_DATA_BUFFER_SIZE];

} DRV8876_TypeDef;

/*			Exported Functions			*/

HAL_StatusTypeDef Init_DRV8876 (DRV8876_TypeDef *DRV8876, TIM_HandleTypeDef *Timer_Handle, uint32_t Timer_Channel_IN1, uint32_t Timer_Channel_IN2);
HAL_StatusTypeDef Start_DRV8876 (DRV8876_TypeDef *DRV8876);

#endif /* INC_DRV8876_H_ */
