#include "headers.h"

void drawPoint(unsigned int xCoordinate, unsigned int yCoordinate, int size, sRGB ** data, sRGB color)
{
	for (int i = -size; i <= size; i++)
	{
		data[yCoordinate + i][xCoordinate] = color;
		data[yCoordinate][xCoordinate + i] = color;
	}
}