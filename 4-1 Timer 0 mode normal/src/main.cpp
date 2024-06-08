#include <avr/io.h> //header avr
void TimerInit();   //initialisasi timer0
unsigned char periode;
/*
prescaller 8, Xtal 16MHz
tick = 8/16Mhz= 0.5 us
 delay=counter*tick
 delay=counter*0.5us
 counter=delayus/0.5us
untuk sampling rate 30 khz maka Tsampling= 1/30Khz= 33.3us
 counter = 33.3us/0.5us = 67
nilai TCNT1= (255-67)-> karena counter up
 */
int main(void) {
    DDRB |= _BV(PB7);   //pb7 sebagai output
    TimerInit();    //inisialisasi timer 0
    while (1) {
        if (TIFR0&(1<<TOV0)) {  //jika everflow
            // TCNT0= (unsigned char)(255-64); //reset cunter
            //clear flag
            TIFR0|=(1<<TOV0);  //atur prescaller 8
            PORTB ^= (1 << PB7);    //ganti nilai pb7
        }
    }
}
void TimerInit(void) {
    TCNT0 = (unsigned char) (255-64); // reset counter
    TCCR0B = (1 << CS01) ; //konfigurasi timer dengan prescaller 8
}