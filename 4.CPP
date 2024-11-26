#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void symmetry(int x, int y, int xc, int yc, int color){
	putpixel(-x+xc,-y+yc, color);
//	putpixel(-x+xc, y+yc, 1);
	putpixel(x+xc, -y+yc, color);
  //	putpixel(x+xc, y+yc, 1);
	putpixel(-y+xc, -x+yc, color);
  //	putpixel(-y+xc, x+yc,1);
	putpixel(y+xc, -x+yc, color);
  //	putpixel(y+xc, x+yc, RED);
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

	int x=100, y=100, i, r=10;
	int gd = DETECT, gm;
	clrscr();
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	for(i = 0; i<7; i++){
		for(int j = 0; j<10; j++, r++){
			mcircle(x, y, r, i+1);
		}
	}
	getch();
}