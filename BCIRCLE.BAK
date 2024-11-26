#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void plot(int x, int y, int xc, int yc){
	putpixel(xc+x, yc+y, WHITE);
	putpixel(xc+x, yc-y, WHITE);
	putpixel(xc-x, yc+y, WHITE);
	putpixel(xc-x, yc-y, WHITE);
	putpixel(xc+y, yc+x, WHITE);
	putpixel(xc+y, yc-x, WHITE);
	putpixel(xc-y, yc+x, WHITE);
	putpixel(xc-y, yc-x, WHITE);
}

void main(){
	int xc, yc, r;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	cout<<"Enter center of teh circle and radius : ";
	cin>>xc>>yc>>r;
	int p = 3-2*r;
	int x = 0, y = r;
	while(y >= x){
		x++;
		if(p < 0){
			p = p + 4*x + 6;
		}else{
			p = p + 4*(x-y) + 10;
			y--;
		}
		plot(x, y, xc, yc);
	}



	getch();
	closegraph();

}