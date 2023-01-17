#include<htc.h>

#include<xc.h>
#include "main.h"
#include "lcd.h"
#include "sci.h"

#define __XTAL_FREQ 20000000


int time,distance;



//-------------- UART INTERUPT-------------------
void interrupt isr(void)
		{
		char udata;
			udata=UART_READ_CHR();			// Read char from RCREG
			
			switch(udata)
				{
				case 'F':forward();break;
		
				case 'B':back();break;
		
				case 'R':right();break;
		
				case 'L':left();break;
		
				case 'S':stop();break;
				}
		
		}



int check_object()

		{__delay_ms(400);
		
		 	TMR1H = 0;                  //Sets the Initial Value of Timer
		    TMR1L = 0;                  //Sets the Initial Value of Timer
		
		    TRIGGER = 1;               	//TRIGGER HIGH
		    __delay_us(10);             //10uS Delay
		    TRIGGER = 0;               	//TRIGGER LOW
		
		    while(!ECHO);           	//Waiting for Echo
		    TMR1ON = 1;              	//Timer Starts
		    while(ECHO);            	//Waiting for Echo goes LOW
		    TMR1ON = 0;               	//Timer Stops
		
		
			time = (TMR1L | (TMR1H<<8)) *( 1 / (__XTAL_FREQ/4)); 	// Time = (TMR1H:TMR1L)*(1/Internal Clock)*Prescaler

			//	Distance = Speed * Time
			//	Speed of Sound in Air : 340 m/s = 34000 cm/s

			distance = 34000 * time;
		    distance += 1;						// Distance Calibration
		
		      
		      LCD_CHR(1,13,distance%10 + 48);
		
		      distance = distance/10;
		      LCD_CHR(1,12,distance%10 + 48);
		
		      distance = distance/10;
		      LCD_CHR(1,11,distance%10 + 48);
		
		      LCD_OUT(1,14,"cm");
			

		
			return distance;
		
		
		
		  }
		




//////////////////MAIN FUNCTION\\\\\\\\\\\\\\\\\\\\\\\\\\\\


void main()
{


  TRISD = 0x00; // Set PORTB as  Output

  TRISB = 0x00; // Set PORTB as  Output


  LCD_INIT();	// Initilise LCD

  UART_INIT();

  LCD_CLEAR();	// Clear LCD

	GIE=1;
	PEIE=1;
	RCIE=1;
	LED=0;
  	int c=0;



  TRISC = 0b10010000;           //RB4 as Input PIN (ECHO)

  PORTC=0X00;

  LCD_OUT(1,0,"Developed By ");

  LCD_OUT(2,0,"M.Shibili");

  T1CON = 0x20;
                 //Initialize Timer Module
  LCD_OUT(1,0,"Distance = ");

  while(1)
  {        

   check_object();

		if(distance<25)
		{

				M1A=0;
				M1A=0;
				M2A=0;
				M2B=0;

				LED=1;
				__delay_ms(100);
				LED=0;
				__delay_ms(100);
				LED=1;
				__delay_ms(100);
				LED=0;
				__delay_ms(100);
				LED=1;
				__delay_ms(100);
				LED=0;

			while(distance<25)
			{
				
							TURN_RIGHT();
							check_object();				
							

			}
			
		}

	}
   
}


//---------------L293D H-Driver signal----------------

void TURN_LEFT()
	{
	M1A=0;
	M1A=1;
	M2A=1;
	M2B=0;
	__delay_ms(3000);
	M1A=0;
	M1A=0;
	M2A=0;
	M2B=0;
	}

void TURN_RIGHT()
	{
	M1A=1;
	M1A=0;
	M2A=0;
	M2B=1;
	__delay_ms(1000);
	M1A=0;
	M1A=0;
	M2A=0;
	M2B=0;
	}

TURN_BACK()
{
	M1A=0;
	M1A=1;
	M2A=0;
	M2B=1;
	__delay_ms(1000);
	M1A=0;
	M1A=0;
	M2A=0;
	M2B=0;
}
void forward()
{
M1A=1;
M1A=0;
M2A=1;
M2B=0;
}

void back()
{
M1A=0;
M1A=1;
M2A=0;
M2B=1;
}

void right()
{
M1A=1;
M1A=0;
M2A=0;
M2B=1;
}

void left()
{
M1A=0;
M1A=1;
M2A=1;
M2B=0;
}

void stop()
{
M1A=0;
M1A=0;
M2A=0;
M2B=0;
}




