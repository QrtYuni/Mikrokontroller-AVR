#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile int posisi = 0;  //deklarasi int
volatile int last_interrupt = 0;

ISR(INT0_vect){ //mengubah nilai interrupt terahir = 0
  last_interrupt = 0;
}

ISR(INT1_vect){ //mengubah nilai interrupt terahir = 1
 last_interrupt = 1;
}

int main (void){
  DDRC=0xff;  //PORTC OUTPUT
  PORTD |=_BV(PD2) | _BV(PD3); // pin PD.2 & PD.3 INPUT pullup
  EIMSK |= (1<<INT0) | (1<<INT1); // mengaktifkan interrupt
  EICRA |= _BV(ISC01) | _BV(ISC00) | _BV(ISC10) | _BV(ISC11); //rising edge activate INT0
  sei();  //  global interrupt
  PORTC = 0XFF;

  while (1){
  // cek nilai last_interrupt
    if(last_interrupt == 0){
      PORTC =~(1<<posisi);  //led posisi mati yg lain menyala
      posisi++;
      if (posisi == 6){
        posisi = 0;
      }
    }else if(last_interrupt == 1){
      PORTC =~(1<<posisi);//led posisi mati yg lain menyala
      posisi--;
      if (posisi == -1){
        posisi = 5;
      }
    }
    _delay_ms(500);
  }
  return 0;
}
