#include <graphics.h>
#include <math.h>

main()
{
	int i, r, xx[21], yy[21], x0, y0;
	float st = 360 / 20 * 3.14 / 180;
	int driver = DETECT, mode = 0;
	x0 = 300;
	y0 = 250;
	r = 200;

	initgraph(&driver, &mode, "");
	setbkcolor(BLUE);
	setcolor(YELLOW);

	for (i = 0; i < 21; i++)
	{
		xx[i] = x0 + r * cos(i * st);
		yy[i] = y0 - r * sin(i * st);
	}
	for (i = 0; i < 20; i++)
	{
		line(xx[i], yy[i], xx[i + 1], yy[i + 1]);
	}
	getch();
	closegraph();
}