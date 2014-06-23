/*
Auteur: Etienne Ischer & Thomas Jolain
Date :	16.06.2014
Titre : Travail Personnel

But:
Fonction permettant de créer un buffer de donnée pour la création ou nodification d'image.

Exemple:
sRGB** data = bitmapCreateData(unsigned long width,unsigned long height);
bitmapFreeData(data);

width:	Largeur totale de l'image
height:	Hauteur totale de l'image


/!\	-	La gestion dynamique de tableau NECESSITE de libérer la mémoire une fois utilisée
*/
#define BITMAPCREATEDATA_H
#ifndef TYPEDEF_H
#include "typedef.h"
#endif

sRGB **bitmapCreateData(unsigned long width, unsigned long height);