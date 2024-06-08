#include <avr/io.h>         //header avr
#include <avr/interrupt.h>  //header interupt
#include <avr/sleep.h>      //header mode sleep

void TimerInit();   //inisialisasi timer 0
unsigned char periode;  

ISR (TIMER0_COMPA_vect){    // jika interupsi compare match pada timer 0
    PORTB ^= (1 << PB7);    //membalik nilai pb7
}
/*
prescaller 8 , Xtal 16MHz
 tick = 8/16Mhz= 0.5 us
 delay=counter*tick
 delay=counter*0.5us
untuk sampling rate 30khz maka Tsampling= 1/30Khz= 33.3us
 counter = 33.3/0.5us = 67
nilai TCNT1= -250 -> karena counter up
 */
int main(void) {
    DDRB |= _BV(PB7);   //atur pb7 sebagai output
    TimerInit(); // inisialisasi timer 0
    sei();      /// enable global interupsi
    while (1) {
    sleep_mode(); // mode sleep aktif hingga ada interrupt
    }
}

void TimerInit(void) {
    // TCNT0 = -250; // reset counter
    TCCR0B = (1 << CS01) ; //prescaller 8
    TIMSK0 |= (1 << OCIE0A); // enable compare maatch interrupt
    TCCR0A |=_BV(WGM01); //mode Timer CTC
    OCR0A = 67;
}
