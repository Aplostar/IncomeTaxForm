// pass word checking
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#include<graphics.h>
char nm[100]={""},pass[100]={""},cpass[100]={""};
void initialisegraph()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"");
}
ofstream fout;
ifstream fin;
void home();
void newuserinactive();
void newusactive();
void newusinactive();
void newuseractive();
void newuserpassinactive();
void newuserpassactive();
void newuserpassconfirminactive();
void newuserpassconfirmactive();

void olduseractive();
void olduserinactive();
void oldusernameactive();
void oldusernameinactive();
void olduserpassactive();
void olduserpassinactive();
void main()
{
clrscr();

	home();

getch();
}
void newusinactive()
{
	setfillstyle(10,EGA_RED);
	bar(100,100,200,140);
	setcolor(EGA_GREEN);
	settextstyle(3,0,1);
	outtextxy(110,110,"New Users");
	settextstyle(8,0,3);
	setcolor(EGA_DARKGRAY);
	outtextxy(50,140,"Create your account");
	newuserinactive();
	newuserpassinactive();
	newuserpassconfirminactive();
}
void newusactive()
{
	fout.open("Users.txt",ios::app);
	newuseractive();
}
void olduserinactive()
{
	setfillstyle(10,EGA_RED);
	bar(400,100,500,140);
	setcolor(EGA_GREEN);
	settextstyle(3,0,1);
	outtextxy(410,110,"Old Users");
	settextstyle(8,0,3);
	setcolor(EGA_DARKGRAY);
	outtextxy(350,140,"Sign in");
	oldusernameinactive();
	olduserpassinactive();
}
void olduseractive()
{
	oldusernameactive();
}

void oldusernameactive()
{
	char ch,s[1];
	int maxx;
	maxx=getmaxx();
	setfillstyle(SOLID_FILL,EGA_GREEN);
	bar(350,210,600,240);
	int i=0,f=0;
	setcolor(EGA_RED);
	settextstyle(11,0,1);

	for(i=0;i<100;i++)
		nm[i]=' ';
	i=0;
	while(1)
	{
		ch=getch();
		if(ch==13||ch==9)
		{
			fin.open("USERS.txt");
			char t[100];
			while(!fin.eof())
			{
				fin.getline(t,100,' ');
				if(fin.eof())
					break;

				if(strcmpi(t,nm)==0)
				{
					f++;
					olduserpassactive();
				}
			}
			if(!f)
			{
				outtextxy(400,400,"Sorryusernotfound");
				getch();
				exit(1);
			}

		}
		if(ch==8&&i>0)
		{

			nm[i-1]='\0';
			bar(350+(7*i),210,350+(7*(i+1)),240);
			i--;
			continue;
		}

		nm[i]=ch;
		nm[i+1]='\0';

		i++;
		s[0]=ch;
		s[1]='\0';
		outtextxy(350+(7*i),220,s);

	}

}
void oldusernameinactive()
{
	int maxx;
	maxx=getmaxx();
	setfillstyle(SOLID_FILL,EGA_WHITE);
	setcolor(EGA_RED);
	settextstyle(8,0,1);
	outtextxy(350,180,"Username");
	setfillstyle(SOLID_FILL,EGA_WHITE);
	bar(350,210,600,240);
}
void olduserpassactive()
{
	olduserinactive();
	settextstyle(0,0,1);
	outtextxy(350,220,nm);
	int maxx;
	i=0;
	char ch,s[1];
	maxx=getmaxx();
	setcolor(EGA_RED);
	settextstyle(8,0,1);
	outtextxy(50,250,"Password");
	setfillstyle(SOLID_FILL,EGA_GREEN);
	bar(50,280,maxx/2-40,310);
	while(1)
	{
		ch=getch();
		if(ch==13||ch==9)
		{
			fin.open("USERS.txt");
			char t[100];
			while(!fin.eof())
			{
				fin.getline(t,100,' ');
				if(fin.eof())
					break;

				if(strcmpi(t,nm)==0)
				{
					f++;
					olduserpassactive();
				}
			}
			if(!f)
			{
				outtextxy(400,400,"Sorryusernotfound");
				getch();
				exit(1);
			}

		}
		if(ch==8&&i>0)
		{

			pass[i-1]='\0';
			bar(50+(7*i),280,50+(7*(i+1)),310);
			i--;
			continue;
		}

		pass[i]=ch;
		pass[i+1]='\0';

		i++;
		s[0]='*';
		s[1]='\0';
		outtextxy(50+(7*i),280,s);

	}

}
void olduserpassinactive()
{
	int maxx;
	maxx=getmaxx();
	setfillstyle(SOLID_FILL,EGA_WHITE);
	setcolor(EGA_RED);
	oldusernameinactive();
	settextstyle(8,0,1);
	outtextxy(350,270,"Password");
	setfillstyle(SOLID_FILL,EGA_WHITE);
	bar(350,310,600,340);

}
void home()
{
	initialisegraph();
	setbkcolor(BLACK);
	int maxx,maxy;

	maxx=getmaxx();
	maxy=getmaxy();
	setcolor(EGA_BLUE);
	settextstyle(3,0,4);
	outtextxy(5,10,"WELCOME");
	setcolor(EGA_RED);
	setlinestyle(SOLID_LINE,0,4);
	line(maxx/2,140,maxx/2,maxy-40);

	olduserinactive();
	newusinactive();
	olduseractive();
}
void newuserinactive()
{
	int maxx;
	maxx=getmaxx();
	setcolor(EGA_RED);
	settextstyle(8,0,1);
	outtextxy(50,180,"Username");
	setfillstyle(SOLID_FILL,EGA_WHITE);
	bar(50,210,maxx/2-40,240);

}
void newuseractive()
{
	char ch,s[1];
	int maxx;
	maxx=getmaxx();
	setcolor(EGA_RED);
	settextstyle(8,0,1);
	outtextxy(50,180,"Username");
	setfillstyle(SOLID_FILL,EGA_GREEN);
	bar(50,210,maxx/2-40,240);
	int i=0;
	settextstyle(11,0,1);

	while(1)
	{
		ch=getch();
		if(ch==13||ch==9)
		{
			fout<<nm;
			newuserpassactive();
			break;
		}
		if(ch==8&&i>0)
		{

			nm[i-1]='\0';
			bar(50+(7*i),210,50+(7*(i+1)),240);
			i--;
			continue;
		}

		nm[i]=ch;
		nm[i+1]='\0';

		i++;
		s[0]=ch;
		s[1]='\0';
		outtextxy(50+(7*i),220,s);

	}

}
void newuserpassinactive()
{
	int maxx;
	maxx=getmaxx();
	setcolor(EGA_RED);
	settextstyle(8,0,1);
	outtextxy(50,250,"Password");
	setfillstyle(SOLID_FILL,EGA_WHITE);
	bar(50,280,maxx/2-40,310);

}
void newuserpassactive()
{
	for(int i=0;pass[i]!='\0';i++)
		pass[i]=' ';
	for(i=0;cpass[i]!='\0';i++)
		cpass[i]=' ';

	newuserinactive();
	settextstyle(0,0,1);
	outtextxy(50,250,nm);
	int maxx;
	i=0;
	char ch,s[1];
	maxx=getmaxx();
	setcolor(EGA_RED);
	settextstyle(8,0,1);
	outtextxy(50,250,"Password");
	setfillstyle(SOLID_FILL,EGA_GREEN);
	bar(50,280,maxx/2-40,310);
	while(1)
	{
		ch=getch();
		if(ch==13||ch==9)
		{
			fout<<"\t\t";
			fout<<pass;
			newuserpassconfirmactive();
			break;
		}
		if(ch==8&&i>0)
		{

			pass[i-1]='\0';
			bar(50+(7*i),280,50+(7*(i+1)),310);
			i--;
			continue;
		}

		pass[i]=ch;
		pass[i+1]='\0';

		i++;
		s[0]='*';
		s[1]='\0';
		outtextxy(50+(7*i),280,s);

	}

}

void newuserpassconfirminactive()
{
	int maxx;
	maxx=getmaxx();
	setcolor(EGA_RED);
	settextstyle(8,0,1);
	outtextxy(50,320,"Confirm Password");
	setfillstyle(SOLID_FILL,EGA_WHITE);
	bar(50,350,maxx/2-40,380);
}
void newuserpassconfirmactive()
{
	for(int i=0;cpass[i]!='\0';i++)
		cpass[i]=' ';
	newuserpassinactive();
	settextstyle(0,0,1);
	for(i=0;pass[i]!='\0';i++)
		;

	for(int j=0;j<i;j++)
	{
		outtextxy(50+(7*j),280,"*");
	}
	int maxx;
	maxx=getmaxx();
	setcolor(EGA_RED);
	settextstyle(8,0,1);
	outtextxy(50,320,"Confirm Password");
	setfillstyle(SOLID_FILL,EGA_GREEN);
	bar(50,350,maxx/2-40,380);
	i=0;
	char ch,s[1];
	while(1)
	{
		ch=getch();
		if(ch==13||ch==9)
		{
			if(strcmpi(pass,cpass)==0)
			{
				outtextxy(80,390,"Sign in complete");
				getch();
				break;
			}
			else
			{
				outtextxy(80,390,"Sorry re-enter password");
				newuserpassactive();
			}
		}
		if(ch==8&&i>0)
		{

			cpass[i-1]='\0';
			bar(50+(7*i),280,50+(7*(i+1)),340);
			i--;
			continue;
		}

		cpass[i]=ch;
		cpass[i+1]='\0';

		i++;
		s[0]='*';
		s[1]='\0';
		outtextxy(50+(7*i),340,s);

	}
	fout.close();
}
