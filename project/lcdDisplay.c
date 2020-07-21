#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachineAssembly.h"
#include "lcdutils.h"
#include "lcddraw.h"

void drawTriangle(int color){
    int j;
  for (j=0; j<80; j++){
    int row = j;
    for (int col=j; col < 100 - j; col++)
      drawPixel(col, row, color);	      
  }
}

void triangleShow() {
  int color = 0x001F;
  for(int i = 0; i < 5; i++){
   drawTriangle(color);
   __delay_cycles(20000);
   color = color << 1;
   drawTriangle(color);
  }
}
