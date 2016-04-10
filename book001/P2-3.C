#include <math.h>
#include <stdio.h>
#include <graphics.h>

main()
{
	int driver = DETECT, mode;
	int n, m, x, y, bx, by, px, py, i;
	float pi, a, x1[121], y1[121], x2[121], y2[121];

	initgraph(&driver, &mode, "");
	setbkcolor(1);
	setcolor(14);

	pi = 3.14159;
	n = -1;
	m = 36;
	i = 0;
	for (a = 0; a <= 2 * pi; a += pi / 60)
	{
		i++;
		x1[i] = 26 * cos(a);
		y1[i] = 35 * cos(2 * a);
		x2[i] = 26 * cos(a);
		y2[i] = 35 * sin(a);
	}
	for (px = 170; px <= 470; px += 60)
	{
		for (py = 50; py <= 350; py += 60)
		{
			n++;
			for (i = 1; i <= 120; i++)
			{
				x = (x2[i] - x1[i]) / m * n + x1[i];
				y = (y2[i] - y1[i]) / m * n + y1[i];
				x += px;
				y += py;
				if (i == 1)
				{
					bx = x;
					by = y / 1.2;
					moveto(bx, by);
				}
				lineto(x, y / 1.2);
			}
			lineto(bx, by);
		}
	}
	rectangle(130, 10, 510, 320);
	getch();
	closegraph();
}
