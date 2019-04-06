#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<graphics.h>
#include<fstream.h>
#include<stdlib.h>

ofstream fout;
ifstream fin;
void initiategraph()
{
	int gdriver=DETECT,gmode;

	initgraph(&gdriver,&gmode,"");

}

void drawcalc()
{
	int maxx,maxy;
	maxx=getmaxx();
	maxy=getmaxy();

	setfillstyle(1,EGA_LIGHTBLUE);
	bar(0,0,maxx,maxy);
	setfillstyle(1,EGA_RED);
	bar(0,0,maxx,60);

	setcolor(EGA_WHITE);
	settextstyle(7,0,4);
	outtextxy(200,20,"CALCULATOR");
	setfillstyle(1,0);
	bar((maxx/2)-160,100,(maxx/2)+160,180);

	for(int i=0;i<5;i++)
	{

		bar((maxx/2)-160,190+(50*i),maxx/2-110,230+(50*i));
		bar((maxx/2)-100,190+(50*i),maxx/2-50,230+(50*i));
		bar((maxx/2)-40,190+(50*i),maxx/2+10,230+(50*i));
		bar((maxx/2)+20,190+(50*i),maxx/2+70,230+(50*i));
		bar((maxx/2)+80,190+(50*i),maxx/2+130,230+(50*i));

	}
	setcolor(4);
	setlinestyle(0,1,3);
	for(i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			line(maxx/2-110+(60*j),190+(50*i),maxx/2-110+(60*j),230+(50*i));
	}
	for(i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			line(maxx/2-160+(60*i),230+(50*j),maxx/2-110+(60*i),230+(50*j));
	}
	settextstyle(7,0,2);
	setcolor(EGA_WHITE);

	outtextxy(maxx/2-140,200,"1");
	outtextxy(maxx/2-80,200,"2");
	outtextxy(maxx/2-20,200,"3");
	outtextxy(maxx/2-140,250,"4");
	outtextxy(maxx/2-80,250,"5");
	outtextxy(maxx/2-20,250,"6");
	outtextxy(maxx/2-140,300,"7");
	outtextxy(maxx/2-80,300,"8");
	outtextxy(maxx/2-20,300,"9");
	outtextxy(maxx/2-140,350,"0");
	outtextxy(maxx/2+35,200,"+");
	outtextxy(maxx/2+100,200,"-");
	outtextxy(maxx/2+35,250,"*");
	outtextxy(maxx/2+100,250,"/");
	outtextxy(maxx/2+35,300,"<Ù");



}
void main()
{
clrscr();
	int i=0,r,t,maxx,j,k,l,m,x;
	char ch;

	float result=0;
	fout.open("calfile.txt");
	initiategraph();
		drawcalc();
	maxx=getmaxx();

	while(1)
	{
		ch=getch();
		if(ch=='='||ch==13)
		{
			break;
		}
		if(ch==8)
		{

			bar(maxx/2+(10*(i-1)),100,maxx/2+(10*i),160);
			i--;
			fout.seekp(-1,ios::cur);
			fout<<" ";
			fout.seekp(-1,ios::cur);

			continue;
		}
		char s[2];
		s[0]=ch;
		s[1]='\0';
		outtextxy(maxx/2+(10*i),140,s);
		fout<<ch;
		i++;

	}
	fout.close();

	fin.open("calfile.txt");
	fin.clear();
	i=0;j=0;k=0;
	int a[50]={0};
	char op[50];
	closegraph();
	clrscr();
	while(!fin.eof())
	{
		ch=fin.get();
		if(fin.eof())
			break;
		if(ch>='0'&&ch<='9')
		{
			switch(ch)
			{
				case 48: x=0;
					 break;
				case 49: x=1;
					 break;
				case 50: x=2;
					 break;
				case 51: x=3;
					 break;
				case 52: x=4;
					 break;
				case 53: x=5;
					 break;
				case 54: x=6;
					 break;
				case 55: x=7;
					 break;
				case 56: x=8;
					 break;
				case 57: x=9;
					 break;

			}

			a[i]=(a[i]*10)+x;


		}
		if(ch=='+'||ch=='*'||ch=='/'||ch=='-')
		{
			op[k]=ch ;
			k++;
			i++;
		}

	}
	l=i;
	result=0;

	result=a[0];
	for(i=0;i<=l;i++)
	{
		switch(op[i])
		{
			case '+' :	result=result+a[i+1];
					break;
			case '-' :      result=result-a[i+1];
					break;
			case '/' :      result=result/a[i+1];
					break;
			case '*' :      result=result*a[i+1];
					break;
		}
	}
 getch();
}