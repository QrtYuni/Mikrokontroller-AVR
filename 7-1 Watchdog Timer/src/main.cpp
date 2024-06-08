#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>
volatile int f_wdt=0;
int counter=0;
ISR(WDT_vect)
{
if(f_wdt == 0)
{
f_wdt=1;
}
else
{
}
}
int main(void) {
DDRB |= (1<<7); //portB.7 output
DDRA=0xFF;
/* Clear the reset flag. */
MCUSR &= ~(1<<WDRF);
/* In order to change WDE or the prescaler, we need to
 * set WDCE (This will allow updates for 4 clock cycles).
 */
WDTCSR |= (1<<WDCE) | (1<<WDE);
/* set new watchdog timeout prescaler value */
 WDTCSR = (1<<WDP2) | (1<<WDP1)|(1<<WDP0); /* 4.0 seconds */
// wdt_enable(WDTO_4S); // don't used, cause system reset.
/* Enable the WD interrupt (note no reset). */
WDTCSR |= _BV(WDIE);
sei(); // don't forget to activate global interrupt
while(1){
if(f_wdt == 1)
{
/* Toggle the LED */
PORTB ^=(1<<7);
/* Don't forget to clear the flag. */
f_wdt = 0;
/* Re-enter sleep mode. */
// enterSleep();
}
else
{
/* Do nothing. */
_delay_ms(1000);
PORTA=~counter++;
}
}
}
