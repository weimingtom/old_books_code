#include <graphics.h>
#include "affine.c"

main()
{
	int gdriver = DETECT, gmode;
	static double x1[] = {0.0, 10.0, 100.0, 110.0, 0.0};
	static double y1[] = {0.0, 50.0, 50.0, -10.0, 0.0};
	static double x2[5], y2[5];

	int i;
	double x, xx, yy;

	initgraph(&gdriver, &gmode, "");
	axis();
	for (x = -300; x <= 200; x = x + 10)
	{
		parallel(x, x / 2);
		for (i = 0; i <= 4; i++)
		{
			x2[i] = affinex(x1[i], y1[i], 1.0);
			y2[i] = affiney(x1[i], y1[i], 1.0) / 2;
		}
		for (i = 0; i <= 3; i++)
		{
			line(scx(x2[i]), scy(y2[i]), scx(x2[i + 1]), scy(y2[i + 1]));
		}
	}
	getch();
	closegraph();
}
