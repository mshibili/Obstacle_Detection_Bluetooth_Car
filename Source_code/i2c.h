void I2CINIT();

void I2CSTART();

void I2CSTOP();

void I2CRESTART();

void I2CACK();

void I2CNAK();

void I2CWAIT();

void I2CSEND(unsigned char dat);

char I2CINITval[10];

char rcdata[30];

double rdaddr=0x00;

unsigned char I2CREAD();

unsigned char I2CDATA[] = {"i-St@r"};

unsigned char i,j;


void I2CINIT(void)
{

TRISC3 = 1; 

TRISC4 = 1;
 
SSPSTAT |= 0x80; // Slew rate disabled 

SSPCON = 0x28; 

SSPADD = 0x28; /* 100Khz @ 4Mhz Fosc */
}



void I2CSTART()
{

SEN = 1; 

while(SEN); 

}


void I2CSTOP()
{

PEN = 1;

while(PEN); 

}


void I2CRESTART()
{

RSEN = 1; 

while(RSEN);

}


void I2CACK()
{

ACKDT = 0;

ACKEN = 1; 

while(ACKEN); 

}


void I2CNAK()
{
ACKDT = 1; 

ACKEN = 1;

while(ACKEN); 

}


void I2CWAIT()
{

while ((SSPCON2 & 0x1F ) || ( SSPSTAT & 0x04 ) );

}


void I2CSEND(unsigned char dat)
{

SSPBUF = dat;

while(BF); 

I2CWAIT();

}



unsigned char I2CREAD()
{

unsigned char temp;

RCEN = 1; 

while(!BF); 

temp = SSPBUF; 

I2CWAIT(); 

return temp;

} 

