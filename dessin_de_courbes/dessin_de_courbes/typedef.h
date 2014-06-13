/* 
Auteur: Etienne Ischer & Thomas Jolain
Date :	12.06.2014
Titre : Travail Personnel

But :	
-----
This file contains every single struct and typedef necessary.
*/


//Pragma pack, to prevent padding
#pragma pack(push, 1)
typedef struct
{
	unsigned char B;
	unsigned char V;
	unsigned char R;
} sRGB;	

typedef struct
{
	unsigned short bfType;
	unsigned long bfSize;
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned long bfOffBits;
} sFileInfoHeader;

typedef struct
{
	unsigned long bmpSize;
	unsigned long bmpWidth;
	unsigned long bmpHeight;
	unsigned short bmpPlanes;
	unsigned short bmpBitCount;
	unsigned long bmpCompression;
	unsigned long bmpSizeImage;
	unsigned long bmpPixelPerMeterX;
	unsigned long bmpPixelPerMeterY;
	unsigned long bmpColorUsed;
	unsigned long bmpImportantColor;
} sBitmapInfoHeader;

#pragma pack(pop)