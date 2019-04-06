#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<fstream.h>
#include<string.h>
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
public  :
	void viewrecord(unsigned long int posi)
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

	}
	void check()
	{
		char s[20];
		outtextxy(50,50,"Write first name ");
		outtextxy(50,150,"->");cin>>s;

		fin.open("Record.txt",ios::binary);
		unsigned long int posi;
		int f;
		person p1;
		while(!fin.eof())
		{
			fin.read((char*)&p1,sizeof(p1));

			if(fin.eof())
				break;
			if(strcmpi(s,p1.fnm)==0)
			{
				posi=fin.tellg()-sizeof(p1);
				f++;
				fin.close();
				viewrecord(posi);

			}

		}
		if(!f)
		{

			outtextxy(200,200,"Sorry not found ");

		}
	}
} ;
void main()
{
clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");

	person p1;
	p1.check();


getch();
}