#ifndef lcdDisplay_included
#define lcdDisplay_included
void triangle(u_char colMin, u_char rowMin, u_char width, u_char height, u_int colorBGR);
void drawTriangle(int color);
void triangleShow();
void clearWindow();
void drawInit();

extern int redrawScreen;

#endif
