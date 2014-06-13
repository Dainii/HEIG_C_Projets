#include "typedef.h"
// liste des fonctions utilisées dans le programme

sBitmapInfoHeader bitmapCreateBitmapInfoHeader(unsigned long width, unsigned long height);
sFileInfoHeader bitmapCreateFileInfoHeader(unsigned int totalSize);
void createBitmapCanvas(unsigned long width, unsigned long height);
sRGB **bitmapCreateData(unsigned long width, unsigned long height);
void bitmapFreeData(sRGB **Data);
void drawMargin(unsigned int margin, sRGB ** data, unsigned int width, unsigned int height);