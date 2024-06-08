#include <avr/io.h>         //file header avr   
#include <avr/interrupt.h>  //file header interrupt
#include <avr/sleep.h>      //file header mode sleep

void TimerInit();       //inisialisasi timer 0
unsigned char periode;

ISR (TIMER0_OVF_vect){ 
    PORTB ^= (1 << PB7);    //mengubah kondisi pb7
    TCNT0= (255-67);            //reset counter
}
/*
prescaller 8 , Xtal 16MHz
 tick = 8/16Mhz= 0.5 us
 delay=counter*tick
 delay=counter*0.5us
 counter=delayus/0.5us
 untuk sampling rate 30 khz maka Tsampling= 1/30Khz=33.3us
 counter = 33.3/0.5us = 67
 nilai TCNT1= (255-67) -> karena counter up
 */
int main(void) {
    DDRB |= _BV(PB7);   //deklar output pada pb7
    TimerInit();        //inisialisasi timer dan schedule 10ms
    sei();              // enable global interupsi
    while (1) {
        sleep_mode(); // masuk mode sleep hingga ada interupsi
    }
}

void TimerInit(void) {
    // TCNT0 = -250; // reset counter
    TCCR0B = (1 << CS01) ; //prescaller 8
    TIMSK0 |= (1 << TOIE0); // enable overflow interrupt
}