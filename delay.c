void delay_ms(int a)
{
	for(a*=12000;a>=0;a--);
}
void delay_s(int a)
{
	for(a*=12000000;a>=0;a--);
}
void delay_us(int a)
{
	for(a*=12;a>=0;a--);
}
