/*
 * stm32g491xx_gpio_driver.c
 *
 *  Created on: 16 sie 2026
 *      Author: Paweł Smusz
 */

#include "stm32g491xx_gpio_driver.h"

/*
 * Peripheral clock setup
 */

/*********************************************************************
 * @fn					- GPIO_PeriClockControl
 *
 * @brief				- This function enables or disables peripheral clock for the given GPIO port.
 *
 * @param[in]			- pGPIOx: Base address of the GPIO peripheral
 * @param[in]			- EnorDi: ENABLE or DISABLE macros
 * @param[in]			-
 *
 * @return				- None
 *
 * @Note				- None
 *********************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
	}else
	{
		if(pGPIOx == GPIOA)
			{
				GPIOA_PCLK_DI();
			}else if(pGPIOx == GPIOB)
			{
				GPIOB_PCLK_DI();
			}else if(pGPIOx == GPIOC)
			{
				GPIOC_PCLK_DI();
			}else if(pGPIOx == GPIOD)
			{
				GPIOD_PCLK_DI();
			}else if(pGPIOx == GPIOE)
			{
				GPIOE_PCLK_DI();
			}else if(pGPIOx == GPIOF)
			{
				GPIOF_PCLK_DI();
			}else if(pGPIOx == GPIOG)
			{
				GPIOG_PCLK_DI();
			}
	}
}

/*
 * Init and De-init
 */

/*********************************************************************
 * @fn					- GPIO_Init
 *
 * @brief				- Initializes the GPIO peripheral according
 *                        to the configuration specified in the handle
 *
 * @param[in]			- pGPIOHandle: Pointer to GPIO handle structure
 * @param[in]			-
 * @param[in]			-
 *
 * @return				- None
 *
 * @Note				- None
 *********************************************************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp=0;	//temp. register
	//1. Configure the mode of the pin

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		// the non interrupt mode
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing
		pGPIOHandle->pGPIOx->MODER |= temp; //setting

	} else
	{
		// (interrupt mode)
	}

	temp = 0;
	//2. Configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing
	pGPIOHandle->pGPIOx->OSPEEDR |= temp; //setting

	temp = 0;
	//3. Configure the pupd settings
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing
	pGPIOHandle->pGPIOx->PUPDR |= temp; //setting

	temp = 0;
	//4. Configure the optype
	temp =(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing
	pGPIOHandle->pGPIOx->OTYPER |= temp; //setting

	//5. Configure the alt functionality.
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		uint8_t temp1, temp2;

		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << ( 4 * temp2)); //clearing
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << ( 4 * temp2)); //setting

	}
}

/*********************************************************************
 * @fn					- GPIO_DeInit
 *
 * @brief				- Removes all settings of the GPIO peripheral
 *
 *
 * @param[in]			-
 * @param[in]			-
 *
 * @return				- None
 *
 * @Note				- None
 *********************************************************************/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
		{
			GPIOA_REG_RESET();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_REG_RESET();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_REG_RESET();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_REG_RESET();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_REG_RESET();
		}else if(pGPIOx == GPIOF)
		{
			GPIOF_REG_RESET();
		}else if(pGPIOx == GPIOG)
		{
			GPIOG_REG_RESET();
		}
}

/*
 * Data read and write
 */

/*********************************************************************
 * @fn					- GPIO_ReadFromInputPin
 *
 * @brief				- Reads the input state of a GPIO pin
 *
 *
 * @param[in]			- pGPIOx: Pointer to GPIO port base address
 * @param[in]			- PinNumber: GPIO Pin number
 * @param[in]			-
 *
 * @return				- Pin state (0 or 1)
 *
 * @Note				- None
 *********************************************************************/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}

/*********************************************************************
 * @fn					- GPIO_ReadFromInputPort
 *
 * @brief				- Reads the input state of a GPIO port
 *
 *
 * @param[in]			- pGPIOx: Pointer to GPIO port base address
 * @param[in]			-
 * @param[in]			-
 *
 * @return				- Input port value
 *
 * @Note				- None
 *********************************************************************/
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}

/*********************************************************************
 * @fn					- GPIO_WriteToOutputPin
 *
 * @brief				- Writes a value to a GPIO output pin
 *
 *
 * @param[in]			- pGPIOx: Pointer to GPIO port base address
 * @param[in]			- PinNumber: GPIO Pin number
 * @param[in]			- Value: 0 or 1
 *
 * @return				- None
 *
 * @Note				- None
 *********************************************************************/
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{

}

/*********************************************************************
 * @fn					- GPIO_WriteToOutputPort
 *
 * @brief				- Writes a value to a GPIO output port
 *
 *
 * @param[in]			- pGPIOx: Pointer to GPIO port base address
 * @param[in]			- Value: 16-bit value to write to the GPIO port
 * @param[in]			-
 *
 * @return				- None
 *
 * @Note				- None
 *********************************************************************/
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{

}

/*********************************************************************
 * @fn					- GPIO_ToggleOutputPin
 *
 * @brief				- Toggle a value to a GPIO output pin.
 *
 *
 * @param[in]			- pGPIOx: Pointer to GPIO port base address
 * @param[in]			- PinNumber: GPIO pin number
 * @param[in]			-
 *
 * @return				- None
 *
 * @Note				- None
 *********************************************************************/
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

}

/*
 * IRQ Configuration and ISR handling
 */

/*********************************************************************
 * @fn					- GPIO_IRQConfig
 *
 * @brief				- Configure the GPIO interrupt.
 *
 *
 * @param[in]			- IRQNumber: IRQ Number
 * @param[in]			- IRQPriority: Priority of the IRQ
 * @param[in]			- EnorDi: ENABLE or DISABLE the IRQ
 *
 * @return				- None
 *
 * @Note				- None
 *********************************************************************/
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{

}

/*********************************************************************
 * @fn					- GPIO_IRQHandling
 *
 * @brief				- Handles the GPIO interrupt and clears
 * 						  the corresponding EXTI pending flag
 *
 *
 * @param[in]			- PinNumber: GPIO Pin number
 * @param[in]			-
 * @param[in]			-
 *
 * @return				- None
 *
 * @Note				- None
 *********************************************************************/
void GPIO_IRQHandling(uint8_t PinNumber)
{

}

