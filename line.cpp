//Bresenham’s Line Drawing Algorithm
#include "line.h"
#include "tgaimage.h"
//tga view : https://schmittl.github.io/tgajs/
void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
	for (float i = 0; i < 1.; i += 0.1)
	{
		int x = x0 + (x1 - x0) * i;
		int y = y0 + (y1 - y0) * i;
		image.set(x, y, color);
	}
}