#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void boundaryfill(int x, int y, int bColor, int nColor){
	int p = getpixel(x, y);
	if(p != bColor && p!= nColor)
	{
		delay(10);
		putpixel(x, y, nColor);
		boundaryfill(x+1, y, bColor, nColor);
		boundaryfill(x-1, y, bColor, nColor);
		boundaryfill(x, y+1, bColor, nColor);
		boundaryfill(x, y-1, bColor, nColor);
	}
}

void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");
	rectangle(100, 100, 120, 120);
	boundaryfill(115, 115, WHITE, RED);
	getch();
}
