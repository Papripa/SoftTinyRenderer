#include "tgaimage.h"
#include "line.h"
#include "geometry.h"
#include "Model.h"
#include <vector>
const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);
const int width = 400;
const int height = 400;
TGAImage image(width, height, TGAImage::RGB);
void draw_model();
int main(int argc, char** argv) {
	
	draw_model();
	/*code for testing the line function
	line(25, 25, 75, 75, image, blue);
	line(25, 80, 75, 75, image, green);
	line(25, 80, 25, 25, image, red);*/
	/*line(130, 100, 280, 270, image, blue);
	line(280, 270, 330, 360, image, green);
	line(330, 360, 130, 100, image, red);
	image.flip_vertically();
	image.write_tga_file("output_line.tga");*/
	return 0;
}

void draw_model()
{
	Model* model = new Model("obj/african_head.obj");
	for (int i = 0; i < model->nfaces(); i++)
	{
		Vec3f a = model->vert(model->face(i)[0]);
		Vec3f b = model->vert(model->face(i)[1]);
		Vec3f c = model->vert(model->face(i)[2]);
		//还要把这些转换成对应的像素位置
		//原来属于[-1,1] 变成了[0,800]
		int xa = (a.x + 1.) * width / 2.;
		int ya = (a.y + 1.) * height / 2.;

		int xb = (b.x + 1.) * width / 2.;
		int yb = (b.y + 1.) * height / 2.;

		int xc = (c.x + 1.) * width / 2.;
		int yc = (c.y + 1.) * height / 2.;
		line(xa, ya, xb, yb, image, white);
		line(xa, ya, xc, yc, image, white);
		line(xb, yb, xc, yc, image, white);
	}
	
	image.flip_vertically();
	image.write_tga_file("output_L1_Model.tga");
	delete model;
}