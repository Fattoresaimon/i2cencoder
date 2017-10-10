/* 
 * File:   DataVariable.h
 * Author: Saimon
 *
 * Created on 11 settembre 2017, 21.20
 */

#ifndef DATAVARIABLE_H
#define	DATAVARIABLE_H

#include <stdint.h>
#include <stdbool.h>

extern volatile uint8_t i2c_address;

extern volatile uint8_t I2C1_slaveWriteData;

extern volatile bool DataType;
#define DATA_INT 1
#define DATA_UINT 0
/** Internal register **/
/** Configuratiom **/
extern volatile uint8_t Gconf;
extern volatile uint8_t Fconf;

/** Status **/
extern volatile uint8_t Estatus;

/** Data Value **/
extern volatile union Data_v Cvalue;
extern volatile union Data_v Cmax;
extern volatile union Data_v Cmin;

/** LED Variable **/
extern volatile uint8_t leda;
extern volatile uint8_t ledb;

union Data_v {
    int32_t val;
    uint8_t bval[4];
};

extern volatile bool C_INTE, C_LEDE, C_WRST, C_DIRE, C_PLUP, C_RMOD, C_RST;

typedef enum {
    S_PUSH = 0x01,
    S_RINC = 0x02,
    S_RDEC = 0x04,
    S_RMAX = 0x08,
    S_RMIN = 0x10,
} ENCODER_STATUS_CASE;

void GeneralDataSplit(void);
void StatusUpdate(ENCODER_STATUS_CASE stat);
void StatusClear(void);


#endif	/* DATAVARIABLE_H */