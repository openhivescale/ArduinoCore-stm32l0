/*
 * Copyright (c) 2017-2018 Thomas Roell.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal with the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimers.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimers in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of Thomas Roell, nor the names of its contributors
 *     may be used to endorse or promote products derived from this Software
 *     without specific prior written permission.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * WITH THE SOFTWARE.
 *
 * Pierre Beck  04/03/19  Support for SNOC BRKABZ Based on Grasshopper-L082CZ
 * https://yadom.fr/kit-carte-breakout-brkabz01.html
 */

#ifndef _VARIANT_SNOC_BRKABZ_STM32L082CZ_
#define _VARIANT_SNOC_BRKABZ_STM32L082CZ_

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

#define STM32L0_CONFIG_LSECLK             32768
#define STM32L0_CONFIG_HSECLK             0
#define STM32L0_CONFIG_SYSOPT             0

#define STM32L0_CONFIG_PIN_VBUS           STM32L0_GPIO_PIN_NONE
#define STM32L0_CONFIG_ANTENNA_GAIN       -2.5f


#define USBCON

/** Master clock frequency */
#define VARIANT_MCK                       F_CPU

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
#include "USBAPI.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (31u)
#define NUM_DIGITAL_PINS     (18u)
#define NUM_ANALOG_INPUTS    (3u)
#define NUM_ANALOG_OUTPUTS   (1u)

// LEDs
#define PIN_LED_27           (27u)

#define PIN_LED              PIN_LED_27
#define LED_BUILTIN          PIN_LED_27

/*
 * Analog pins
 */
#define PIN_A0               (12ul)
#define PIN_A1               (11ul)
#define PIN_A2               (10ul)
#define PIN_DAC0             (10ul)


static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t DAC0 = PIN_DAC0;

#define ADC_RESOLUTION          12
#define DAC_RESOLUTION          12

/*
 * Serial interfaces
 */

#define SERIAL_INTERFACES_COUNT 2

#define PIN_SERIAL1_RX       (7ul)
#define PIN_SERIAL1_TX       (8ul)


/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO         (4u)
#define PIN_SPI_MOSI         (3u)
#define PIN_SPI_SCK          (5u)

static const uint8_t SS   = 6;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (16u)
#define PIN_WIRE_SCL         (15u)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/*
 * USB Interface
 */
#define PIN_USB_DM           (28ul)
#define PIN_USB_DP           (29ul)
#define PIN_USB_VBUS         (30ul)

#define PWM_INSTANCE_COUNT    1

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern CDC  SerialUSB;
extern Uart Serial1;
#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
#define SERIAL_PORT_HARDWARE1       Serial1
#define SERIAL_PORT_HARDWARE_OPEN1  Serial1

// Alias Serial to SerialUSB
#define Serial                      SerialUSB

#endif /* _VARIANT_SNOC_BRKABZ_STM32L082CZ_ */

