#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
ofstream fout;
ifstream fin;
struct adress
	{
		char circle[100];
		char flat[25];
		char street[25];
		char area[25];
		char city[25];
		char state[25];
		char country[25];
		int pincode[6];
	};
struct dat{
		int day[2],month[2],year[2];
	};

class person{
	char fnm[25];
	char mnm[25];
	char lnm[60];
	int account[10];
	char sex;
	adress a1;
	dat d1;
	char email[50];
	int mn1[10];
	int mn2[10];
	char f[20];
public :void viewrecord(unsigned long int posi)
	{
		clearviewport();
		fin.open("record.txt",ios::binary);
		person p1;
		fin.seekg(posi);
		fin.read((char*)&p1,sizeof(p1));
		setfillstyle(1,EGA_WHITE);
		int maxx=getmaxx(),maxy=getmaxy();
		bar(0,0,maxx,maxy);
		settextstyle(11,0,1);
		setcolor(EGA_RED);
		for(int i=0;i<3;i++)
		{
			line(0,i,maxx,i);
			line(0,i+4,maxx,i+4);
			line(0,maxy-i-4,maxx,maxy-i-4);
			line(0,maxy-i,maxx,maxy-i);
		}
		for(i=0;i<3;i++)
		{
			line(i,0,i,maxy);
			line(i+4,0,i+4,maxy);
			line(maxx-i,0,maxx-i,maxy);
			line(maxx-i-4,0,maxx-i-4,maxy);
		}
		setfillstyle(1,EGA_BLACK);
		bar(9,9,maxx-9,39);
		settextstyle(3,0,2);
		setcolor(EGA_GREEN);
		outtextxy(maxx/2-40,10,"Record");
		setcolor(EGA_MAGENTA);
		settextstyle(4,0,1);
		outtextxy(maxx/2-60,40,"Personal Details");
		setcolor(0);
		setfillstyle(1,EGA_LIGHTBLUE);
		bar(9,63,250,86);
		setfillstyle(1,EGA_BROWN);
		for(i=1;i<17;i++)
		{
			bar(9,63+(23*i),250,86+(23*i));
		}
		setfillstyle(1,EGA_YELLOW);
		for(i=1;i<17;i++)
		{
			bar(250,63+(23*i),maxx-15,86+(23*i));
		}
		for(i=0;i<19;i++)
		{
			line(9,40+(23*i),maxx-15,40+(23*i));
		}
		char s[][40]={"Field","First name","Middle name","Last name","Account number","Sex","Date of Birth","Income tax ward/ Circle","Flat/Door/Building","Road/Street","Area/Locality","Town/City/District","State","Country","Email Address","Mobile no. 1 ","Mobile no. 2"};
		line(9,63,9,453);line(10,63,10,453);line(11,63,11,453);
		line(250,63,250,453);
		line(maxx-17,63,maxx-17,453);line(maxx-16,63,maxx-16,453);line(maxx-15,63,maxx-15,453);
		settextstyle(1,0,1);
		for(i=0;i<17;i++)
		{
			outtextxy(15,60+(23*i),s[i]);
		}
		outtextxy(255,83,p1.fnm);
		outtextxy(255,109,p1.mnm);
		outtextxy(255,132,p1.lnm);
		char a[10][2];
		for(i=0;i<10;i++)
		{
			itoa(p1.account[i],a[i],10);
			outtextxy(255+(10*i),155,a[i]);
		}
		if(p1.sex=='m')
			outtextxy(255,178,"Male");
		else
			outtextxy(255,201,"Female");
		outtextxy(255,224,p1.a1.circle);
		outtextxy(255,247,p1.a1.flat);
		outtextxy(255,270,p1.a1.street);
		outtextxy(255,293,p1.a1.area);
		outtextxy(255,316,p1.a1.city);
		outtextxy(255,339,p1.a1.state);
		outtextxy(255,362,p1.a1.country);
		outtextxy(255,385,p1.email);
		for(i=0;i<10;i++)
		{
			itoa(p1.mn1[i],a[i],10);
			outtextxy(255+(10*i),408,a[i]);
		}
		for(i=0;i<10;i++)
		{
			itoa(p1.mn2[i],a[i],10);
			outtextxy(255+(10*i),431,a[i]);
		}
		getch();
}
};
void viewme();
void viewall();
void viewbyname();
void viewbyarea();
void viewbydob();
void mainmenu();
void viewbynumber();
void main()
{
clrscr();
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"");
	viewme();
getch();
}
void viewme()
{
	clearviewport();
	int maxx=getmaxx(),maxy=getmaxy();
	setcolor(EGA_GREEN);

	for(int i=0;i<3;i++)
	{
		line(0,i,maxx,i);line(0,i+5,maxx,i+5);
		line(0,maxy-i,maxx,maxy-i);line(0,maxy-i-5,maxx,maxy-i-5);
	}
	for(i=0;i<3;i++)
	{
		line(i,0,i,maxy);line(i+5,0,i+5,maxy);
		line(maxx-i,0,maxx-i,maxy);line(maxx-i-5,0,maxx-i-5,maxy);
	}

	setfillstyle(9,EGA_BLUE);
	bar(8,8,maxx-8,maxy-8);
	setfillstyle(1,EGA_WHITE);
	bar(8,8,maxx-8,40);
	settextstyle(7,0,5) ;
	setcolor(0);
	outtextxy(maxx/2-40,-2,"View");
	setcolor(15);outtextxy(200,240,"Press any key");
	getch();

	setfillstyle(9,EGA_YELLOW);
	bar(8,41,170,maxy-9);
	setfillstyle(9,EGA_RED);
	bar(8,75,170,125);
	bar(8,150,170,200);
	bar(8,225,170,275);
	bar(8,300,170,350);
	bar(8,375,170,425);
	bar(8,435,170,460);
	setcolor(EGA_WHITE);settextstyle(1,0,1);
	outtextxy(15,75,"View all ");
	outtextxy(15,150,"View by name ");
	outtextxy(15,225,"View by area ");
	outtextxy(15,300,"View by dob ");
	outtextxy(15,375,"View by number ");
	outtextxy(15,435,"Main menu");
	viewall();
}
void viewall()
{
	int maxx=getmaxx(),maxy=getmaxy();
	setfillstyle(9,EGA_RED);
	bar(8,435,170,460);
	settextstyle(1,0,1);outtextxy(15,435,"Main menu");
	setfillstyle(9,EGA_GREEN);
	bar(8,75,170,125);
	outtextxy(15,75,"View all");
	setfillstyle(9,EGA_BLUE);
	bar(171,85,maxx-8,maxy-8);
	settextstyle(7,0,4);
	outtextxy(200,240,"Views all the records");
	char ch;
	while(1)
	{
		ch=getch();
		if(ch!=13&&ch!=9)
		{
			setfillstyle(9,EGA_BLUE);
			bar(171,85,maxx-8,maxy-8);
			setcolor(EGA_RED);
			settextstyle(1,0,1);
			outtextxy(250,220,"Please press ");
			setfillstyle(1,EGA_BLACK);
			setcolor(EGA_WHITE);
			bar(360,220,400,250);
			settextstyle(0,0,1);
			outtextxy(370,225,"Tab");
			outtextxy(370,235,"<--");
			outtextxy(370,242,"-->");
			settextstyle(1,0,1);
			setcolor(EGA_RED);
			outtextxy(410,220,"or");
			settextstyle(0,0,1);
			setcolor(EGA_WHITE);
			bar(440,220,490,250);
			outtextxy(450,225,"Enter");
			outtextxy(450,240,"<--Ù");
			ch=getch();

		}
		if(ch==13)
		{
			person p1;
			fin.open("record.txt",ios::binary);
			unsigned long int posi;
			while(1)
			{
				fin.read((char*)&p1,sizeof(p1));
				if(fin.eof())
					break;
				posi=fin.tellg()-sizeof(p1);
				fin.close();
				p1.viewrecord(posi);
			}
			exit(1);
		}
		if(ch==9)
		{
			viewbyname();
		}
	}

}
void viewbyname()
{
	setfillstyle(9,EGA_RED);
	bar(8,75,170,125);
	settextstyle(1,0,1);
	setfillstyle(9,EGA_GREEN);
	bar(8,150,170,200);
	outtextxy(15,75,"View all");
	outtextxy(15,150,"View by name ");
	int maxx=getmaxx(),maxy=getmaxy();
	setfillstyle(9,EGA_BLUE);
	bar(171,85,maxx-8,maxy-8);
	settextstyle(7,0,4);
	outtextxy(200,240,"Views records by name");
	while(1)
	{
		char ch=getch();
		if(ch!=13&&ch!=9)
		{
			setfillstyle(9,EGA_BLUE);
			bar(171,85,maxx-8,maxy-8);
			setcolor(EGA_RED);
			settextstyle(1,0,1);
			outtextxy(250,220,"Please press ");
			setfillstyle(1,EGA_BLACK);
			setcolor(EGA_WHITE);
			bar(360,220,400,250);
			settextstyle(0,0,1);
			outtextxy(370,225,"Tab");
			outtextxy(370,235,"<--");
			outtextxy(370,242,"-->");
			settextstyle(1,0,1);
			setcolor(EGA_RED);
			outtextxy(410,220,"or");
			settextstyle(0,0,1);
			setcolor(EGA_WHITE);
			bar(440,220,490,250);
			outtextxy(450,225,"Enter");
			outtextxy(450,240,"<--Ù");
			ch=getch();

		}
		if(ch==13)
		{
			setfillstyle(9,EGA_BLUE);
			bar(171,85,maxx-8,maxy-8);
			setfillstyle(9,EGA_WHITE);
			for(int i=0;i<200;i++)
			{
				bar(171,100,171+i,maxy-10);
				delay(1);
			}
			setfillstyle(1,EGA_RED);
			settextstyle(1,0,1);
			bar(171,120,371,180);outtextxy(175,120,"View by first name");
			bar(171,200,371,260);outtextxy(175,200,"View by middle name");
			bar(171,280,371,340);outtextxy(175,280,"View by last name");
			bar(171,360,371,420);outtextxy(175,360,"View menu");

			getch();
			exit(1);
		}
		if(ch==9)
		{
			viewbyarea();
		}
	}
}
void viewbyarea()
{
	setfillstyle(9,EGA_RED);
	bar(8,150,170,200);
	settextstyle(1,0,1);
	setfillstyle(9,EGA_GREEN);
	bar(8,225,170,275);
	outtextxy(15,150,"View by name ");
	outtextxy(15,225,"View by area ");
	int maxx=getmaxx(),maxy=getmaxy();
	setfillstyle(9,EGA_BLUE);
	bar(171,85,maxx-8,maxy-8);
	settextstyle(7,0,4);
	outtextxy(200,240,"Views records by area");

	char ch;
	while(1)
	{
		ch=getch();
		if(ch!=13&&ch!=9)
		{
			setfillstyle(9,EGA_BLUE);
			bar(171,85,maxx-8,maxy-8);
			setcolor(EGA_RED);
			settextstyle(1,0,1);
			outtextxy(250,220,"Please press ");
			setfillstyle(1,EGA_BLACK);
			setcolor(EGA_WHITE);
			bar(360,220,400,250);
			settextstyle(0,0,1);
			outtextxy(370,225,"Tab");
			outtextxy(370,235,"<--");
			outtextxy(370,242,"-->");
			settextstyle(1,0,1);
			setcolor(EGA_RED);
			outtextxy(410,220,"or");
			settextstyle(0,0,1);
			setcolor(EGA_WHITE);
			bar(440,220,490,250);
			outtextxy(450,225,"Enter");
			outtextxy(450,240,"<--Ù");
			ch=getch();

		}
		if(ch==13)
		{
			getch();
			exit(1);
		}
		if(ch==9)
		{
			viewbydob();
		}
	}

}
void viewbydob()
{
	setfillstyle(9,EGA_RED);
	bar(8,225,170,275);
	settextstyle(1,0,1);
	setfillstyle(9,EGA_GREEN);
	bar(8,300,170,350);
	outtextxy(15,225,"View by area ");
	outtextxy(15,300,"View by dob ");
	setfillstyle(9,EGA_BLUE);
	int maxx=getmaxx(),maxy=getmaxy();
	bar(171,85,maxx-8,maxy-8);
	settextstyle(7,0,4);
	outtextxy(200,240,"Views record by the");
	outtextxy(200,300,"Date of Birth");

	char ch;
	while(1)
	{
		ch=getch();
		if(ch!=13&&ch!=9)
		{
			setfillstyle(9,EGA_BLUE);
			bar(171,85,maxx-8,maxy-8);
			setcolor(EGA_RED);
			settextstyle(1,0,1);
			outtextxy(250,220,"Please press ");
			setfillstyle(1,EGA_BLACK);
			setcolor(EGA_WHITE);
			bar(360,220,400,250);
			settextstyle(0,0,1);
			outtextxy(370,225,"Tab");
			outtextxy(370,235,"<--");
			outtextxy(370,242,"-->");
			settextstyle(1,0,1);
			setcolor(EGA_RED);
			outtextxy(410,220,"or");
			settextstyle(0,0,1);
			setcolor(EGA_WHITE);
			bar(440,220,490,250);
			outtextxy(450,225,"Enter");
			outtextxy(450,240,"<--Ù");
			ch=getch();

		}
		if(ch==13)
		{
			getch();
			exit(1);
		}
		if(ch==9)
		{
			viewbynumber();
		}
	}
}
void viewbynumber()
{
	setfillstyle(9,EGA_RED);
	bar(8,300,170,350);
	settextstyle(1,0,1);
	setfillstyle(9,EGA_GREEN);
	bar(8,375,170,425);
	outtextxy(15,300,"View by dob");
	outtextxy(15,375,"View by number");
	setfillstyle(9,EGA_BLUE);
	int maxx=getmaxx(),maxy=getmaxy();
	bar(171,85,maxx-8,maxy-8);
	settextstyle(7,0,4);
	outtextxy(200,240,"Views record by ");
	outtextxy(200,300,"Mobile number");
	char ch;
	while(1)
	{
		ch=getch();
		if(ch!=13&&ch!=9)
		{
			setfillstyle(9,EGA_BLUE);
			bar(171,85,maxx-8,maxy-8);
			setcolor(EGA_RED);
			settextstyle(1,0,1);
			outtextxy(250,220,"Please press ");
			setfillstyle(1,EGA_BLACK);
			setcolor(EGA_WHITE);
			bar(360,220,400,250);
			settextstyle(0,0,1);
			outtextxy(370,225,"Tab");
			outtextxy(370,235,"<--");
			outtextxy(370,242,"-->");
			settextstyle(1,0,1);
			setcolor(EGA_RED);
			outtextxy(410,220,"or");
			settextstyle(0,0,1);
			setcolor(EGA_WHITE);
			bar(440,220,490,250);
			outtextxy(450,225,"Enter");
			outtextxy(450,240,"<--Ù");
			ch=getch();

		}
		if(ch==13)
		{
			getch();
			exit(1);
		}
		if(ch==9)
		{
			mainmenu();
		}
	}

}

void mainmenu()
{
	setfillstyle(9,EGA_RED);
	bar(8,375,170,425);
	settextstyle(1,0,1);
	setfillstyle(9,EGA_GREEN);
	bar(8,435,170,460);
	outtextxy(15,375,"View by number");
	outtextxy(15,435,"Main menu");
	int maxx=getmaxx(),maxy=getmaxy();
	setfillstyle(9,EGA_BLUE);
	bar(171,85,maxx-8,maxy-8);
	settextstyle(7,0,4);
	outtextxy(200,240,"Back to main menu");
	char ch;
	while(1)
	{
		ch=getch();
		if(ch!=13&&ch!=9)
		{
			setfillstyle(9,EGA_BLUE);
			bar(171,85,maxx-8,maxy-8);
			setcolor(EGA_RED);
			settextstyle(1,0,1);
			outtextxy(250,220,"Please press ");
			setfillstyle(1,EGA_BLACK);
			setcolor(EGA_WHITE);
			bar(360,220,400,250);
			settextstyle(0,0,1);
			outtextxy(370,225,"Tab");
			outtextxy(370,235,"<--");
			outtextxy(370,242,"-->");
			settextstyle(1,0,1);
			setcolor(EGA_RED);
			outtextxy(410,220,"or");
			settextstyle(0,0,1);
			setcolor(EGA_WHITE);
			bar(440,220,490,250);
			outtextxy(450,225,"Enter");
			outtextxy(450,240,"<--Ù");
			ch=getch();

		}
		if(ch==13)
		{
			getch();
			exit(1);
		}
		if(ch==9)
		{
			viewall();
		}
	}

}