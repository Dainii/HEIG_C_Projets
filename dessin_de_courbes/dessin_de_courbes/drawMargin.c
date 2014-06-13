/*
Auteur: Etienne Ischer & Thomas Jolain
Date :	16.06.2014
Titre : Travail Personnel

But:
Fonction permettant de cr�er un cadre sur une zone de buffer.

Exemple:
drawMargin(unsigned int marge, sRGB** data,unsigned int width,unsigned int height);

marge:	Largeur � partir du bord � laisser vide
data:	Tableau de pointeur dynamiquement cr�er. Correspond aux donn�es brut (sans header) de l'image
width:	Largeur totale de l'image
height:	Hauteur totale de l'image

*/


#include "typedef.h"

void drawMargin(unsigned int margin, sRGB ** data, unsigned long width, unsigned long height)
{
	sRGB grey = { 0xCD, 0xCD, 0xCD };

	//	Y coordinate manipulation. Bitmap is read from last to first line
	for (unsigned long y = 0; y < height; y++)
	{
		for (unsigned long x = 0; x < width; x++)
		{
			if (((x == margin || x == width - margin) && y>margin && y < height - margin) || ((y == margin || y == height - margin) && x > margin && x < width - margin))
			{
				data[y][x] = grey;
			}
		}
	}

	return;
}