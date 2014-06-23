/*
Auteur: Etienne Ischer & Thomas Jolain
Date :	16.06.2014
Titre : Travail Personnel

But:
Fonction permettant de créer le header d'information de la zone bitmap.

Exemple:
sRGB** data = bitmapCreateData(unsigned long width,unsigned long height);
bitmapFreeData(sRGB **data);

/!\	-	La gestion dynamique de tableau NECESSITE de libérer la mémoire une fois utilisée
*/

#ifndef TYPEDEF_H
#include "typedef.h"
#endif

#include <stdlib.h>
#include <stdio.h>


void bitmapFreeData(sRGB **Data){
	free(Data[0]);
	free(Data);
}