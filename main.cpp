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
void draw_triangle();
int main(int argc, char** argv) {
	
	draw_model();
	/*draw_triangle();*/
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

void draw_triangle(Vec2i a, Vec2i b, Vec2i c, TGAColor Color)
{
	/*Vec2i a(80,30), b(380,120), c(200,360);*/
	/*line(a.x, a.y, b.x, b.y, image, red);
	line(c.x, c.y, b.x, b.y, image, red);
	line(c.x, c.y, a.x, a.y, image, red);*/
	Vec2i min(std::min(std::min(a.x,b.x),c.x), std::min(std::min(a.y, b.y), c.y)), 
		max(std::max(std::max(a.x, b.x), c.x), std::max(std::max(a.y, b.y), c.y));
	Vec2i ab = b - a;
	Vec2i bc = c - b;
	Vec2i ca = a - c;
	for (int i = min.x; i <= max.x; i++)
	{
		bool inside = false;
		for (int j = min.y; j <= max.y; j++)
		{
			Vec2i point(i, j);
			Vec2i ap = point - a;
			Vec2i bp = point - b;
			Vec2i cp = point - c;
			int t1 = ap * ab, t2 = bp * bc, t3 = cp * ca;
			if (t1 == 0 || t2 == 0 || t3 == 0 || t1 > 0 && t2 > 0 && t3 > 0 || t1 < 0 && t2 < 0 && t3 < 0 )
			{
				inside = true;
				image.set(point.x,point.y, Color);
			}
			else
			{
				if(inside)
				{
					inside = false;
					break;
				}
			}
		}
	}

	/*image.flip_vertically();*/
	/*image.write_tga_file("images/Simple_triangle.tga");*/
}
void draw_model()
{
	Vec3f light_dir1(0, 0, 1); // 
	Vec3f light_dir2(0, 0, -1); // 
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

		Vec3f ab = b - a;
		Vec3f ac = c - a;
		//Vec3f N = (ab ^ ac).normalize();//
		Vec3f N = (ac ^ ab).normalize();
		float intensity = N * light_dir2; 
		if (intensity > 0)
		{
			draw_triangle(Vec2i(xa, ya), Vec2i(xb, yb), Vec2i(xc, yc), TGAColor(intensity * 255, intensity * 255, intensity * 255, 255));
		}
		/*int gray = rand() % 256;*/
		/*line(xa, ya, xb, yb, image, white);
		line(xa, ya, xc, yc, image, white);
		line(xb, yb, xc, yc, image, white);*/
	}
	image.flip_vertically();
	/*image.write_tga_file("output_L1_Model.tga");*/
	image.write_tga_file("images/Light2_Gray_Model.tga");//从后往前看
	delete model;
}