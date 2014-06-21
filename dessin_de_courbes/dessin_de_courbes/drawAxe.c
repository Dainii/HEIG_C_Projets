/*
Auteur: Etienne Ischer & Thomas Jolain
Date :	16.06.2014
Titre : Travail Personnel

But:
Fonction permettant de dessiner les axes

Exemple:
drawAxe(minX, maxX, stepX, minY, maxY, stepY, sRGB ** data, long width, long height, int margin)

marge:	Largeur à partir du bord à laisser vide
data:	Tableau de pointeur dynamiquement créer. Correspond aux données brut (sans header) de l'image
width:	Largeur totale de l'image
height:	Hauteur totale de l'image

*/
#include "headers.h"
#include "math.h"
#include "character.xbm"
#include <string.h>
#define GRAD_SIZE 10

void drawAxe(double minX, double maxX, double stepX, double minY, double maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin)
{
	//	Find Origin coordinate
	int xorigin = (int)floor((fabs(minX) / (fabs(minX) + fabs(maxX))) * (width - (2*margin)));
	int yorigin = (int)floor((fabs(minY) / (fabs(minY) + fabs(maxY))) * (height - (2 * margin)));

	//	Find number of grade to draw
	unsigned long numberOfYGrade = (unsigned long)round((fabs(minY) + fabs(maxY)) / stepX);
	unsigned long numberOfXGrade = (unsigned long)round((fabs(minX) + fabs(maxX)) / stepX);

	//	Find size in pixel between graduation
	double xStepInPixel = ((width - (2 * margin)) / (fabs(minX) + fabs(maxX)));
	double yStepInPixel = ((height - (2 * margin)) / (fabs(minY) + fabs(maxY)));

	//	Draw Axe
	for (unsigned long y = 0; y < height; y++)
	{
		for (unsigned long x = 0; x < width; x++)
		{
			//if (((x == margin || x == width - margin) && y>margin && y < height - margin) || ((y == margin || y == height - margin) && x > margin && x < width - margin))
			if ((x == (xorigin + margin) && y >= margin && y <= height - margin) || (y == (yorigin + margin) && x >= margin && x <= width - margin))
			{
				data[y][x] = _BLACK;
			}
		}
	}


	//	Graduate X
	for (unsigned int i = 0; i <= numberOfXGrade; i++)
	{
		//	To prevent minor imprecision when approaching origin. It will prevent an additional line to be drawn just after the origin
		if (i * stepX - fabs(minX) != 0)
		{
			//	Write Graduation
			int x_coordinate = (unsigned long)round(i * xStepInPixel * stepX) + margin;
			char buffer[10];
			sprintf(buffer, "%.2lf", minX + i * stepX);
			drawString(x_coordinate - (CHAR_WIDTH * strlen(buffer) / 2), yorigin + CHAR_HEIGHT + margin, data, buffer, strlen(buffer), width, height);
			drawVerticalLine(x_coordinate, yorigin + margin, GRAD_SIZE, data);
		}
	}

	//	Graduate Y
	for (unsigned int i = 0; i <= numberOfYGrade; i++)
	{
		//	To prevent minor imprecision when approaching origin. It will prevent an additional line to be drawn just after the origin
		if (i * stepY - fabs(minY) != 0)
		{	
			//	Write Graduation
			int y_coordinate = (unsigned long)round(i * yStepInPixel * stepY) + margin;
			char buffer[10];
			sprintf(buffer, "%.2lf", minX + i * stepX);
			drawString(xorigin + margin - (strlen(buffer) * CHAR_WIDTH), y_coordinate - CHAR_HEIGHT, data, buffer, strlen(buffer), width, height);
			drawHorizontalLine(xorigin + margin, y_coordinate, GRAD_SIZE, data);
		}
	}
	
	//	Draw Axe Origin Point

	for (int crossSize = -5; crossSize <= 5; crossSize++)
	{
		data[yorigin + margin + crossSize][xorigin + margin + crossSize] = _BLUE;
		data[yorigin + margin + crossSize][xorigin + margin - crossSize] = _BLUE;
	}

	return;
}