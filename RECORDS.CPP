// Just like pc settings
/*  View records :-  a) view all
		   ->b) view with particular name (first, middle ,last)
		     c) search with date of birth
		   ->d) search with particular number
		   ->e) view all belonging to one city,state,country
			(then select from shown records)
*/

#include<iostream.h>
#include<conio.h>
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
public : void showall()
	{
		fin.open("record.txt",ios::binary);
		person p1;
		int maxx=getmaxx(),maxy=getmaxy();
		int i=1;
		char s[1];
		setcolor(EGA_RED);
		setfillstyle(1,EGA_YELLOW);
		bar(0,0,maxx,maxy);
		outtextxy(30,10,"First name ");
		for(i=0;i<3;i++)
		{	line(1+i,1,1+i,maxy);
			line(5+i,1,5+i,maxy);
		}
		setcolor(EGA_BLACK);
		i=1;
		while(!fin.eof())
		{
			setcolor(EGA_BLACK);
			fin.read((char*)&p1,sizeof(p1));
			if(fin.eof())
				break;
			itoa(i,s,10);
			outtextxy(15,(35*i),s);
			outtextxy(30,(35*i),")");
			outtextxy(60,(35*i),p1.fnm);
			setcolor(EGA_RED);
			line(9,(35*i)-10,maxx,(35*i)-10);
			line(9,(35*i)+10,maxx,(35*i)+10);
			getch();
			i++;

		}
		fin.close();

	}
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
	   getch();
	   return;
	}
	void viewbyfname()
	{
		fin.open("record.txt",ios::binary);
		person p1;
		int maxx=getmaxx(),maxy=getmaxy();
		setcolor(EGA_WHITE);
		settextstyle(1,0,1);

		outtextxy(30,80,"View Records");
		outtextxy(30,160,"Modify Records");
		outtextxy(30,240,"Delete Records");
		outtextxy(30,320,"Main menu");
		outtextxy(30,400,"Exit");
		bar(maxx/4+25,60,maxx-8,maxy-8);
		setcolor(EGA_RED);
		outtextxy(maxx/4+50,150,"Enter the first name of user");
		setfillstyle(1,EGA_GREEN);
		bar(200,maxy/2,450,maxy/2+40);

		char s[1];
		char name[25];
		int i=0,f=0;
		unsigned long int posi;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				while(!fin.eof())
				{
					fin.read((char*)&p1,sizeof(p1));
					if(fin.eof())
						break;

					if(strcmpi(p1.fnm,name)==0)
					{
						outtextxy(400,180,"Found");
						posi=fin.tellg()-sizeof(p1);
						fin.close();
						viewrecord(posi);
						f++;
					}

				}
				if(!f)
				{
					outtextxy(400,180,"Sorry user not found");
				}
				getch();
				exit(1);
			}
			if(ch==8&&i>0)
			{

				name[i-1]='\0';
				setfillstyle(1,GREEN);
				bar(205+(10*(i-1)),maxy/2,205+(10*(i)),maxy/2+40);
				i--;
				continue;
			}
			settextstyle(6,0,1);
			s[0]=ch;
			s[1]='\0';
			name[i]=ch;
			name[i+1]='\0';
			setcolor(EGA_BLUE);
			outtextxy(205+(10*i),maxy/2,s);
			i++;
		}

		getch();
		fin.close();

	}
	void viewbymname()
	{
		fin.open("record.txt",ios::binary);
		person p1;
		int maxx=getmaxx(),maxy=getmaxy();
		setcolor(EGA_WHITE);
		settextstyle(1,0,1);

		outtextxy(30,80,"View Records");
		outtextxy(30,160,"Modify Records");
		outtextxy(30,240,"Delete Records");
		outtextxy(30,320,"Main menu");
		outtextxy(30,400,"Exit");
		bar(maxx/4+25,60,maxx-8,maxy-8);
		setcolor(EGA_RED);
		outtextxy(maxx/4+50,150,"Enter the middle name of user");
		setfillstyle(1,EGA_GREEN);
		bar(200,maxy/2,450,maxy/2+40);

		char s[1];
		char name[25];
		int i=0,f=0;
		unsigned long int posi;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				while(!fin.eof())
				{
					fin.read((char*)&p1,sizeof(p1));
					if(fin.eof())
						break;

					if(strcmpi(p1.mnm,name)==0)
					{
						outtextxy(400,180,"Found");
						posi=fin.tellg()-sizeof(p1);
						fin.close();
						viewrecord(posi);
						f++;
					}

				}
				if(!f)
				{
					outtextxy(400,180,"Sorry user not found");
				}
				getch();
				exit(1);
			}
			if(ch==8&&i>0)
			{

				name[i-1]='\0';
				setfillstyle(1,GREEN);
				bar(205+(10*(i-1)),maxy/2,205+(10*(i)),maxy/2+40);
				i--;
				continue;
			}
			settextstyle(6,0,1);
			s[0]=ch;
			s[1]='\0';
			name[i]=ch;
			name[i+1]='\0';
			setcolor(EGA_BLUE);
			outtextxy(205+(10*i),maxy/2,s);
			i++;
		}

		getch();
		fin.close();

	}
	void viewbylname()
	{
		fin.open("record.txt",ios::binary);
		person p1;
		int maxx=getmaxx(),maxy=getmaxy();
		setcolor(EGA_WHITE);
		settextstyle(1,0,1);

		outtextxy(30,80,"View Records");
		outtextxy(30,160,"Modify Records");
		outtextxy(30,240,"Delete Records");
		outtextxy(30,320,"Main menu");
		outtextxy(30,400,"Exit");
		bar(maxx/4+25,60,maxx-8,maxy-8);
		setcolor(EGA_RED);
		outtextxy(maxx/4+50,150,"Enter the Last name of user");
		setfillstyle(1,EGA_GREEN);
		bar(200,maxy/2,450,maxy/2+40);

		char s[1];
		char name[25];
		int i=0,f=0;
		unsigned long int posi;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				while(!fin.eof())
				{
					fin.read((char*)&p1,sizeof(p1));
					if(fin.eof())
						break;

					if(strcmpi(p1.lnm,name)==0)
					{
						outtextxy(400,180,"Found");
						posi=fin.tellg()-sizeof(p1);
						fin.close();
						viewrecord(posi);
						f++;
					}

				}
				if(!f)
				{
					outtextxy(400,180,"Sorry user not found");
				}
				getch();
				exit(1);
			}
			if(ch==8&&i>0)
			{

				name[i-1]='\0';
				setfillstyle(1,GREEN);
				bar(205+(10*(i-1)),maxy/2,205+(10*(i)),maxy/2+40);
				i--;
				continue;
			}
			settextstyle(6,0,1);
			s[0]=ch;
			s[1]='\0';
			name[i]=ch;
			name[i+1]='\0';
			setcolor(EGA_BLUE);
			outtextxy(205+(10*i),maxy/2,s);
			i++;
		}

		getch();
		fin.close();

	}
	void viewbycity()
	{
		fin.open("record.txt",ios::binary);
		person p1;
		int maxx=getmaxx(),maxy=getmaxy();
		setcolor(EGA_WHITE);
		settextstyle(1,0,1);

		outtextxy(30,80,"View Records");
		outtextxy(30,160,"Modify Records");
		outtextxy(30,240,"Delete Records");
		outtextxy(30,320,"Main menu");
		outtextxy(30,400,"Exit");
		bar(maxx/4+25,60,maxx-8,maxy-8);
		setcolor(EGA_RED);
		outtextxy(maxx/4+50,150,"Enter the city of user");
		setfillstyle(1,EGA_GREEN);
		bar(200,maxy/2,450,maxy/2+40);

		char s[1];
		char name[25];
		int i=0,f=0;
		unsigned long int posi;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				while(!fin.eof())
				{
					fin.read((char*)&p1,sizeof(p1));
					if(fin.eof())
						break;

					if(strcmpi(p1.a1.city,name)==0)
					{
						outtextxy(400,180,"Found");
						posi=fin.tellg()-sizeof(p1);
						fin.close();
						viewrecord(posi);
						getch();
						f++;
					}

				}
				if(!f)
				{
					outtextxy(400,180,"Sorry no user belongs to this city");
				}
				getch();
				exit(1);
			}
			if(ch==8&&i>0)
			{

				name[i-1]='\0';
				setfillstyle(1,GREEN);
				bar(205+(10*(i-1)),maxy/2,205+(10*(i)),maxy/2+40);
				i--;
				continue;
			}
			settextstyle(6,0,1);
			s[0]=ch;
			s[1]='\0';
			name[i]=ch;
			name[i+1]='\0';
			setcolor(EGA_BLUE);
			outtextxy(205+(10*i),maxy/2,s);
			i++;
		}
	}
	void viewbystate()
	{
		fin.open("record.txt",ios::binary);
		person p1;
		int maxx=getmaxx(),maxy=getmaxy();
		setcolor(EGA_WHITE);
		settextstyle(1,0,1);

		outtextxy(30,80,"View Records");
		outtextxy(30,160,"Modify Records");
		outtextxy(30,240,"Delete Records");
		outtextxy(30,320,"Main menu");
		outtextxy(30,400,"Exit");
		bar(maxx/4+25,60,maxx-8,maxy-8);
		setcolor(EGA_RED);
		outtextxy(maxx/4+50,150,"Enter the state of user");
		setfillstyle(1,EGA_GREEN);
		bar(200,maxy/2,450,maxy/2+40);

		char s[1];
		char name[25];
		int i=0,f=0;
		unsigned long int posi;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				while(!fin.eof())
				{
					fin.read((char*)&p1,sizeof(p1));
					if(fin.eof())
						break;

					if(strcmpi(p1.a1.state,name)==0)
					{
						outtextxy(400,180,"Found");
						posi=fin.tellg()-sizeof(p1);
						fin.close();
						viewrecord(posi);
						getch();
						f++;
					}

				}
				if(!f)
				{
					outtextxy(400,180,"Sorry no user belongs to this state");
					getch();
					exit(1);
				}
			}
			if(ch==8&&i>0)
			{

				name[i-1]='\0';
				setfillstyle(1,GREEN);
				bar(205+(10*(i-1)),maxy/2,205+(10*(i)),maxy/2+40);
				i--;
				continue;
			}
			settextstyle(6,0,1);
			s[0]=ch;
			s[1]='\0';
			name[i]=ch;
			name[i+1]='\0';
			setcolor(EGA_BLUE);
			outtextxy(205+(10*i),maxy/2,s);
			i++;
		}
	}
	void viewbycountry()
	{
		fin.open("record.txt",ios::binary);
		person p1;
		int maxx=getmaxx(),maxy=getmaxy();
		setcolor(EGA_WHITE);
		settextstyle(1,0,1);

		outtextxy(30,80,"View Records");
		outtextxy(30,160,"Modify Records");
		outtextxy(30,240,"Delete Records");
		outtextxy(30,320,"Main menu");
		outtextxy(30,400,"Exit");
		bar(maxx/4+25,60,maxx-8,maxy-8);
		setcolor(EGA_RED);
		outtextxy(maxx/4+50,150,"Enter the country of user");
		setfillstyle(1,EGA_GREEN);
		bar(200,maxy/2,450,maxy/2+40);

		char s[1];
		char name[25];
		int i=0,f=0;
		unsigned long int posi;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				while(!fin.eof())
				{
					fin.read((char*)&p1,sizeof(p1));
					if(fin.eof())
						break;

					if(strcmpi(p1.a1.country,name)==0)
					{
						outtextxy(400,180,"Found");
						posi=fin.tellg()-sizeof(p1);
						fin.close();
						viewrecord(posi);
						getch();
						f++;
					}

				}
				if(!f)
				{
					outtextxy(400,180,"Sorry no user belongs to this country");
				}
				getch();
				exit(1);
			}
			if(ch==8&&i>0)
			{

				name[i-1]='\0';
				setfillstyle(1,GREEN);
				bar(205+(10*(i-1)),maxy/2,205+(10*(i)),maxy/2+40);
				i--;
				continue;
			}
			settextstyle(6,0,1);
			s[0]=ch;
			s[1]='\0';
			name[i]=ch;
			name[i+1]='\0';
			setcolor(EGA_BLUE);
			outtextxy(205+(10*i),maxy/2,s);
			i++;
		}
	}
	viewbymn()
	{
		char ch;
		int i=0;
		int maxx=getmaxx(),maxy=getmaxy();
		setfillstyle(1,EGA_GREEN);
		bar(200,maxy/2,450,maxy/2+40);
		char s[1];
		int a[10];
		while(i<10)
		{
			ch=getch();
			if(ch>=48&&ch<=57)
			{
				switch(ch)
				{
					case 48: a[i]=0;
						 break;
					case 49: a[i]=1;
						 break;
					case 50: a[i]=2;
						 break;
					case 51: a[i]=3;
						 break;
					case 52: a[i]=4;
						 break;
					case 53: a[i]=5;
						 break;
					case 54	: a[i]=6;
						 break;
					case 55: a[i]=7;
						 break;
					case 56: a[i]=8;
						 break;
					case 57: a[i]=9;
						 break;
				}

			}
			if(ch==8)
			{
				bar(200+(10*(i-1)),maxy/2,200+(10*i),maxy/2+40);
				i=i-1;
				continue;
				break;
			}
			if(ch!=8&&ch!=48&&ch!=49&&ch!=50&&ch!=51&&ch!=52&&ch!=53&&ch!=54&&ch!=55&&ch!=56&&ch!=57)
				continue;

			s[0]=ch;
			s[1]='\0';
			outtextxy(200+(10*i),maxy/2,s);
			i++;
			if(i>10)
				break;
		}
		int f=0;
		person p1;
		unsigned long int posi;
		fin.open("record.txt",ios::binary);
		while(!fin.eof())
		{
			fin.read((char*)&p1,sizeof(p1));
			if(fin.eof())
				break;
			for(i=0;i<10;i++)
				cout<<p1.mn1[i];
			getch();
			int gd=DETECT,gm;
			initgraph(&gd,&gm,"");
			for(i=0;i<10;i++)
			{
				if(a[i]==p1.mn1[i])
					f=1;
				else
					f=0;
			}

			if(f)
			{	outtextxy(400,180,"Found");
				posi=fin.tellg()-sizeof(p1);
				fin.close();
				viewrecord(posi);
				getch();
				f++;
			}
		}
		if(!f)
		{
				outtextxy(400,180,"Sorry no user has this number");
		}

	}

};

/*
	1) delete records :- a) delete all
			     b) delete by name
			     c) delete by dob
			     d) delete by mn
	2) modify records :- a) modify all personal details
			     b) modify the income
			     c) modify the date of submission
	4) submit income tax :-	a) sign cheque
				b) cash payment
	5) income tax notices a) anyone who is due
*/
void showall();
void recordmenu();
void viewmenu();
void deletemenu();
void modifymenu();
void mainmenu();
void exitmenu();
void viewall();
void viewme();
void viewbyname();
void viewbyarea();
void viewbydob();
void viewbynumber();
void main()
{
 clrscr();

	int gd=DETECT,gm;

	initgraph(&gd,&gm,"");
	recordmenu();
	person p1;
//	p1.viewbymn();
 getch();
}
void recordmenu()
{
	setfillstyle(1,EGA_GREEN);
	int maxx=getmaxx(),maxy=getmaxy();
	bar(0,0,maxx,50);
	int i;
	settextstyle(8,0,1);
	setcolor(EGA_BLACK);
	for(i=maxx-100;i>maxx/2;i--)
	{
		setfillstyle(1,EGA_RED);
		bar(i-65,0,i+65,50);
		setfillstyle(1,EGA_GREEN);
		bar(i+65,0,i+70,50);
		outtextxy(i-40,10,"RECORDS");
		delay(25);
	}
	setcolor(EGA_MAGENTA);
	int j=0;
	for(i=0;i<maxx;i++)
	{
		line(1,0,1,j);line(maxx-2,0,maxx-2,j);
		line(3,0,3,j);line(maxx-1,0,maxx-1,j);
		line(2,0,2,j);line(maxx,0,maxx,j);
		line(0,0,i,0);line(0,1,i,1);
		line(0,2,i,2);line(0,48,i,48);
		line(0,49,i,49);line(0,50,i,50);
		delay(4);
		if(j<50)
			j++;
	}
	setcolor(EGA_BLUE);
	for(i=0;i<maxx;i++)
	{
		line(0,51,i,51);line(0,53,i,53);line(0,52,i,52);
		line(0,55,i,55);line(0,56,i,56);line(0,57,i,57);
		line(0,maxy-2,i,maxy-2);line(0,maxy,i,maxy);line(0,maxy-1,i,maxy-1);
		line(0,maxy-4,i,maxy-4);line(0,maxy-5,i,maxy-5);line(0,maxy-6,i,maxy-6);
		delay(2);
	}
	for(i=50;i<maxy;i++)
	{
		line(0,50,0,i);line(1,50,1,i);line(2,50,2,i);
		line(4,50,4,i);line(5,50,5,i);line(6,50,6,i);
		line(maxx-6,50,maxx-6,i);line(maxx-5,50,maxx-5,i);line(maxx-4,50,maxx-4,i);
		line(maxx-2,50,maxx-2,i);line(maxx-1,50,maxx-1,i);line(maxx,50,maxx,i);
		delay(2);
	}


	setfillstyle(1,EGA_WHITE);
	setcolor(EGA_WHITE);
	settextstyle(1,0,1);

	outtextxy(30,80,"View Records");
	outtextxy(30,160,"Modify Records");
	outtextxy(30,240,"Delete Records");
	outtextxy(30,320,"Main menu");
	outtextxy(30,400,"Exit");
	bar(maxx/4+25,60,maxx-8,maxy-8);
	setcolor(EGA_RED);
	outtextxy(maxx/4+50,100,"Press any key to continue");
	for(i=0;i<5;i++)
		line(maxx/4+20+i,54,maxx/4+20+i,maxy-8);
	getch();
	viewmenu();
};
void viewmenu()
{
	setfillstyle(1,EGA_LIGHTGRAY);
	int maxx=getmaxx(),maxy=getmaxy();
	bar(8,70,maxx/4+15,120);
	settextstyle(1,0,1);
	setcolor(15);
	outtextxy(30,80,"View Records");
	setfillstyle(1,EGA_WHITE);
	bar(maxx/4+25,60,maxx-8,maxy-8);

	setfillstyle(1,EGA_RED);
	bar(220,110,320,240);
	setfillstyle(1,EGA_WHITE);
	pieslice(270,150,0,360,25);
	arc(270,140,290,300,50);
	pieslice(300,190,0,360,10);
	pieslice(240,190,0,360,10);
	bar(230,187,310,230);
	setcolor(EGA_BLUE);
	outtextxy(210,250,"View menu provides following features ");
	outtextxy(210,270,"1) View all records ");
	outtextxy(210,290,"2) View by name (first, middle, last)");
	outtextxy(210,310,"3) View by mobile no. ");
	outtextxy(210,330,"4) View by area (city, state, country)");
	settextstyle(8,0,5);
	setcolor(EGA_GREEN);
	outtextxy(340,170,"View Menu");
	char ch;
	while(1)
	{
		ch=getch();
	if(ch!=9&&ch!=13)
	{
		setfillstyle(1,EGA_WHITE);
		bar(maxx/4+25,60,maxx-8,maxy-8);
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
		getch();
		exit(1);
		//viewme();
	}
	if(ch==9)
	{
		settextstyle(1,0,1);
		setcolor(EGA_WHITE);
		setfillstyle(1,EGA_BLACK);
		bar(8,70,maxx/4+15,120);
		outtextxy(30,80,"View Records");
		modifymenu();
	}
	}
}
void modifymenu()
{
	setfillstyle(1,EGA_LIGHTGRAY);
	int maxx=getmaxx(),maxy=getmaxy();
	bar(8,140,maxx/4+15,200);
	settextstyle(1,0,1);
	outtextxy(30,160,"Modify Records");
	setfillstyle(1,EGA_WHITE);
	bar(maxx/4+25,60,maxx-8,maxy-8);
	setcolor(EGA_BLUE);
	outtextxy(210,230,"Modify menu helps you to search");
	outtextxy(210,260,"a record and modify its various fields");
	settextstyle(8,0,5);
	setcolor(EGA_GREEN);
	outtextxy(240,170,"Modify Menu");
	char ch;
	while(1)
	{
		ch=getch();
	if(ch!=9&&ch!=13)
	{
		setcolor(EGA_RED);
		setfillstyle(1,EGA_WHITE);
		bar(maxx/4+25,60,maxx-8,maxy-8);
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
		clearviewport();
		closegraph();
		getch();
		exit(1);
	}
	if(ch==9)
	{
		setcolor(EGA_WHITE);
		settextstyle(1,0,1);
		setfillstyle(1,EGA_BLACK);
		bar(8,140,maxx/4+15,200);
		outtextxy(30,160,"Modify Records");
		deletemenu();
	}
	}
}
void deletemenu()
{
	setfillstyle(1,EGA_LIGHTGRAY);
	int maxx=getmaxx(),maxy=getmaxy();
	settextstyle(1,0,1);
	bar(8,220,maxx/4+15,280);
	outtextxy(30,240,"Delete Records");
	setfillstyle(1,EGA_WHITE);
	bar(maxx/4+25,60,maxx-8,maxy-8);
	setcolor(EGA_BLUE);
	outtextxy(210,230,"Delete menu helps you to search");
	outtextxy(210,260,"a record and delete it or ");
	outtextxy(210,300,"to delete all records");
	settextstyle(8,0,5);
	setcolor(EGA_GREEN);
	outtextxy(240,170,"Delete Menu");

	char ch;
	while(1)
	{
		ch=getch();
	if(ch!=9&&ch!=13)
	{
		setfillstyle(1,EGA_WHITE);
		bar(maxx/4+25,60,maxx-8,maxy-8);
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
		clearviewport();
		closegraph();
		getch();
		exit(1);
	}
	if(ch==9)
	{
		setcolor(EGA_WHITE);
		settextstyle(1,0,1);
		setfillstyle(1,EGA_BLACK);
		bar(8,220,maxx/4+15,280);
		outtextxy(30,240,"Delete Records");
		mainmenu();
	}
	}
}
void mainmenu()
{
	setfillstyle(1,EGA_LIGHTGRAY);
	int maxx=getmaxx(),maxy=getmaxy();
	bar(8,300,maxx/4+15,360);
	settextstyle(1,0,1);
	outtextxy(30,320,"Main menu");
	setfillstyle(1,EGA_WHITE);
	bar(maxx/4+25,60,maxx-8,maxy-8);
	setcolor(EGA_BLUE);
	outtextxy(210,230,"Takes back to the main menu");
	settextstyle(8,0,5);
	setcolor(EGA_GREEN);
	outtextxy(240,170,"Main Menu");
	char ch;
	while(1)
	{ch=getch();
	if(ch!=9&&ch!=13)
	{
		setfillstyle(1,EGA_WHITE);
		bar(maxx/4+25,60,maxx-8,maxy-8);
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
		clearviewport();
		closegraph();
		getch();
		exit(1);
	}
	if(ch==9)
	{
		settextstyle(1,0,1);
		setcolor(EGA_WHITE);
		setfillstyle(1,EGA_BLACK);
		bar(8,300,maxx/4+15,360);
		outtextxy(30,320,"Main menu");
		exitmenu();
	}
}

void exitmenu()
{
	setfillstyle(1,EGA_LIGHTGRAY);
	int maxx=getmaxx(),maxy=getmaxy();
	bar(8,380,maxx/4+15,440);
	settextstyle(1,0,1);
	outtextxy(30,400,"Exit");
	setfillstyle(1,EGA_WHITE);
	bar(maxx/4+25,60,maxx-8,maxy-8);
	setcolor(EGA_BLUE);
	outtextxy(210,230,"Exits the program");
	settextstyle(8,0,5);
	setcolor(EGA_GREEN);
	outtextxy(240,170,"Exit");
	char ch;
	while(1)
	{ch=getch();
	if(ch!=9&&ch!=13)
	{
		setfillstyle(1,EGA_WHITE);
		bar(maxx/4+25,60,maxx-8,maxy-8);
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
		clearviewport();
		closegraph();
		getch();
		exit(1);
	}
	if(ch==9)
	{
		settextstyle(1,0,1);
		setcolor(EGA_WHITE);
		setfillstyle(1,EGA_BLACK);
		bar(8,380,maxx/4+15,440);
		outtextxy(30,400,"Exit");
		viewmenu();
	}
	}
}