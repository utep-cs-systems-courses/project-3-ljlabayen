#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachineAssembly.h"
#include "lcdutils.h"
#include "lcddraw.h"

int redrawScreen;

// draws pink triangle used for button/switch 1
void drawPinkTriangle(){
    int j;
  for (j=30; j<60; j++){
    int row = j;
    for (int col=j; col < 100 - j; col++)
      drawPixel(col+15, row, COLOR_HOT_PINK);	      
  }
}
// helper method for triangleShow method. takes color as parameter  
void drawTriangle(int color){
    int j;
  for (j=30; j<60; j++){
    int row = j;
    for (int col=j; col < 100 - j; col++)
      drawPixel(col+15, row, color);	      
  }
}

// method for changing color of the triangle 
void triangleShow() {
  int color = 0x001F; // set initial color in hex
  for(int i = 0; i < 20; i++){
    drawTriangle(color);
    __delay_cycles(40000); // delay to clk cycles to slow down color change
    color = color << 1; // shift left 1 to current hex color
    drawTriangle(color);
  }
}

// simple rectangle used to show change using interrupts
void drawRect() {
  fillRectangle(37,22,57,47, COLOR_BLACK);
  fillRectangle(42,27,47,37, COLOR_YELLOW);
}

// draw initialization. used to draw algorithmically rendered background for project 3
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
}

// used to clear the small display window to avoid overlap with the shapes
void clearWindow() {
  fillRectangle(37,22,57,47, COLOR_WHITE);
  redrawScreen = 1;
}
