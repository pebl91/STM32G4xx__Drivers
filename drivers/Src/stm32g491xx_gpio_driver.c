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
 * @param[in]			- Base address of the GPIO peripheral
 * @param[in]			- ENABLE or DISABLE macros
 * @param[in]			-
 *
 * @return				- None
 *
 * @Note				- None
 *********************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{

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

