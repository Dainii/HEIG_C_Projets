#define WRITELABEL_H
#ifndef TYPEDEF_H
#include "typedef.h"
#endif
void writeLabel(unsigned long width, unsigned long height, double minX, double maxX, double minY, double maxY, long margin, char * x_label, unsigned long x_labelSize, char * y_label, unsigned long y_labelSize, sRGB ** data);