#include "headers.h"
#include "character.xbm"

void writeTitle(unsigned long width, unsigned long height, unsigned long margin, char * title, char sizeOfTitle, sRGB ** data)
{
	unsigned int x_middle = width / 2;
	unsigned int y_coordinate = margin / 2;

	unsigned int totalLength = sizeOfTitle * CHAR_WIDTH;
	unsigned int totalHeight = CHAR_HEIGHT;

	unsigned int x_firstLetter = x_middle - (totalLength / 2);
	unsigned int y_firstletter = margin / 3;

	if ((margin / 2) > CHAR_HEIGHT)
	{
		drawString(x_firstLetter, y_firstletter, data, title, sizeOfTitle, width, height);
	}

}