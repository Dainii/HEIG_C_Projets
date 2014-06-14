/*
ATTENTION. LE TRAIT HORIZONTALE EST INSERER DEPUIS LE POINT DONNE EN PARTANT DU MILIEUX VERS LES EXTREMITES

exemple:

			<---.--->








*/

#include "headers.h"

void drawHorizontalLine(unsigned int xCoordinate, unsigned int yCoordinate, int size, sRGB ** data)
{
	for (int line = -size; line <= size; line++)
	{
		data[yCoordinate + line][xCoordinate] = _RED;
	}
}