#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void ffill(int x, int y, int bgcolor, int fcolor){
	int cp = getpixel(x, y);
	if(cp == bgcolor && cp != fcolor){
		putpixel(x, y, fcolor);
		delay(10);
		ffill(x+1, y,bgcolor, fcolor);
		ffill(x-1, y, bgcolor, fcolor);
		ffill(x, y-1, bgcolor, fcolor);
		ffill(x, y+1, bgcolor,  fcolor);
	}
}

void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");
	rectangle(100, 100, 120, 120);
	ffill(110, 110, BLACK, RED);
	getch();
}