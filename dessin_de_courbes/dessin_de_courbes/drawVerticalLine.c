#include "headers.h"

void drawVerticalLine(unsigned int xCoordinate, unsigned int yCoordinate, int size, sRGB ** data)
{
	for (int line = -size; line <= size; line++)
	{
		data[yCoordinate][xCoordinate + line] = _BLUE;
	}
}