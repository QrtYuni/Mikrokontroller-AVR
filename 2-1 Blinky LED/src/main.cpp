// Nama  : Qurrota A'yuni Jumayanti
// Kelas : 2 D3 Elektronika A
// NRP   : 2122500009 

#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRB |= (1<<DDB7);  //led bawaan arduino

  while(1){
    PORTB ^= (1<<7); // nyala-mati led PB7
    _delay_ms(400);
  }
}