/*
ATTENTION. LE TRAIT HORIZONTALE EST INSERER DEPUIS LE POINT DONNE EN PARTANT DU MILIEUX VERS LES EXTREMITES

exemple:

			<---.--->








*/


#ifndef TYPEDEF_H
#include "typedef.h"
#endif

void drawHorizontalLine(unsigned long xCoordinate, unsigned long yCoordinate, int size, sRGB ** data)
{
	for (int line = -size; line <= size; line++)
	{
		data[yCoordinate][xCoordinate + line] = _BLACK;
	}
}