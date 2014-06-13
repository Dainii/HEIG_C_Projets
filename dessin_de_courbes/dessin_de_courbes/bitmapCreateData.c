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