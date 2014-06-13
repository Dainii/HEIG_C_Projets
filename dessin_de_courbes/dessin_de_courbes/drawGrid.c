#include "typedef.h"

void drawMargin (unsigned int margin, sRGB * data, unsigned int width, unsigned int height)
{
	sRGB grey = { 0xCD, 0xCD, 0xCD };

	//	Y coordinate manipulation. Bitmap is read from last to first line
	for (int y = height; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			if (x == (0 + margin) && y == (0 + margin))
			{

			}
		}
	}

	return;
}