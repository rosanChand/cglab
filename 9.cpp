#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void flood(int, int, int, int);

int main()
{ 
	int gd,gm=DETECT;
	clrscr();
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	printf("Name: Roshan Chand\n"); //Added
	printf("Roll No: 123/21\n\n");	//Added
	rectangle(100,100,150,150);
	flood(110,110,7,0);
	getch(); 
	return 0;
}
void flood(int x,int y, int fill_col, int old_col)
{ 
	if(getpixel(x,y)==old_col)
	{ 
		delay(10);
		putpixel(x,y,fill_col);
		flood(x+1,y,fill_col,old_col);
		flood(x-1,y,fill_col,old_col);
		flood(x,y+1,fill_col,old_col);
		flood(x,y-1,fill_col,old_col);
	}
}

