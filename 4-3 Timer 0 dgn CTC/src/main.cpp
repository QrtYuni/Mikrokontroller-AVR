#include <avr/io.h> //file header avr

void TimerInit();     //inisialisasi timer 0
unsigned char periode;
/*
prescaller 8 , Xtal 16MHz
 tick = 8/16Mhz= 0.5 us
 delay=counter*tick
 delay=counter*1/2us
untuk sampling rate 30 khz maka Tsampling= 1/30Khz= 33.3us
 counter = 33.3/0.5us = 67
 */
int main(void) {
  DDRB |= _BV(PB7); //atur pb7 sebagai output
  TimerInit();  //menginisialisasi timer 0
  while (1) {
    if(TIFR0&(1<<OCF0A)){ //jika terjadi interrupt
      PORTB ^= (1 << PB7);  //membalik nilai pb7
      TIFR0 |= (1<<OCF0A);  //reset ulang bit&membersihkan flag interupsi
    }
  }
}

void TimerInit(void) {
  TCCR0B = (1 << CS01) ; //prescaller 8
  TCCR0A |=_BV(WGM01); //mode Timer CTC
  OCR0A = 67;  
}
