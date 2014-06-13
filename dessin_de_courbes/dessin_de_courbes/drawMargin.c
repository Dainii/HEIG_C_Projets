#include "typedef.h"

void drawMargin (unsigned int margin, sRGB ** data, unsigned int width, unsigned int height)
{
	sRGB grey = { 0xCD, 0xCD, 0xCD };

	//	Y coordinate manipulation. Bitmap is read from last to first line
	for (unsigned y = 0; y < height; y++)
	{
		for (unsigned x = 0; x < width; x++)
		{
			if (x == margin || y == margin)
			{
				data[y][x] = grey;
			}

			if (x == width-margin || y == height-margin)
			{
				data[y][x] = grey;
			}
		}
	}

	return;
}