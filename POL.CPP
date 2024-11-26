#include <iostream>
#include <graphics.h>
using namespace std;

// Maximum number of vertices the polygon can have after clipping
#define MAX_VERTICES 20

// Clipping window boundaries
int xwmin, xwmax, ywmin, ywmax;

// Structure to represent a point
struct Point {
    int x, y;
};

// Function to check if a point is inside a clipping boundary
bool isInside(Point p, int edge) {
    switch (edge) {
        case 0: return p.x >= xwmin;  // Left
        case 1: return p.x <= xwmax;  // Right
        case 2: return p.y >= ywmin;  // Bottom
        case 3: return p.y <= ywmax;  // Top
    }
    return false;
}

// Function to find the intersection point between a line and a clipping boundary
Point findIntersection(Point p1, Point p2, int edge) {
    Point intersection;
    float slope = (float)(p2.y - p1.y) / (p2.x - p1.x);

    switch (edge) {
        case 0: // Left
            intersection.x = xwmin;
            intersection.y = p1.y + slope * (xwmin - p1.x);
            break;
        case 1: // Right
            intersection.x = xwmax;
            intersection.y = p1.y + slope * (xwmax - p1.x);
            break;
        case 2: // Bottom
            intersection.y = ywmin;
            intersection.x = p1.x + (ywmin - p1.y) / slope;
            break;
        case 3: // Top
            intersection.y = ywmax;
            intersection.x = p1.x + (ywmax - p1.y) / slope;
            break;
    }
    return intersection;
}

// Clip the polygon against a single edge
int clipEdge(Point* input, int inputSize, Point* output, int edge) {
    int outputSize = 0;

    for (int i = 0; i < inputSize; i++) {
        Point curr = input[i];
        Point prev = input[(i + inputSize - 1) % inputSize];

        bool currInside = isInside(curr, edge);
        bool prevInside = isInside(prev, edge);

        if (prevInside && currInside) {
            // Add current point
            output[outputSize++] = curr;
        } else if (prevInside && !currInside) {
            // Add intersection
            output[outputSize++] = findIntersection(prev, curr, edge);
        } else if (!prevInside && currInside) {
            // Add intersection and current point
            output[outputSize++] = findIntersection(prev, curr, edge);
            output[outputSize++] = curr;
        }
    }

    return outputSize;
}

// Perform Sutherland-Hodgman polygon clipping
int sutherlandHodgman(Point* polygon, int n, Point* clippedPolygon) {
    Point temp[MAX_VERTICES];
    int tempSize = n;

    for (int edge = 0; edge < 4; edge++) {
        tempSize = clipEdge(polygon, tempSize, clippedPolygon, edge);
        for (int i = 0; i < tempSize; i++) {
            polygon[i] = clippedPolygon[i];
        }
    }

    return tempSize;
}

// Draw polygon using graphics.h
void drawPolygon(Point* polygon, int n, int color) {
    setcolor(color);
    for (int i = 0; i < n; i++) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];
        line(p1.x, p1.y, p2.x, p2.y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Input polygon
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    if (n > MAX_VERTICES) {
        cout << "Polygon too large! Maximum vertices allowed: " << MAX_VERTICES << endl;
        return -1;
    }

    Point polygon[MAX_VERTICES];
    cout << "Enter vertices (x, y): \n";
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    // Input clipping window
    cout << "Enter clipping window (xwmin, ywmin, xwmax, ywmax): ";
    cin >> xwmin >> ywmin >> xwmax >> ywmax;

    // Draw original polygon and clipping window
    drawPolygon(polygon, n, WHITE);
    setcolor(YELLOW);
    rectangle(xwmin, ywmin, xwmax, ywmax);
    getch();

    // Perform clipping
    Point clippedPolygon[MAX_VERTICES];
    int clippedSize = sutherlandHodgman(polygon, n, clippedPolygon);

    // Draw clipped polygon
    cleardevice();
    setcolor(YELLOW);
    rectangle(xwmin, ywmin, xwmax, ywmax);
    drawPolygon(clippedPolygon, clippedSize, GREEN);

    getch();
    closegraph();
    return 0;
}
