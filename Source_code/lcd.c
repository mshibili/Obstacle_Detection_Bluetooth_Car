#include "lcd.h"


void LCD_PORT(char a)
{
	if(a & 1)
		D4 = 1;
	else 
		D4 = 0;
	
	if(a & 2)
		D5 = 1;
	else
		D5 = 0;
	
	if(a & 4)
		D6 = 1;
	else
		D6 = 0;
	
	if(a & 8)
		D7 = 1;
	else
		D7 = 0;
}


void LCD_CMD(char a)
{ 
	RS = 0;              // => RS = 0
	LCD_PORT(a);
	EN  = 1;             // => E = 1
 	 __delay_ms(4);
  	EN  = 0;             // => E = 0
}



LCD_CLEAR()
{
	LCD_CMD(0);
	LCD_CMD(1);
}



void LCD_OUT(char a, char b, char *c)
{
	char temp,z,y,x[10];
	if(a == 1)
	{
	  temp = 0x80 + b;
		z = temp>>4;
		y = (0x80+b) & 0x0F;
		LCD_CMD(z);
		LCD_CMD(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b;
		z = temp>>4;
		y = (0xC0+b) & 0x0F;
		LCD_CMD(z);
		LCD_CMD(y);
	}
	int i;
	for(i=0;c[i]!='\0';i++)
	LCD_CHR1(c[i]);



}



void LCD_INIT()
{
  LCD_PORT(0x00);
  __delay_ms(20);
  LCD_CMD(0x03);
  __delay_ms(5);
  LCD_CMD(0x03);
  __delay_ms(11);
  LCD_CMD(0x03);
  LCD_CMD(0x02);    
  LCD_CMD(0x02);
  LCD_CMD(0x08); 	
  LCD_CMD(0x00); 
  LCD_CMD(0x0C);     
  LCD_CMD(0x00);    
  LCD_CMD(0x06);   
}



void LCD_CHR1(char a)
{

   char temp,y;
   temp = a&0x0F; 
   y = a&0xF0;	
	 RS = 1;             // => RS = 1
   LCD_PORT(y>>4);             //Data transfer
	 EN = 1;
	 __delay_ms(5);
	 EN = 0;
	 LCD_PORT(temp);
	 EN = 1;
	 __delay_ms(5);
	 EN = 0;
}





void LCD_CHR(char a, char b, char c)
{
	char temp,z,y,x[10];
	if(a == 1)
	{
	  temp = 0x80 + b;
		z = temp>>4;
		y = (0x80+b) & 0x0F;
		LCD_CMD(z);
		LCD_CMD(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b;
		z = temp>>4;
		y = (0xC0+b) & 0x0F;
		LCD_CMD(z);
		LCD_CMD(y);
	}

	LCD_CHR1(c);



}

void LCD_SHIFT_RIGHT()
{
	LCD_CMD(0x01);
	LCD_CMD(0x0C);
}



void LCD_SHIFT_LEFT()
{
	LCD_CMD(0x01);
	LCD_CMD(0x08);
}


