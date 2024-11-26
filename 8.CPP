#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>


void dda(int x1, int y1, int x2, int y2){
	float x, y, xinc, yinc;
	int dx, dy, steps;
	x = x1;
	y = y1;
	dx =(x2-x1);
	dy = (y2-y1);
	steps =  dx > dy ? abs(dx) : abs(dy);
	xinc=dx/(float)steps;
	yinc = dy/(float)steps;

	for(int i = 0; i<=steps; i++){
		putpixel(floor(x+0.5), floor(y+0.5), 1);
		x+=xinc;
		y+=yinc;
		delay(10);
	}
}

void main(){
	int gd = DETECT, gm;
	clrscr();
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");

	dda(50, 200, 100, 100);
	dda(100, 100, 150, 200);
	dda(150, 200, 30, 140);
	dda(30, 140, 170, 140);
	dda(170, 140, 50, 200);
	getch();
}