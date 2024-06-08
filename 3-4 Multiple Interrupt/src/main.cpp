#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect){
  PORTB|=(1<<4);  //menyalakan
  _delay_ms(30);
}

ISR(INT1_vect){
  PORTB&=~(1<<4); //mematikan
  _delay_ms(30);
}

int main (void){
  DDRC=0xff;
  DDRB |=(1<<PB4);// LED output enable
  PORTD |=_BV(PD2); // pin PD.2 input pullup
  PORTD |=_BV(PD3); // pin PD.3 input pullup
  EIMSK |= (1<<INT0)|_BV(INT1); // enable interrupt
  EICRA |= _BV(ISC01)|_BV(ISC00)|_BV(ISC10)|_BV(ISC11); //rising edge activate INT0
  sei();
  
  while (1){
    PORTC = 0x00;
    for (unsigned char i=0;i<8;i++){
      PORTC = ~(1<<i);
      _delay_ms(500);
    }
  }
}
