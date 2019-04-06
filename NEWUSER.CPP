// pass word checking                                                         4361

/*  ERRORS 1) return to username
	   2) only letters in username
	   3) no empty fields
	   4) roll down menu for new and old user
	   5) Better background and interface

*/
char nm[100]={""},pass[100]={""},cpass[100]={""};
void initialisegraph()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"");
}

ofstream fout;
ifstream fin;
void home();
void print();
void newuserinactive();
void newuser();
void newusactive();
void newusinactive();
void newuseractive();
void newuserpassinactive();
void newuserpassactive();
void newuserpassconfirminactive();
void newuserpassconfirmactive();

void olduseractive();
void olduser();
void olduserinactive();
void oldusernameactive();
void oldusernameinactive();
void olduserpassactive(long int pos);
void olduserpassinactive();
void mains();
class users
{
	char nm[100];
	char pass[100];
	char fnm[20];
public:
	users()
	{   strcpy(fnm,"user.txt");
	}
	users(char a[100],char b[100])
	{	strcpy(nm,a);
		strcpy(pass,b);
	}
	void input()
	{  	cout<<"\n Enter username ";
		gets(nm);
		cout<<"\n Enter password ";
		gets(pass);
	}
	void write()
	{
		fout.open(fnm,ios::app|ios::binary);
		users u1;
		value(u1,nm,pass);
		fout.write((char *)&u1,sizeof(u1));
		fout.close();
	}
	void show()
	{
		int f=0;
		fin.open(fnm,ios::binary);
		while(!fin.eof())
		{
			fin.read((char*)this,sizeof(this));
			if(fin.eof())
				break;
			cout<<this->nm<<"    "<<this->pass<<endl;
		}
		fin.close();
	}
	void getname (char s[100])
	{
		strcpy(s,nm);
	}
	void gpass(char s[100])
	{
		strcpy(s,pass);
	}
	void usercheck()
	{	users u1;
		int f=0;
		char u[100];
		fin.open(fnm,ios::binary);
		cout<<"\n Enter username ";
		gets(u);
		while(!fin.eof())
		{
			fin.read((char*)&u1,sizeof(u1));
			if(fin.eof())
				break;
			if(strcmpi(u1.nm,u)==0)
			{
				f++;
				cout<<"\n\n Found ";
				break;
			}
		}
		if(!f)
			cout<<"\n\n Sorry not found";
	 fin.close();
	}
	friend void value(users &t,char a[100],char b[100]);

};
void value(users &t,char a[100],char b[100])
{

	strcpy(t.nm,a);
	strcpy(t.pass,b);
}
void print()
{
int f=0;
		users u1;
		fin.open("user.txt",ios::binary);
		while(!fin.eof())
		{
			fin.read((char*)&u1,sizeof(u1));
			if(fin.eof())
				break;
			char s[100] ;
			u1.getname(s);

			cout<<"USername "<<s;
			u1.gpass(s);
			cout<<"\tPassword "<<s<<"\n";
		}
		fin.close();
}
void olduser()
{
	setfillstyle(1,EGA_RED);
	bar(400,100,500,140);
	setcolor(EGA_GREEN);
	settextstyle(3,0,1);
	outtextxy(410,110,"Old Users");
	char ch;
	while(1)
	{
		ch=getch();
		if(ch==9)
		{
			olduserinactive();
			newuser();
		}
		if(ch==13)
			olduseractive();
		if(ch=='q')
			exit(1);
	}
}
void newuser()
{
	setfillstyle(1,EGA_RED);
	bar(100,100,200,140);
	setcolor(EGA_GREEN);
	settextstyle(3,0,1);
	outtextxy(110,110,"New Users");
	char ch;
	while(1)
	{
		ch=getch();
		if(ch==9)
		{
			newusinactive();
			olduser();
		}
		if(ch==13)
			newusactive();
		if(ch=='q')
			exit(1);
	}

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
void newuserpassactive()
{
	for(int i=0;pass[i]!='\0';i++)
		pass[i]=' ';
	for(i=0;cpass[i]!='\0';i++)
		cpass[i]=' ';

	newuserinactive();
	settextstyle(0,0,1);
	outtextxy(50,220,nm);
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
		outtextxy(50+(7*j),290,"*");
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
				users u;
				value(u,nm,pass);
				u.write();
				clearviewport();
				outtextxy(80,390,"Sign in complete");
				getch();
				mains();
			}
			else
			{
				outtextxy(50,390,"Sorry re-enter password");
				newuserpassinactive();
				newuserpassconfirminactive();
				newuserpassactive();
			}
		}
		if(ch==8&&i>0)
		{

			cpass[i-1]='\0';
			bar(50+(7*i),350,50+(7*(i+1)),380);
			i--;
			continue;
		}

		cpass[i]=ch;
		cpass[i+1]='\0';

		i++;
		s[0]='*';
		s[1]='\0';
		outtextxy(50+(7*i),350,s);

	}
	fout.close();
}

void oldusernameactive()
{
	unsigned long int pos;
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
			fin.open("user.txt",ios::binary);
			while(!fin.eof())
			{
				int f=0;
				char s[100];
				users u1;
				fin.read((char*)&u1,sizeof(u1));
				if(fin.eof())
					break;
				u1.getname(s);
				if(strcmpi(s,nm)==0)
				{
					pos=fin.tellg()-sizeof(u1);
					f++;
					fin.close();
					olduserpassactive(pos);
					break;
				}
			}
			fin.close();
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
void olduserpassactive(long int pos)
{
	oldusernameinactive();
	settextstyle(0,0,1);
	outtextxy(350,220,nm);
	int maxx,i,f;
	i=0;
	char ch,s[1];
	maxx=getmaxx();
	setcolor(EGA_RED);
	settextstyle(8,0,1);
	outtextxy(50,250,"Password");
	setfillstyle(SOLID_FILL,EGA_GREEN);
	bar(350,310,600,340);
	while(1)
	{
		ch=getch();
		if(ch==13||ch==9)
		{
			fin.open("user.txt",ios::binary);
			users u1;
			fin.seekg(pos);
			fin.read((char *)&u1,sizeof(u1));
			char s[100];
			u1.gpass(s);
			int gd=DETECT,gm;
			initgraph(&gd,&gm,"");
			if(strcmpi(s,pass)==0)
			{
				clearviewport();
				outtextxy(100,100,"WELCOME");
				getch();
				fin.close();
				mains();
			}
		}
		if(ch==8&&i>0)
		{

			pass[i-1]='\0';
			bar(350+(7*i),310,350+(7*(i+1)),340);
			i--;
			continue;
		}
		pass[i]=ch;
		pass[i+1]='\0';
		i++;
		s[0]='*';
		s[1]='\0';
		outtextxy(350+(7*i),310,s);
	}

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
	olduserinactive();
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
	newuserinactive();
	oldusernameactive();
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

	char ch;
	while(1)
	{
		newuser();
	}
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
