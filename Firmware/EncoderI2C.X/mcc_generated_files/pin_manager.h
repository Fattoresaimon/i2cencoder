/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC16F15323
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ADD0 aliases
#define ADD0_TRIS               TRISAbits.TRISA0
#define ADD0_LAT                LATAbits.LATA0
#define ADD0_PORT               PORTAbits.RA0
#define ADD0_WPU                WPUAbits.WPUA0
#define ADD0_OD                ODCONAbits.ODCA0
#define ADD0_ANS                ANSELAbits.ANSA0
#define ADD0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define ADD0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define ADD0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define ADD0_GetValue()           PORTAbits.RA0
#define ADD0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define ADD0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define ADD0_SetPullup()      do { WPUAbits.WPUA0 = 1; } while(0)
#define ADD0_ResetPullup()    do { WPUAbits.WPUA0 = 0; } while(0)
#define ADD0_SetPushPull()    do { ODCONAbits.ODCA0 = 1; } while(0)
#define ADD0_SetOpenDrain()   do { ODCONAbits.ODCA0 = 0; } while(0)
#define ADD0_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define ADD0_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set ADD1 aliases
#define ADD1_TRIS               TRISAbits.TRISA1
#define ADD1_LAT                LATAbits.LATA1
#define ADD1_PORT               PORTAbits.RA1
#define ADD1_WPU                WPUAbits.WPUA1
#define ADD1_OD                ODCONAbits.ODCA1
#define ADD1_ANS                ANSELAbits.ANSA1
#define ADD1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define ADD1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define ADD1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define ADD1_GetValue()           PORTAbits.RA1
#define ADD1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define ADD1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define ADD1_SetPullup()      do { WPUAbits.WPUA1 = 1; } while(0)
#define ADD1_ResetPullup()    do { WPUAbits.WPUA1 = 0; } while(0)
#define ADD1_SetPushPull()    do { ODCONAbits.ODCA1 = 1; } while(0)
#define ADD1_SetOpenDrain()   do { ODCONAbits.ODCA1 = 0; } while(0)
#define ADD1_SetAnalogMode()  do { ANSELAbits.ANSA1 = 1; } while(0)
#define ADD1_SetDigitalMode() do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()    do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()   do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()   do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()         PORTAbits.RA2
#define RA2_SetDigitalInput()   do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()  do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()     do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()   do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode() do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set ADD3 aliases
#define ADD3_PORT               PORTAbits.RA3
#define ADD3_WPU                WPUAbits.WPUA3
#define ADD3_GetValue()           PORTAbits.RA3
#define ADD3_SetPullup()      do { WPUAbits.WPUA3 = 1; } while(0)
#define ADD3_ResetPullup()    do { WPUAbits.WPUA3 = 0; } while(0)

// get/set ADD2 aliases
#define ADD2_TRIS               TRISAbits.TRISA4
#define ADD2_LAT                LATAbits.LATA4
#define ADD2_PORT               PORTAbits.RA4
#define ADD2_WPU                WPUAbits.WPUA4
#define ADD2_OD                ODCONAbits.ODCA4
#define ADD2_ANS                ANSELAbits.ANSA4
#define ADD2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define ADD2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define ADD2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define ADD2_GetValue()           PORTAbits.RA4
#define ADD2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define ADD2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define ADD2_SetPullup()      do { WPUAbits.WPUA4 = 1; } while(0)
#define ADD2_ResetPullup()    do { WPUAbits.WPUA4 = 0; } while(0)
#define ADD2_SetPushPull()    do { ODCONAbits.ODCA4 = 1; } while(0)
#define ADD2_SetOpenDrain()   do { ODCONAbits.ODCA4 = 0; } while(0)
#define ADD2_SetAnalogMode()  do { ANSELAbits.ANSA4 = 1; } while(0)
#define ADD2_SetDigitalMode() do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set INT aliases
#define INT_TRIS               TRISAbits.TRISA5
#define INT_LAT                LATAbits.LATA5
#define INT_PORT               PORTAbits.RA5
#define INT_WPU                WPUAbits.WPUA5
#define INT_OD                ODCONAbits.ODCA5
#define INT_ANS                ANSELAbits.ANSA5
#define INT_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define INT_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define INT_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define INT_GetValue()           PORTAbits.RA5
#define INT_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define INT_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define INT_SetPullup()      do { WPUAbits.WPUA5 = 1; } while(0)
#define INT_ResetPullup()    do { WPUAbits.WPUA5 = 0; } while(0)
#define INT_SetPushPull()    do { ODCONAbits.ODCA5 = 1; } while(0)
#define INT_SetOpenDrain()   do { ODCONAbits.ODCA5 = 0; } while(0)
#define INT_SetAnalogMode()  do { ANSELAbits.ANSA5 = 1; } while(0)
#define INT_SetDigitalMode() do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()    do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()   do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()   do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()         PORTCbits.RC0
#define RC0_SetDigitalInput()   do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()  do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()     do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()   do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode() do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()    do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()   do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()   do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()         PORTCbits.RC1
#define RC1_SetDigitalInput()   do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()  do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()     do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()   do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode() do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()    do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()   do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()   do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()         PORTCbits.RC2
#define RC2_SetDigitalInput()   do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()  do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()     do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()   do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode() do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()    do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()   do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()   do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()         PORTCbits.RC3
#define RC3_SetDigitalInput()   do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()  do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()     do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()   do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode() do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()    do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()   do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()   do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()         PORTCbits.RC4
#define RC4_SetDigitalInput()   do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()  do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()     do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()   do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode() do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set PUSHB aliases
#define PUSHB_TRIS               TRISCbits.TRISC5
#define PUSHB_LAT                LATCbits.LATC5
#define PUSHB_PORT               PORTCbits.RC5
#define PUSHB_WPU                WPUCbits.WPUC5
#define PUSHB_OD                ODCONCbits.ODCC5
#define PUSHB_ANS                ANSELCbits.ANSC5
#define PUSHB_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define PUSHB_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define PUSHB_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define PUSHB_GetValue()           PORTCbits.RC5
#define PUSHB_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define PUSHB_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define PUSHB_SetPullup()      do { WPUCbits.WPUC5 = 1; } while(0)
#define PUSHB_ResetPullup()    do { WPUCbits.WPUC5 = 0; } while(0)
#define PUSHB_SetPushPull()    do { ODCONCbits.ODCC5 = 1; } while(0)
#define PUSHB_SetOpenDrain()   do { ODCONCbits.ODCC5 = 0; } while(0)
#define PUSHB_SetAnalogMode()  do { ANSELCbits.ANSC5 = 1; } while(0)
#define PUSHB_SetDigitalMode() do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/