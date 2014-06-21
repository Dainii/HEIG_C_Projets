#include "headers.h"
#include "math.h"

void drawPoint(double x_value, double y_value, double minX, double maxX, double stepX, double minY, double maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin)
{
	//Invert y coordinate because of bmp structure
	y_value = -y_value;

	if (y_value > minY && y_value < maxY)
	{

		//	Multiply this proportion with the number of pixel
		unsigned int xCoordinate = (unsigned int)ceil((((x_value + fabs(minX)) * (width - (2 * margin))) / (fabs(minX) + fabs(maxX)))) + margin;
		unsigned int yCoordinate = (unsigned int)ceil((((y_value + fabs(minY)) * (height - (2 * margin))) / (fabs(minY) + fabs(maxY)))) + margin;


		//	Write Pixel
		data[yCoordinate][xCoordinate] = _RED;

	}

	return;
}