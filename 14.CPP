#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void translate(int x1,int y1, int x2, int y2){
	int tx, ty;
	cout<<"Enter the value of tx and ty";
	cin>>tx>>ty;
	rectangle(x1+tx, y1+ty, x2+tx, y2+ty);
}

void scale(int x1, int y1, int x2, int y2){
	cout<<"Enter the value of sx and sy";
	int sx, sy;
	cin>>sx>>sy;;
	rectangle(x1*sx, y1*sy, x2*sx, y2*sy);
}

void rotation(int x1, int y1, int x2, int y2){
	float angle;
	cout<<"Enter the angle of rotation";
	cin>>angle;
	angle=(angle*3.14)/180;
	rectangle(x1,y1, x2*cos(angle)-y2*sin(angle),x2*sin(angle)+y2*cos(angle));

}

void main(){
	int gd = DETECT, gm;
	int x1 = 100, y1=100, x2=200, y2=200;
	clrscr();
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");
	rectangle(x1, y1, x2, y2);
	setcolor(RED);
	rotation(x1, y1, x2, y2);
	getch();
}