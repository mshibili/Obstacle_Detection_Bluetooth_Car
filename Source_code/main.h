#ifndef __MAIN_H
#define    __MAIN_H


#define M1A      PORTCbits.RC0
#define M1B      PORTCbits.RC1
#define M2A      PORTCbits.RC2
#define M2B      PORTCbits.RC3

#define TRIGGER  PORTCbits.RC4
#define ECHO     PORTCbits.RC5


#define LED      PORTDbits.RD2


void TURN_LEFT();
void TURN_RIGHT();
TURN_BACK();
void forward();
void back();
void right();
void left();
void stop();
int check_object();
void interrupt isr(void);

#endif
