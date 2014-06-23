

#ifndef TYPEDEF_H
#include "typedef.h"
#endif

#ifndef CHARACTER_H
#include "character.xbm"
#endif


#ifndef DRAWCHAR_H
#include "drawChar.h"
#endif

void drawString(unsigned long x_coord, unsigned long y_coord, sRGB ** data, char * string, int sizeOfString, unsigned long width, unsigned long height)
{
	for (int i = 0; i < sizeOfString; i++)
	{
		if (x_coord + i*CHAR_WIDTH < width && y_coord + CHAR_HEIGHT < height)
		{
			drawChar(x_coord + i*CHAR_WIDTH, y_coord, data, string[i]);
		}
	}
}