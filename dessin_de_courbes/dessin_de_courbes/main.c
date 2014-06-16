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
	unsigned long width = 1280;
	unsigned long height = 720;

	//	Define minimum and maximum Value
	double minX = -10;
	double maxX = 10;
	double minY = -10;
	double maxY = +10;

	//	Define graduation precision for the drawAxe function only
	double stepX = 2;
	double stepY = 2;

	//	Define Alternate graduation precision for the drawGrid function only
	double gridStepX = 0.5;
	double gridStepY = 0.5;

	//	Define Margin
	unsigned int margin = 100;

	//	Define precision
	double stepPrecision = 0.0001;

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


	for (double i = minX; i <= maxX; i += stepPrecision)
	{
		drawPoint(i, tan(i), minX, maxX, stepX, minY, maxY, stepY, data, width, height, margin);
	}


	fileWrite(width, height, data);

	bitmapFreeData(data);
	return 0;
}