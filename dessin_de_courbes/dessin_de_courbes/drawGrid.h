#define DRAWGRID_H
#ifndef TYPEDEF_H
#include "typedef.h"
#endif
void drawGrid(double minX, double maxX, double stepX, double minY, double maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin);