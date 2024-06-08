#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect){ //fungsi interrupt INT0
  PORTB|=(1<<4);
  _delay_ms(1000);
  PORTB&=~(1<<4);
}

int main (void){
  DDRC=0xff;
  DDRB |=(1<<PB4);// LED output enable
  PORTD |=_BV(PD2); // pin int0 PD0 pullup
  EIMSK |= (1<<INT0); // menyalakan interrupt
  EICRA |= _BV(ISC01);  
  EICRA &=~_BV(ISC00); //falling edge activate INT0
  sei();

  while (1){
    PORTC = 0x00;
    for (unsigned char i=0;i<8;i++){
      PORTC = ~(1<<i);
      _delay_ms(500);
    }
  }
}