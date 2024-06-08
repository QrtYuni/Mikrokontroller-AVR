// Implementasikan traffic light untuk pejalan kaki untuk penyebrangan jalan. 
// Ada 2 traffic Light. 
// 1 buat traffic light untuk kendaran dan  (LED merah, kuning, hijau) 
// 1 buah lagi diarahkan ke pejalan kaki.   (LED merah, hijau)
// Lampu Traffic Light Kendaran akan selalu nyala defaultnya dan 
// lampu untuk pejalakan kaki defaultnya akan mati
// button untuk start/reset

// Nama   : Qurrota A'yuni Jumayanti
// Kelas  : 2 D3 Elektronika A
// NRP    : 2122500009

#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRA = 0xFF;      //output 3+2 led 
  DDRB &=~ (1<<4);  //input start/reset
  PORTB |= (1<<4);  //  mengaktifkan pushb button
  // input led : Car-merah(PA0) - Car-kuning(PA1) - Car-hijau(PA2) 
            // Pejalan kaki-merah(PA3) - Pejalan kaki-hijau(PA4)

  while(1){
    PORTA = 0b01100; //setting awal untuk PA0-PA4 
    
    if (!(PINB &(1<<4))){  //Jika PB4 ditekan
      // Lampu kuning kendaraan nyala 1 detik, lampu pejalan kaki default, yang lain mati
      PORTA = 0b01010;
      _delay_ms (1000); 

      // Lampu merah kendaraan nyala, dan lampu hijau pejalan kaki nyala 3 detik
      PORTA = 0b10001;
      _delay_ms(3000);

      // Lampu kuning kendaraan nyala, dan lampu merah pejalan kaki nyala 2 detik 
      PORTA = 0b01010;
      _delay_ms(2000);

      // Kembali ke keadaan awal 
      PORTA = 0b01100;
    }
  }
}