// Rotation and shear

#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>

float x1, y1, x2, y2, x3, y3, x4, y4;

void draw(float,float, float, float, float, float, float, float);

void rotate(){
	float angle;
	cout<<"Enter angle :";
	cin>>angle;
	angle = angle * (3.14/180);;
	rectangle(x1, y1, x3*cos(angle) - y3*sin(angle), x3*sin(angle) + y3*cos(angle));
}

void shear(){
	int ch;
	cout<<"Enter 1 to xshear 2 to y shear:";
	cin>>ch;
	if(ch == 1){
		clrscr();

		float shx;
		cout<<"Enter the value of shx:";
		cin>>shx;
		draw(x1 + shx*y1, y1, x2 + shx*y2, y2, x3 + shx*y3, y3, x4  + shx*y4, y4);
	}else if(ch == 2){
		clrscr();
		float shy;
		cout<<"Enter teh value of shy :";
		cin>>shy;
		draw(x1, y1 + shy*x1, x2, y2 + shy*x2, x3, y3+shy*x3, x4, y4+shy*x4);
	}
}

void draw(float _x1, float _y1, float _x2, float _y2, float _x3, float _y3, float _x4,float  _y4){
	line(_x1, _y1, _x2, _y2);
	line(_x2, _y2, _x3, _y3);
	line(_x3, _y3, _x4, _y4);
	line(_x4, _y4, _x1,_y1);
}

void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	cout<<"Enter the co-ordintaes of the ";

	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	draw(x1, y1, x2, y2, x3, y3, x4, y4);
//	rotate();
	shear();
	getch();
	closegraph();
}