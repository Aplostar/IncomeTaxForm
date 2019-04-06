#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void main()
{
clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");

	setfillstyle(1,EGA_RED);
	bar(100,100,240,250);
	setfillstyle(1,EGA_WHITE);
	pieslice(170,150,0,360,25);
	arc(170,140,240,300,50);
	getch();
	pieslice(200,190,0,360,10);
	pieslice(140,190,0,360,10);
	bar(130,187,210,250);

getch();
}