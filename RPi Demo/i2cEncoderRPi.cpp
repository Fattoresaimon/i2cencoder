//
//    FILE: i2cEncoderRPi.h
// VERSION: 0.1..
// PURPOSE: Libreary for the i2c encoder board with arduinp
// LICENSE: GPL v3 (http://www.gnu.org/licenses/gpl.html)
//
// DATASHEET:
//
//     URL:
//
// AUTHOR:
// Simone Caron
//

#include "i2cEncoderRPi.h"
#include <wiringPiI2C.h>
#include <stdint.h>

/** Used for initialize the encoder **/
void I2CEncWriteConf(int32_t enc, uint8_t conf) {

	wiringPiI2CWriteReg8(enc, GENERAL_CONFIG, conf);

}

/*********************************** Read functions *************************************/

/** Return the status of the encoder **/
uint8_t I2CEncReadStatus(int32_t enc) {
	return (wiringPiI2CReadReg8(enc, ENCODER_STATUS));
}

/** Return the PWM LED A value  **/
uint8_t I2CEncReadLEDA(int32_t enc) {
	return (wiringPiI2CReadReg8(enc, LED_A_PWM));

}

/** Return the PWM LED B value  **/
uint8_t I2CEncReadLEDB(int32_t enc) {
	return (wiringPiI2CReadReg8(enc, LED_B_PWM));

}

/** Return the 32 bit value of the encoder counter  **/
int32_t I2CEncReadCounterLong(int32_t enc) {
	uint32_t temp;

	temp = wiringPiI2CReadReg8(enc, DATA_COUNTER_BYTE4);
	temp = (temp << 8) | wiringPiI2CReadReg8(enc, DATA_COUNTER_BYTE3);
	temp = (temp << 8) | wiringPiI2CReadReg8(enc, DATA_COUNTER_BYTE2);
	temp = (temp << 8) | wiringPiI2CReadReg8(enc, DATA_COUNTER_BYTE1);
	return (temp);
}

/** Return the 16 bit value of the encoder counter  **/
int16_t I2CEncReadCounterInt(int32_t enc) {
	uint16_t temp;

	temp = wiringPiI2CReadReg8(enc, DATA_COUNTER_BYTE2);
	temp = (temp << 8) | wiringPiI2CReadReg8(enc, DATA_COUNTER_BYTE1);
	return (temp);
}

/** Return the 8 bit value of the encoder counter  **/
int8_t I2CEncReadCounterByte(int32_t enc) {
	return (wiringPiI2CReadReg8(enc, DATA_COUNTER_BYTE1));
}

/** Return the Maximum threshold of the counter **/
int32_t I2CEncReadMax(int32_t enc) {
	uint32_t temp;

	temp = wiringPiI2CReadReg8(enc, DATA_MAX_BYTE4);
	temp = (temp << 8) | wiringPiI2CReadReg8(enc, DATA_MAX_BYTE3);
	temp = (temp << 8) | wiringPiI2CReadReg8(enc, DATA_MAX_BYTE2);
	temp = (temp << 8) | wiringPiI2CReadReg8(enc, DATA_MAX_BYTE1);
	return (temp);

}

/** Return the Minimum threshold of the counter **/
int32_t I2CEncReadMin(int32_t enc) {
	uint32_t temp;

	temp = wiringPiI2CReadReg8(enc, DATA_MIN_BYTE4);
	temp = (temp << 8) | wiringPiI2CReadReg8(enc, DATA_MIN_BYTE3);
	temp = (temp << 8) | wiringPiI2CReadReg8(enc, DATA_MIN_BYTE2);
	temp = (temp << 8) | wiringPiI2CReadReg8(enc, DATA_MIN_BYTE1);
	return (temp);

}

/*********************************** Wite functions *************************************/
/** Write the PWM value of the led A **/
void I2CEncWriteLEDA(int32_t enc, uint8_t pwma) {

	wiringPiI2CWriteReg8(enc, LED_A_PWM, pwma);
}

/** Write the PWM value of the led B **/
void I2CEncWriteLEDB(int32_t enc, uint8_t pwmb) {
	wiringPiI2CWriteReg8(enc, LED_B_PWM, pwmb);
}

/** Write the counter value **/
void I2CEncWriteCounter(int32_t enc, int32_t counter) {

	wiringPiI2CWriteReg8(enc, DATA_COUNTER_BYTE1, (counter & 0xFF));
	wiringPiI2CWriteReg8(enc, DATA_COUNTER_BYTE2, ((counter >> 8) & 0xFF));
	wiringPiI2CWriteReg8(enc, DATA_COUNTER_BYTE3, ((counter >> 16) & 0xFF));
	wiringPiI2CWriteReg8(enc, DATA_COUNTER_BYTE4, ((counter >> 24) & 0xFF));

}

/** Write the maximum threshold value **/
void I2CEncWriteMax(int32_t enc, int32_t max) {
	wiringPiI2CWriteReg8(enc, DATA_MAX_BYTE1, (max & 0xFF));
	wiringPiI2CWriteReg8(enc, DATA_MAX_BYTE2, ((max >> 8) & 0xFF));
	wiringPiI2CWriteReg8(enc, DATA_MAX_BYTE3, ((max >> 16) & 0xFF));
	wiringPiI2CWriteReg8(enc, DATA_MAX_BYTE4, ((max >> 24) & 0xFF));

}

/** Write the minimum threshold value **/
void I2CEncWriteMin(int32_t enc, int32_t min) {
	wiringPiI2CWriteReg8(enc, DATA_MIN_BYTE1, (min & 0xFF));
	wiringPiI2CWriteReg8(enc, DATA_MIN_BYTE2, ((min >> 8) & 0xFF));
	wiringPiI2CWriteReg8(enc, DATA_MIN_BYTE3, ((min >> 16) & 0xFF));
	wiringPiI2CWriteReg8(enc, DATA_MIN_BYTE4, ((min >> 24) & 0xFF));
}

