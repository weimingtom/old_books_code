#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <alloc.h>
#include <process.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

double xx[20], yy[20], zz[20];
static int iver[6][100];
static double t[4][4], f[4][4], d[60];

int iv, ief, ie, i, j, m, v;
double th1, th2, th;
double x, y, z;
double x0, y0, z0;
char ch;
double wxr, wyt, wxl, wyb, vxl, vyb, vxr, vyt;
double a, b, c, tx, ty, tz, dx, dy, dz;

axis()
{
	line(320, 240, 620, 240);
	line(320, 240, 320, 100);
}

paralle1(double dx, double dy, double dz)
{
	f[0][0] = 1.0;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[0][3] = 0.0;
	f[1][0] = 0.0;
	f[1][1] = 1.0;
	f[1][2] = 0.0;
	f[1][3] = 0.0;
	f[2][0] = 0.0;
	f[2][1] = 0.0;
	f[2][2] = 1.0;
	f[2][3] = 0.0;
	f[3][0] = dx;
	f[3][1] = dy;
	f[3][2] = dz;
	f[3][3] = 1.0;
}

scale(double sx, double sy, double sz)
{
	f[0][0] = sx;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[0][3] = 0.0;
	f[1][0] = 0.0;
	f[1][1] = sy;
	f[1][2] = 0.0;
	f[1][3] = 0.0;
	f[2][0] = 0.0;
	f[2][1] = 0.0;
	f[2][2] = sz;
	f[2][3] = 0.0;
	f[3][0] = 0.0;
	f[3][1] = 0.0;
	f[3][2] = 0.0;
	f[3][3] = 1.0;
}

rotate_x(double theta_x)
{
	double co = cos(theta_x), si = sin(theta_x);
	f[0][0] = 1.0;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[0][3] = 0.0;
	f[1][0] = 0.0;
	f[1][1] = co;
	f[1][2] = -si;
	f[1][3] = 0.0;
	f[2][0] = 0.0;
	f[2][1] = si;
	f[2][2] = co;
	f[2][3] = 0.0;
	f[3][0] = 0.0;
	f[3][1] = 0.0;
	f[3][2] = 0.0;
	f[3][3] = 1.0;
}

rotate_y(double theta_y)
{
	double co = cos(theta_y), si = sin(theta_y);
	f[0][0] = co;
	f[0][1] = 0.0;
	f[0][2] = si;
	f[0][3] = 0.0;
	f[1][0] = 0.0;
	f[1][1] = 1.0;
	f[1][2] = 0.0;
	f[1][3] = 0.0;
	f[2][0] = -si;
	f[2][1] = 0.0;
	f[2][2] = co;
	f[2][3] = 0.0;
	f[3][0] = 0.0;
	f[3][1] = 0.0;
	f[3][2] = 0.0;
	f[3][3] = 1.0;
}

rotate_z(double theta_z)
{
	double co = cos(theta_z), si = sin(theta_z);
	f[0][0] = co;
	f[0][1] = -si;
	f[0][2] = 0.0;
	f[0][3] = 0.0;
	f[1][0] = si;
	f[1][1] = co;
	f[1][2] = 0.0;
	f[1][3] = 0.0;
	f[2][0] = 0.0;
	f[2][1] = 0.0;
	f[2][2] = 1.0;
	f[2][3] = 0.0;
	f[3][0] = 0.0;
	f[3][1] = 0.0;
	f[3][2] = 0.0;
	f[3][3] = 1.0;
}

rotate_any(double x1, double y1, double z1, double x2, double y2, double z2, double th)
{
	double l, m, n, lmn;
	double sqrt(), cos(), sin();
	double co, si;
	lmn = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
	l = (x2 - x1) / lmn;
	m = (y2 - y1) / lmn;
	n = (z2 - z1) / lmn;
	co = cos(th);
	si = sin(th);
	f[0][0] = l * l + (l - l * l) * co;
	f[0][1] = l * m * (l - co) + n * si;
	f[0][2] = l * n * (l - co) - m * si;
	f[0][3] = 0.0;
	f[1][0] = l * m * (l - co) - n * si;
	f[1][1] = m * m + (l - m * m) * co;
	f[1][2] = n * m * (l - co) + l * si;
	f[1][3] = 0.0;
	f[2][0] = l * n * (l - co) + m * si;
	f[2][1] = m * n * (l - co) - l * si;
	f[2][2] = n * n + (l - n * n) * co;
	f[2][3] = 0.0;
	f[3][0] = 0.0;
	f[3][1] = 0.0;
	f[3][2] = 0.0;
	f[3][3] = 1.0;
}

shear(int m, int v, double a)
{
	f[0][0] = 1.0;
	f[1][1] = 1.0;
	f[2][2] = 1.0;
	f[3][3] = 1.0;
	f[0][3] = 0.0;
	f[1][3] = 0.0;
	f[2][3] = 0.0;
	f[3][0] = 0.0;
	f[3][1] = 0.0;
	f[3][2] = 0.0;
	
	if (m == 1)
	{
		if (v == 2)
		{
			f[1][0] = a;
			f[2][0] = 0.0;
		}
		if (v == 3)
		{
			f[2][0] = a;
			f[1][0] = 0.0;
		}
		f[0][1] = 0.0;
		f[0][2] = 0.0;
		f[2][1] = 0.0;
		f[1][2] = 0.0;
	}
	if (m == 2)
	{
		if (v == 1)
		{
			f[0][1] = a;
			f[2][1] = 0.0;
		}
		if (v == 3)
		{
			f[2][1] = a;
			f[0][1] = 0.0;
		}
		f[1][0] = 0.0;
		f[0][2] = 0.0;
		f[2][0] = 0.0;
		f[1][2] = 0.0;
	}
	if (m == 3)
	{
		if (v == 1)
		{
			f[0][2] = a;
			f[1][2] = 0.0;
		}
		if (v == 2)
		{
			f[1][2] = a;
			f[0][2] = 0.0;
		}
		f[1][0] = 0.0;
		f[0][1] = 0.0;
		f[2][0] = 0.0;
		f[2][1] = 0.0;
	}
}

affine3(double *x, double *y, double *z)
{
	double _x, _y, _z;
	_x = *x;
	_y = *y;
	_z = *z;
	*x = _x + f[0][0] + _y * f[1][0] + _z * f[2][0] + f[3][0];
	*y = _x + f[0][1] + _y * f[1][1] + _z * f[2][1] + f[3][1];
	*z = _x + f[0][2] + _y * f[1][2] + _z * f[2][2] + f[3][2];
}

affine1()
{
	double asz[60];
	for (i = 0; i <= iv - 1; i++)
	{
		asz[i] = xx[i];
		asz[i + iv] = yy[i];
		asz[i + iv + iv] = zz[i];
	}
	for (i = 0; i <= iv - 1; i++)
	{
		x = xx[i];
		y = yy[i];
		z = zz[i];
		affine3(&x, &y, &z);
		xx[i] = x;
		yy[i] = y;
		zz[i] = z;
	}
	draw();
	for (i = 0; i <= iv - 1; i++)
	{
		xx[i] = asz[i];
		yy[i] = asz[i + iv];
		zz[i] = asz[i + iv + iv];
	}
}

draw()
{
	int i, j, ab, ae;
	double abx, aby, aex, aey;
	
	for (i = 0; i <= ie - 1; i++)
	{
		ab = iver[0][i];
		ae = iver[1][i];
		abx = xx[ab - 1];
		aby = yy[ab - 1];
		w_v(&abx, &aby);
		aex = xx[ae - 1];
		aey = yy[ae - 1];
		w_v(&aex, aey);
		line((int)abx, (int)aby, (int)aex, (int)aey);
	}
}

cal()
{
	int k, j;
	for (k = 0; k <= 3; k++)
	{
		for (j = 0; j <= 3; j++)
		{
			f[k][j] = f[k][0] * t[0][j] + f[k][1] * t[1][j] + f[k][2] * t[2][j] + f[k][3] * t[3][j];
		}
	}
}

t_z(double a, double b, double tx, double tz)
{
	f[0][0] = -1.0;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[0][3] = 0.0;
	
	f[1][0] = 0.0;
	f[1][1] = 0.0;
	f[1][2] = 0.0;
	f[1][3] = 0.0;
	
	f[2][0] = 0.0;
	f[2][1] = 1.0;
	f[2][2] = 0.0;
	f[2][3] = 0.0;
	
	f[3][0] = a - tx;
	f[3][1] = b + tz;
	f[3][2] = 0.0;
	f[3][3] = 1.0;
}

t_f(double a, double b, double tx, double tz)
{
	f[0][0] = -1.0;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[0][3] = 0.0;
	
	f[1][0] = 0.0;
	f[1][1] = -1.0;
	f[1][2] = 0.0;
	f[1][3] = 0.0;
	
	f[2][0] = 0.0;
	f[2][1] = 0.0;
	f[2][2] = 0.0;
	f[2][3] = 0.0;
	
	f[3][0] = a - tx;
	f[3][1] = b - tz;
	f[3][2] = 0.0;
	f[3][3] = 1.0;
}

t_c(double a, double b, double tx, double tz)
{
	f[0][0] = 0.0;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[0][3] = 0.0;
	
	f[1][0] = 1.0;
	f[1][1] = 0.0;
	f[1][2] = 0.0;
	f[1][3] = 0.0;
	
	f[2][0] = 0.0;
	f[2][1] = 1.0;
	f[2][2] = 0.0;
	f[2][3] = 0.0;
	
	f[3][0] = a + tx;
	f[3][1] = b + tz;
	f[3][2] = 0.0;
	f[3][3] = 1.0;
}

zzc(double thx, double thy)
{
	double cox, coy, six, siy;
	
	coy = cos(thy);
	siy = sin(thy);
	cox = cos(thx);
	six = sin(thx);
	
	f[0][0] = coy;
	f[0][1] = siy * six;
	f[0][2] = 0.0;
	f[0][3] = 0.0;
	
	f[1][0] = 0.0;
	f[1][1] = cox;
	f[1][2] = 0.0;
	f[1][3] = 0.0;
	
	f[2][0] = siy;
	f[2][1] = -six * coy;
	f[2][2] = 0.0;
	f[2][3] = 0.0;
	
	f[3][0] = 0.0;
	f[3][1] = 0.0;
	f[3][2] = 0.0;
	f[3][3] = 1.0;	
}

zdc()
{
	f[0][0] = 0.707;
	f[0][1] = 0.408;
	f[0][2] = 0.0;
	f[0][3] = 0.0;
	
	f[1][0] = 0.0;
	f[1][1] = 0.316;
	f[1][2] = 0.0;
	f[1][3] = 0.0;
	
	f[2][0] = -0.707;
	f[2][1] = -0.408;
	f[2][2] = 0.0;
	f[2][3] = 0.0;
	
	f[3][0] = 0.0;
	f[3][1] = 0.0;
	f[3][2] = 0.0;
	f[3][3] = 1.0;
}

z2c()
{
	f[0][0] = 0.935;
	f[0][1] = -0.118;
	f[0][2] = 0.0;
	f[0][3] = 0.0;
	
	f[1][0] = 0.0;
	f[1][1] = 0.943;
	f[1][2] = 0.0;
	f[1][3] = 0.0;
	
	f[2][0] = -0.354;
	f[2][1] = -0.312;
	f[2][2] = 0.0;
	f[2][3] = 0.0;
	
	f[3][0] = 0.0;
	f[3][1] = 0.0;
	f[3][2] = 0.0;
	f[3][3] = 1.0;
}

x2c()
{
	f[0][0] = 1.0;
	f[0][1] = 0.0;
	f[0][2] = 0.0;
	f[0][3] = 0.0;
	
	f[1][0] = 0.0;
	f[1][1] = 1.0;
	f[1][2] = 0.0;
	f[1][3] = 0.0;
	
	f[2][0] = 0.354;
	f[2][1] = -0.354;
	f[2][2] = 0.0;
	f[2][3] = 0.0;
	
	f[3][0] = 0.0;
	f[3][1] = 0.0;
	f[3][2] = 0.0;
	f[3][3] = 1.0;
}

w_v(double *aix, double *aiy)
{
	double wxr, wyt, wxl, wyb, vxr, vyb, vxl, vyt, _aix, _aiy;
	
	_aix = *aix;
	_aiy = *aiy;
	wxr = 50.0;
	wyt = 50.0;
	wxl = -50.0;
	wyb = -50.0;
	vxr = 400.0;
	vyb = 10.0;
	vxl = 10.0;
	vyt = 400.0;
	
	*aix = (vxr - vxl) / (wxr - wxl) * (_aix - wxl) + vxl;
	*aiy = (vyt - vyb) / (wyt - wyb) * (_aiy - wyb) + vyb;
}


