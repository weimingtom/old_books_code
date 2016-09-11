#include <stdio.h>
#include <graphics.h>
#define PI 3.14159
#define MAX 150

main()
{
	double x1[MAX], y1[MAX], x2[MAX], y2[MAX];
	int i, j, m = 25;
	double x, y, fpx, fpy, lpx = 0.0, lpy = 0.0;

	int driver = DETECT, mode = 0;
	initgraph(&driver, &mode, "");
	setbkcolor(1);
	setcolor(14);
	graph1(x1, y1);
	graph2(x2, y2);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j <= 120; j++)
		{
			x = (x2[j] - x1[j]) / m * i + x1[j];
			y = (y2[j] - y1[j]) / m * i + y1[j];
			x += 320.0;
			y += 200.0;
			if (j == 0)
			{
				fpx = x;
				fpy = y;
			}
			else
			{
				line((int)lpx, (int)lpy, (int)x, (int)y);
			}
			lpx = x;
			lpy = y;
		}
		line((int)x, (int)y, (int)fpx, (int)fpy);
	}
	getch();
	closegraph();
}

graph1(double *x1, double *y1)
{
	double r, a, sin(), cos();
	r = 180.0;
	for (a = 0; a < 2 * PI; a += PI / 60)
	{
		*x1 = r * cos(a);
		*y1 = -r * sin(a);
		x1++;
		y1++;
	}
}

graph2(double *x2, double *y2)
{
	double r, a, b, sin(), cos();
	r = 100.0;
	for (a = 0.0; a < 2 * PI; a += PI / 60)
	{
		b = r * (1.0 + sin(a * 15.0) / 6.0);
		b *= 0.5 + sin(5.0 * a) / 2.0;
		*x2 = b * cos(a);
		*y2 = -b * sin(a);
		x2++;
		y2++;
	}
}
