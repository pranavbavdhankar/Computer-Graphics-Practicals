

// DDA Algo
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");
	float x1, y1, x2, y2;
	cout<<"Enter the end points of line";
	cin>>x1>>y1>>x2>>y2;
	float dx = x2-x1;
	float dy = y2-y1;

	int steps = dx > dy ? abs(dx) : abs(dy);
	float xinc = dx/steps;
	float yinc = dy/steps;

	float x = x1;
	float y = y1;
	while(steps-- > 0){
		putpixel(floor(x+0.5), floor(y+0.5), WHITE);
		x = x + xinc;
		y = y + yinc;
		delay(10);
	}
	getch();
	closegraph();
}