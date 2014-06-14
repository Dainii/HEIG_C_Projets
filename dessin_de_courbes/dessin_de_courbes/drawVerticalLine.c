#include "headers.h"

void drawVerticalLine(unsigned long xCoordinate, unsigned long yCoordinate, int size, sRGB ** data)
{
	for (int line = -size; line <= size; line++)
	{
		data[yCoordinate][xCoordinate + line] = _BLUE;
	}
}