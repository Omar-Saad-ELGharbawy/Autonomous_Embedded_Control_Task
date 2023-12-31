/* *****************************************************************************
 * Module: GPIO
 *
 * File Name: Gpio.h
 *
 * Description: Header file for the STM32 GPIO driver
 *
 * Created on: Apr 16, 2023
 * Author: Omar Saad
 *
 *******************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

#include "../../Libraries/Std_Types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define NUM_OF_PORTS           6
#define NUM_OF_PINS_PER_PORT   16


/*PortName*/
#define GPIO_A  0
#define GPIO_B  1
#define GPIO_C  2
#define GPIO_D  3
#define GPIO_E  4
#define GPIO_H  5


/*PinMode*/
#define GPIO_INPUT  0x00
#define GPIO_OUTPUT 0x01
#define GPIO_AF     0x02
#define GPIO_ANALOG 0x03

/*DefaultState*/
#define GPIO_PUSH_PULL  0x00
#define GPIO_OPEN_DRAIN 0x01

/*InputMode*/
#define GPIO_NO_PULL  0x00
#define GPIO_PULL_UP  0x01
#define GPIO_PULL_DOWN 0x02
//#define RESERVED 0x11
#define NOT_INPUT 0x00

/*Data*/
#define LOW  0x00
#define HIGH 0x01

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
    * Function : Gpio_Init
    * Input : void
    * Output : void
    * Description :
    * Initialize GPIO Driver
    * Enable Clock for used GPIO PORTs using Static Configurationin RCC Register .
    */
void Gpio_Init(void);

/*
 * Function : Gpio_ConfigPin
 * Input : PortName, PinNum, PinMode, DefaultState, InputMode
 * Output : void 
 * Description :
 * Configure Pin
 * 1- Setting the Direction of the required pin : input/output/AF/Analog in Moder Register .
 * 2- Configure Output type of the required pin : push-pull / open-drain in OTYPER Register.
 * 3- Configure Input mode of pull up,pull down or neither in PUPDR Register
 *  If the input port number or pin number are not correct, The function will not handle the request.
 */
void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState, uint8 InputMode);

/*
 * Function : Gpio_WritePinValue
 * Input : PortName, PinNum, Data
 * Output : uint8 0 or 1
 * Description :
 * Write Pin
 * 1- Write output data in ODR Register  .
 * If initialized configuration of the requested pin  didn’t match the write request needs, it returns NOK and didn’t perform the action.
 */
uint8 Gpio_WritePinValue(uint8 PortName, uint8 PinNum, uint8 Data);


/*
 * Function : Gpio_ReadPinState
 * Input : PortName, PinNum, Data
 * Output : uint8 0 or 1
 * Description :
 * Read Pin
 * 1- Read input data from IDR Registe and return it  .
 */
uint8 Gpio_ReadPinState(uint8 PortName, uint8 PinNum);


#endif /* GPIO_H_ */
