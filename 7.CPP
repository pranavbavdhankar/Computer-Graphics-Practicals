
#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm,"c:\\turboc3\\bgi");
	circle(100, 200, 20);
	circle(200, 200, 20);
	line(200, 200, 160, 140);
	line(120,180, 120, 180);
	line(100, 200, 120, 180);
	line(100,200, 160, 200);
	line(180, 180, 160, 200);
	getch();
}