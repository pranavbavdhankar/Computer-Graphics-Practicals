#include<iostream.h>
#include<conio.h>
#include<graphics.h>

float x1, x2, x3, x4, y1, y2, y3, y4;

void draw(){
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x4, y4);
	line(x4, y4, x1, y1);
}

void putpoints(float _x1, float _y1, float _x2, float _y2, float _x3, float _y3, float _x4, float _y4){
	setcolor(RED);
	line(_x1, _y1, _x2, _y2);
	line(_x2, _y2, _x3, _y3);
	line(_x3, _y3, _x4, _y4);
	line(_x4, _y4, _x1, _y1);
}

void translate(){
	int tx, ty;
	cout<<"Enter the value of tx and ty";
	cin>>tx>>ty;
	line(x1+tx, y1+ty, x2+tx, y2+ty);
	line(x2+tx, y2+ty, x3+tx, y3+ty);
	line(x3+tx, y3+ty, x4+tx, y4+ty);
	line(x4+tx, y4+ty, x1+tx, y1+ty);
}

void shear(){
	int ch;
	cout<<"Enter 1 to x-shear and 2 to y-shear";
	cin>>ch;
	if(ch == 1){
		cout<<"Enter the value of shx:";
		float shx;
		cin>>shx;
		putpoints(x1 + y1*shx, y1, x2+y2*shx, y2, x3+y3*shx, y3, x4+y4*shx, y4);
	}else if(ch == 2){
		cout<<"Enter the value of shy:";
		float shy;
		cin>>shy;
		putpoints(x1, y1 + x1*shy, x2, y2 + x2 * shy, x3, y3 + x3*shy, x4, y4+ x4*shy);
	}else{
		cout<<"Invalid choice";
	}
}


void scale(){
	cout<<"Enter the value of sx and sy:";
	int sx, sy;
	cin>>sx>>sy;
	putpoints(x1*sx, y1*sy, x2*sx, y2*sy, x3*sx, y3*sy, x4*sx, y4*sy);
}

void drawaxis(){
	int xmax = getmaxx();
	int ymax = getmaxy();
	line(xmax/2, 0, xmax/2, ymax);
	line(0, ymax/2,xmax, ymax/2);
}

void reflection(){
	int xmax = getmaxx()/2;
	int ymax = getmaxy()/2;
	int ch;
	cout<<"Enter 1 to refelction about x-axis. 2 to reflecion about y-axis. 3 to reflection about y=x";
	cin>>ch;
	putpoints(xmax+x1,ymax-y1, xmax+x2,ymax-y2, xmax+x3 ,ymax- y3, xmax+x4,ymax-y4);
	if(ch == 1){
		setcolor(BLUE);
		putpoints(xmax+x1, ymax+y1, xmax+x2, ymax+y2, xmax+x3, ymax+y3, xmax+x4, ymax+y4);
	}else if(ch == 2){
		setcolor(YELLOW);
		putpoints(xmax-x1,ymax- y1, xmax-x2, ymax-y2, xmax-x3,ymax- y3, xmax-x4, ymax-y4);
	}else if(ch == 3){
		setcolor(GREEN);
		putpoints(xmax-x1, ymax+y1, xmax-x2, ymax+y2, xmax-x3, ymax+y3, xmax-x4, ymax+y4);
	}else{
	}
}
void main(){
	int gd = DETECT, gm;
	clrscr();
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	//int x1, x2, x3, x4, y1, y2, y3, y4;
	cout<<"Enter the 4 coordinates of the polygon as (x, y)";
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	draw();
//	scale();
//	drawaxis();
  //	reflection();
	shear();
	getch();
}
