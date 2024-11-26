
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

void bline(int x1, int y1, int x2, int y2){
	int x, y, i;
	int dx=abs(x2-x1);
	int dy = abs(y2-y1);

	int steps = dx;
	int p = 2*(dy)-dx;
	x = x1;
	y = y1;
	for(i = 0; i<=steps; i++){
		x++;
		if(p<=0){
			p = p + 2*dy;
		}else{
			y++;
			p = p + 2*dy-2*dx;
		}
		putpixel(x, y, BLUE);
	}
	getch();
}
void main(){
	int x1, x2, y1, y2;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");

	cout<<"Enter the end points of the line";
	cin>>x1>>y1>>x2>>y2;
	bline(x1, y1, x2, y2);
	getch();
}

