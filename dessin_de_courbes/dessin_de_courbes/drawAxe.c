/*
Auteur: Etienne Ischer & Thomas Jolain
Date :	16.06.2014
Titre : Travail Personnel

But:
Fonction permettant de dessiner les axes

Exemple:
drawAxe(unsigned long minX, unsigned long maxX, double stepX, unsigned long minY, unsigned long maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin);

marge:	Largeur à partir du bord à laisser vide
data:	Tableau de pointeur dynamiquement créer. Correspond aux données brut (sans header) de l'image
width:	Largeur totale de l'image
height:	Hauteur totale de l'image

*/
#include "typedef.h"
#include "math.h"

void drawAxe(double minX, double maxX, double stepX, double minY, double maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin)
{
	/*unsigned int xorigin = (unsigned int)floor(((minX + maxX) * ((fabs(minX) + fabs(maxX)) / (width - (2 * margin)))) + (width - (2 * margin)));
	unsigned int yorigin = (unsigned int)floor(((minY + maxY) * ((fabs(minY) + fabs(maxY)) / (height - (2 * margin)))) + (height - (2 * margin)));*/

	int xorigin = (fabs(minX) / (fabs(minX) + fabs(maxX))) * (width - (2*margin));
	int yorigin = (fabs(minY) / (fabs(minY) + fabs(maxY))) * (height - (2 * margin));


	sRGB red = { 0xff, 0x00, 0x00 };
	data[yorigin][xorigin] = red;

	return;
}