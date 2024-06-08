// Nama  : Qurrota A'yuni Jumayanti
// Kelas : 2 D3 Elektronika A
// NRP   : 2122500009

#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRA = 0xFF;  // input led
  PORTA = 0xFF; // input led PA

  while(1){
    for (int i = 0; i <=7; i++)
    {
      PORTA = ~(1<<i);  // led PA 0-7 nyala bergantian
      _delay_ms(300);
    }
    for (int i = 7; i >= 0; i--)
    {
      PORTA = ~(1<<i);  // led PA 7-0 nyla bergantian
      _delay_ms(300);
    }
  }
}