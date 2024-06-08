#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>
void TimerInit();
/*
pada mode ctc interupsi yang berpengaruh adalah compare match
karena tcnt tidak pernah mencapai level max(0xFF) tetapi
mencapai level TOP yaitu sama dengan nilai dari output compare
 */
/*
prescaller 8 , Xtal 16MHz
 tick = 8/16Mhz= 0.5 us
 delay=counter*tick
 delay=counter*0.5us
untuk sampling rate 8 khz maka Tsampling= 1/8Khz= 125us
 counter = 125/0.5us = 250
 */
int main(void) {
DDRB |=_BV(DDB7); //LED output
TimerInit(); 
while (1) {
if (TIFR1 & _BV(OCF1A)){
PORTB ^= (1 << PB7);
TIFR1 |= _BV(OCF1A);
}
}
}
void TimerInit() {
TCCR1B |= _BV(WGM12); // CTC
TCCR1B |= _BV(CS12); //prescaller 8
OCR1A = 625 ; //
}
