#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
class stu{

	int roll;
public: void print()
	{
		cout<<"\n Roll "<<roll<<"\n";
	}
	friend void show(stu &t);
};

void show (stu &t)
{
	t.roll=101;
}
void main()
{
 clrscr();
	  stu p;

	  show(p);
	  p.print();

 getch();
}
