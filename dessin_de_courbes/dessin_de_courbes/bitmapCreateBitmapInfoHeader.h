/*
Auteur: Etienne Ischer & Thomas Jolain
Date :	16.06.2014
Titre : Travail Personnel

But:
Fonction permettant de créer le header d'information de la zone bitmap.

Exemple:
bitmapCreateBitmapInfoHeader(unsigned int width,unsigned int height);

width:	Largeur totale de l'image
height:	Hauteur totale de l'image

*/
#define BITMAPCREATEBITMAPINFOHEADER_H

#ifndef TYPEDEF_H
#include "typedef.h"
#endif

sBitmapInfoHeader bitmapCreateBitmapInfoHeader(unsigned long width, unsigned long height);