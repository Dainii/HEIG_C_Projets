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
	/*unsigned int xorigin = (unsigned int)floor(((minX + maxX) * ((fabs(minX) + fabs(maxX)) / (width - (2 * margin)))) + (width - (2 * margin)));
	unsigned int yorigin = (unsigned int)floor(((minY + maxY) * ((fabs(minY) + fabs(maxY)) / (height - (2 * margin)))) + (height - (2 * margin)));*/


	//	Find Origin coordinate
	int xorigin = (fabs(minX) / (fabs(minX) + fabs(maxX))) * (width - (2*margin));
	int yorigin = (fabs(minY) / (fabs(minY) + fabs(maxY))) * (height - (2 * margin));

	//	developpement test variables

	data[yorigin + margin][xorigin + margin] = _RED;

	//	DrawLines
	for (unsigned long y = 0; y < height; y++)
	{
		for (unsigned long x = 0; x < width; x++)
		{
			//if (((x == margin || x == width - margin) && y>margin && y < height - margin) || ((y == margin || y == height - margin) && x > margin && x < width - margin))
			if ((x == (xorigin + margin) && y >= margin && y <= height - margin) || (y == (yorigin + margin) && x >= margin && x <= width - margin))
			{
				if (x % 10 == 0)
				{
					drawHorizontalLine(x, y, 5, data);
				}

				if (y % 10 == 0)
				{
					drawVerticalLine(x, y, 5, data);
				}
				data[y][x] = _BLACK;
			}
		}
	}

	//	Draw Axe Origin Point
	for (int crossSize = -5; crossSize <= 5; crossSize++)
	{
		data[yorigin + margin + crossSize][xorigin + margin] = _RED;
		data[yorigin + margin][xorigin + margin + crossSize] = _RED;
	}

	return;
}