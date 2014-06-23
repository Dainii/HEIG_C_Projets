#ifndef TYPEDEF_H
#include "typedef.h"
#endif
#ifndef CHARACTER_H
#include "character.xbm"
#endif
#ifndef DRAWSTRING_H
#include "drawString.h"
#endif

#include <math.h>

void writeLabel(unsigned long width, unsigned long height, double minX, double maxX, double minY, double maxY, long margin, char * x_label, unsigned long x_labelSize, char * y_label, unsigned long y_labelSize, sRGB ** data)
{
	//	Find Origin coordinate
	int xorigin = (int)floor((fabs(minX) / (fabs(minX) + fabs(maxX))) * (width - (2 * margin)));
	int yorigin = (int)floor((fabs(minY) / (fabs(minY) + fabs(maxY))) * (height - (2 * margin)));

	//	Calculate first letter coordinate for X, adding a little space (5px)
	unsigned long x1_x_coordinate = width - margin + 5;
	unsigned long x2_y_coordinate = yorigin + margin - (CHAR_HEIGHT / 2);

	//	Calculate first letter coordinate for y, adding a little space (CHAR_HEIGHT * 2)
	unsigned long y1_x_coordinate = (unsigned long)round(xorigin - ((CHAR_WIDTH * y_labelSize) / 2) + margin);
	unsigned long y2_y_coordinate = margin - (2* CHAR_HEIGHT);

	//	Calculate size of x Label
	long x_width = x_labelSize * CHAR_WIDTH;
	if (x_width <= margin)
	{
		drawString(x1_x_coordinate, x2_y_coordinate, data, x_label, x_labelSize, width, height);
	}

	//	Calculate size of y Label
	long y_width = y_labelSize * CHAR_WIDTH;
	if ((unsigned long)x_width <= width)
	{
		drawString(y1_x_coordinate, y2_y_coordinate, data, y_label, y_labelSize, width, height);
	}

}