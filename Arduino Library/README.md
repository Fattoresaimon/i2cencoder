# I2C Encoder Arduino Library
--------------------------------------------------------------------------------

## Introduction

Here you can find the library and some example for the arduino boards

## Installation

The installation is very simple:
* Dowload the file **i2cEncoderLib.cpp** and **i2cEncoderLib.h**
* Put in the folder where you have you arduino **.ino** source file
* Add the following include in the top of the source file:
``` C++
#include <Wire.h>
#include "i2cEncoderLib.h"
```


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

## Methods

### General
#### void begin( uint8_t conf)
This method write the configuration register (reg: 0x00) of the encoder.
The parameters can be concatenate in OR mode.
Possible parameters are the following:

| Parameter   | Description   |
|:-----------:|:-------------:|
| INTE_ENABLE	| Enable the interrupt output pin|
|INTE_DISABLE | Disable the interrupt output pin|
|LEDE_ENABLE	| Enable the LED output|
|LEDE_DISABLE | Disable the LED output|
|WRAP_ENABLE	| Wrap enable. When the counter value reaches the CMAX+1, restart to the CMIN and vice versa|
|WRAP_DISABLE | Wrap disable. When the counter value reaches the CMAX or CMIN, the counter stops to increasing or decreasing |
|DIRE_LEFT	  | Rotate left side to increase the value counter |
|DIRE_RIGHT	  | Rotate right side to increase the value counter |
|IPUP_DISABLE | Interrupt Pull-UP disable |
|IPUP_ENABLE  | Interrupt Pull-UP enable |
|RMOD_X2		  | Reading the encoder in X2 mode |
|RMOD_X1		  | Reading the encoder in X1 mode |
|RESET		    | Reset the encoder |

##### Examples:
```C++
  encoder.begin((INTE_ENABLE | LEDE_ENABLE | WRAP_ENABLE |  DIRE_RIGHT | IPUP_ENABLE | RMOD_X1));
```
#### bool updateStatus(void)
Read from the encoder the status register (reg:0x01) and save the value internally.
Return value is **true** in case of some event, otherwise is **false**

#### bool readStatus(uint8_t s)
Must be called after **updateStatus()**, this method us ued for check if some event occured.
Return value is **true** in case of the event occured, otherwise is **false**
Possible parameter are:

| Parameter   | Description   |
|:-----------:|:-------------:|
| E_PUSH      | The push button of the encoder is pressed |
| E_INCREMENT | Counter value is incresed          
| E_DECREMENT | Counter value is decresed         |
| E_MAXVALUE  | The maximum threshold is reached  |
| E_MINVALUE  | The minimum threshold is reached  |

##### Example:
```C++
encoder.updateStatus();

if (encoder.readStatus(E_PUSH)) {
    Serial.println("Push button pressed");
  }

if (encoder.readStatus(E_MAXVALUE)) {
    Serial.println("Maximum reached");
  }

if (encoder.readStatus(E_MINVALUE)) {
    Serial.println("Minimum reached");
  }
```

### Reading
#### uint8_t readStatus(void)
Return the status register of the encoder (reg:0x01).

#### uint8_t readLEDA(void)
Return the PWM value of the LED A (reg:0x0E).

#### uint8_t readLEDB(void)
Return the PWM value of the LED B (reg:0x0F).

#### int32_t readCounterLong(void)
Retrun the counter value in the format **int32_t**, bye reading all the 4 byte of the counter registers (reg:0x02 0x03 0x04 0x05).

#### int16_t readCounterInt(void)
Retrun the counter value in the format **int16_t**, bye reading the 2 LSB byte of the counter registers (reg:0x04 0x05).
Useful when the counter register is between the values -32768 to 32767

#### int8_t readCounterByte(void)
Retrun the counter value in the format **int8_t**, bye reading the LSB byte of the counter registers (reg:0x05).
Useful when the counter register is between the values -128 to 127

#### int32_t readMax(void)
Return the maximum threshold in fromat **int32_t**, bye reading all the 4 byte of the counter Max (reg:0x06 0x07 0x08 0x09).

#### int32_t readMin(void)
Return the minimum threshold in fromat **int32_t**, bye reading all the 4 byte of the counter Min (reg:0x0A 0x0B 0x0C 0x0D).

### Writing
#### void writeLEDA(uint8_t pwma)
Write the PWM value of the LED A (reg:0x0E). When 0 means PWM at 0%, LED off while 0xFF means PWM at 100% and LED ON
#### void writeLEDB(uint8_t pwmb)
Write the PWM value of the LED B (reg:0x0F). When 0 means PWM at 0%, LED off while 0xFF means PWM at 100% and LED ON
#### void writeCounter(int32_t counter)
Write the counter value register with a  **int32_t** (reg:0x02 0x03 0x04 0x05).
This value will be increased or decresed every time the encoder is rotated

#### void writeMax(int32_t max)
Write the counter Max register with a  **int32_t** (reg:0x06 0x07 0x08 0x09).
This value will be used as a maximum threshold of the counter value.

#### void writeMin(int32_t min)
Write the counter Min register with a  **int32_t** (reg:0x0A 0x0B 0x0C 0x0D).
This value will be used as a minimum threshold of the counter value.
