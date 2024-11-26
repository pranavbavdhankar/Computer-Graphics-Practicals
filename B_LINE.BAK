#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void bline(int x1, int y1, int x2, int y2){
	int dy = y2-y1;
	int dx = x2-x1;

	if(abs(dx) > abs(dy)){ // gentel
		int p = 2*dy-dx;
		int x = x1, y = y1;
		while(x<x2){
			x++;
			if(p < 0){
				p = p+2*dy;
			}else{
				p= p + 2*(dy-dx);
				y++;
			}
			putpixel(x, y, WHITE);
		}
	}else{  // steep slope
		int p = 2*dx-dy;
		int x = x1, y = y1;

		while(x < x2){
			y++;
			if(p < 0){
				p = p + 2*dx;
			}else{
				p = p + 2*(dx-dy);
				x++;
			}
			putpixel(x, y, RED);
		}

}

}
void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	bline(200, 200, 100, 100);
	getch();
	closegraph();
}