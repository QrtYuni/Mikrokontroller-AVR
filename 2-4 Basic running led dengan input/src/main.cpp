// Nama  : Qurrota A'yuni Jumayanti
// Kelas : 2 D3 ELektronika A
// NRP   : 2122500009

#include <avr/io.h>
#include <util/delay.h>
#define CW 0 
#define CCW 1

int main (void) {
  DDRA=0xFF;      // PA input
  DDRB &=~(1<<4); // PB4 input
  PORTB |=(1<<4); // PB4 switch 1
  DDRH &=~(1<<4); // PH input 
  PORTH |=(1<<4); // PH4 switch 2
  PORTA=0xFF;     // PA LED
  int arah=0;     // arah led
  
  while(1){
    if (arah==CW) { //default arah = 0 = CW
      for(int i=0;i<=7;i++){
        PORTA &= ~(1<<i); //PA0-7 mati semua
        _delay_ms(200);
      }
    } else if (arah==CCW){
      for(int i=7;i>=0;i--){
        PORTA = ~(1<<i);  //PA7-0 mati bergantian
        _delay_ms(200);
      }
    }

    if (!(PINB&(1<<4))) {
      arah=CW;  
    } else if (!(PINH&(1<<4))) {
        arah=CCW; 
    }
  }
}
