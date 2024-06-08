#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>
uint8_t data;
int main (void) {
DDRB|=(1<<DDB7);
DDRB|=(1<<DDB5);
PORTB|= (1<<4); // D9-PH.6 pullup pushbtn -konfirm mode
PORTH|= (1<<5); // D10-PB.4 pullup pushbtn --change mode
PORTH|= (1<<6); // D8-PH.5 pullup pushbtn -run
DDRA=0xFF;
data=eeprom_read_byte((uint8_t*)0);
PORTA=~data;

while(1){

  while (!(PINB&(1<<4)))
  {
    if(data++<=8) {
      PORTA=~data;
      _delay_ms(700);
    } else {
      data=0;
    } 
  }

  if (!(PINH & (1<<6))){
    eeprom_write_byte((uint8_t*)0,data); // write data to eeprom
    for (int i=0;i<8;i++) {
      PORTB ^=(1<<7);
      _delay_ms(200);
    }
  }

  if (!(PINH & (1<<5))){
    data=eeprom_read_byte((uint8_t*)0);
    PORTA=0xFF;
    _delay_ms(800);
    PORTA=~data;
    if(data==1){
      while(1){
      PORTB ^= (1<<5);
      _delay_ms(700);
      }
    } 
    
    if(data==2){
      while(1){
      PORTB ^= (1<<5);
      _delay_ms(300);
      }
    } 
     if(data==3){
      while(1){
      PORTB ^= (1<<5);
      _delay_ms(100);
      }
    } 
  }}
}

