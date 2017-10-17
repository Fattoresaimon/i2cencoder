# I2C Encoder Arduino Library
--------------------------------------------------------------------------------

## Introduction

Here yuo can find the library and some example for the arduino boards

## Installation 

The installation is very simple:
* Dowload the file **i2cEncoderLib.cpp** and **i2cEncoderLib.h**
* Put in the folder where you have you arduino **.ino** source file
* Add **#include <Wire.h>** and **#include "i2cEncoderLib.h"** on the top of your arduino source file

## Initialization of the class

The library make avaible the class **i2cEncoderLib**
For initialize the library you have to declare an istance of the class **i2cEncoderLib** for each encoders.
For example:

``` C++
i2cEncoderLib encoder(0x30);
```
Declaration of one encoder with the address 0x30.

```C++
i2cEncoderLib encoder1(0x30);
i2cEncoderLib encoder2(0x32);
```
Declaration of tow encoders with the address 0x30 and 0x34 in tow separated variable.

```C++
 i2cEncoderLib encoder[2] = { i2cEncoderLib(0x30), i2cEncoderLib(0x34)};
```
Declaration of an array of tow encoders with the address 0x30 and 0x34.

## Avaiable methods

### General
#### void begin( uint8_t conf)
This method write the configuration register (add: 0x00) of the encoder.
Possible parameter are the following:

| Parameter     | Description   | 
| ------------- |:-------------:| 
INTE_ENABLE	    | Enable the interrupt output pin
INTE_DISABLE    | Disable the interrupt output pin
LEDE_ENABLE	    | Enable the LED output
LEDE_DISABLE    | Disable the LED output
WRAP_ENABLE	    | Wrap enable. When the counter value reaches the CMAX+1, restart to the CMIN and vice versa
WRAP_DISABLE    | Wrap disable. When the counter value reaches the CMAX or CMIN, the counter stops to increasing or
decreasing  
DIRE_LEFT	      |
DIRE_RIGHT	     |
IPUP_DISABLE    |
IPUP_ENABLE     |
RMOD_X2		       |
RMOD_X1		       |
RESET		         |



#### bool updateStatus(void)
#### bool readStatus(uint8_t s)
   
### Reading
#### uint8_t readStatus(void)
#### uint8_t readLEDA(void)
#### uint8_t readLEDB(void)
#### int32_t readCounterLong(void)
#### int16_t readCounterInt(void)
#### int8_t readCounterByte(void)
#### int32_t readMax(void)
#### int32_t readMin(void)

### Writing
#### void writeLEDA(uint8_t pwma)
#### void writeLEDB(uint8_t pwmb)
#### void writeCounter(int32_t counter)
#### void writeMax(int32_t max)
#### void writeMin(int32_t min)



