#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
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
public:
	person()
	{
		strcpy(f,"Record.txt");
	}
	void getfnm()
	{
		int maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,35,maxx-50,50);
		char s[1];
		int i=0;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				getmnm();

			}
			if(ch==8&&i>0)
			{

				fnm[i-1]='\0';
				setfillstyle(11,GREEN);
				bar(195+(10*(i-1)),35,195+(10*(i)),50);
				i--;
				continue;
			}
			settextstyle(0,0,1);
			s[0]=ch;
			s[1]='\0';
			fnm[i]=ch;
			fnm[i+1]='\0';
			setcolor(15);
			outtextxy(195+(10*i),40,s);
			i++;
		}
	}
	void getmnm()
	{

		int maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,55,maxx-50,70);
		char s[1];
		int i=0;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				getlnm();
			}
			if(ch==8&&i>0)
			{

				mnm[i-1]='\0';
				setfillstyle(11,GREEN);
				bar(195+(10*(i-1)),55,195+(10*(i)),70);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			mnm[i]=ch;
			mnm[i+1]='\0';
			setcolor(15);
			outtextxy(195+(10*i),60,s);
			i++;

		}
	  }
	  void getlnm()
	  {
		int maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,75,maxx-50,90);
		char s[1];
		int i=0;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				getaccount();
			}
			if(ch==8&&i>0)
			{

				lnm[i-1]='\0';
				setfillstyle(11,GREEN);
				bar(195+(10*(i-1)),75,195+(10*i),90);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			lnm[i]=ch;
			lnm[i+1]='\0';
			setcolor(15);

			outtextxy(195+(10*i),80,s);
			i++;

		}
	}
	void getaccount()
	{
		char ch;
		int i=0;
		int maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,95,maxx/2+100,110);
		char s[1];

		while(i<10)
		{
			ch=getch();
			if(ch>=48&&ch<=57)
			{
				switch(ch)
				{
					case 48: account[i]=0;
						 break;
					case 49: account[i]=1;
						 break;
					case 50: account[i]=2;
						 break;
					case 51: account[i]=3;
						 break;
					case 52: account[i]=4;
						 break;
					case 53: account[i]=5;
						 break;
					case 54	: account[i]=6;
						 break;
					case 55: account[i]=7;
						 break;
					case 56: account[i]=8;
						 break;
					case 57: account[i]=9;
						 break;
				}

			}
			if(ch==8)
			{
				bar(195+(10*(i-1)),95,195+(10*i),110);
				i=i-1;
				continue;
				break;
			}
			if(ch!=8&&ch!=48&&ch!=49&&ch!=50&&ch!=51&&ch!=52&&ch!=53&&ch!=54&&ch!=55&&ch!=56&&ch!=57)
				continue;
			s[0]=ch;
			s[1]='\0';
			outtextxy(195+(10*i),100,s);
			i++;
			if(i>=10)
			{
				getgender();
			}
		}


	}
	void male()
	{
		char ch;
		int maxx;
		maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(maxx/2+180,95,maxx/2+195,110);
		setfillstyle(11,EGA_LIGHTGRAY);
		bar(maxx/2+240,95,maxx/2+255,110);
		while(ch!=13&&ch!=9)
		{	ch=getch();
			if(ch==13)
			{
				setfillstyle(1,4);
				sex='m';
				bar(maxx/2+185,100,maxx/2+190,105);
				getdate();
			}
			if(ch==9)
			{
				female();
			}
		}
	}
	void female()
	{
		char ch;
		int maxx;
		maxx=getmaxx();
		setfillstyle(11,EGA_LIGHTGRAY);
		bar(maxx/2+180,95,maxx/2+195,110);
		setfillstyle(11,EGA_GREEN);
		bar(maxx/2+240,95,maxx/2+255,110);
		while(ch!=13&&ch!=9)
		{
			ch=getch();
			if(ch==13)
			{
				setfillstyle(1,4);
				sex='f';
				bar(maxx/2+245,100,maxx/2+250,105);
				getdate();
			}
			if(ch==9)
			{
				male();
			}
		}
	}
	void getgender()
	{
		int maxx;
		char ch;
		maxx=getmaxx();
		male();
	}
	void getdate()
	  {
		setfillstyle(11,EGA_GREEN);
		setcolor(15);
		bar(190,115,380,130);
		char ch,ch1;
		for(int i=0;i<6;i++)
		{
			setcolor(15);
			line(190+(30*i),115,190+(30*i),130);
		}
		while(ch!=48&&ch!=49&&ch!=50&&ch!=51)
		{	ch=getch();
			switch(ch)
			{
				case 48:outtextxy(195,120,"0");
					d1.day[0]=0;
					break;
				case 49:outtextxy(195,120,"1");
					d1.day[0]=1;
					break;
				case 50:outtextxy(195,120,"2");
					d1.day[0]=2;
					break;
				case 51:outtextxy(195,120,"3");
					d1.day[0]=3;
					break;
			}
		 }
		while(ch1!=48&&ch1!=49&&ch1!=50&&ch1!=51&&ch1!=52&&ch1!=53&&ch1!=54&&ch1!=55&&ch1!=56&&ch1!=57)
		{
			ch1=getch();
			switch(ch1)
			{
				case 48:outtextxy(205,120,"0");
					d1.day[1]=0;
					break;
				case 49:outtextxy(205,120,"1");
					d1.day[1]=1;
					break;
				case 50:outtextxy(205,120,"2");
					d1.day[1]=2;
					break;
				case 51:outtextxy(205,120,"3");
					d1.day[1]=3;
					break;
				case 52:outtextxy(205,120,"4");
					d1.day[1]=4;
					break;
				case 53:outtextxy(205,120,"5");
					d1.day[1]=5;
					break;
				case 54:outtextxy(205,120,"6");
					d1.day[1]=6;
					break;
				case 55:outtextxy(205,120,"7");
					d1.day[1]=7;
					break;
				case 56:outtextxy(205,120,"8");
					d1.day[1]=8;
					break;
				case 57:outtextxy(205,120,"9");
					d1.day[1]=9;
					break;

			}
		  }
		getcircle();

	  }

	void getcircle()
	{
		int maxx;
		maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,135,maxx-50,150);
		char s[1];
		int i=0;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				getflat();

			}
			if(ch==8&&i>0)
			{

				a1.circle[i-1]='\0';
				setfillstyle(11,GREEN);
				bar(195+(10*(i-1)),135,195+(10*(i)),150);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			a1.circle[i]=ch;
			a1.circle[i+1]='\0';
			setcolor(15);
			outtextxy(195+(10*i),140,s);
			i++;

		}

       }
       void getflat()
       {
		int maxx;
		maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,180,maxx-50,195);
		char s[1];
		int i=0;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				getstreet();
			}
			if(ch==8&&i>0)
			{

				a1.flat[i-1]='\0';
				setfillstyle(11,GREEN);
				bar(195+(10*(i-1)),180,195+(10*(i)),195);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			a1.flat[i]=ch;
			a1.flat[i+1]='\0';
			setcolor(15);
			outtextxy(195+(10*i),185,s);
			i++;
		}

       }
       void getstreet()
       {
		int maxx;
		maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,205,maxx-50,220);
		char s[1];
		int i=0;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				getarea();
			}
			if(ch==8&&i>0)
			{

				a1.street[i-1]='\0';
				setfillstyle(11,GREEN);
				bar(195+(10*(i-1)),205,195+(10*(i)),220);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			a1.street[i]=ch;
			a1.street[i+1]='\0';
			setcolor(15);
			outtextxy(195+(10*i),210,s);
			i++;
		}

       }
       void getarea()
       {
		int maxx;
		maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,230,maxx-50,245);
		char s[1];
		int i=0;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				gettown();
			}
			if(ch==8&&i>0)
			{

				a1.area[i-1]='\0';
				setfillstyle(11,GREEN);
				bar(195+(10*(i-1)),230,195+(10*(i)),245);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			a1.area[i]=ch;
			a1.area[i+1]='\0';
			setcolor(15);
			outtextxy(195+(10*i),235,s);
			i++;
		}

       }
       void gettown()
       {
		int maxx;
		maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,255,maxx-50,270);
		char s[1];
		int i=0;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				getstate();
			}
			if(ch==8&&i>0)
			{

				a1.city[i-1]='\0';
				setfillstyle(11,GREEN);
				bar(195+(10*(i-1)),255,195+(10*(i)),270);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			a1.city[i]=ch;
			a1.city[i+1]='\0';
			setcolor(15);
			outtextxy(195+(10*i),260,s);
			i++;
		}

       }
       void getstate()
       {
		int maxx;
		maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,280,maxx-50,295);
		char s[1];
		int i=0;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				getcountry();
			}
			if(ch==8&&i>0)
			{

				a1.state[i-1]='\0';
				setfillstyle(11,GREEN);
				bar(195+(10*(i-1)),280,195+(10*(i)),295);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			a1.state[i]=ch;
			a1.state[i+1]='\0';setcolor(15);
			outtextxy(195+(10*i),285,s);
			i++;
		}

       }
       void getcountry()
       {
		int maxx;
		maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,305,maxx-50,320);
		char s[1];
		int i=0;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				getpin();
			}
			if(ch==8&&i>0)
			{

				a1.country[i-1]='\0';
				setfillstyle(11,GREEN);
				bar(195+(10*(i-1)),305,195+(10*(i)),320);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			a1.country[i]=ch;
			a1.country[i+1]='\0';
			setcolor(15);
			outtextxy(195+(10*i),310,s);
			i++;
	 }
       }
       void getpin()
       {
		char ch;
		int i=0;
		int maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,330,maxx/2,345);
		char s[1];

		while(i<10)
		{
			ch=getch();
			if(ch>=48&&ch<=57)
			{
				switch(ch)
				{
					case 48: a1.pincode[i]=0;
						 break;
					case 49: a1.pincode[i]=1;
						 break;
					case 50: a1.pincode[i]=2;
						 break;
					case 51: a1.pincode[i]=3;
						 break;
					case 52: a1.pincode[i]=4;
						 break;
					case 53: a1.pincode[i]=5;
						 break;
					case 54	: a1.pincode[i]=6;
						 break;
					case 55: a1.pincode[i]=7;
						 break;
					case 56: a1.pincode[i]=8;
						 break;
					case 57: a1.pincode[i]=9;
						 break;
				}

			}
			if(ch==8)
			{
				bar(195+(10*(i-1)),330,195+(10*i),345);
				i=i-1;
				continue;
				break;
			}
			if(ch!=8&&ch!=48&&ch!=49&&ch!=50&&ch!=51&&ch!=52&&ch!=53&&ch!=54&&ch!=55&&ch!=56&&ch!=57)
				continue;
			s[0]=ch;
			s[1]='\0';
			outtextxy(195+(10*i),335,s);
			i++;
			if(i>=6)
			{
				getmn1();
			}
		}

	}
	void getmn1()
	{
		char ch;
		int i=0;
		int maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(maxx/2+100,330,maxx-50,345);
		char s[1];

		while(i<10)
		{
			ch=getch();
			if(ch>=48&&ch<=57)
			{
				switch(ch)
				{
					case 48: mn1[i]=0;
						 break;
					case 49: mn1[i]=1;
						 break;
					case 50: mn1[i]=2;
						 break;
					case 51: mn1[i]=3;
						 break;
					case 52: mn1[i]=4;
						 break;
					case 53: mn1[i]=5;
						 break;
					case 54	: mn1[i]=6;
						 break;
					case 55: mn1[i]=7;
						 break;
					case 56: mn1[i]=8;
						 break;
					case 57: mn1[i]=9;
						 break;
				}

			}
			if(ch==8)
			{
				bar(maxx/2+100+(10*(i-1)),330,maxx/2+100+(10*i),345);
				i=i-1;
				continue;
				break;
			}
			if(ch!=8&&ch!=48&&ch!=49&&ch!=50&&ch!=51&&ch!=52&&ch!=53&&ch!=54&&ch!=55&&ch!=56&&ch!=57)
				continue;
			s[0]=ch;
			s[1]='\0';
			outtextxy(maxx/2+100+(10*i),335,s);
			i++;
			if(i>=10)
			{
				getemail();
			}

		 }
	}
	void getemail()
	{
		int maxx;
		maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,350,maxx-50,365);
		char s[1];
		int i=0;
		while(1)
		{
			char ch;
			ch=getch();
			if(ch==13||ch==9)
			{
				getmn2();
			}
			if(ch==8&&i>0)
			{

				email[i-1]='\0';
				setfillstyle(11,GREEN);
				bar(195+(10*(i-1)),350,195+(10*(i)),365);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			email[i]=ch;
			email[i+1]='\0';
			setcolor(15);
			outtextxy(195+(10*i),355,s);
			i++;
		}
	}
	void fname(char a[25])
	{
		strcpy(fnm,a);
	}
	void mname(char a[25])
	{
		strcpy(mnm,a);
	}
	void lname(char a[25])
	{
		strcpy(lnm,a);
	}
	void acc(int a[10])
	{
		for(int i=0;i<10;i++)
		{
			account[i]=a[i];
		}
	}
	void gender(char ch)
	{
		sex=ch;
	}
	void acir(char a[100])
	{
		strcpy(a1.circle,a);
	}
	void aflat(char a[25])
	{
		strcpy(a1.flat,a);
	}
	void astreet(char a[25])
	{
		strcpy(a1.street,a);
	}
	void aarea(char a[25])
	{
		strcpy(a1.area,a);
	}
	void acity(char a[25])
	{
		strcpy(a1.city,a);
	}
	void astate(char a[25])
	{
		strcpy(a1.state,a);
	}
	void acountr(char a[25])
	{
		strcpy(a1.country,a);
	}
	void pin(int a[6])
	{
		for(int i=0;i<6;i++)
		{
			a1.pincode[i]=a[i];
		}
	}
	void emal(char a[50])
	{
		strcpy(email,a);
	}
	void mno1(int a[10])
	{
		for(int i=0;i<10;i++)
		       mn1[i]=a[i];
	}
	void mno2(int a[10])
	{
		for(int i=0;i<10;i++)
			mn2[i]=a[i];
	}
	void date(int d[2])
	{
		for(int i=0;i<2;i++)
			d1.day[i]=d[i];
	}
	void write()
	{
		person p1;
		p1.fname(fnm);p1.mname(mnm);p1.lname(lnm);p1.acc(account);p1.gender(sex);
		p1.gender(sex);p1.date(d1.day);p1.acir(a1.circle);p1.aflat(a1.flat);p1.astreet(a1.street);p1.aarea(a1.area);
		p1.acity(a1.city);p1.astate(a1.state);p1.acountr(a1.country);p1.pin(a1.pincode);
		p1.emal(email);p1.mno1(mn1);p1.mno2(mn2);
		fout.open(f,ios::app|ios::binary);
		fout.write((char *)&p1,sizeof(p1));
		fout.close();
		show();

	}
	void getmn2()
	{
		char ch;
		int i=0;
		int maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(190,380,maxx/2+100,395);
		char s[1];

		while(i<10)
		{
			ch=getch();
			if(ch>=48&&ch<=57)
			{
				switch(ch)
				{
					case 48: mn2[i]=0;
						 break;
					case 49: mn2[i]=1;
						 break;
					case 50: mn2[i]=2;
						 break;
					case 51: mn2[i]=3;
						 break;
					case 52: mn2[i]=4;
						 break;
					case 53: mn2[i]=5;
						 break;
					case 54	: mn2[i]=6;
						 break;
					case 55: mn2[i]=7;
						 break;
					case 56: mn2[i]=8;
						 break;
					case 57: mn2[i]=9;
						 break;
				}

			}
			if(ch==8)
			{
				bar(195+(10*(i-1)),380,195+(10*i),395);
				i=i-1;
				continue;
				break;
			}
			if(ch!=8&&ch!=48&&ch!=49&&ch!=50&&ch!=51&&ch!=52&&ch!=53&&ch!=54&&ch!=55&&ch!=56&&ch!=57)
				continue;
			s[0]=ch;
			s[1]='\0';
			outtextxy(195+(10*i),385,s);
			i++;
			if(i>=10)
			{
				write();
			}

		   }

	}
	void show()
	{
		clearviewport();
		closegraph();
		person p1;
		fin.open(f,ios::binary);
		while(!fin.eof())
		{
			fin.read((char*)&p1,sizeof(p1));
			if(fin.eof())
				break;
			cout<<"First name "<<p1.fnm;
			cout<<"Middle name "<<p1.mnm;
			cout<<"\n Last name "<<p1.lnm;
			cout<<"\n Account number :- ";
			for(int i=0;i<10;i++)
				cout<<p1.account[i];
			cout<<"\n Sex :- ";
			if(p1.sex=='m')
				cout<<"Male ";
			else
				cout<<"Female ";
			cout<<"\n Date :- "<<p1.d1.day[0]<<p1.d1.day[1];
			cout<<"\n Circle :-"<<p1.a1.circle;
			cout<<"\n Flat\Door\Building :- "<<p1.a1.flat;
			cout<<"\n Road\Street :- "<<p1.a1.street;
			cout<<"\n Area\Locality :- "<<p1.a1.area;
			cout<<"\n Town\City\District :- "<<p1.a1.city;
			cout<<"\n State :- "<<p1.a1.state;
			cout<<"\n Country :- "<<p1.a1.country;
			cout<<"\n Pincode :- ";
			for(i=0;i<6;i++)
				cout<<p1.a1.pincode[i];
			cout<<"\n Mobile no. 1";
			for(i=0;i<10;i++)
				cout<<p1.mn1[i];
			cout<<"\n Mobile no. 2";
			for(i=0;i<10;i++)
				cout<<p1.mn2[i];
			cout<<"\n Email :- "<<p1.email;
			getch();
		}
		fin.close();
	}
} ;

void main()
{
clrscr();

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");

	int maxx,maxy;

	maxx=getmaxx();
	maxy=getmaxy();

	//setbkcolor(YELLOW);
	setfillstyle(1,WHITE);
	bar(0,0,maxx,maxy);
	setfillstyle(1,EGA_RED);
	bar(9,10,maxx-9,30);
	settextstyle(1,0,3);
	setcolor(0);
	outtextxy(11,4,"ITR-1 SAHAJ ");
	settextstyle(8,0,1);
	outtextxy(160,4,"INDIVIDUAL INCOME TAX RETURN ");
	settextstyle(1,0,3);
	setcolor(15);
	outtextxy(500,4,"AY 20");
	setcolor(0);
	settextstyle(8,0,1);
	outtextxy(570,4,"14-15");

	setcolor(EGA_BLUE);
	setfillstyle(11,EGA_LIGHTGRAY);
	settextstyle(3,0,1);
	outtextxy(10,28,"1) First Name ");
	bar(190,35,maxx-50,50);
	outtextxy(10,50,"2)Middle Name ");
	bar(190,55,maxx-50,70);
	outtextxy(10,70,"3) Last Name ");
	bar(190,75,maxx-50,90);
	outtextxy(10,90,"4) Account number ");

	bar(190,95,maxx/2+100,110);outtextxy(maxx/2+120,90,"Sex");
	setcolor(4);outtextxy(maxx/2+160,90,"M");bar(maxx/2+180,95,maxx/2+195,110);
	outtextxy(maxx/2+220,90,"F");bar(maxx/2+240,95,maxx/2+255,110);
	setcolor(EGA_BLUE);outtextxy(10,110,"6) Date of Birth");
	bar(190,115,380,130);
	for(int i=0;i<6;i++)
	{
		setcolor(15);
		line(190+(30*i),115,190+(30*i),130);
	}
	outtextxy(195,110," D  D  M  M  Y  Y");
	setcolor(EGA_BLUE);outtextxy(10,130,"7) Income Tax Ward");outtextxy(10,150,"/Circle");
	bar(190,135,maxx-50,150);
	outtextxy(10,175,"8)Flat\Door\Building");bar(190,180,maxx-50,195);
	outtextxy(10,200,"9) Road\Street");bar(190,205,maxx-50,220);
	outtextxy(10,225,"10) Area\Locality");bar(190,230,maxx-50,245);
	outtextxy(10,250,"11)Town\City\District");bar(190,255,maxx-50,270);
	outtextxy(10,275,"12) State");bar(190,280,maxx-50,295);
	outtextxy(10,300,"13) Country");bar(190,305,maxx-50,320);
	outtextxy(10,325,"14) Pincode");bar(190,330,maxx/2,345);
	outtextxy(maxx/2+10,325,"Mob. no 1");bar(maxx/2+100,330,maxx-50,345);
	outtextxy(10,350,"16) Email");bar(190,350,maxx-50,365);
	outtextxy(10,375,"17) Mob. no 2");bar(190,380,maxx/2+100,395);

	person p1;

	p1.getfnm();
	p1.show();
	getch();
}

