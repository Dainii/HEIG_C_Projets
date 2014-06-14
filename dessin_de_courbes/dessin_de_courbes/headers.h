#include "typedef.h"
// liste des fonctions utilisées dans le programme

//	Bitmap Functions
sBitmapInfoHeader bitmapCreateBitmapInfoHeader(unsigned long width, unsigned long height);
sFileInfoHeader bitmapCreateFileInfoHeader(unsigned int totalSize);
sRGB **bitmapCreateData(unsigned long width, unsigned long height);
void bitmapFreeData(sRGB **Data);

//	Drawing Functions
void drawMargin(unsigned int margin, sRGB ** data, unsigned int width, unsigned int height);
void drawAxe(double minX, double maxX, double stepX, double minY, double maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin);
void drawHorizontalLine(unsigned int xCoordinate, unsigned int yCoordinate, unsigned int size, sRGB ** data);
void drawVerticalLine(unsigned int xCoordinate, unsigned int yCoordinate, int size, sRGB ** data);

//	File Functions
void fileWrite(unsigned long width, unsigned long height, sRGB ** data);