
#include "i2c_register.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/i2c1.h"
#include "main.h"

#include "DataVariable.h"


volatile uint8_t EncoderReg = 0;
volatile bool intclear = false;

/**
 * @brief Function that set the I2C address according to the A0-A3 jumper setting
 */

void I2C1_AddressSet(void) {

    i2c_address = I2C1_SLAVE_ADDRESS;

    if (!ADD0_GetValue())
        i2c_address |= 0x01;

    if (!ADD1_GetValue())
        i2c_address |= 0x02;

    if (!ADD2_GetValue())
        i2c_address |= 0x04;

    if (!ADD3_GetValue())
        i2c_address |= 0x08;


    i2c_address = (uint8_t) (i2c_address << 1);
}

/**
 * @brief Callback for managing the I2C request from the master
 * @param i2c_bus_state 
 */
void I2C1_StatusCallback(I2C1_SLAVE_DRIVER_STATUS i2c_bus_state) {
    static uint8_t slaveWriteType = SLAVE_NORMAL_DATA;

    switch (i2c_bus_state) {
        case I2C1_SLAVE_WRITE_REQUEST:
            // the master will be sending the eeprom address next
            slaveWriteType = SLAVE_DATA_ADDRESS;
            break;


        case I2C1_SLAVE_WRITE_COMPLETED:

            switch (slaveWriteType) {
                case SLAVE_DATA_ADDRESS:
                    EncoderReg = I2C1_slaveWriteData;
                    break;

                case SLAVE_NORMAL_DATA:
                default:
                    RegisterWrite(EncoderReg, I2C1_slaveWriteData);
                    EncoderReg++;
                    break;

            } // end switch(slaveWriteType)

            slaveWriteType = SLAVE_NORMAL_DATA;
            break;

        case I2C1_SLAVE_READ_REQUEST:
            SSP1BUF = RegisterRead(EncoderReg);
            EncoderReg++;
            break;

        case I2C1_SLAVE_READ_COMPLETED:
            if (intclear == true) {
                StatusClear();
                ClearInterrupt();
                intclear = false;
            }
            break;

        default:
            break;

    } // end switch(i2c_bus_state)

}

/**
 * @brief Function that write inside on the Encoder register 
 * @param add Address of the internal register
 * @param data Data to be written inside of the register
 */
void RegisterWrite(uint8_t add, uint8_t data) {

    switch (add) {
        case GENERAL_CONFIG:
            Gconf = data;
            GeneralDataSplit();
            GeneralDataSet();
            break;


        case DATA_COUNTER_BYTE4:
            Cvalue.bval[BYTE4] = data;

            break;

        case DATA_COUNTER_BYTE3:
            Cvalue.bval[BYTE3] = data;
            break;
        case DATA_COUNTER_BYTE2:
            Cvalue.bval[BYTE2] = data;
            break;
        case DATA_COUNTER_BYTE1:
            Cvalue.bval[BYTE1] = data;
            if (Cvalue.val > Cmax.val)
                Cvalue.val = Cmax.val;
            else {
                if (Cvalue.val < Cmin.val)
                    Cvalue.val = Cmin.val;
            }
            break;

            /*** Max Value ***/
        case DATA_MAX_BYTE4:
            Cmax.bval[BYTE4] = data;

            break;

        case DATA_MAX_BYTE3:
            Cmax.bval[BYTE3] = data;
            break;

        case DATA_MAX_BYTE2:
            Cmax.bval[BYTE2] = data;
            break;

        case DATA_MAX_BYTE1:
            Cmax.bval[BYTE1] = data;
            if (Cvalue.val > Cmax.val)
                Cvalue.val = Cmax.val;
            break;

            /*** Min Value ***/
        case DATA_MIN_BYTE4:
            Cmin.bval[BYTE4] = data;

            break;

        case DATA_MIN_BYTE3:
            Cmin.bval[BYTE3] = data;
            break;

        case DATA_MIN_BYTE2:
            Cmin.bval[BYTE2] = data;
            break;

        case DATA_MIN_BYTE1:
            Cmin.bval[BYTE1] = data;
            if (Cvalue.val < Cmin.val)
                Cvalue.val = Cmin.val;
            break;

        case LED_A_PWM:
            leda = data;
            PWM3_LoadDutyValue(leda);
            break;

        case LED_B_PWM:
            ledb = data;
            PWM4_LoadDutyValue(ledb);
            break;

    }
}

/**
 * @brief Function called when there is a Read request from the i2c master
 * @param add Address of the internal register
 * @return Value of the internal register, 0 in case of invalid register
 */

uint8_t RegisterRead(uint8_t add) {
    uint8_t return_value = 0;

    switch (add) {
        case GENERAL_CONFIG:
            return_value = Gconf;
            break;

        case ENCODER_STATUS:
            return_value = Estatus;
            intclear = true;
            break;

            /*** Data Value ***/
        case DATA_COUNTER_BYTE4:
            return_value = Cvalue.bval[BYTE4];
            intclear = true;
            break;
        case DATA_COUNTER_BYTE3:
            return_value = Cvalue.bval[BYTE3];
            intclear = true;
            break;
        case DATA_COUNTER_BYTE2:
            return_value = Cvalue.bval[BYTE2];
            intclear = true;
            break;
        case DATA_COUNTER_BYTE1:
            return_value = Cvalue.bval[BYTE1];
            intclear = true;
            break;

            /*** Max Value ***/
        case DATA_MAX_BYTE4:
            return_value = Cmax.bval[BYTE4];
            break;

        case DATA_MAX_BYTE3:
            return_value = Cmax.bval[BYTE3];
            break;

        case DATA_MAX_BYTE2:
            return_value = Cmax.bval[BYTE2];
            break;

        case DATA_MAX_BYTE1:
            return_value = Cmax.bval[BYTE1];
            break;

            /*** Min Value ***/
        case DATA_MIN_BYTE4:
            return_value = Cmin.bval[BYTE4];
            break;

        case DATA_MIN_BYTE3:
            return_value = Cmin.bval[BYTE3];
            break;

        case DATA_MIN_BYTE2:
            return_value = Cmin.bval[BYTE2];
            break;

        case DATA_MIN_BYTE1:
            return_value = Cmin.bval[BYTE1];
            break;

        case LED_A_PWM:
            return_value = leda;
            break;

        case LED_B_PWM:
            return_value = ledb;
            break;

        default:
            return_value = 0;
            break;

    }



    return return_value;
}

/**
 * @brief Function that execute the command according on the configuration register
 */
void GeneralDataSet(void) {

    if (C_LEDE == true) {
        PWM3_Initialize();
        PWM4_Initialize();
        PWM3_LoadDutyValue(leda);
        PWM4_LoadDutyValue(ledb);
    } else {
        PWM3_LoadDutyValue(0);
        PWM4_LoadDutyValue(0);
        PWM3CON = 0x10;
        PWM4CON = 0x10;
    }

    if (C_DIRE == true) {
        UNLOCK_PPS;
        CLCIN1PPSbits.CLCIN1PPS = 0x13; //RC3->CLC3:CLCIN0;
        CLCIN0PPSbits.CLCIN0PPS = 0x14; //RC4->CLC3:CLCIN1;
        LOCK_PPS;
    } else {
        UNLOCK_PPS;
        CLCIN1PPSbits.CLCIN1PPS = 0x14; //RC4->CLC3:CLCIN1;
        CLCIN0PPSbits.CLCIN0PPS = 0x13; //RC3->CLC3:CLCIN0;
        LOCK_PPS;
    }

    if (C_PLUP == true) {
        INT_ResetPullup();
        INT_SetHigh();
    } else {
        INT_SetPullup();
        INT_SetHigh();

    }

    if (C_RMOD == true) {
        PIR5bits.CLC1IF = 0;
        PIE5bits.CLC1IE = 0;
        CLC1CON = 0x9D;
        PIE5bits.CLC1IE = 1;

        PIR5bits.CLC2IF = 0;
        PIE5bits.CLC2IE = 0;
        CLC2CON = 0x9D;
        PIE5bits.CLC2IE = 1;

    } else {
        PIR5bits.CLC1IF = 0;
        PIE5bits.CLC1IE = 0;
        CLC1CON = 0x95;
        PIE5bits.CLC1IE = 1;

        PIR5bits.CLC2IF = 0;
        PIE5bits.CLC2IE = 0;
        CLC2CON = 0x95;
        PIE5bits.CLC2IE = 1;
    }

    if (C_RST == true) {
        RESET();
    }


}