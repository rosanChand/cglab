//Z Buffer
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point vertex[3];
    int zValues[3];
} Triangle;

int zBuffer[WIDTH][HEIGHT];

void initZBuffer() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            zBuffer[i][j] = INT_MIN;
        }
    }
}

void setPixel(int x, int y, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        if (zBuffer[x][y] < color) {
            zBuffer[x][y] = color;
            putpixel(x, y, color);
        }
    }
}

void drawLine(Point p1, Point p2, int color) {
    // Bresenham's line drawing algorithm
    int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);
    int x = p1.x;
    int y = p1.y;
    int sx = (p1.x < p2.x) ? 1 : -1;
    int sy = (p1.y < p2.y) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        setPixel(x, y, color);

        if (x == p2.x && y == p2.y) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

void drawTriangle(const Triangle *triangle, int color) {
    // Draw the edges of the triangle using drawLine function
    for (int i = 0; i < 3; i++) {
        int j = (i + 1) % 3;
        drawLine(triangle->vertex[i], triangle->vertex[j], color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    initZBuffer();

    Triangle triangle = {
        {{100, 100}, {200, 400}, {400, 200}},
        {300, 500, 200}
    };

    drawTriangle(&triangle, WHITE);

    getch();
    closegraph();
    return 0;
}

