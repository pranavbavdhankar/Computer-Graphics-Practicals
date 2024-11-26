
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void symmetry(int x, int y, int xc, int yc){
	putpixel(-x+xc,-y+yc, 1);
	putpixel(-x+xc, y+yc, 1);
	putpixel(x+xc, -y+yc, 1);
	putpixel(x+xc, y+yc, 1);
	putpixel(-y+xc, -x+yc, 1);
	putpixel(-y+xc, x+yc, 1);
	putpixel(y+xc, -x+yc, 1);
	putpixel(y+xc, x+yc, 1);
}


void mcircle(int xc, int yc, int r){
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
		 symmetry(x, y, xc, yc);
	}
}

void main(){
	int x, y, i, r;
	int gd = DETECT, gm;
	clrscr();
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	cout<<"Enter the center of the circle and the radius";
	cin>>x>>y>>r;
	mcircle(x, y, r);
	getch();
}