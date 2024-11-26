#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<malloc.h>
#define SIZE 4

int x1, y1, x2, y2;
int xwmin, xwmax, ywmin, ywmax;
float m;
int *p1, *p2;

void clipleft(int);
void clipright(int);
void clipbottom(int);
void  cliptop(int);
void callclipfun(int l, int side){
	switch(side){
		case 0: clipleft(l); break;
		case 1: clipright(l); break;
		case 2: clipbottom(l); break;
		case 3: cliptop(l); break;
	}
}

void clip(int l){
	getch();
	clrscr();
	rectangle(xwmin, ywmin, xwmax, ywmax);
	for(int i = 0; i<4; i++){
		if(l == 1 && p1[i] == 1)
			callclipfun(1, i);
		if(l == 2 && p2[i] ==1)
			callclipfun(2, i);
	}
	setcolor(RED);
	line(x1, y1, x2, y2);
}

void clipleft(int l){
	cout<<"Left chip";
	int x, y;
	if(l == 1){
		x = xwmin;
		y = -((m*(x1-x))-y1);
		x1 = x;
		y1 = y;
	}else if(l == 2){
		x = x2;
		y = -((m*(x2-x)-y2));
		x2=x;
		y2=y;
	}
}

void clipright(int l){
	cout<<"Right clip";
	int x, y;
	if(l == 1){
		x = xwmax;
		y = -((m*(x1-x)-y1));
		x1=x;
		y1=y;
	}else if(l == 2){
		x = xwmax;
		y = -((m*(x2-x)-y2));
		x2 = x;
		y2 = y;
	}
}

void clipbottom(int l){
	cout<<"Bottom clip";
	int x, y;
	if(l == 1){
		y = xwmax;
		x = -((y1-y)/m)+x1;
		x1 = x;
		y1 = y;
	}if(l == 2){
		y = ywmax;
		x = -((y2-y)/m)+x2;
		x2 = x;
		y2 = y;
	}
	cout<<x<<" " <<y;
}


void cliptop(int l){
	cout<<"Clip top";
	int x, y;
	if(l == 1){
		y = ywmin;
		x = -((y1-y)/m)+x1;
		x1 = x;
		y1=y;
	}if(l == 2){
		y = ywmin;
		x = -((y2-y)/m)+x2;
		x2 = x;
		y2 = y;
	}
}


// performing the logical AND of the region codes
int logicalAND(){
	for(int i = 0; i<4; i++){
		if(p1[i] == 1 && p2[i] == 1) return 0;
	}
	return 1;
}
int logicalOR(){
	for(int i = 0; i<4; i++){
		if(p1[i] == 1 || p2[i] == 1) return 0;
	}
	return 1;
}

int* findregioncode(int x, int y){
	int* arr = new int[SIZE];
	;
	for(int i = 0; i<SIZE; i++) arr[i] = 0;
	//left
	if(x < xwmin){
		arr[0] = 1;
	}
	// right
	if(x > xwmax){
		arr[1] = 1;
	}
	// top
	if(y < ywmin){
		arr[3] = 1;
	}
	// bottom
	if(y > ywmax){
		arr[2] = 1;
	}
	cout<<"Region codes";
	for(i = 0; i<4; i++)
		cout<<arr[i]<" ";
	cout<<endl;
	return arr;
}
void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");
	// Line endpoints input
	cout<<"Enter the end pooints of line:";
	cin>>x1>>y1>>x2>>y2;
	// window endpoints input
	cout<<"Enter the endpoits of window";
	cin>>xwmin>>ywmin>>xwmax>>ywmax;
	// slope of the line
	m = (float)(y2-y1)/(float)(x2-x1);
	rectangle(xwmin, ywmin, xwmax, ywmax);
	line(x1, y1, x2, y2);
	// getting the region code for the line
	p1 =findregioncode(x1, y1);
	p2 = findregioncode(x2, y2);
	// logical OR to check weather line is completely inside or not
	int res = logicalOR();
	if(res == 1){
		cout<<"No need of clipping";
	}else{
		// logical AND for checking the position of the line
		res =logicalAND();
		if(res == 0){
			cout<<"Line is completrly outside, reejecting it";
		}else{
			cout<<"Line is partially inside need to clip it";
			// clipping logic
			// point 1
			clip(1);
			clip(2);

		}
	}



	getch();
}