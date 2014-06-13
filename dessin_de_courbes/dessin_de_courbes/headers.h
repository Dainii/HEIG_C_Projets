#include "typedef.h"
// liste des fonctions utilisées dans le programme

//	Bitmap Functions
sBitmapInfoHeader bitmapCreateBitmapInfoHeader(unsigned long width, unsigned long height);
sFileInfoHeader bitmapCreateFileInfoHeader(unsigned int totalSize);
sRGB **bitmapCreateData(unsigned long width, unsigned long height);
void bitmapFreeData(sRGB **Data);

//	Drawing Functions
void drawMargin(unsigned int margin, sRGB ** data, unsigned int width, unsigned int height);