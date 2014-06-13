#include "typedef.h"

sBitmapInfoHeader createBitmapInfoHeader(unsigned long width, unsigned long height)
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