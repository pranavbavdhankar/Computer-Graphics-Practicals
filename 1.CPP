#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void dda(int x1, int y1, int x2, int y2){
	float x, y;
	float xinc, yinc;
	int steps, i;

	float dx = x2-x1;
	float dy = y2-y1;

	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	xinc = dx/steps;
	yinc = dy/steps;
	x = x1;
	y = y1;
	for(i = 0; i<=steps; i++){
//		cout<<x<<" "<<y<<endl;
		putpixel(x, y, (i)%10);
		x = x+xinc;
		y = y+yinc;
	}
	getch();
}

void main(){
	int x1, y1, x2, y2;
	int gd = DETECT, gm;
	clrscr();
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");
	cout<<"Enter end points of line";
	cin>>x1>>y1>>x2>>y2;
	dda(x1, y1, x2, y2);
	getch();
}