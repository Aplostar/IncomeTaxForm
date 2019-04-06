// Form 1

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>

class person{
	char fnm[25];
	char mnm[25];
	char lnm[60];
	int account[10];
	char sex;
	struct date{
		int date,month,year;
	};
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
	char email[50];
	int mn1[10];
	int mn2[10];


public: void getfnm()
	{
		int maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(9,40,maxx/2-30,50);
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
				bar(9+(10*(i-1)),40,9+(10*(i)),50);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			fnm[i]=ch;
			setcolor(15);
			outtextxy(9+(10*i),40,s);
			i++;
		}
	}
	void getmnm()
	{
		int maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(maxx/2+30,40,maxx-30,50);
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
				bar(maxx/2+35+(10*(i-1)),40,maxx/2+35+(10*(i)),50);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			mnm[i]=ch;
			setcolor(15);
			outtextxy(maxx/2+35+(10*i),40,s);
			i++;

		}
	   }
	void getlnm()
	{
		int maxx=getmaxx();
		setfillstyle(11,EGA_GREEN);
		bar(9,62,maxx/2+80,72);
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
				bar(9+(10*(i-1)),62,9+(10*i),72);
				i--;
				continue;
			}

			s[0]=ch;
			s[1]='\0';
			lnm[i]=ch;
			setcolor(15);

			outtextxy(9+(10*i),62,s);
			i++;

		}
	}

		void getaccount()
		{

			char ch;
			int i=0;
			int maxx=getmaxx();
			setfillstyle(11,EGA_GREEN);
			bar(maxx/2+100,62,maxx-9,72);
			char s[1];

			while(i<10)
			{
				ch=getch();
				if(ch<=48||ch>=57)
				{
					if(ch!=13||ch!=9)
						continue;
				}
				switch(ch)
				{
						case 13: getgender();
							break;

						case 9:  getgender();
							 break;
						case 8:  bar(maxx/2+100+(10*(i-1)),62,maxx/2+100+(10*i),72);
							 i=i-1;
							 continue;
							 break;
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

				    s[0]=ch;
				    s[1]='\0';
				    outtextxy(maxx/2+100+(10*i),62,s);
				    i++;

				}
				if(i>=10)
					getgender();
		}
		void getgender()
		{
			getdob();
		}
		void getdob()
		{
			int maxx=getmaxx();
			bar(160,87,310,97);
			outtextxy(160,89,"D  D   M  M   Y  Y");
			setcolor(EGA_WHITE);line(175,87,175,97);line(203,87,203,97);line(230,87,230,97);line(262,87,262,97);line(290,87,290,97);
			char s[1],n;
			int i;
	getch();
			exit(1);
		}

} ;

void form1();

void fillform()
{
	getch();
	person p;
	p.getfnm();

}
void main()
{

 clrscr();
	 int gd=DETECT,gm;

	 initgraph(&gd,&gm,"");

	 form1();
	 fillform();

 getch();

}
void form1()
{
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
	setcolor(4);
	settextstyle(0,0,1);
	outtextxy(9,32,"1) FIRST NAME");
	setfillstyle(1,EGA_LIGHTGRAY);
	bar(9,40,maxx/2-30,50);
	outtextxy(maxx/2+30,32,"2) MIDDLE NAME");
	bar(maxx/2+30,40,maxx-30,50);
	outtextxy(9,53,"3) LAST NAME");
	bar(9,62,maxx/2+80,72);
	outtextxy(maxx/2+100,53,"4) PERMANENT ACCOUNT NUMBER");
	bar(maxx/2+100,62,maxx-9,72);
	outtextxy(9,75,"5) SEX");
	outtextxy(160,75,"6) DATE OF BIRTH");
	outtextxy(320,75,"7) INCOME TAX WARD/CIRCLE");
	bar(9,87,20,97);setcolor(0);outtextxy(22,87,"Male");bar(65,87,76,97);outtextxy(79,87,"Female");
	bar(160,87,310,97); bar(320,87,maxx-9,97);setcolor(4);
	outtextxy(9,100,"8) FLAT/DOOR/BUILDING" );outtextxy(300,100,"9) ROAD/STREET");
	for(int i=1;i<10;i++)
	{
		bar(9,87+(24*i),maxx-9,97+(24*i));
	}
	outtextxy(9,126,"10) AREA/LOCALITY");outtextxy(300,126,"11) TOWN/CITY/DISTRICT");
	outtextxy(9,150,"12) STATE "); outtextxy(300,150,"13) COUNTRY");outtextxy(500,150,"14) PINCODE");
	outtextxy(9,174,"15) EMAIL ADRESS");
	outtextxy(9,196,"16)MOBILENO.1/RESIDENTIAL/OFFICE PHONENO.WITH STDCODE");
	outtextxy(450,196,"17) MOBILE NO.2 ");
}
