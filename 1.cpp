#include<stdio.h>
#include<conio.h>
#include<graphics.h> //must be included for every graphics program
#include<dos.h> //for including delay function.

int main()
{
int gd=DETECT,gm; //gd=detects best available graphics driver, gm =graphics mode.
initgraph(&gd,&gm,"C:\\TurboC3\\BGI");	// for initializing graph mode
// above 2 steps are must for every graphics program.
//declaration of any variables must be done before calling initgraph() function.
// next write code for producing requiring design or drawing object
printf("Name: Roshan Chand\n");
printf("Roll No: 123/21");
line(100,100,200,200);//draws a line segment.
getch();
return 0;
}
