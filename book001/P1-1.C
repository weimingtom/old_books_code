#include <graphics.h>
main()
{
	int shape[10] = {
		 50,  50,
		100, 150,
		200, 150,
		350,  90,
		 50,  50
	};
	int driver, mode;
	driver = DETECT;
	initgraph(&driver, &mode, ""),
	setbkcolor(CYAN);
	setcolor(RED);
	drawpoly(5, shape);
	getch();
	restorecrtmode();
}
