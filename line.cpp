//Bresenham’s Line Drawing Algorithm
#include "line.h"
#include "tgaimage.h"
//tga view : https://schmittl.github.io/tgajs/
#define small 1e-5
void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
	int dx = (x1 == x0) ? 0 : x1 - x0;
	int dy = (y1 == y0) ? 0 : y1 - y0;
	if (dx == 0)
	{
		for (float t = 1; t <= std::abs(dy); t += 1)
		{
			int y = y0 + std::abs(dy)/dy* t;
			image.set(x0, y, color);
		}
	}
	else if (dy == 0)
	{
		for (float t = 1; t <= std::abs(dx); t += 1)
		{
			int x = x0 + std::abs(dx) / dx * t;
			image.set(x, y0, color);
		}
	}
	else {
		if (std::abs(dx) > std::abs(dy))
		{
			for (float t = 1; t <= std::abs(dx) + small; t += 1)
			{
				int x = x0 + std::abs(dx) / dx * t;
				int y = y0 + dy / dx * t;
				image.set(x, y, color);
			}
		}
		else {
			for (float t = 1; t <= std::abs(dy)+small; t += 1)
			{

				int x = x0 + dx / dy* t;
				int y = y0 + std::abs(dy) / dy * t;
				image.set(x, y, color);
			}
		}
	}
	
}