#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachineAssembly.h"
#include "lcdDisplay.h"

int redrawScreen = 1;

void main() 
{
  P1DIR |= LED_GREEN;
  P1OUT |= LED_GREEN;
  
  configureClocks();
  switch_init();
  buzzer_init();
  led_init();
  enableWDTInterrupts();
  lcd_init();
  
  drawInit();
  
  or_sr(0x8);  // GIE on

  for(;;) {
    while(!redrawScreen){
      P1OUT &= ~LED_GREEN;
      or_sr(0x10);
    }
    P1OUT |= LED_GREEN;
    __delay_cycles(30000); //delay clock cycle to make LED more visible when CPU is on
    redrawScreen = 0;
  }
}

void wdt_c_handler() {
  static short count = 0;
  static short dim = 0;
  count++;
    if (count == 125) {
      state_advance();
      count = 0;
    }
    if (switch_state_changed == 2) {
      if (count == 5) {
	state_advance();
	count = 0;
      }
    }
}
  
