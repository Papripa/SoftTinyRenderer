//Bresenham’s Line Drawing Algorithm
#include "line.h"
#include "tgaimage.h"
//tga view : https://schmittl.github.io/tgajs/
#define small 1e-5
void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) {
    
    bool steep = false;
    if (std::abs(x0 - x1) < std::abs(y0 - y1)) { // if the line is steep, we transpose the image 
        std::swap(x0, y0);
        std::swap(x1, y1);
        //让大的为x
        steep = true;
    }
    if (x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    int dx = x1 - x0;
    int dy = y1 - y0;
    float derror2 = std::abs(dy )*2;//斜率 小于1的
    float error2 = 0;
    int y = y0;
    for (int x = x0; x <= x1; x++) {
        if (steep) {
            image.set(y, x, color);
        }
        else {
            image.set(x, y, color);
        }
        error2 += derror2;//每次y增加多少斜率 而会四舍五入
        if (error2 > dx) {
            y += (y1 > y0 ? 1 : -1); //
            error2  -= dx * 2;
            //不能直接为0 必须要减dx * 2 是根据变换的点去找像素 如果直接归零则类似于向上平移了0.5个格子
        }
    }
}