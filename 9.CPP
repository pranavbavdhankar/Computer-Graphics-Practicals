#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void plot(int x, int y, int xc, int yc, int color){
	putpixel(-x+xc,-y+yc, color);
	putpixel(-x+xc, y+yc, color);
	putpixel(x+xc, -y+yc, color);
	putpixel(x+xc, y+yc, color);
	putpixel(-y+xc, -x+yc, color);
	putpixel(-y+xc, x+yc, color);
	putpixel(y+xc, -x+yc, color);
	putpixel(y+xc, x+xc, color);
}

void mcircle(int xc, int yc, int r, int color){
	int x = 0, y = r;
	int p = 1-r;
	while(x<y){
		x++;
		if(p<=0){
			 p = p+4*x+1;
		}else{
			p = p + 4*x-4*y+1;
			y--;
		}
		plot(x, y,xc, yc, color);
	}
}

void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");
	mcircle(100, 100, 50,1);
	mcircle(100,100, 40, 2);
	mcircle(100, 100, 30, 3);
	mcircle(100, 100, 20, 4);
	mcircle(100, 100, 10, 5);
	getch();
	getch();
}