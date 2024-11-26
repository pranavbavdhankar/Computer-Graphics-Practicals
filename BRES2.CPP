// Breshnams line Algo for steep slope
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
	int dx = abs(x2-x1);
	int dy = abs(y2-y1);
	int p = 2*dx - dy;
	// check the steep slope
	int steep = (dy> dx);
	int x = x1;
	int y = y1;

	if(steep){
	   swap(&x1, &y1);
	   swap(&x2, &y2);
	   swap(&dx,&dy);
	}

	cout<<x1<<y1;
	cout<<x2<<y2;
	cout<<dx<<dy;
	if(x1 > x2){
		swap(&x1, &x2);
		swap(&y1, &y2);
	}
	int ystep = (y2 > y1) ? 1 : -1;

	clrscr();


	for(int i = x1; i<=x2; i++){
		x++;
		if(steep){
			putpixel(y, x, WHITE);
		}else{
			putpixel(x, y, WHITE);
		}

		if(p < 0){
			p = p +  2*dx;

		}else{
			y+=ystep;
			p = p + 2*dx-2*dy;
		}
		delay(10);
	}


	getch();
	closegraph();
}