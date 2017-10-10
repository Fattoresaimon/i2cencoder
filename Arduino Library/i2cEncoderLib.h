//
//    FILE: i2cEncoderLib.h
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

#ifndef I2CENCODERLIB_H
#define I2CENCODERLIB_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif



/*Encoder register definition*/
#define		GENERAL_CONFIG  0x00
#define		ENCODER_STATUS 0x01
#define		DATA_COUNTER_BYTE4  0x02
#define		DATA_COUNTER_BYTE3  0x03
#define		DATA_COUNTER_BYTE2  0x04
#define		DATA_COUNTER_BYTE1  0x05
#define		DATA_MAX_BYTE4  0x06
#define		DATA_MAX_BYTE3 0x07
#define		DATA_MAX_BYTE2  0x08
#define		DATA_MAX_BYTE1 0x09
#define		DATA_MIN_BYTE4 0x0A
#define		DATA_MIN_BYTE3 0x0B
#define		DATA_MIN_BYTE2 0x0C
#define		DATA_MIN_BYTE1 0x0D
#define		LED_A_PWM 0x0E
#define		LED_B_PWM 0x0F

/* Encoder configuration bit */
#define INTE_ENABLE		0x01
#define INTE_DISABLE	0x00

#define LEDE_ENABLE		0x02
#define LEDE_DISABLE		0x00

#define WRAP_ENABLE		0x04
#define WRAP_DISABLE	0x00


#define DIRE_LEFT		0x08
#define DIRE_RIGHT		0x00

#define IPUP_DISABLE  0x10
#define IPUP_ENABLE 	0x00


#define RMOD_X2			0x20
#define RMOD_X1			0x00

#define RESET			0x80

/* Encoder status bit    */
#define E_PUSH 0x01
#define E_INCREMENT 0x02
#define E_DECREMENT 0x04
#define E_MAXVALUE 0x08
#define E_MINVALUE 0x10



class i2cEncoderLib
{
  public:
    i2cEncoderLib(uint8_t add);
    void begin( uint8_t conf);
    bool updateStatus(void);
    bool readStatus(uint8_t s);
    
    uint8_t readStatus(void);
    uint8_t readLEDA(void);
    uint8_t readLEDB(void);
    int32_t readCounterLong(void);
    int16_t readCounterInt(void);
    int8_t readCounterByte(void);
    int32_t readMax(void);
    int32_t readMin(void);

    void writeLEDA(uint8_t pwma);
    void writeLEDB(uint8_t pwmb);
    void writeCounter(int32_t counter);
    void writeMax(int32_t max);
    void writeMin(int32_t min);

  private:
    uint8_t _add = 0x30;
    uint8_t _stat = 0x00;
    uint8_t readEncoderByte(uint8_t reg);
    int16_t readEncoderInt(uint8_t reg);
    int32_t readEncoderLong(uint8_t reg);
    void writeEncoder(uint8_t reg, uint8_t data);
    void writeEncoder(uint8_t reg, int32_t data);

};




#endif
