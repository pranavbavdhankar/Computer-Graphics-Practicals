#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void plotpoints(int x, int y, int xc, int yc, int side){
	if(side == 1){
		putpixel(-y+xc, -x+yc, 1);
		putpixel(-x+xc, -y+yc, 1);
		putpixel(x+xc, -y+yc, 1);
		putpixel(y+xc, -x+yc, 1);
	}else{
		putpixel(-y+xc, x+yc, 1);
		putpixel(-x+xc, y+yc, 1);
		putpixel(x+xc,y+yc, 1);
		putpixel(y+xc, x+yc, 1);
	}
}


void bcircle(int xc, int yc, int r, int side){
	int x = 0, y = r;
	int p = 3-2*r;
	while(x<y){
		x++;
		if(p<=0){
			p = p+4*x+6;
		}else{
			p = p+4*x-4*y+10;
			y--;
		}
		plotpoints(x, y, xc, yc, side);
	}
}


void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");


	line(50,100,100+(50*10) ,100);
	line(50, 0, 50, 200);
	for(int i = 1; i<=10; i++){
		bcircle(25+(50*i), 100, 25, i%2);
	}
	getch();
}