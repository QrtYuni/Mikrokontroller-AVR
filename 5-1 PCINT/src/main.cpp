#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
ISR(PCINT0_vect){
  PORTB|=(1<<7);
  _delay_ms(1000);
  PORTB&=~(1<<7);
}

int main (void){
  DDRC=0xff;
  DDRB |=(1<<PB7);// LED output enable
  PORTB|=(1<<PB4); // pint PCINT4 pullup
  PCMSK0 |= (1<<PCINT0); // enable interrupt
  PCICR |= _BV(PCIE0);
  sei();

  while (1){
    PORTC=0x00;
    for (unsigned char i=0;i<8;i++){
      PORTC = ~(1<<i);
      _delay_ms(500);
    }
  }
}