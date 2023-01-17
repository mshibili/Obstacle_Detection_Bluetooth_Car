#include<htc.h>
#include<xc.h>
#define _XTAL_FREQ 20000000

void UART_INIT();
void UART_WRITE(char *a);
void UART_WRITE_CHR(char a);
 UART_READ_CHR();
void WAITE_TX();


void UART_INIT()
{
BRGH=1;
SPBRG=129;
SYNC=0;
SPEN=1;
SREN=0;
RCIE=1;
RX9=0;
TX9=0;
TXEN=1;
CSRC=1;
CREN=1;
GIE=1;
TRISC6=0;
TRISC7=1;

}




void UART_WRITE(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	UART_WRITE_CHR(a[i]);
}



void UART_WRITE_CHR(char a)
{
TXREG=a;
WAITE_TX();
}



void WAITE_TX()
{
	while(!TRMT)
	{
	continue;
	}
}

 UART_READ_CHR()
{
	while(!RCIF)
	{
	continue;
	}
return RCREG;
}
