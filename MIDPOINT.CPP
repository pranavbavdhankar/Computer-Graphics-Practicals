
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void plot(int x, int y, int xc , int yc){
	putpixel(x+xc,y+yc, WHITE);
	putpixel(x+xc,-y+yc, WHITE);
	putpixel(-x+xc, y+yc, WHITE);
	putpixel(-x+xc,-y+yc, WHITE);
	putpixel(y+xc,x+yc, WHITE);
	putpixel(y+xc,-x+yc, WHITE);
	putpixel(-y+xc,x+yc, WHITE);
	putpixel(-y+xc,-x+yc, WHITE);
}

void main(){
	int gd= DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");
	int xc, yc, r;
	cout<<"ENter the center and radius of the circle";
	cin>>xc>>yc>>r;

	float p = 1-r;
	int x = 0, y = r;
	while(x<y){
		x++;
		if(p < 0){
			p = p + 2*x+1;
		}else{
			p = p + 2*x-2*y+1;
			y--;
		}
		plot(x, y, xc, yc);
	}


	getch();
	closegraph();
}