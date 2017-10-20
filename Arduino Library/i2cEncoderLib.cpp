//
//    FILE: i2cEncoderLib.cpp
// VERSION: 0.2.0
// PURPOSE: Library for the I2C Encoder with arduino
// LICENSE: GPL v3 (http://www.gnu.org/licenses/gpl.html)
//
// DATASHEET: https://github.com/Fattoresaimon/i2cencoder/blob/master/EncoderI2C%20v1.2.pdf
//
//     URL:
//
// AUTHOR:
// Simone Caron
//


#include "i2cEncoderLib.h"
#include <Wire.h>

/*********************************** Public functions *************************************/
/** Class costructor **/
i2cEncoderLib::i2cEncoderLib(uint8_t add) {
  _add = add;
}

/** Used for initialize the encoder **/
void i2cEncoderLib::begin(uint8_t conf) {

  Wire.begin();
  writeEncoder(GENERAL_CONFIG, conf);
}

/*********************************** Read functions *************************************/

/** Return true if the status of the econder changed, otherwise return false **/
bool i2cEncoderLib::updateStatus(void) {
  _stat = readStatus();
  if (_stat == 0)
    return false;
  else
    return true;
}

/** Check if a particular status match, return true is match otherwise false. Before require updateStatus() **/
bool i2cEncoderLib::readStatus(uint8_t s) {
  if ((_stat & s) == 0)
    return false;
  else
    return true;
}

/** Return the status of the encoder **/
uint8_t i2cEncoderLib::readStatus(void) {
  return (readEncoderByte(ENCODER_STATUS));
}

/** Return the PWM LED A value  **/
uint8_t i2cEncoderLib::readLEDA(void) {
  return ((uint8_t)readEncoderByte(LED_A_PWM));
}

/** Return the PWM LED B value  **/
uint8_t i2cEncoderLib::readLEDB(void) {
  return ((uint8_t)readEncoderByte(LED_B_PWM));
}

/** Return the 32 bit value of the encoder counter  **/
int32_t i2cEncoderLib::readCounterLong(void) {
  return ((int32_t)readEncoderLong(DATA_COUNTER_BYTE4));
}

/** Return the 16 bit value of the encoder counter  **/
int16_t i2cEncoderLib::readCounterInt(void) {
  return ((int16_t)readEncoderInt(DATA_COUNTER_BYTE2));
}

/** Return the 8 bit value of the encoder counter  **/
int8_t i2cEncoderLib::readCounterByte(void) {
  return ((int8_t)readEncoderByte(DATA_COUNTER_BYTE1));
}

/** Return the Maximum threshold of the counter **/
int32_t i2cEncoderLib::readMax(void) {
  return ((int32_t)readEncoderLong(DATA_MAX_BYTE4));
}

/** Return the Minimum threshold of the counter **/
int32_t i2cEncoderLib::readMin(void) {
  return ((int32_t)readEncoderLong(DATA_MIN_BYTE4));

}

/*********************************** Wite functions *************************************/
/** Write the PWM value of the led A **/
void i2cEncoderLib::writeLEDA(uint8_t pwma) {
  writeEncoder(LED_A_PWM, pwma);
}

/** Write the PWM value of the led B **/
void i2cEncoderLib::writeLEDB(uint8_t pwmb) {
  writeEncoder(LED_B_PWM, pwmb);
}

/** Write the counter value **/
void i2cEncoderLib::writeCounter(int32_t value) {
  writeEncoder(DATA_COUNTER_BYTE4, value);
}

/** Write the maximum threshold value **/
void i2cEncoderLib::writeMax(int32_t max) {
  writeEncoder(DATA_MAX_BYTE4, max);
}

/** Write the minimum threshold value **/
void i2cEncoderLib::writeMin(int32_t min) {
  writeEncoder(DATA_MIN_BYTE4, min);
}


/*********************************** Private functions *************************************/
/***************************** Read function to the encoder ********************************/

/** Read 1 byte from the encoder **/
uint8_t i2cEncoderLib::readEncoderByte(uint8_t reg) {
  byte rdata = 0xFF;

  Wire.beginTransmission(_add);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(_add, 1);
  if (Wire.available()) {
    rdata = Wire.read();
  }
  delay(5);
  return rdata;
}

/** Read 2 bytes from the encoder **/
int16_t i2cEncoderLib::readEncoderInt(uint8_t reg) {
  uint16_t rdata = 0xFFFF;

  Wire.beginTransmission(_add);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(_add, 2);
  if (Wire.available()) {
    rdata = Wire.read();
    rdata = (rdata << 8) | Wire.read();
  }
  delay(5);
  return ((int16_t)rdata);
}

/** Read 4 bytes from the encoder **/
int32_t i2cEncoderLib::readEncoderLong(uint8_t reg) {
  uint32_t rdata = 0xFFFFFFFF;

  Wire.beginTransmission(_add);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(_add, 4);
  if (Wire.available()) {
    rdata = Wire.read();
    rdata = (rdata << 8) | Wire.read();
    rdata = (rdata << 8) | Wire.read();
    rdata = (rdata << 8) | Wire.read();
  }
  delay(5);
  return ((int32_t)rdata);
}

/***************************** Write function to the encoder ********************************/
/** Send to the encoder 1 byte **/
void i2cEncoderLib::writeEncoder(uint8_t reg, uint8_t data) {

  Wire.beginTransmission(_add);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
  delay(5);

}

/** Send to the encoder 4 byte **/
void i2cEncoderLib::writeEncoder(uint8_t reg, int32_t data) {
  uint8_t e_tmp[4];

  e_tmp[3] = (uint32_t)data & 0xFF;
  e_tmp[2] = ((uint32_t)data >> 8) & 0xFF ;
  e_tmp[1] = ((uint32_t)data  >> 16)  & 0xFF ;
  e_tmp[0] = ((uint32_t)data  >> 24)  & 0xFF ;

  Wire.beginTransmission(_add);
  Wire.write(reg);
  Wire.write(e_tmp, 4);
  Wire.endTransmission();
  delay(5);

}

