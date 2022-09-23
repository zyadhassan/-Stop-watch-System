#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
#include "Interrupt.h"
#include"Display_segment.h"


int* time_c;

void init_Timer(int* time){
	TCCR1A=0;
	TCCR1B=(1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS12);
	TCNT1=0;
	ICR1=977;
	TIMSK=(1<<OCIE1A);
	SREG|=(1<<7);
	time_c=time;
	return;
	}


ISR(TIMER1_COMPA_vect){
	Count(time_c);
}


void init_INT0(void){
	DDRD&=~(1<<PD2);
	PORTD|=(1<<PD2);

	MCUCR|=(1<<ISC01);
	MCUCR&=~(1<<ISC00);

	GICR|=(1<<INT0);
	SREG|=(1<<7);

}


ISR(INT0_vect){
	for(int i=0;i<6;i++){
		time_c[i]=0;
	}
	/* when reset the counter in the timer hold value so it can interrupt and
	 * increase the time by 1 sec before it counts real one sec so when we put the counter of the timer by 0*/
	TCNT1=0;

}



void init_INT1(void){

	DDRD&=~(1<<PD3);

	MCUCR|=(1<<ISC11)|(1<<ISC10);

	GICR|=(1<<INT1);
	SREG|=(1<<7);



}
ISR(INT1_vect){

	TCCR1B=0;
}





void init_INT2(void){

	DDRB&=~(1<<PB2);
	PORTB|=(1<<PB2);

	MCUCSR&=~(1<<ISC2);

	GICR|=(1<<INT2);
	SREG|=(1<<7);


}
ISR(INT2_vect){
	init_Timer(time_c);
}
