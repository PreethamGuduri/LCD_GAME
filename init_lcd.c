
#include<LPC21xx.h>
#include "header.h"
void numlcd(int a)	// Converting number to each char and displaying on LCD
{
	CharLCD((a/10)+'0');
	CharLCD((a%10)+'0');
}
void cmdlcd(int a)
{
		IOCLR0 = 1 << 16;
	  IOCLR0 = 1 << 17;
		IOPIN0 = ((IOPIN0 &(~(255 << 0))) |  a);
		IOSET0 = 1 << 18;
		delay_us(1);
		IOCLR0 = 1 << 18;
		delay_ms(2);
}
void CharLCD(char a)
{
		IOSET0 = 1 << 16;
	  IOCLR0 = 1 << 17;
		IOPIN0 = ((IOPIN0 &(~(255 << 0))) |  a);
		IOSET0 = 1 << 18;
		delay_us(1);
		IOCLR0 = 1 << 18;
		delay_ms(2);

}
void strlcd(char *a)
{
	char *s;
		s=a;
	while(*s)
		{
		CharLCD(*s++);
		//delay_ms(300);
		//if(s==(a+16))
		//	cmdlcd(0xc0);
		}
}
void initlcd()
	{
		IODIR0 = 0xff;
	IODIR0 |= 1 << 16; // rs
	IODIR0 |= 1 << 17; //rw
	IODIR0 |= 1 << 18; //en
	
	delay_ms(15);
	cmdlcd(0x30);
	
	delay_ms(1);
	cmdlcd(0x30);
		
	delay_us(100);
	cmdlcd(0x30);

	cmdlcd(0x38);
		
		
	cmdlcd(0x0c);
		
		
	cmdlcd(0x01);
		
	cmdlcd(0x06);
	}
