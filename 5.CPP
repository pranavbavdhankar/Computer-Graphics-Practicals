
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void symmetry(int x, int y, int xc, int yc, int color){
	putpixel(-x+xc,-y+yc, color);
	putpixel(-x+xc, y+yc, color);
	putpixel(x+xc, -y+yc, color);
	putpixel(x+xc, y+yc, color);
	putpixel(-y+xc, -x+yc, color);
	putpixel(-y+xc, x+yc, color);
	putpixel(y+xc, -x+yc, color);
	putpixel(y+xc, x+yc, color);
}


void mcircle(int xc, int yc, int r, int color){
	int p = 1-r;
	int x = 0;
	int y = r;
	while(x<y){
		 x++;
		 if(p<0){
			p = p + 2*x+1;
		 }else{
			p = p +  2*x-2*y + 1;
			y--;
		 }
		 symmetry(x, y, xc, yc, color);
	}
}

void main(){
	int x, y, i, r=25;
	int gd = DETECT, gm;
	clrscr();
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

	mcircle(100, 100, r, BLUE);
	mcircle(160,100, r, WHITE);
	mcircle(220, 100, r, RED);
	mcircle(130, 120, r, YELLOW);
	mcircle(190, 120, r, GREEN);
	getch();
}