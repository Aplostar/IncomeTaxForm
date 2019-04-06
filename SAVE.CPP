#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
ofstream fout;
struct stu{
	int roll;
	char a[20];

};

void print()
{
	fout.open("TRY.txt",ios::app|ios::binary);
	stu s1;
	s1.roll=101;
	strcpy(s1.a,"arpit");
	fout.write((char *)&s1,sizeof(s1));
	fout.close();
}
void main()
{
	print();
}