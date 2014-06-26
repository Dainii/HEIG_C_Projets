/*
Auteur: Etienne Ischer & Thomas Jolain
Date :
Titre : Travail Personnel
But : Dessin de courbes
*/

// En-tetes et inclure
#include "typedef.h"

#include "bitmapCreateData.h"
#include "bitmapFreeData.h"

#include "drawAxe.h"
#include "drawGrid.h"
#include "drawMargin.h"
#include "drawPoint.h"

#include "writeLabels.h"
#include "writeTitle.h"

#include "fileWrite.h"

#include "errorThrow.h"
#include "errrorInputCheck.h"

#include "readConfig.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
// Programme principal
int main(){

	//	DEFAULT VALUES

	//	Size of image
	unsigned long width = 1280;
	unsigned long height = 720;

	// crée la structure de config
	sConfig config;

	// Remplis la config
	config = readConfig();

	//	Define minimum and maximum Value
	double minX = config.xmin;
	double maxX = config.xmax;
	double minY = config.ymin;
	double maxY = config.ymax;

	//	Define graduation precision for the drawAxe function only
	double stepX = config.stepX;
	double stepY = 1.;

	//	Define Alternate graduation precision for the drawGrid function only
	double gridStepX = config.stepLabelX;
	double gridStepY = config.stepLabelY;

	//	Define Margin
	unsigned long margin = 100;

	//	Define precision
	double stepPrecision = 0.0001;

	//	Define Graphics title
	char title[50] = config.title;

	//	Define x - y Label
	char x_label[10] = config.xLabel;
	char y_label[10] = config.yLabel;

	//	DATA INPUT



	//	CHECK INPUT
	int errorNbr = errorInputCheck(minX, maxX, stepX, gridStepX, minY, maxY, gridStepY, width, height, margin);
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
		double y = i*sin(i);

		drawPoint(i, y, minX, maxX, stepX, minY, maxY, stepY, data, width, height, margin);
	}

	writeTitle(width, height, margin, title, strlen(title), data);
	writeLabel(width, height, minX, maxX, minY, maxY, margin, x_label, strlen(x_label), y_label, strlen(y_label), data);

	fileWrite(width, height, data);

	bitmapFreeData(data);
	return 0;
}