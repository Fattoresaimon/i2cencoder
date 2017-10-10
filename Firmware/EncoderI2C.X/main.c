/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
        Device            :  PIC16F15323
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

#include "mcc_generated_files/mcc.h"
#include "i2c_register.h"
#include "main.h"
#include "DataVariable.h"


volatile uint8_t debounce = 0;

/**
 * @brief function that is called on one direction of the encoder
 */
void CLC_1_Interrupt(void) {

    if (debounce > 0)
        return;


    debounce = DEBOUNCE_CNT;

    Cvalue.val++;
    StatusUpdate(S_RINC);
    if (Cvalue.val > Cmax.val) {
        StatusUpdate(S_RMAX);
        if (C_WRST == true) {
            Cvalue.val = Cmin.val;
        } else {
            Cvalue.val = Cmax.val;
        }
    }

    SetInterrupt();
    debounce = DEBOUNCE_CNT;
}

/**
 * @brief function that is called on the other direction of the encoder
 */

void CLC_2_Interrupt(void) {

    if (debounce > 0)
        return;

    Cvalue.val--;
    StatusUpdate(S_RDEC);
    if (Cvalue.val < Cmin.val) {
        StatusUpdate(S_RMIN);
        if (C_WRST == true) {
            Cvalue.val = Cmax.val;
        } else {
            Cvalue.val = Cmin.val;
        }
    }

    SetInterrupt();
    debounce = DEBOUNCE_CNT;
}

/**
 * @brief Function for set the output interrupt pin
 */
void SetInterrupt(void) {
    if (C_INTE == true) {
        INT_SetLow();
    }
}

/**
 * @brief Function for clear the output interrupt pin
 */
void ClearInterrupt(void) {
    INT_SetHigh();
}

/*
                         Main application
 */
void main(void) {
    uint8_t pb_fsm = ENCODER_WAITPUSH;
    uint8_t pb_cnt = 0;
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:


    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    GeneralDataSplit();
    GeneralDataSet();

    while (1) {

        if (debounce > 0) {
            debounce--;
        }

        switch (pb_fsm) {

            case ENCODER_WAITPUSH:
                if (PUSHB_GetValue() == LOW) {
                    pb_cnt++;
                    if (pb_cnt > DEBOUNCE_CNT) {
                        pb_fsm = ENCODER_PUSHED;
                    }
                } else {
                    if (pb_cnt > 0)
                        pb_cnt--;
                }
                break;

            case ENCODER_PUSHED:
                StatusUpdate(S_PUSH);
                SetInterrupt();
                pb_fsm = ENCODER_WAITRELEASE;
                break;

            case ENCODER_WAITRELEASE:
                if (PUSHB_GetValue()== HIGH) {
                    pb_cnt--;
                    if (pb_cnt <= 0) {
                        pb_fsm = ENCODER_WAITPUSH;
                        pb_cnt = 0;
                    }
                }
                break;
        }
    }
}
/**
 End of File
 */