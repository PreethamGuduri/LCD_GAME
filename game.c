#include <LPC21xx.h>
#include <stdlib.h>
#include "init_lcd.c"

#define sw_1 16 // Forward
#define sw_2 17 // Backward
#define sw_3 18 // Fire



void numlcd(int a)	// Converting number to each char and displaying on LCD
{
	CharLCD((a/10)+'0');
	CharLCD((a%10)+'0');
}


//	int arr2[8]={0x0e,0x0e,0x0e,0x0e,0x1f,0x1f,0x1f,0x00}; // GUN -1
	int arr1[8]={0x11,0x11,0x1f,0x1f,0x1f,0x11,0x11,0x00}; // robot -1
	//int shoot[8]={0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04}; // bullet 
	int arr[8]={0x00,0x00,0x0e,0x0e,0x0e,0x1f,0x1f,0x00};//gun - 0
	int shoot[8]={0x04,0x04,0x0e,0x0e,0x0e,0x1f,0x1f,0x00}; //fire -2
	int hu[8]={0x0e,0x0e,0x0e,0x15,0x04,0x0a,0x11,0x00};// hu -3
	int main()
{
	int i,time,ran_pos,gun_pos,seed,score_cnt=0,time_end=0,time_cnt=60,x,tt;
	int time_set=180; // Time to display Robots (3 sec)
	int level_1=1,level_2=0,level_3=0	;
	int ran_x,ran_flag=0;
	IODIR0 = 0xff00ff;
	initlcd();
  srand(1234);  // You can use a constant for testing
	cmdlcd(0x40);
		for(i=0;i<8;i++)
	{
		CharLCD(arr[i]);
	}
		for(i=0;i<8;i++)
	{
		CharLCD(arr1[i]);
	}
			for(i=0;i<8;i++)
	{
		CharLCD(shoot[i]);
	}
				for(i=0;i<8;i++)
	{
		CharLCD(hu[i]);
	}
	gun_pos=-1; // making gun pos -1 
	time_end=0;
	
	
	cmdlcd(0x80);
	cmdlcd(0x01);
	strlcd("LEVEL-1");
	delay_ms(800);
	cmdlcd(0x01);
	cmdlcd(0x80);
	strlcd("MISSON:");
	cmdlcd(0xc0);
	strlcd("10 Kills in 60 Sec");
	delay_ms(800);
	cmdlcd(0x01);
	
	cmdlcd(0x80);
	strlcd("Shoot Robots-");
	CharLCD(1);
		delay_ms(800);
	cmdlcd(0x01);
	
	time_set=120;
	score_cnt=0;
	goto T;
	while(1)
	{
			time_end++;	 // For count sec
			time++;  // time for random generation
			/** random robot generation **/
			if(time>=time_set)
			{
				T:
				srand(seed++); // seed for random
				cmdlcd(0x80+ran_pos); // Making previous x position to Sapce(removing symbol)
				CharLCD(' ');
				ran_pos=rand()%14; // RANDOM POSITONS
				
				if(level_3==0)
				{
						cmdlcd(0x80+ran_pos); // Setting randim pos
						CharLCD(1);
				}else 
				{
					ran_x=rand()%2;
					if(ran_x)
					{
						cmdlcd(0x80+ran_pos); // Setting randim pos
						CharLCD(1);
						ran_flag=1;
					}
					if(ran_x==0)
					{
							cmdlcd(0x80+ran_pos); // Setting randim pos
							CharLCD(3);
							ran_flag=2;
					}
				}

				time=0; //making time 0
			}		
			
			/** On switch press GUN pos to Forward**/
			
			if(((1 << sw_1)& IOPIN1)==0)
			{
						time_end++;
						if(gun_pos==13) // Reseting to previous position when it reaches to final position
							 gun_pos=12;
						
						cmdlcd(0xc0+(gun_pos));
						CharLCD(' '); 						// Removing previous position
						cmdlcd(0xc0+(++gun_pos));
						CharLCD(0); // GUN
					
						for(x=70*12000;x>=0;x--)
						{
							if(((1 << sw_1)& IOPIN1))
							{
								x=0;
							}
						}
									if((time_end%60)==0)
									{
											time_cnt--;
											
									}
									cmdlcd(0xce);
									numlcd(time_cnt);				// Displaying time count in sec
		
							while((( 1 << sw_1)&IOPIN1)==0)
						{			
							/** TIME CHECKING AND UPDATING **/
									time_end++;
									time++;
										if(gun_pos==13)
									 gun_pos=12;
							if(time >=time_set*10000) 
								{
								
									cmdlcd(0x80+ran_pos);
									CharLCD(' ');
									srand(seed++);
									ran_pos=rand()%14; // RANDOM POSITONS
									cmdlcd(0x80+ran_pos);
									CharLCD(1);
									time=0;
								}
									if((time_end%7)==0) // time
									{
										time_cnt--;
										cmdlcd(0xce);
										numlcd(time_cnt);
									}
								cmdlcd(0xc0+(gun_pos));
								CharLCD(' ');
								cmdlcd(0xc0+(++gun_pos));
								CharLCD(0); // GUN
								delay_ms(70);
								time_end+=(70*1200); // adding delay time to time end
								time+=(70*1200);

								}	
			} /// Forward
			
			
			/** On switch press GUN pos to Backward **/
			
			if(((1 << sw_2)& IOPIN1)==0)
			{
						if(gun_pos==0)
							 gun_pos=1;
						
						cmdlcd(0xc0+(gun_pos));
						CharLCD(' ');
						cmdlcd(0xc0+(--gun_pos));
						CharLCD(0); // GUN
					
						for(x=70*12000;x>=0;x--)
						{
							if(((1 << sw_2)& IOPIN1))
							{
								x=0;
							}
						}
									if((time_end%60)==0)
									{
											time_cnt--;
											
									}
									cmdlcd(0xce);
									numlcd(time_cnt);

						while(((1 << sw_2)& IOPIN1)==0)
						{
																time_end++;
									time++;
								if(gun_pos==0)
								 gun_pos=1;
							
							/** TIME CHECKING AND UPDATING **/

							if(time >=time_set*10000) 
								{
									cmdlcd(0x80+ran_pos);
									CharLCD(' ');
									srand(seed++);
									ran_pos=rand()%14; // RANDOM POSITONS
									cmdlcd(0x80+ran_pos);
									CharLCD(1);
									time=0;
								}
									if((time_end%7)==0) // time
									{
										time_cnt--;
										cmdlcd(0xce);
										numlcd(time_cnt);
									}
								/*--------------------------------------*/
								cmdlcd(0xc0+(gun_pos));
								CharLCD(' ');
								cmdlcd(0xc0+(--gun_pos));
								CharLCD(0); // GUN
								delay_ms(70);
								time_end+=(70*1200);
								time+=(70*1200);		
						}
						
			} // Backward
			
			/**  SHHOT BUTTON **/
			if(((1 << sw_3)& IOPIN1)==0) 
			{
					if(gun_pos==ran_pos)
					{
						if(ran_flag==2)
							goto E;
							cmdlcd(0x80+ran_pos);
							CharLCD(' ');
							score_cnt++;
							cmdlcd(0x8e);
							numlcd(score_cnt);
							time=time_set;
						for(tt=0;tt<5;tt++)
						{
							cmdlcd(0x80+ran_pos);
							CharLCD(' ');
							cmdlcd(0xc0+gun_pos);
							CharLCD(2);
							delay_ms(30);
							cmdlcd(0x80+ran_pos);
							CharLCD(1);
							cmdlcd(0xc0+gun_pos);
							CharLCD(0);
							delay_ms(30);
						}
					}
						cmdlcd(0x80+ran_pos);
					CharLCD(1);
					while(((1 << sw_3)& IOPIN1)==0)
					{
						;

						time_end++;
					}
					cmdlcd(0xc0+gun_pos);
					CharLCD(0);
				
						
			}
			/*----------------------*/
			
			if((time_end%60)==0)
			{
					time_cnt--;
					
			}
			cmdlcd(0xce);
			numlcd(time_cnt);
			
			if(time_cnt==0)
			{
				E:
					cmdlcd(0x80);
					cmdlcd(0x01);	
					strlcd("GAME_OVER");
					
					break;
			}
			if((score_cnt==10)&&(level_1==1))
			{
					cmdlcd(0x80);
					cmdlcd(0x01);
					strlcd("LEVEL-2");
			
					delay_ms(800);
			
					cmdlcd(0x01);
					cmdlcd(0x80);
					strlcd("MISSON:");
					cmdlcd(0xc0);
					strlcd("12 Kills in 45 Sec");
					delay_ms(800);
					cmdlcd(0x01);
					time_set=120;
					time_cnt=45;
					score_cnt=0;
					level_1=0;
					level_2=1;
				goto T;
			}
			if((score_cnt==12)&&(level_2==1))
			{
					cmdlcd(0x80);
					cmdlcd(0x01);
					strlcd("LEVEL-3");
			
					delay_ms(800);
			
					cmdlcd(0x01);
					cmdlcd(0x80);
					strlcd("MISSON:");
					cmdlcd(0xc0);
					strlcd("12 Kills in 30 Sec");
					delay_ms(800);
					cmdlcd(0x01);
				
					cmdlcd(0x80);
					strlcd("Shoot Robots-");
					CharLCD(1);
					cmdlcd(0xc0);
					strlcd("Save Huamans-");
					CharLCD(3);
					delay_ms(800);
					cmdlcd(0x01);				
				
				
					time_set=100;
					time_cnt=35;
					score_cnt=0;
					level_1=0;
					level_2=0;
					level_3=1;
				goto T;
			}
			
	} // while
	
}
