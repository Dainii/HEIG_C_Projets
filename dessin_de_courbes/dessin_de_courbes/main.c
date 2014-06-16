/*
Auteur: Etienne Ischer & Thomas Jolain
Date :
Titre : Travail Personnel
But : Dessin de courbes
*/

// En-tetes et inclure
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "headers.h"
#include <time.h>
// Programme principal
int main(){

	//	DEFAULT VALUES

	//	Size of image
	unsigned long width = 800;
	unsigned long height = 600;

	//	Define minimum and maximum Value
	double minX = -5;
	double maxX = 10;
	double minY = -5;
	double maxY = +5;

	//	Define graduation precision for the drawAxe function only
	double stepX = 1;
	double stepY = 1;

	//	Define Alternate graduation precision for the drawGrid function only
	double gridStepX = 0.25;
	double gridStepY = 0.25;

	//	Define Margin
	unsigned int margin = 100;

	//	DATA INPUT


	//	CHECK INPUT
	int errorNbr = errorInputCheck(minX, maxX, stepX, gridStepX, minY, maxY, stepY, gridStepY, width, height, margin);
	if (errorNbr != 0)
	{
		errorThrow(errorNbr);
		return errorNbr;
	}

	//	CREATE MEMORY ZONE
	sRGB** data = bitmapCreateData(width, height);

	//	Initialisation des DATA en blanc
	for (unsigned long y = 0; y < height; y++)
	{
		for (unsigned long x = 0; x < width; x++)
		{
			/*int r = rand() % 255;
			int g = rand() % 255;
			int b = rand() % 255;
			sRGB tmp = { r, g, b };*/
			data[y][x] = _WHITE;
		}
	}

	drawMargin(margin, data, width, height);
	drawGrid(minX, maxX, gridStepX, minY, maxY, gridStepY, data, width, height, margin);
	drawAxe(minX, maxX, stepX, minY, maxY, stepY, data, width, height, margin);

	fileWrite(width, height, data);

	bitmapFreeData(data);
	return 0;
}