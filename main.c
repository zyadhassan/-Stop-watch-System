
/*
 * Stop-watch Project
 * */


#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
#include "Interrupt.h"
#include"Display_segment.h"

int time[6]={0};


int main(void){
	init_segments();
	init_Timer(time);
	init_INT0();
	init_INT1();
	init_INT2();



	while(1){
		Display(time);
	}
}
