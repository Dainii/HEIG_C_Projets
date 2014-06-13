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
	//	Create table of pointer of pointer
	sRGB **DataLine = (sRGB **)malloc(sizeof(sRGB*)*height);

	//	Create table of pointer
	sRGB *DataColumn = (sRGB *)malloc(sizeof(sRGB)*width*height);

	//	Allocate adresses
	for (unsigned int i = 0; i < height; i++){
		DataLine[i] = &DataColumn[i*width];
	}

	//Return
	return DataLine;
}