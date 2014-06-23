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
#define BITMAPCREATEDATA_H
#ifndef TYPEDEF_H
#include "typedef.h"
#endif

sRGB **bitmapCreateData(unsigned long width, unsigned long height);