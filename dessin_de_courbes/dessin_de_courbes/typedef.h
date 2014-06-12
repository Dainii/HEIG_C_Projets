/* 
Auteur: Etienne Ischer & Thomas Jolain
Date :	12.06.2014
Titre : Travail Personnel

But :	
-----
This file contains every single struct and typedef necessary.
*/

typedef struct
{
	char B;
	char V;
	char R;
} sRGB;

typedef struct
{
	unsigned char bfType[2];
	unsigned char bfSize[4];
	unsigned char bfReserved1[2];
	unsigned char bfReserved2[2];
	unsigned char bfOffBits[4];
} sBitmapFileHeader;

typedef struct
{
	unsigned char bmpSize[4];
	unsigned char bmpWidth[4];
	unsigned char bmpHeight[4];
	unsigned char bmpPlanes[2];
	unsigned char bmpBitCount[2];
	unsigned char bmpCompression[4];
	unsigned char bmpSizeImage[4];
	unsigned char bmpPixelPerMeterX[4];
	unsigned char bmpPixelPerMeterY[4];
	unsigned char bmpColorUsed[4];
	unsigned char bmpImportantColor[4];
} sBitmapDataHeader;