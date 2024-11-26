#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<malloc.h>
#define SIZE 4
#define MAX 40

// int x1, y1, x2, y2;
int points[MAX][2];
int xwmin, xwmax, ywmin, ywmax;
float slope[MAX];
// int *p1, *p2;
int regioncode[MAX][4];
int n;


void drawpolygon(){
	int i = 0;
	clrscr();
	for(i = 0; i<n-1; i++){
		line(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
		// cout<<points[i][0]<<points[i][1]<<points[i+1][0]<<points[i+1][1]<<endl;
	}
	// cout<<points[n-1][0]<<points[n-1][1]<<points[0][0]<<points[0][1];
	line(points[n-1][0], points[n-1][1], points[0][0], points[0][1]);
}

 void clipleft(int);
 void clipright(int);
 void clipbottom(int);
 void  cliptop(int);
void callclipfun(int lineno, int side){
	switch(side){
		case 0: clipleft(lineno); break;
		case 1: clipright(lineno); break;
		case 2: clipbottom(lineno); break;
		case 3: cliptop(lineno); break;
	}
}

void clip(int lineno){
	getch();
	clrscr();
	rectangle(xwmin, ywmin, xwmax, ywmax);
	for(int i = 0; i<4; i++){
		if(regioncode[lineno][i] == 1)
			callclipfun(lineno, i);
	}
	setcolor(RED);
//	drawpolygon();
}

void clipleft(int l){
	cout<<"Left chip";
	int x, y;
	x = xwmin;
	y = -((slope[l]*(points[l][0]-x))-points[l][1]);
	points[l][0] = x;
	points[l][1] = y;
}

void clipright(int l){
	cout<<"Right clip";
	int x, y;
	x = xwmax;
	y = -((slope[l]*(points[l][0]-x)-points[l][1]));
	points[l][0]=x;
	points[l][1]=y;

}

void clipbottom(int l){
	cout<<"Bottom clip";
	int x, y;
	y = ywmax;
	x = -((points[l][1]-y)/slope[l])+points[l][0];
	points[l][0] = x;
	points[l][1] = y;
}


void cliptop(int l){
	cout<<"Clip top";
	int x, y;

	y = ywmin;
	x = -((points[l][1]-y)/slope[l])+points[l][0];
	points[l][0] = x;
	points[l][1] = y;
}


// performing the logical AND of the region codes
int logicalAND(int l1, int l2){
	for(int i = 0; i<4; i++){
		if(regioncode[l1][i] == 1 && regioncode[l2][i] == 1) return 0;
	}
	return 1;
}
int logicalOR(int l1, int l2){
	for(int i = 0; i<4; i++){
		if(regioncode[l1][i] == 1 || regioncode[l2][i] == 1) return 0;
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
		cout<<arr[i]<<" ";
	 cout<<endl;
	return arr;
}

void main(){
	int gd = DETECT, gm;
	int i;
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");
	// Enter the points of the polygon
	cout<<"Enter total number of points : ";
	cin>>n;
	if(n > 20) {
		cout<<"Points should be less than 20";
		return;
	}
	// Input the co-ordinates of the points;
	for(i = 0; i<n; i++){
		cout<<"Enter the co-ordinates for point "<<(i)+1<<" as (x, y) : ";
		cin>>points[i][0]>>points[i][1];
	}
	drawpolygon();
	// window endpoints input
	cout<<"Enter the endpoits of window";
	cin>>xwmin>>ywmin>>xwmax>>ywmax;
	cout<<xwmin<<ywmin<<xwmax<<ywmax;
	rectangle(xwmin, ywmin, xwmax, ywmax);
	getch();

	// calculate the slope and region codes
	// regioncode = new int*[n];
	for(i = 0; i<n; i++){
		cout<<points[i][0]<<" " <<points[i][1]<<endl;
		for(int j = 0; j<SIZE; j++) regioncode[i][j] = 0;
		//left
		if(points[i][0] < xwmin){
			regioncode[i][0] = 1;
		}
		// right
		if(points[i][0] > xwmax){
			regioncode[i][1] = 1;
		}
		// top
		if(points[i][1] < ywmin){
			regioncode[i][3] = 1;
		}
		// bottom
		if(points[i][1] > ywmax){
			regioncode[i][2] = 1;
		}
		 cout<<"Region codes";
		 for(j = 0; j<4; j++)
			cout<<regioncode[i][j]<<" ";
		 cout<<endl;
		 getch();
	}
	// Calculate the slopes
	for(i = 0; i<n-1; i++){
		// slope[i] = findslope(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
		slope[i] = (points[i+1][1]-points[i][1])/(points[i+1][0]- points[i][0]);
		// cout<<slope[i]<<"/t";
	}
	// slope[n-1] = findslope(points[n-1][0], points[n-1][1], points[0][0], points[0][1]);
	slope[n-1] = (points[n-1][1]-points[0][1])/(points[n-1][0]- points[0][0]);
	// cout<<slope[n-1];

	// clip the lines
	for(i = 0; i<n-1; i++){
		if(logicalOR(i, i+1) == 0) continue;
		else if(logicalAND(i, i+1) == 1) continue;
		else clip(i);
	}
	if(logicalOR(n-1, 0) == 0);
	else if(logicalAND(n-1, 0) == 1);
	else clip(i);

	clrscr();
	setcolor(RED);
	rectangle(xwmin, ywmin, xwmax, ywmax);
	setcolor(BLUE);
	drawpolygon();
	cout<<"Slope and regioncodes calculated";
	getch();
}