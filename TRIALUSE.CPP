#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
ofstream fout;
ifstream fin;

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
	{	fout.open(fnm,ios::app|ios::binary);
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
		fin.open("User.txt",ios::binary);
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
void main()
{
clrscr();
	 users u;
	 u.input();
	 u.write();
//	 print();
getch();
}
