#include <graphics.h>
#include <math.h>

#define PI 3.1415926

main()
{
	int driver = DETECT, mode = 0;
	int i, n;
	double r, rr, theta, x, y;
	/*double sin(), cos(), sqrt();*/
	r = 80, n = 45;

	initgraph(&driver, &mode, "");
	circle(320, 210, (int)r);
	theta =  2.0 * PI / n;
	for (i = 0; i < n; i++)
	{
		x = r * cos(i * theta);
		y = r * sin(i * theta);
		rr = sqrt(x * x);
		x = 320.0 + x;
		y = 210.0 - y;
		circle((int)x, (int)y, (int)rr);
	}
	getch();
	closegraph();
}