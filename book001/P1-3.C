#include<graphics.h>

main()
{
	int driver, mode;
	driver = DETECT;

	initgraph(&driver, &mode, "");
	setbkcolor(YELLOW);
	setcolor(RED);
	ellipse(100, 100, 0, 360, 80, 40);
	floodfill(100, 100, RED);
	setcolor(CYAN);
	circle(320, 100, 80);
	setfillstyle(8, 5);
	floodfill(320, 100, CYAN);
	getch();
	restorecrtmode();
}