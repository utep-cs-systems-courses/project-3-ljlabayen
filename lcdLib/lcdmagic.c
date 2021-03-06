/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  // drawString5x7(20,20, "MAGIC", COLOR_GREEN, COLOR_RED);

  //fillRectangle(-30,30, 80, 80, COLOR_RED);
  /*
  for (int i=0; i<100; i++)
    drawPixel(i,i, COLOR_PINK);
  for (int i=128; i> 100; i--)
    drawPixel(i, i, COLOR_RED);
  
  //triangle
  
  int j;
  for (j=0; j<80; j++){
    int row = j;
    for (int col=j; col < screenWidth - j; col++)
      drawPixel(col, row, COLOR_RED);	      
  }
 

  //right triangle
  
  int j;
  for (j=0; j<80; j++){
    int row = j;
    for (int col=0; col < j ; col++)
      drawPixel(row, col, COLOR_RED);
  }
  */

  //test shape
  int j;
  for (int i=110; i<160; i++){
    for (j=0; j < i; j++)
      drawPixel(j,i,COLOR_FOREST_GREEN);
  }
  //right wall
  for (j=110; j<130; j++){
    for(int k=0; k<j; k++)
      drawPixel(j,k,COLOR_NAVY);
  }
  /*
  for (j=0; j<20; j++){
    for(int k=0; k<j; k++)
      drawPixel(j,k,COLOR_NAVY);
  }
  */
  //triangle
  /*  for (j=0; j<80; j++){
    int row = j;
    for (int col=j; col < 30-j; col++)
      drawPixel(col, row, COLOR_RED);	      
      }*/
  /* 
  for (j=0; j<80; j++){
    int row = j;
    for (int col=j; col < 100-j; col++)
      drawPixel(col, row, COLOR_NAVY);	      
  }
  */

  drawRectOutline(25,20,60,50, COLOR_GOLD);
  fillRectangle(27,22,57,47, COLOR_YELLOW);

  for(int n=0; n<=20; n++);{
  for(int i=20; i>=0; i--) { 
    for(int k=0; k<=i; k++)
      drawPixel(k,i,COLOR_GREEN);
  }
  }
      
  
}
