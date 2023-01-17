#ifndef __LCD_H
#define    __LCD_H


#include<xc.h>

#define _XTAL_FREQ 20000000

void LCD_CHR1(char a);

void LCD_CHR(char a,char b, char c);

void LCD_PORT(char a);

void LCD_CMD(char a);

LCD_CLEAR();

void LCD_OUT(char a, char b, char *c);

void LCD_INIT();

void LCD_CHR1(char a);

void LCD_SHIFT_RIGHT();

void LCD_SHIFT_LEFT();


#define RS PORTBbits.RB0
#define EN PORTBbits.RB1
#define D4 PORTBbits.RB2
#define D5 PORTBbits.RB3
#define D6 PORTBbits.RB4
#define D7 PORTBbits.RB5


#endif





