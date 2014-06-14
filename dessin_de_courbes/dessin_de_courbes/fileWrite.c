//	Bypass Visual Studio secure verification
//
//	Visual Studio ne permet pas de compiler avec des fonctions tel que "fopen", car ils ont implémenté leurs propre fonctions.
//	Mais utiliser leurs fonctions "sécurisée" ferait perdre toute portabilité.
//
#define _CRT_SECURE_NO_WARNINGS 1

#include "headers.h"
#include <stdio.h>

#define PATH "test.bmp"

void fileWrite(unsigned long width, unsigned long height, sRGB ** data)
{
	//	Open File
	FILE * file = NULL;
	file = fopen(PATH, "wb");

	//	Generate headers
	sBitmapInfoHeader sbih = bitmapCreateBitmapInfoHeader(width, height);
	sFileInfoHeader sfih = bitmapCreateFileInfoHeader(((width * height) * sizeof(sRGB)) + sizeof(sFileInfoHeader)+sizeof(sBitmapInfoHeader));

	//	Iff successfully opened
	if (file != NULL)
	{
		//	Write header + data
		fwrite(&sfih, sizeof(sFileInfoHeader), 1, file);
		fwrite(&sbih, sizeof(sBitmapInfoHeader), 1, file);
		for (unsigned y = 0; y < height; y++)
		{
			for (unsigned x = 0; x < width; x++)
			{
				//Write Data Backward from axe Y
				fwrite(&data[(height - 1) - y][x], sizeof(sRGB), 1, file);
				
				//Write Data
				//fwrite(&data[y][x], sizeof(sRGB), 1, file);
			}
		}

		//	Close File
		fclose(file);
	}
}