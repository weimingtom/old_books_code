#include <graphics.h>

void move();
int dx[10] = {0, 100, 100, 40, 0, 0, 100, 100, 40, 0};
int dy[10] = {80, 80, 80, 80, 80, 0, 0, 0, 0, 0};
int dz[10] = {0, 0, 40, 40, 60, 0, 0, 40, 40, 60};
int ld[] = {0, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 5, 4, 9, 8, 3, 2, 7, 6, 1};
int tl[] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1};
int x0 = 300;
int y0 = 200;
int pn = 31;
int x, y, i, j;
int pt = 25, vh = 100, vw = 150;
int dxx, dyy;

main()
{
	int driver = DETECT, mode;
	initgraph(&driver, &mode, "");
	setbkcolor(BLUE);
	setcolor(WHITE);
	move();
	getch();
	closegraph();
}

void move()
{
	setfillstyle(1, 1);
	bar(0, 0, 640, 480);
	for (dxx = - 190; !bioskey(1); dxx++)
	{
		setfillstyle(1, 1);
		bar(0, 0, 640, 300);
		for (i = 0; i <= pn; i++)
		{
			j = ld[i];
			x = x0 - (0.71 * dx[j] - 0.71 * dy[j]);
			y = y0 - (0.82 * dz[j] - 0.41 * dx[j] - 0.41 * dy[j]);
			dyy = 20;
			x = x + dxx;
			y = y + dyy;

			if (tl[i] == 0)
			{
				moveto(x, y);
			}
			lineto(x, y);
			if (x >= 640)
			{
				dxx = -200;
			}
		}
		delay(1000);
	}
}
