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

	//	Variables
	unsigned long width = 1024;
	unsigned long height = 768;

	double minX = -50;
	double maxX = 10;

	double minY = -70;
	double maxY = 20;

	double stepX = 1;
	double stepY = 1;

	unsigned int margin = 100;

	srand(time(NULL));

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
	drawGrid(minX, maxX, stepX, minY, maxY, stepY, data, width, height, margin);
	drawAxe(minX, maxX, stepX, minY, maxY, stepY, data, width, height, margin);

	fileWrite(width, height, data);

	bitmapFreeData(data);
	return 0;
}