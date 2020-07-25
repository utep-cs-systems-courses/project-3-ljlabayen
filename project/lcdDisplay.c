#include <msp430.h>
#include <abCircle.h>
#include <shape.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachineAssembly.h"
#include "lcdutils.h"
#include "lcddraw.h"

int redrawScreen;

void triangle(u_char colMin, u_char rowMin, u_char width, u_char height, u_int colorBGR) {
  for (int i = colMin; i < width; i++) {
    drawPixel(i, i, colorBGR);
  }
}
  
void drawTriangle(int color){
    int j;
  for (j=30; j<60; j++){
    int row = j;
    for (int col=j; col < 100 - j; col++)
      drawPixel(col+15, row, color);	      
  }
}

void triangleShow() {
  int color = 0x001F;
  for(int i = 0; i < 20; i++){
    redrawScreen = 1;
    __delay_cycles(20000);
    drawTriangle(color);
    __delay_cycles(20000);
    color = color << 1;
    drawTriangle(color);
  }
}

void drawInit() {
  redrawScreen = 1;
  clearScreen(COLOR_BLUE);
  int j;
  // bottom shape
  for (int i=110; i<160; i++){
    for (j=0; j < i; j++)
      drawPixel(j,i,COLOR_FOREST_GREEN);
  }
  //right wall
  for (j=110; j<130; j++){
    for(int k=0; k<j; k++)
      drawPixel(j,k,COLOR_NAVY);
  }

  //left wall
  for (int i = 19; i >= 0; i--) {
    for (int j = 0; j <= i; j++)
      drawPixel(i-j, j+110, COLOR_NAVY);
  }
  fillRectangle(0,0,20,110, COLOR_NAVY);
  drawRectOutline(35,20,60,50, COLOR_GOLD);
  fillRectangle(37,22,57,47, COLOR_WHITE);
  drawString5x7(10,130,"Comp Arch1 SU 2020",COLOR_DEEP,COLOR_FOREST_GREEN);
  drawString11x16(10,140,"PROJECT 3",COLOR_BLACK,COLOR_FOREST_GREEN);
  redrawScreen = 1;
  /*
  for(;;){
    fillRectangle(37,22,57,47, COLOR_RED);
    // __delay_cycles(20000000);
    // redrawScreen = 1;
    fillRectangle(37,22,57,47, COLOR_GREEN);
    // __delay_cycles(20000000);
    //\ redrawScreen =1;
    fillRectangle(37,22,57,47, COLOR_BLUE);
    //    __delay_cycles(20000000);
    redrawScreen = 1;
  }
  */
  
}


void clearWindow() {
  fillRectangle(37,22,57,47, COLOR_WHITE);
  redrawScreen = 1;
}
