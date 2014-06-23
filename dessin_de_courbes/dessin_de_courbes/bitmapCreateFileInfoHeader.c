/*
Auteur: Etienne Ischer & Thomas Jolain
Date :	16.06.2014
Titre : Travail Personnel

But:
Fonction permettant de créer le header d'information du fichier bitmap.

Exemple:
sFileInfoHeader var = bitmapCreateBitmapInfoHeader(unsigned int totalSize);


*/


#ifndef TYPEDEF_H
#include "typedef.h"
#endif

sFileInfoHeader bitmapCreateFileInfoHeader(unsigned int totalSize)
{
	sFileInfoHeader bfh;

	//	Type
	bfh.bfType = 0x4D42;
	
	//	Reserved offsets
	bfh.bfReserved1 = 0x0000;
	bfh.bfReserved2 = 0x0000;

	//	total size
	bfh.bfSize = totalSize;

	//	Offset Address that contains the BitmapHeader
	bfh.bfOffBits = 0x00000036;
	
	return bfh;
}