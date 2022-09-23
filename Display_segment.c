#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
#include"Display_segment.h"

void init_segments(void){
	DDRC|=(0x0F);
	DDRA|=(0x3F);

	PORTC&=~(0x0F);
	PORTA&=~(0x3F);
	return;

}


void Display(int* time){
	for (int i=0;i<6;i++){
		PORTA&=~(0x3F);
		PORTA|=(1<<i);
		PORTC=(PORTC & 0xF0) | (time[i] & 0x0F);
		_delay_ms(2);
	}


	return;


}

void Count(int* time){
	time[0]++;
	for(int i=0;i<5;i++){
		if(time[i]==10 && i%2==0){
			time[i+1]++;
			time[i]=0;
		}
		else if(time[i]==6 && i%2!=0){
			time[i+1]++;
			time[i]=0;
		}
	}
	return;
}

