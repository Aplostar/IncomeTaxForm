// Front Page
void front()
{
	 setbkcolor(BLACK);
	 setcolor(EGA_RED);
	 settextstyle(4,0,4);
	 outtextxy(100,50,"St. Anthony's Sr. sec. school ");

	 settextstyle(7,0,3);
	 setcolor(EGA_BLUE);
	 outtextxy(200,100,"COMPUTER PROJECT");

	 settextstyle(10,0,2);
	 setcolor(EGA_GREEN);
	 outtextxy(5,150,"Name :- Arpit Pachauri ");

	 settextstyle(1,0,4);
	 setcolor(EGA_DARKGRAY);
	 outtextxy(5,200,"Class :- XII SC. ");

	 settextstyle(3,0,4);
	 setcolor(EGA_MAGENTA);
	 outtextxy(5,250,"Topic :- Income Tax Management ");

	 settextstyle(8,0,4);
	 setcolor(EGA_WHITE);
	 outtextxy(5,300,"Project guide :- ");
	 outtextxy(5,350,"Mr. Sunil Kumar Sharma");

getch();
}
