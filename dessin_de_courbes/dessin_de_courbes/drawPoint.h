#define DRAWPOINT_H

#ifndef TYPEDEF_H
#include "typedef.h"
#endif
void drawPoint(double x_value, double y_value, double minX, double maxX, double stepX, double minY, double maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin);