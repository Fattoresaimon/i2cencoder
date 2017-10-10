/* 
 * File:   main.h
 * Author: Saimon
 *
 * Created on 10 settembre 2017, 11.48
 */

#ifndef MAIN_H
#define	MAIN_H

#define DEBOUNCE_CNT 0x7F //Debounce of 300us

#define LOCK_PPS     PPSLOCK = 0x55;    PPSLOCK = 0xAA;     PPSLOCKbits.PPSLOCKED = 0x01 // lock PPS
#define UNLOCK_PPS   PPSLOCK = 0x55;    PPSLOCK = 0xAA;     PPSLOCKbits.PPSLOCKED = 0x00 // unlock PPS    


/** FSM for the push button **/
typedef enum {
    ENCODER_WAITPUSH,
    ENCODER_PUSHED,
    ENCODER_WAITRELEASE,
} ENCODER_SWITCH_STATUS;


void CLC_1_Interrupt(void);
void CLC_2_Interrupt(void);
void SetInterrupt(void);
void ClearInterrupt(void);

#endif	/* MAIN_H */

