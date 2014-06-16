/*
Auteur: Etienne Ischer & Thomas Jolain
Date :	16.06.2014
Titre : Travail Personnel

But:
Fonction permettant de cr�er un buffer de donn�e pour la cr�ation ou nodification d'image.

Exemple:
sRGB** data = bitmapCreateData(unsigned long width,unsigned long height);
bitmapFreeData(data);

width:	Largeur totale de l'image
height:	Hauteur totale de l'image


/!\	-	La gestion dynamique de tableau NECESSITE de lib�rer la m�moire une fois utilis�e
*/


#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"

sRGB **bitmapCreateData(unsigned long width, unsigned long height)
{
	//	Cr�e un tableau de pointeur
	sRGB **DataLine = (sRGB **)malloc(sizeof(sRGB*)*height);

	//	Cr�e un tableau avec la taille totale
	sRGB *DataColumn = (sRGB *)malloc(sizeof(sRGB)*width*height);

	//	Allocation d'adresse
	for (unsigned int i = 0; i < height; i++){
		DataLine[i] = &DataColumn[i*width];
	}

	//Return
	return DataLine;
}