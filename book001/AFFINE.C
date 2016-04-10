#include <math.h>

/*double sin();*/
/*double cos();*/
double xmax = 639.0, ymax = 399.0;
double f[3][3], xx, yy;

scx(double xj)
{
	int x;
	x = (int)(xj + xmax / 2);
	return x;
}

scy(double yj)
{
	int y;
	y = ymax - (int)(yj + (ymax / 2));
	return y;
}

parallel(double dx, double dy)
{
	f[0][0] = 1.0;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[1][0] = 0.0;
	f[1][1] = 1.0;
	f[1][2] = 0.0;
	f[2][0] = dx;
	f[2][1] = dy;
	f[2][2] = 1.0;
}

rotate(double theta)
{
	double th;
	th = theta / 180 * 3.1415927;
	f[0][0] = cos(th);
	f[0][1] = sin(th);
	f[0][2] = 0.0;
	f[1][0] = -sin(th);
	f[1][1] = cos(th);
	f[1][2] = 0.0;
	f[2][0] = 0.0;
	f[2][1] = 0.0;
	f[2][2] = 1.0;
}

scale(double s)
{
	f[0][0] = s;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[1][0] = 0.0;
	f[1][1] = s;
	f[1][2] = 0.0;
	f[2][0] = 0.0;
	f[2][1] = 0.0;
	f[2][2] = 1.0;
}

taisho_x()
{
	f[0][0] = 1.0;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[1][0] = 0.0;
	f[1][1] = -1;
	f[1][2] = 0.0;
	f[2][0] = 0.0;
	f[2][1] = 0.0;
	f[2][2] = 1.0;
}

taisho_y()
{
	f[0][0] = -1.0;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[1][0] = 0.0;
	f[1][1] = 1.0;
	f[1][2] = 0.0;
	f[2][0] = 0.0;
	f[2][1] = 0.0;
	f[2][2] = 1.0;
}

taisho_0()
{
	f[0][0] = -1.0;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[1][0] = 0.0;
	f[1][1] = 1.0;
	f[1][2] = 0.0;
	f[2][0] = 0.0;
	f[2][1] = 0.0;
	f[2][2] = 1.0;
}

taisho_xy()
{
	f[0][0] = 0.0;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[1][0] = 1.0;
	f[1][1] = 0.0;
	f[1][2] = 0.0;
	f[2][0] = 0.0;
	f[2][1] = 0.0;
	f[2][2] = 1.0;
}

taisho(aa, bb, cc)
{
	float r, p;
	r = bb * bb - aa * aa;
	p = aa * aa + bb * bb;
	f[0][0] = -r / p;
	f[0][1] = -2 * aa * bb / p;
	f[0][2] = 0.0;
	f[1][0] = -2 * aa * bb / p;
	f[1][1] = -r / p;
	f[1][2] = 0.0;
	f[2][0] = -2 * aa * cc / p;
	f[2][1] = -2 * bb * cc / p;
	f[2][2] = 1.0;
}

shear(double c, double b)
{
	f[0][0] = 1.0;
	f[0][1] = b;
	f[0][2] = 0.0;
	f[1][0] = c;
	f[1][1] = 1.0;
	f[1][2] = 0.0;
	f[2][0] = 0.0;
	f[2][1] = 0.0;
	f[2][2] = 1.0;
}

axis()
{
	line(scx(0), scy(-ymax / 2), scx(0), scy(ymax / 2));
	line(scx(-xmax / 2), scy(0.0), scx(xmax / 2), scy(0.0));
}

affinex(double x, double y, double d)
{
	xx = x * f[0][0] + y * f[1][0] + d * f[2][0];
	return xx;
}

affiney(double x, double y, double d)
{
	yy = x * f[0][1] + y * f[1][1] + d * f[2][1];
	return yy;
}

