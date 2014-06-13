//	Since we're developping also for linux and windows, we have to deactivate _CRT_SECURE_NO_WARNINGS.
//	Microsoft have developped their own fwrite, fread function that are not in the C99 standard, and therefore not portable
#define _CRT_SECURE_NO_WARNINGS 1

//	Define & include
#include "headers.h"
#define PATH "test.bmp"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//	To prevent including multiple times typedef.h
#ifndef TYPEDEF_H
#define TYPEDEF_H
#endif

void createBitmapCanvas(unsigned long width, unsigned long height)
{
	//	Create file handler
	FILE * file = NULL;

	//	White pixel
	sRGB white = { 0xff, 0xff, 0xff };

	//	Create Header
	sFileInfoHeader bfh = bitmapCreateFileInfoHeader(((width * height) * sizeof(sRGB)) + sizeof(sFileInfoHeader) + sizeof(sBitmapInfoHeader));
	sBitmapInfoHeader bih = bitmapCreateBitmapInfoHeader(width, height);


	//	Dynamically alocate "DATA" memory, containing only pixels, according to height and width
	sRGB * data = NULL;
	data = (sRGB*)malloc(width*height*sizeof(sRGB));
	

	//	If data memory successfully alocated
	if(data != NULL)
	{	
		/*//	Write every pixel with "0xff" to create a white image*/
		memset(data, 0xff, width*height*sizeof(sRGB));
	
		//	Open File
		file = fopen(PATH, "wb");

		//	Iff successfully opened
		if(file != NULL)
		{
			//	Write header + data
			fwrite(&bfh, sizeof(sFileInfoHeader), 1, file);
			fwrite(&bih, sizeof(sBitmapInfoHeader), 1, file);
			fwrite(data, (width*height)*sizeof(sRGB), 1, file);

			//	Close File
			fclose(file);
		}

	}

	else
	{
		free(data);
		return;
	}
	
	free(data);
	return;
}