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

void drawAxe(double minX, double maxX, double stepX, double minY, double maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin)
{
	//	Find Origin coordinate
	int xorigin = (int)floor((fabs(minX) / (fabs(minX) + fabs(maxX))) * (width - (2*margin)));
	int yorigin = (int)floor((fabs(minY) / (fabs(minY) + fabs(maxY))) * (height - (2 * margin)));

	//	Find number of grade to draw
	unsigned long numberOfYGrade = (fabs(minY) + fabs(maxY)) / stepX;
	unsigned long numberOfXGrade = (fabs(minX) + fabs(maxX)) / stepX;

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
	for (int i = 0; i <= numberOfXGrade; i++)
	{
		//	To prevent minor imprecision when approaching origin. It will prevent an additional line to be drawn just after the origin
		if (i * stepX - fabs(minX) != 0)
		{
			drawVerticalLine((unsigned long)round(i * xStepInPixel * stepX) + margin, yorigin + margin, 5, data);
		}
	}

	//	Graduate Y
	for (int i = 0; i <= numberOfYGrade; i++)
	{
		//	To prevent minor imprecision when approaching origin. It will prevent an additional line to be drawn just after the origin
		if (i * stepY - fabs(minY) != 0)
		{
			drawHorizontalLine(xorigin + margin, (unsigned long)round(i * yStepInPixel * stepY) + margin, 5, data);
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