#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


ISR(INT0_vect)
{
	PORTB|=(1<<7);
	_delay_ms(3000);
}
ISR(INT1_vect)
{
	PORTB&=~(1<<7);
	_delay_ms(3000);

}

int main (void)
{
	DDRA=0xff;
	DDRB |=(1<<PB7);// LED output enable
	PORTD |=_BV(PD0);  // pin PD.0 input pullup
	PORTE |=_BV(PD1);  // pin PD.1 input pullup
	EIMSK |= (1<<INT0)|_BV(INT1);    // enable interrupt
	EICRA |= _BV(ISC01)|_BV(ISC00)|_BV(ISC10)|_BV(ISC11); //rising edge activate INT0
	sei();
	while (1){
		PORTA=0x00;
		for (unsigned char i=0;i<8;i++)
		{
			PORTA = ~(1<<i);
			_delay_ms(500);
		}

	}
}