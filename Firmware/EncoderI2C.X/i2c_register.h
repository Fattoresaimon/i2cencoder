/* 
 * File:   i2c_register.h
 * Author: Saimon
 *
 * Created on September 9, 2017, 6:08 PM
 */


#ifndef I2C_REGISTER_H
#define	I2C_REGISTER_H

#include <stdint.h>

/** Default I2C address **/
#define I2C1_SLAVE_ADDRESS 0x30 

/** Internal i2C address definition **/
typedef enum {
    GENERAL_CONFIG = 0x00,
    ENCODER_STATUS = 0x01,
    DATA_COUNTER_BYTE4 = 0x02,
    DATA_COUNTER_BYTE3 = 0x03,
    DATA_COUNTER_BYTE2 = 0x04,
    DATA_COUNTER_BYTE1 = 0x05,
    DATA_MAX_BYTE4 = 0x06,
    DATA_MAX_BYTE3 = 0x07,
    DATA_MAX_BYTE2 = 0x08,
    DATA_MAX_BYTE1 = 0x09,
    DATA_MIN_BYTE4 = 0x0A,
    DATA_MIN_BYTE3 = 0x0B,
    DATA_MIN_BYTE2 = 0x0C,
    DATA_MIN_BYTE1 = 0x0D,
    LED_A_PWM = 0x0E,
    LED_B_PWM = 0x0F,
} I2C1_REGISTER;

/** MSB or LSB order in 16bit variable **/
#define BYTE1 0
#define BYTE2 1
#define BYTE3 2
#define BYTE4 3

typedef enum {
    I2C1_SLAVE_WRITE_REQUEST,
    I2C1_SLAVE_READ_REQUEST,
    I2C1_SLAVE_WRITE_COMPLETED,
    I2C1_SLAVE_READ_COMPLETED,
} I2C1_SLAVE_DRIVER_STATUS;

typedef enum {
    SLAVE_NORMAL_DATA,
    SLAVE_DATA_ADDRESS,
} SLAVE_WRITE_DATA_TYPE;


void I2C1_AddressSet(void);
void I2C1_StatusCallback(I2C1_SLAVE_DRIVER_STATUS i2c_bus_state);
void RegisterWrite(uint8_t add, uint8_t data);
uint8_t RegisterRead(uint8_t add);
void GeneralDataSet(void);

#endif	/* I2C_REGISTER_H */

