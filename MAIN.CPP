// Main menu
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<graphics.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include"newuser.cpp"
#include"front.cpp"
void forms();
void records();
void others();
void help();
void mains();

void main()
{
clrscr();


	textmode(C4350);
	textcolor(4+128);
	gotoxy(10,5);
	cprintf("²²²²²²²²²²² ²²       ²² ²²²²²² ²²²²²²²² ²²          ²² ²²²²²²");gotoxy(10,6);
	cprintf("²    ²    ² ² ²       ² ²    ² ²      ² ² ²        ² ² ²    ²");gotoxy(10,7);
	cprintf("     ²      ²  ²      ² ²      ²      ² ²  ²      ²  ² ²     ");gotoxy(10,8);
	cprintf("     ²      ²   ²     ² ²      ²      ² ²   ²    ²   ² ²    ");gotoxy(10,9);
	cprintf("     ²      ²    ²    ² ²      ²      ² ²    ²  ²    ² ²²²²²");gotoxy(10,10);
	cprintf("     ²      ²     ²   ² ²      ²      ² ²     ²²     ² ²    ");gotoxy(10,11);
	cprintf("     ²      ²      ²  ² ²      ²      ² ²            ² ²    ");gotoxy(10,12);
	cprintf("²    ²    ² ²       ² ² ²    ² ²      ² ²            ² ²    ²");gotoxy(10,13);
	cprintf("²²²²²²²²²²² ²²       ²² ²²²²²² ²²²²²²²² ²            ² ²²²²²²");//gotoxy(12,5);
	textcolor(1+128);
	gotoxy(20,19);
	cprintf("²²²²²²²²²²²  ²²²²²²  ²²       ²² ");gotoxy(20,20);
	cprintf("     ²      ²      ²   ²     ²");gotoxy(20,21);
	cprintf("     ²      ²      ²    ²   ²");gotoxy(20,22);
	cprintf("     ²      ²      ²     ² ²  ");gotoxy(20,23);
	cprintf("     ²      ²²²²²²²²      ²");gotoxy(20,24);
	cprintf("     ²      ²      ²     ² ²");gotoxy(20,25);
	cprintf("     ²      ²      ²    ²   ²");gotoxy(20,26);
	cprintf("     ²      ²      ²  ²²     ²²");

	textcolor(2+128);
	gotoxy(1,30);
	cprintf("²²      ²²  ²²²²²  ²²      ²  ²²²²  ²²²²²² ²²²² ²²      ²² ²²²² ²²      ² ²²²²²²"  );gotoxy(1,31);
	cprintf("² ²    ² ² ²     ² ² ²     ² ²    ² ²      ²    ² ²    ² ² ²    ² ²     ²    ²");gotoxy(1,32);
	cprintf("²  ²  ²  ² ²     ² ²  ²    ² ²    ² ²      ²    ²  ²  ²  ² ²    ²  ²    ²    ²"  );gotoxy(1,33);
	cprintf("²   ²²   ² ²     ² ²   ²   ² ²    ² ²      ²²²² ²   ²²   ² ²²²² ²   ²   ²    ² " );gotoxy(1,34);
	cprintf("²        ² ²²²²²²² ²    ²  ² ²²²²²² ²  ²²² ²    ²        ² ²    ²    ²  ²    ²"    ) ;gotoxy(1,35);
	cprintf("²        ² ²     ² ²     ² ² ²    ² ²    ² ²    ²        ² ²    ²     ² ²    ²" );gotoxy(1,36);
	cprintf("²        ² ²     ² ²      ²² ²    ² ²²²²²² ²²²² ²        ² ²²²² ²      ²²    ²" );gotoxy(1,37);


	getch();
	clrscr();
	cout<<"Loading bar";
	getch();
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"");
	front();
	home();

getch();
}
void forms()
{
	int maxx=getmaxx(),maxy=getmaxy();
	setfillstyle(1,EGA_GREEN);bar(11,75,maxx/4,120);
	setfillstyle(1,EGA_RED);bar(maxx*3/4+11,75,maxx-11,120);

	settextstyle(1,0,1);
	setcolor(0);
	outtextxy(40,85,"Forms");outtextxy(540,85,"Help");
	setcolor(15);
	char for1[100]="This menu helps you to enter";
	char for2[100]="the records for income tax payment and information";
	setfillstyle(9,4);
	bar(11,140,maxx-11,maxy-11);
	outtextxy(50,maxy/2,for1);
	outtextxy(50,maxy/2+100,for2);
		setcolor(15);
	line(11,75,maxx/4,75); line(maxx/4+11,75,maxx/2,75);line(maxx/2+11,75,maxx*3/4,75);line(maxx*3/4+11,75,maxx-11,75);
	line(11,76,maxx/4,76); line(maxx/4+11,76,maxx/2,76);line(maxx/2+11,76,maxx*3/4,76);line(maxx*3/4+11,76,maxx-11,76);
	line(11,78,maxx/4,78); line(maxx/4+11,78,maxx/2,78);line(maxx/2+11,78,maxx*3/4,78);line(maxx*3/4+11,78,maxx-11,78);
	line(11,79,maxx/4,79); line(maxx/4+11,79,maxx/2,79);line(maxx/2+11,79,maxx*3/4,79);line(maxx*3/4+11,79,maxx-11,79);
	line(11,116,maxx/4,116); line(maxx/4+11,116,maxx/2,116);line(maxx/2+11,116,maxx*3/4,116);line(maxx*3/4+11,116,maxx-11,116);
	line(11,117,maxx/4,117); line(maxx/4+11,117,maxx/2,117);line(maxx/2+11,117,maxx*3/4,117);line(maxx*3/4+11,117,maxx-11,117);
	line(11,119,maxx/4,119); line(maxx/4+11,119,maxx/2,119);line(maxx/2+11,119,maxx*3/4,119);line(maxx*3/4+11,119,maxx-11,119);
	line(11,120,maxx/4,120); line(maxx/4+11,120,maxx/2,120);line(maxx/2+11,120,maxx*3/4,120);line(maxx*3/4+11,120,maxx-11,120);
	line(11,75,11,120);line(12,75,12,120);line(14,75,14,120);line(15,75,15,120);line(maxx/4-4,75,maxx/4-4,120);line(maxx/4-3,75,maxx/4-3,120);line(maxx/4-1,75,maxx/4-1,120);line(maxx/4,75,maxx/4,120);
	line(maxx/4+11,75,maxx/4+11,120);line(maxx/4+12,75,maxx/4+12,120);line(maxx/4+14,75,maxx/4+14,120);line(maxx/4+15,75,maxx/4+15,120);line(maxx/2-4,75,maxx/2-4,120);line(maxx/2-3,75,maxx/2-3,120);line(maxx/2-1,75,maxx/2-1,120);line(maxx/2,75,maxx/2,120);
	line(maxx/2+11,75,maxx/2+11,120);line(maxx/2+12,75,maxx/2+12,120);line(maxx/2+14,75,maxx/2+14,120);line(maxx/2+15,75,maxx/2+15,120);line(maxx*3/4-4,75,maxx*3/4-4,120);line(maxx*3/4-3,75,maxx*3/4-3,120);line(maxx*3/4-1,75,maxx*3/4-1,120);line(maxx*3/4,75,maxx*3/4,120);
	line(maxx*3/4+11,75,maxx*3/4+11,120);line(maxx*3/4+12,75,maxx*3/4+12,120);line(maxx*3/4+14,75,maxx*3/4+14,120);line(maxx*3/4+15,75,maxx*3/4+15,120);line(maxx-10-4,75,maxx-10-4,120);line(maxx-10-3,75,maxx-10-3,120);line(maxx-10-1,75,maxx-10-1,120);line(maxx-10,75,maxx-10,120);
	char ch;
	while(1)
	{
		ch=getch();
		if(ch==13)
		{
			getch();
			exit(1);
		}
		if(ch==9)
		{
			records();
		}
	}
}
void records()
{
	int maxx=getmaxx(),maxy=getmaxy();
	setfillstyle(1,EGA_RED);
	bar(11,75,maxx/4,120);
	setcolor(0);outtextxy(40,85,"Forms");
	setfillstyle(1,EGA_GREEN);
	bar(maxx/4+11,75,maxx/2,120);
	outtextxy(200,85,"Records");

	setcolor(15);
	line(11,75,maxx/4,75); line(maxx/4+11,75,maxx/2,75);line(maxx/2+11,75,maxx*3/4,75);line(maxx*3/4+11,75,maxx-11,75);
	line(11,76,maxx/4,76); line(maxx/4+11,76,maxx/2,76);line(maxx/2+11,76,maxx*3/4,76);line(maxx*3/4+11,76,maxx-11,76);
	line(11,78,maxx/4,78); line(maxx/4+11,78,maxx/2,78);line(maxx/2+11,78,maxx*3/4,78);line(maxx*3/4+11,78,maxx-11,78);
	line(11,79,maxx/4,79); line(maxx/4+11,79,maxx/2,79);line(maxx/2+11,79,maxx*3/4,79);line(maxx*3/4+11,79,maxx-11,79);
	line(11,116,maxx/4,116); line(maxx/4+11,116,maxx/2,116);line(maxx/2+11,116,maxx*3/4,116);line(maxx*3/4+11,116,maxx-11,116);
	line(11,117,maxx/4,117); line(maxx/4+11,117,maxx/2,117);line(maxx/2+11,117,maxx*3/4,117);line(maxx*3/4+11,117,maxx-11,117);
	line(11,119,maxx/4,119); line(maxx/4+11,119,maxx/2,119);line(maxx/2+11,119,maxx*3/4,119);line(maxx*3/4+11,119,maxx-11,119);
	line(11,120,maxx/4,120); line(maxx/4+11,120,maxx/2,120);line(maxx/2+11,120,maxx*3/4,120);line(maxx*3/4+11,120,maxx-11,120);
	line(11,75,11,120);line(12,75,12,120);line(14,75,14,120);line(15,75,15,120);line(maxx/4-4,75,maxx/4-4,120);line(maxx/4-3,75,maxx/4-3,120);line(maxx/4-1,75,maxx/4-1,120);line(maxx/4,75,maxx/4,120);
	line(maxx/4+11,75,maxx/4+11,120);line(maxx/4+12,75,maxx/4+12,120);line(maxx/4+14,75,maxx/4+14,120);line(maxx/4+15,75,maxx/4+15,120);line(maxx/2-4,75,maxx/2-4,120);line(maxx/2-3,75,maxx/2-3,120);line(maxx/2-1,75,maxx/2-1,120);line(maxx/2,75,maxx/2,120);
	line(maxx/2+11,75,maxx/2+11,120);line(maxx/2+12,75,maxx/2+12,120);line(maxx/2+14,75,maxx/2+14,120);line(maxx/2+15,75,maxx/2+15,120);line(maxx*3/4-4,75,maxx*3/4-4,120);line(maxx*3/4-3,75,maxx*3/4-3,120);line(maxx*3/4-1,75,maxx*3/4-1,120);line(maxx*3/4,75,maxx*3/4,120);
	line(maxx*3/4+11,75,maxx*3/4+11,120);line(maxx*3/4+12,75,maxx*3/4+12,120);line(maxx*3/4+14,75,maxx*3/4+14,120);line(maxx*3/4+15,75,maxx*3/4+15,120);line(maxx-10-4,75,maxx-10-4,120);line(maxx-10-3,75,maxx-10-3,120);line(maxx-10-1,75,maxx-10-1,120);line(maxx-10,75,maxx-10,120);
	setfillstyle(9,4);
	bar(11,140,maxx-11,maxy-11);
	char record[100]="This menu helps you to view and modify the entered records";
	outtextxy(50,maxy/2,record);
	char ch;
	while(1)
	{
		ch=getch();
		if(ch==13)
		{
			getch();
			exit(1);
		}
		if(ch==9)
		{
			others();
		}
	}
}
void others()
{
	int maxx=getmaxx(),maxy=getmaxy();
	setfillstyle(1,EGA_RED);bar(maxx/4+11,75,maxx/2,120);
	setfillstyle(1,EGA_GREEN);bar(maxx/2+11,75,(maxx*3/4),120);
	setcolor(0);outtextxy(200,85,"Records");
	outtextxy(370,85,"Others ");
	setcolor(15);
	line(11,75,maxx/4,75); line(maxx/4+11,75,maxx/2,75);line(maxx/2+11,75,maxx*3/4,75);line(maxx*3/4+11,75,maxx-11,75);
	line(11,76,maxx/4,76); line(maxx/4+11,76,maxx/2,76);line(maxx/2+11,76,maxx*3/4,76);line(maxx*3/4+11,76,maxx-11,76);
	line(11,78,maxx/4,78); line(maxx/4+11,78,maxx/2,78);line(maxx/2+11,78,maxx*3/4,78);line(maxx*3/4+11,78,maxx-11,78);
	line(11,79,maxx/4,79); line(maxx/4+11,79,maxx/2,79);line(maxx/2+11,79,maxx*3/4,79);line(maxx*3/4+11,79,maxx-11,79);
	line(11,116,maxx/4,116); line(maxx/4+11,116,maxx/2,116);line(maxx/2+11,116,maxx*3/4,116);line(maxx*3/4+11,116,maxx-11,116);
	line(11,117,maxx/4,117); line(maxx/4+11,117,maxx/2,117);line(maxx/2+11,117,maxx*3/4,117);line(maxx*3/4+11,117,maxx-11,117);
	line(11,119,maxx/4,119); line(maxx/4+11,119,maxx/2,119);line(maxx/2+11,119,maxx*3/4,119);line(maxx*3/4+11,119,maxx-11,119);
	line(11,120,maxx/4,120); line(maxx/4+11,120,maxx/2,120);line(maxx/2+11,120,maxx*3/4,120);line(maxx*3/4+11,120,maxx-11,120);
	line(11,75,11,120);line(12,75,12,120);line(14,75,14,120);line(15,75,15,120);line(maxx/4-4,75,maxx/4-4,120);line(maxx/4-3,75,maxx/4-3,120);line(maxx/4-1,75,maxx/4-1,120);line(maxx/4,75,maxx/4,120);
	line(maxx/4+11,75,maxx/4+11,120);line(maxx/4+12,75,maxx/4+12,120);line(maxx/4+14,75,maxx/4+14,120);line(maxx/4+15,75,maxx/4+15,120);line(maxx/2-4,75,maxx/2-4,120);line(maxx/2-3,75,maxx/2-3,120);line(maxx/2-1,75,maxx/2-1,120);line(maxx/2,75,maxx/2,120);
	line(maxx/2+11,75,maxx/2+11,120);line(maxx/2+12,75,maxx/2+12,120);line(maxx/2+14,75,maxx/2+14,120);line(maxx/2+15,75,maxx/2+15,120);line(maxx*3/4-4,75,maxx*3/4-4,120);line(maxx*3/4-3,75,maxx*3/4-3,120);line(maxx*3/4-1,75,maxx*3/4-1,120);line(maxx*3/4,75,maxx*3/4,120);
	line(maxx*3/4+11,75,maxx*3/4+11,120);line(maxx*3/4+12,75,maxx*3/4+12,120);line(maxx*3/4+14,75,maxx*3/4+14,120);line(maxx*3/4+15,75,maxx*3/4+15,120);line(maxx-10-4,75,maxx-10-4,120);line(maxx-10-3,75,maxx-10-3,120);line(maxx-10-1,75,maxx-10-1,120);line(maxx-10,75,maxx-10,120);
	setfillstyle(9,4);
	bar(11,140,maxx-11,maxy-11);
	char other[100]="This menu contains various accessories";
	outtextxy(100,maxy/2,other);
	char ch;
	while(1)
	{
		ch=getch();
		if(ch==13)
		{
			getch();
			exit(1);
		}
		if(ch==9)
		{
			help();
		}
	}
}
void help()
{
	int maxx=getmaxx(),maxy=getmaxy();
	setfillstyle(1,EGA_RED);bar(maxx/2+11,75,(maxx*3/4),120);
	setfillstyle(1,EGA_GREEN);bar(maxx*3/4+11,75,maxx-11,120);
	setcolor(0);outtextxy(370,85,"Others ");
	outtextxy(540,85,"Help");
	setcolor(15);
	line(11,75,maxx/4,75); line(maxx/4+11,75,maxx/2,75);line(maxx/2+11,75,maxx*3/4,75);line(maxx*3/4+11,75,maxx-11,75);
	line(11,76,maxx/4,76); line(maxx/4+11,76,maxx/2,76);line(maxx/2+11,76,maxx*3/4,76);line(maxx*3/4+11,76,maxx-11,76);
	line(11,78,maxx/4,78); line(maxx/4+11,78,maxx/2,78);line(maxx/2+11,78,maxx*3/4,78);line(maxx*3/4+11,78,maxx-11,78);
	line(11,79,maxx/4,79); line(maxx/4+11,79,maxx/2,79);line(maxx/2+11,79,maxx*3/4,79);line(maxx*3/4+11,79,maxx-11,79);
	line(11,116,maxx/4,116); line(maxx/4+11,116,maxx/2,116);line(maxx/2+11,116,maxx*3/4,116);line(maxx*3/4+11,116,maxx-11,116);
	line(11,117,maxx/4,117); line(maxx/4+11,117,maxx/2,117);line(maxx/2+11,117,maxx*3/4,117);line(maxx*3/4+11,117,maxx-11,117);
	line(11,119,maxx/4,119); line(maxx/4+11,119,maxx/2,119);line(maxx/2+11,119,maxx*3/4,119);line(maxx*3/4+11,119,maxx-11,119);
	line(11,120,maxx/4,120); line(maxx/4+11,120,maxx/2,120);line(maxx/2+11,120,maxx*3/4,120);line(maxx*3/4+11,120,maxx-11,120);
	line(11,75,11,120);line(12,75,12,120);line(14,75,14,120);line(15,75,15,120);line(maxx/4-4,75,maxx/4-4,120);line(maxx/4-3,75,maxx/4-3,120);line(maxx/4-1,75,maxx/4-1,120);line(maxx/4,75,maxx/4,120);
	line(maxx/4+11,75,maxx/4+11,120);line(maxx/4+12,75,maxx/4+12,120);line(maxx/4+14,75,maxx/4+14,120);line(maxx/4+15,75,maxx/4+15,120);line(maxx/2-4,75,maxx/2-4,120);line(maxx/2-3,75,maxx/2-3,120);line(maxx/2-1,75,maxx/2-1,120);line(maxx/2,75,maxx/2,120);
	line(maxx/2+11,75,maxx/2+11,120);line(maxx/2+12,75,maxx/2+12,120);line(maxx/2+14,75,maxx/2+14,120);line(maxx/2+15,75,maxx/2+15,120);line(maxx*3/4-4,75,maxx*3/4-4,120);line(maxx*3/4-3,75,maxx*3/4-3,120);line(maxx*3/4-1,75,maxx*3/4-1,120);line(maxx*3/4,75,maxx*3/4,120);
	line(maxx*3/4+11,75,maxx*3/4+11,120);line(maxx*3/4+12,75,maxx*3/4+12,120);line(maxx*3/4+14,75,maxx*3/4+14,120);line(maxx*3/4+15,75,maxx*3/4+15,120);line(maxx-10-4,75,maxx-10-4,120);line(maxx-10-3,75,maxx-10-3,120);line(maxx-10-1,75,maxx-10-1,120);line(maxx-10,75,maxx-10,120);
	char hel[100]="This menu will help you through the program";
	setfillstyle(9,4);
	bar(11,140,maxx-11,maxy-11);
	outtextxy(100,maxy/2,hel);
	char ch;
	while(1)
	{
		ch=getch();
		if(ch==13)
		{
			getch();
			exit(1);
		}
		if(ch==9)
		{
			forms();
		}
	}
}
void mains()
{
	int maxx,maxy;

	clearviewport();
	maxx=getmaxx();
	maxy=getmaxy();
	setcolor(EGA_BLUE);

	line(0,0,maxx,0);
	line(0,1,maxx,1);
	line(0,5,maxx,5);
	line(0,6,maxx,6);
	line(2,0,2,maxy);
	line(3,0,3,maxy);
	line(7,0,7,maxy);
	line(8,0,8,maxy);
	line(0,maxy,maxx,maxy);
	line(0,maxy-1,maxx,maxy-1);
	line(0,maxy-5,maxx,maxy-5);
	line(0,maxy-6,maxx,maxy-6);
	line(maxx,0,maxx,maxy);
	line(maxx-1,0,maxx-1,maxy);
	line(maxx-6,0,maxx-6,maxy);
	line(maxx-5,0,maxx-5,maxy);

	setcolor(EGA_WHITE);
	settextstyle(8,0,3);
	setfillstyle(1,EGA_GREEN);
	bar(9,8,maxx-8,50);
	outtextxy(maxx/2-130,10,"Income Tax Department");
	setfillstyle(1,EGA_YELLOW);
	bar(9,60,maxx-9,140);
	setfillstyle(1,EGA_RED);
	setcolor(BLUE);
	line(9,60,maxx-9,60);
	line(9,61,maxx-9,61);
	setcolor(GREEN);
	line(9,62,maxx-9,62);
	line(9,63,maxx-9,63);
	setcolor(BLUE);
	line(9,64,maxx-9,64);
	line(9,65,maxx-9,65);
	setcolor(BLUE);
	line(9,135,maxx-9,135);
	line(9,136,maxx-9,136);
	setcolor(GREEN);
	line(9,137,maxx-9,137);
	line(9,138,maxx-9,138);
	setcolor(BLUE);
	line(9,139,maxx-9,139);
	line(9,140,maxx-9,140);

	bar(11,75,maxx/4,120);
	bar(maxx/4+11,75,maxx/2,120);
	bar(maxx/2+11,75,(maxx*3/4),120);
	bar(maxx*3/4+11,75,maxx-11,120);

	setcolor(0);
	settextstyle(1,0,1);
	outtextxy(40,85,"Forms");
	outtextxy(200,85,"Records");
	outtextxy(370,85,"Others ");
	outtextxy(540,85,"Help");

	setcolor(15);
	line(11,75,maxx/4,75); line(maxx/4+11,75,maxx/2,75);line(maxx/2+11,75,maxx*3/4,75);line(maxx*3/4+11,75,maxx-11,75);
	line(11,76,maxx/4,76); line(maxx/4+11,76,maxx/2,76);line(maxx/2+11,76,maxx*3/4,76);line(maxx*3/4+11,76,maxx-11,76);
	line(11,78,maxx/4,78); line(maxx/4+11,78,maxx/2,78);line(maxx/2+11,78,maxx*3/4,78);line(maxx*3/4+11,78,maxx-11,78);
	line(11,79,maxx/4,79); line(maxx/4+11,79,maxx/2,79);line(maxx/2+11,79,maxx*3/4,79);line(maxx*3/4+11,79,maxx-11,79);
	line(11,116,maxx/4,116); line(maxx/4+11,116,maxx/2,116);line(maxx/2+11,116,maxx*3/4,116);line(maxx*3/4+11,116,maxx-11,116);
	line(11,117,maxx/4,117); line(maxx/4+11,117,maxx/2,117);line(maxx/2+11,117,maxx*3/4,117);line(maxx*3/4+11,117,maxx-11,117);
	line(11,119,maxx/4,119); line(maxx/4+11,119,maxx/2,119);line(maxx/2+11,119,maxx*3/4,119);line(maxx*3/4+11,119,maxx-11,119);
	line(11,120,maxx/4,120); line(maxx/4+11,120,maxx/2,120);line(maxx/2+11,120,maxx*3/4,120);line(maxx*3/4+11,120,maxx-11,120);
	line(11,75,11,120);line(12,75,12,120);line(14,75,14,120);line(15,75,15,120);line(maxx/4-4,75,maxx/4-4,120);line(maxx/4-3,75,maxx/4-3,120);line(maxx/4-1,75,maxx/4-1,120);line(maxx/4,75,maxx/4,120);
	line(maxx/4+11,75,maxx/4+11,120);line(maxx/4+12,75,maxx/4+12,120);line(maxx/4+14,75,maxx/4+14,120);line(maxx/4+15,75,maxx/4+15,120);line(maxx/2-4,75,maxx/2-4,120);line(maxx/2-3,75,maxx/2-3,120);line(maxx/2-1,75,maxx/2-1,120);line(maxx/2,75,maxx/2,120);
	line(maxx/2+11,75,maxx/2+11,120);line(maxx/2+12,75,maxx/2+12,120);line(maxx/2+14,75,maxx/2+14,120);line(maxx/2+15,75,maxx/2+15,120);line(maxx*3/4-4,75,maxx*3/4-4,120);line(maxx*3/4-3,75,maxx*3/4-3,120);line(maxx*3/4-1,75,maxx*3/4-1,120);line(maxx*3/4,75,maxx*3/4,120);
	line(maxx*3/4+11,75,maxx*3/4+11,120);line(maxx*3/4+12,75,maxx*3/4+12,120);line(maxx*3/4+14,75,maxx*3/4+14,120);line(maxx*3/4+15,75,maxx*3/4+15,120);line(maxx-10-4,75,maxx-10-4,120);line(maxx-10-3,75,maxx-10-3,120);line(maxx-10-1,75,maxx-10-1,120);line(maxx-10,75,maxx-10,120);
	settextstyle(6,0,3);
	setcolor(EGA_BLUE);
	outtextxy(maxx/2-150,maxy/2,"Press any key to start ");
	getch();
	forms();
}