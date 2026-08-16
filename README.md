# STM32G491 Drivers

A collection of custom peripheral drivers for the **STM32G491** microcontroller.

The main goal of this project is to learn STM32 embedded programming and understand how the microcontroller peripherals work at the register level.

## Supported Drivers

* **GPIO** — General Purpose Input/Output
* **UART** — Universal Asynchronous Receiver/Transmitter
* **SPI** — Serial Peripheral Interface
* **I2C** — Inter-Integrated Circuit

## Microcontroller

**STM32G491**

* ARM Cortex-M4
* STMicroelectronics STM32G4 series
* Tested with the **NUCLEO-G491RE** development board

## Project Structure

```text
stm32g4xx_drivers/
├── drivers
|   ├── Inc/
|   |    ├── stm32g491xx.h
│   |    ├── stm32g491xx_gpio_driver.h
│   |    ├── stm32g491xx_uart_driver.h
│   |    ├── stm32g491xx_spi_driver.h
│   |    └── stm32g491xx_i2c_driver.h
│   |
|   ├── Src/
│        ├── stm32g491xx_gpio_driver.c
│        ├── stm32g491xx_uart_driver.c
│        ├── stm32g491xx_spi_driver.c
│        └── stm32g491xx_i2c_driver.c
├── Inc/
│   ├──
│
│   
│   
│
├── Src/
│   ├── main.c
│   ├── syscalls.c
│   ├── system.c
│   
│
└── README.md
```

## How to Start
Include stm32g491xx.h file in project:

For CubeIDE:

Project-> Properties -> C/C++ Build -> Settings -> MCU GCC COMPILER -> Include Paths: in Include Paths(-I) add -> File system... and choose: \\stm32g4xx_drivers\drivers\Inc\stm32g491xx.h -> Open -> Ok -> Apply and Close 

Try to build project to see if there are no errors.
## GPIO

The GPIO driver provides:

* GPIO pin initialization
* PinSpeed
* Reading GPIO pin state
* Setting and clearing GPIO pins
* Pull-up and pull-down configuration
* GPIO mode configuration
* GPIO Interrupt mode

## UART

The UART driver provides basic serial communication.

Planned features:

* UART initialization
* Sending a single character
* Sending data buffers
* Receiving data
* Status flag handling

## SPI

The SPI driver is designed for communication with SPI peripherals.

Planned features:

* SPI initialization
* Data transmission
* Data reception
* Full-duplex communication
* Chip Select handling

## I2C

The I2C driver is designed for communication with I2C peripherals such as:

* Sensors
* Displays
* EEPROM memories
* GPIO expanders
* Other I2C devices

Planned features:

* I2C initialization
* Device scanning
* Data transmission
* Data reception
* Device addressing

## Project Goals

The drivers are developed primarily for **educational purposes**.

The main objective is to understand how STM32 peripherals work by interacting directly with the microcontroller registers instead of relying exclusively on high-level HAL functions.

## Development Environment

* **CachyOS**
* **STM32CubeIDE**
* **ARM GCC**
* **ST-LINK**
* **Git**

## Status

| Driver | Status         |
| ------ | -------------- |
| GPIO   | 🚧 In progress |
| UART   | 🚧 In progress |
| SPI    | 🚧 In progress |
| I2C    | 🚧 In progress |

## Author

**Paweł Smusz**

GitHub: https://github.com/pebl91
