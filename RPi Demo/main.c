/******************************************************************************
 i2ctest.cpp
 Raspberry Pi I2C interface demo
 Byron Jacquot @ SparkFun Electronics>
 4/2/2014
 https://github.com/sparkfun/Pi_Wedge

 A brief demonstration of the Raspberry Pi I2C interface, using the SparkFun
 Pi Wedge breakout board.

 Resources:

 This example makes use of the Wiring Pi library, which streamlines the interface
 the the I/O pins on the Raspberry Pi, providing an API that is similar to the
 Arduino.  You can learn about installing Wiring Pi here:
 http://wiringpi.com/download-and-install/

 The I2C API is documented here:
 https://projects.drogon.net/raspberry-pi/wiringpi/i2c-library/

 The init call returns a standard file descriptor.  More detailed configuration
 of the interface can be performed using ioctl calls on that descriptor.
 See the wiringPi I2C implementation (wiringPi/wiringPiI2C.c) for some examples.
 Parameters configurable with ioctl are documented here:
 http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/tree/Documentation/i2c/dev-interface

 Hardware connections:

 This file interfaces with the SparkFun MCP4725 breakout board:
 https://www.sparkfun.com/products/8736

 The board was connected as follows:
 (Raspberry Pi)(MCP4725)
 GND  -> GND
 3.3V -> Vcc
 SCL  -> SCL
 SDA  -> SDA

 An oscilloscope probe was connected to the analog output pin of the MCP4725.

 To build this file, I use the command:
 >  g++ i2cEncoderRPi.cpp main.c -lwiringPi

 Then to run it, first the I2C kernel module needs to be loaded.  This can be
 done using the GPIO utility.
 > gpio load i2c 400
 > ./a.out

 This will run the MCP through its output range several times.  A rising
 sawtooth will be seen on the analog output.

 Development environment specifics:
 Tested on Raspberry Pi V2 hardware, running Raspbian.
 Building with GCC 4.6.3 (Debian 4.6.3-14+rpi1)

 This code is beerware; if you see me (or any other SparkFun employee) at the
 local, and you've found our code helpful, please buy us a round!

 Distributed as-is; no warranty is given.
 ******************************************************************************/

#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include "i2cEncoderRPi.h"
#include <stdint.h>
#include <stdio.h>

using namespace std;

int main() {
	int enc[5], i;
	float value;

	uint8_t status;
	wiringPiSetup(); // Initializes wiringPi using wiringPi's simlified number system.

	wiringPiSetupSys();
	wiringPiSetupGpio(); // Initializes wiringPi using the Broadcom GPIO pin numbers
	pinMode(4, INPUT);
	pullUpDnControl(4, PUD_UP);
	enc[0] = wiringPiI2CSetup(0x30);
	enc[1] = wiringPiI2CSetup(0x31);
	enc[2] = wiringPiI2CSetup(0x32);
	enc[3] = wiringPiI2CSetup(0x33);
	enc[4] = wiringPiI2CSetup(0x34);

	for (i = 0; i < 5; i++) {
		I2CEncWriteConf(enc[i], (INTE_ENABLE | LEDE_ENABLE | WRAP_DISABLE | DIRE_RIGHT | IPUP_ENABLE | RMOD_X1));
		I2CEncWriteMax(enc[i], 20);
		I2CEncWriteMin(enc[i], 0);
		I2CEncWriteCounter(enc[i], 0);
		I2CEncWriteLEDA(enc[i], 0);
		I2CEncWriteLEDB(enc[i], 0);
	}

	for (i = 0; i < 5; i++) {
		I2CEncWriteLEDB(enc[i], 0xFF);
		delay(100);
		I2CEncWriteLEDB(enc[i], 0x00);
	}

	for (; i >= 0; i--) {
		I2CEncWriteLEDA(enc[i], 0xFF);
		delay(100);
		I2CEncWriteLEDA(enc[i], 0x00);
	}

	for (i = 0; i < 5; i++) {
		I2CEncWriteLEDB(enc[i], 0xFF);
		delay(100);
		I2CEncWriteLEDB(enc[i], 0x00);
	}

	for (; i >= 0; i--) {
		I2CEncWriteLEDA(enc[i], 0xFF);
		delay(100);
		I2CEncWriteLEDA(enc[i], 0x00);
	}
	printf("Encoder Test Start!!\n");
	while (1) {
		if (!digitalRead(4)) {

			for (i = 0; i < 5; i++) {
				status = I2CEncReadStatus(enc[i]);
				if (status != 0) {
					//delay(50);
					value =(float) I2CEncReadCounterByte(enc[i]);
					value = value * 12.75;
					printf("LED n.%d: %.0f%\n", i, (value/255.0)*100.0);
					I2CEncWriteLEDA(enc[i], value);
					I2CEncWriteLEDB(enc[i], 0);
					if ((status & E_PUSH) != 0) {
						I2CEncWriteLEDB(enc[i], value);
						I2CEncWriteLEDA(enc[i], 0);
					}

				}
			}
		}
	}
}
