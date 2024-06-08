#include <avr/io.h>
int main(void){
DDRE= _BV(PE3); //activate PWM output
TCCR3B= _BV(CS30); //prescaller 1 
TCCR3A = _BV(WGM30)|_BV(COM3A1); //non inverting
OCR3A=200;
while(1)
{
}
}