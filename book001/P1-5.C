#include<graphics.h>

main()
{
	int driver, mode, i, j;
	char s[10] = "Graphics";
	driver = DETECT;

	initgraph(&driver, &mode, "");
	setbkcolor(9);
	cleardevice();
	setviewport(50, 50, 550, 430, 1);
	setfillstyle(1, 2);
	setcolor(RED);
	rectangle(0, 0, 500, 380);
	floodfill(50, 50, RED);
	for (i = 3; i <= 6; i++)
	{
		setcolor(i);
		settextstyle(0, HORIZ_DIR, i);
		outtextxy(20, i * 40, s);
	}
	delay(1500);
	clearviewport();
	getch();
	closegraph();
}