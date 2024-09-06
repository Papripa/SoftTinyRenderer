#include "tgaimage.h"
#include "line.h"
const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);
int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);
	/*image.set(52, 41, red);
	image.set(52, 42, green);
	image.set(52, 43, blue);*/
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	line(25, 25, 75, 75, image, blue);
	line(25, 80, 75, 75, image, green);
	line(25, 80, 25, 25, image, red);
	image.write_tga_file("output.tga");

	return 0;
}

