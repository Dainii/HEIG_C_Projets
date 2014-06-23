

#ifndef TYPEDEF_H
#include "typedef.h"
#endif

void drawVerticalLine(unsigned long xCoordinate, unsigned long yCoordinate, int size, sRGB ** data)
{
	for (int line = -size; line <= size; line++)
	{
		data[yCoordinate + line][xCoordinate] = _BLACK;
	}
}