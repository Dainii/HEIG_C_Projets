/* 
Auteur: Etienne Ischer & Thomas Jolain
Date :	12.06.2014
Titre : Travail Personnel

But :	
-----
This file contains every single struct and typedef necessary.
*/

#define TYPEDEF_H

//Pragma pack, to prevent padding
#pragma pack(push, 1)


//	Global Structure Definition
typedef struct
{
	unsigned char Blue;
	unsigned char Green;
	unsigned char Red;
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

typedef struct
{
	char title[100];
	char xLabel[100];
	char yLabel[100];
	double ymin;
	double ymax;
	double xmax;
	double xmin;
	double stepX;
	double stepLabelX;
	double stepLabelY;
} sConfig;

#pragma pack(pop)


//	Global Color definitions

//Primary
const static sRGB _RED = { 0x00, 0x00, 0xff };
const static sRGB _GREEN = { 0x00, 0xff, 0x00 };
const static sRGB _BLUE = { 0xff, 0x00, 0x00 };

//Secondary
const static sRGB _YELLOW = { 0x00, 0xff, 0xff };
const static sRGB _PURPLE = { 0xff, 0x00, 0xff };
const static sRGB _CYAN = { 0xff, 0xff, 0x00 };

//Black & WHITE
const static sRGB _BLACK = { 0x00, 0x00, 0x00 };
const static sRGB _GREY = { 0xCD, 0xCD, 0xCD };
const static sRGB _WHITE = { 0xff, 0xff, 0xff };