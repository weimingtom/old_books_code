/*three-view*/
#include <graphics.h>
void zu();
void fu();
void zo();

int dx[12] = {0, 120, 120, 0, 0, 120, 120, 0, 45, 97.5, 97.5, 45};
int dy[12] = {0, 0, 80, 80, 0, 0, 80, 80, 30, 15, 65, 50};
int dz[12] = {0, 0, 0, 0, 80, 80, 80, 80, 140, 110, 110, 140};
int ld[25] = {0, 1, 2, 3, 0, 4, 8, 9, 5, 4, 7, 3, 2, 6, 7, 11, 8, 11, 10, 9, 5, 10, 6, 5, 1};
int tl[25] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1};

int i, j, pt = 32, vh = 100, vw = 100, x, y, x0 = 300, y0 = 200;

main()
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "");
	setbkcolor(BLUE);
	setcolor(WHITE);
	zu();
	fu();
	zo();
	getch();
	closegraph();
}

void zu()
{
	for (i = 0; i < pt; i++)
	{
		j = ld[i];
		x = x0 - dx[j];
		y = y0 - dz[j];
		if (tl[i] == 0)
		{
			moveto(x, y);
		}
		lineto(x, y);
	}
}

void fu()
{
	for (i = 0; i < pt; i++)
	{
		j = ld[i];
		x = x0 - dx[j];
		y = y0 + dy[j] + vh;
		if (tl[i] == 0)
		{
			moveto(x, y);
		}
		lineto(x, y);
	}
}

void zo()
{
	for (i = 0; i < pt; i++)
	{
		j = ld[i];
		x = x0 + dy[j] + vw;
		y = y0 - dz[j];
		if (tl[i] == 0)
		{
			moveto(x, y);
		}
		lineto(x, y);
	}
}

