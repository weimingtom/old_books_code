#include <graphics.h>
#include <math.h>

main()
{
	int a = 100;
	int b = 10;
	int x, y, m, n, i;
	int driver = DETECT, mode = 0;
	initgraph(&driver, &mode, "");
	x = y = a;
	for (i = 0; i < 11; i++)
	{
		asteroid(x, y);
		x += b;
		y -= b;
	}
	x = y = a;
	for (i = 0; i < 11; i++)
	{
		asteroid(x, y);
		x -= b;
		y += b;
	}
	getch();
	closegraph();
}

asteroid(m, n)
{
	line(320, 200 - n, 320 - m, 200);
	line(320 - m, 200, 320, 200 + n);
	line(320, 200 + n, 320 + m, 200);
	line(320 + m, 200, 320, 200 - n);
}