#include<graphics.h>
#include<stdlib.h>

main()
{
	int driver, mode;
	unsigned size;
	void *buf;

	driver = VGA;
	mode = VGAHI;

	initgraph(&driver, &mode, "");
	setcolor(GREEN);
	rectangle(20, 20, 200, 200);
	line(20, 20, 200, 200);
	line(200, 20, 20, 200);
	outtextxy(50, 25, "Press any key");
	size = imagesize(20, 20, 200, 200);
	/*if (size != -1)*/
	{
		buf = malloc(size);
		if (buf)
		{
			getimage(20, 20, 200, 200, buf);
			getch();
			putimage(250, 20, buf, COPY_PUT);
			getch();
			putimage(250, 250, buf, NOT_PUT);
		}
	}
	getch();
	restorecrtmode();
}

