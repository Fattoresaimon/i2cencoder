
#include "DataVariable.h"
#include "mcc_generated_files/mcc.h"
#include "main.h"
#include <stdbool.h>


/** I2C register according to the address flag**/
volatile uint8_t i2c_address;

/** User selected type of variable unsigned or signed   **/
volatile bool DataType = DATA_UINT;
/** Internal register **/

/** Configuratiom **/
volatile uint8_t Gconf = 0; //address 0x00
/** Status **/
volatile uint8_t Estatus; //address 0x01

/** Data Value **/
volatile union Data_v Cvalue = 0; //address 0x02 - 0x03
volatile union Data_v Cmax = 0; //address 0x04- 0x05
volatile union Data_v Cmin = 0; //address 0x06 - 0x07

/** LED Variable **/
volatile uint8_t leda = 0; //address 0x08
volatile uint8_t ledb = 0; //address 0x09

/** General configuration bit **/
volatile bool C_INTE, C_LEDE, C_WRST, C_DIRE, C_PLUP, C_RMOD, C_RST;

/**
 * @brief Function that split the configuration byte in the single bit
 */
void GeneralDataSplit(void) {

    C_INTE = Gconf & 0x01U;
    C_LEDE = (bool) (Gconf >> 1) & 0x01U;
    C_WRST = (bool) (Gconf >> 2) & 0x01U;
    C_DIRE = (bool) (Gconf >> 3) & 0x01U;
    C_PLUP = (bool) (Gconf >> 4) & 0x01U;
    C_RMOD = (bool) (Gconf >> 5) & 0x01U;
    
    C_RST = (bool) (Gconf >> 7) & 0x01U;

}

/**
 * @brief Function for update the status variable 
 * @param stat Status of the encoder from ::ENCODER_STATUS_CASE
 */
void StatusUpdate(ENCODER_STATUS_CASE stat){
    Estatus |= stat;
}

/**
 * @brief Function for clear the status of the encoder
 */
void StatusClear(void){
    Estatus =0;
}