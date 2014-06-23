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

#ifndef TYPEDEF_H
#include "typedef.h"
#endif

sBitmapInfoHeader bitmapCreateBitmapInfoHeader(unsigned long width, unsigned long height)
{
	
	sBitmapInfoHeader bih;

	//	Define total size of header
	bih.bmpSize = 0x00000028;

	//	Define height and width
	bih.bmpHeight = height;
	bih.bmpWidth = width;

	//	Define nmber of planes
	bih.bmpPlanes = 0x0001;

	//	Define number of bit per pixel, we're using 24bits here
	bih.bmpBitCount = 0x18;

	//	Define compression
	bih.bmpCompression = 0x00000000;

	//	Calculate size image in byte and define in header
	bih.bmpSizeImage = ((height * width) * sizeof(sRGB));

	//Resolution
	bih.bmpPixelPerMeterX = 0x00000000;
	bih.bmpPixelPerMeterY = 0x00000000;

	//	Color Meter + important color
	bih.bmpColorUsed = 0x00000000;
	bih.bmpImportantColor = 0x00000000;
	
	return bih;
}