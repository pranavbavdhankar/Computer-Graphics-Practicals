// Breshnams line Algo
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");
	int x1, y1, x2, y2;
	cout<<"Enter the end points of line";
	cin>>x1>>y1>>x2>>y2;
	int dx =abs(x2-x1);
	int dy = abs(y2-y1);
	int p = 2*dy - dx;

	int x = x1;
	int y = y1;

	for(int i =0; i<dx-1; i++){
		x++;
		if(p <= 0)
			p = p+ 2*dy;
		else{
			p = p + 2*dy-2*dx;
			y++;
		}
		putpixel(x, y, WHITE);
		delay(20);
	}
	getch();
	closegraph();
}