#include <msp430.h>
#include <abCircle.h>
#include <shape.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachineAssembly.h"
#include "lcdDisplay.h"

AbRArrow rightArrow = {abRArrowGetBounds, abRArrowCheck,30};

Layer layer0 = {
    (AbShape *)&rightArrow, {(screenWidth/2)+10, (screenHeight/2)+5},{0,0},{0,0}, COLOR_ORANGE,			   0};
u_int bgColor;
int redrawScreen = 1;

void main() 
{
  P1DIR |= LED_GREEN;
  P1OUT |= LED_GREEN;
  
  configureClocks();
  clearScreen(COLOR_GREEN);
  switch_init();
  buzzer_init();
  led_init();
  enableWDTInterrupts();
  lcd_init();
  shapeInit();
  drawInit();
  
  layerInit(&layer0);
  layerDraw(&layer0);
  
  //u_char width = screenWidth, height = screenHeight;
  or_sr(0x8);  // GIE on

  for(;;) {
    while(!redrawScreen){
      P1OUT &= ~LED_GREEN;
      or_sr(0x10);
    }
    // clearWindow();
    P1OUT |= LED_GREEN;
    __delay_cycles(30000);
    redrawScreen = 0;
  }
}

void wdt_c_handler() {
  static short count = 0;
  // P1OUT |= LED_GREEN;
  count++;
    if (count == 125) {
      state_advance();
      count = 0;
    }
    //    P1OUT &= ~LED_GREEN;
}
  
