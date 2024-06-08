// Nama  : Qurrota A'yuni Jumayanti
// Kelas : 2 D3 ELektronika A
// NRP   : 2122500009

#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRA = 0xFF;    //input led
  DDRB &= (1<<4); //input switch
  PORTB |= (1<<4);  //input switch PB4
  PORTA = 0xFF;   //input led PA

  while(1){
    if(!(PINB&(1<<4))){ //jka PB4 false/mati
      for (int i = 0; i <= 7; i++)  
      {
        PORTA = ~(1<<i);  //PA 0-7 nyala bergantian
        _delay_ms(500);
      }
      }else{
        for (int i = 7; i >= 0; i--)
        {
          PORTA = ~(1<<i);  //PA7-0 nyala bergantian
          _delay_ms(500);
        }
      } 
  }
}