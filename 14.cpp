#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 printf("Name: Roshan Chand\n"); //Added
	printf("Roll No: 123/21\n\n");	//Added
 setcolor(7);
 circle(150,150,35);
 line(150,185,150,300);
 line(150,200,120,230);
 line(150,200,180,230);
 line(150,300,120,330);
 line(150,300,180,330);
 outtextxy(230,350,"This is a Man made using Computer Graphics");
 getch();
 return 0;
}

