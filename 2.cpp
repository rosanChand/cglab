#include<stdio.h>
#include<conio.h> //Added
#include<dos.h> //Added
#include<graphics.h> 
#include<math.h> 
float round(float a); 
int main()
{
	int gd=DETECT,gm;
	int x1,y1,x2,y2,steps,k; 
	float xincr,yincr,x,y,dx,dy; 
	printf("Name: Roshan Chand\n"); //Added
	printf("Roll No: 123/21\n\n");	//Added
	printf("enter x1,y1"); 
	scanf("%d%d",&x1,&y1); 
	printf("enter x2,y2"); 
	scanf("%d%d",&x2,&y2);
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	dx = x2 - x1;  //Addded
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		steps=abs(dx);    
	else
		steps=abs(dy);
	xincr=dx/steps; 
	yincr=dy/steps; 
	x=x1;
	y=y1;
	for(k=1;k<=steps;k++)
	{
		delay(100);
		x += xincr; //Added
		y+=yincr;
		putpixel(round(x),round(y),WHITE);
	}

	outtextxy(200,20,"DDA"); 
	outtextxy(x1+5,y1-5,"(x1,y1)");
	outtextxy(x2+5,y2+5,"(x2,y2)");
	getch();
	closegraph();  
	return 0;
}

float round(float a)
{
	int b=a+0.5;
	return b;
}
