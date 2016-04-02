#include<graphics.h>

main()
{
	int driver, mode;
	driver = DETECT;

	initgraph(&driver, &mode, "");
	setbkcolor(BLUE);
	cleardevice();
	setcolor(YELLOW);
	circle(320, 240, 98);
	setlinestyle(0, 0, 3);
	setcolor(12);
	rectangle(220, 140, 420, 340);
	setlinestyle(4, 0xaaaa, 1);
	setcolor(WHITE);
	line(220, 240, 420, 240);
	getch();
	closegraph();
}