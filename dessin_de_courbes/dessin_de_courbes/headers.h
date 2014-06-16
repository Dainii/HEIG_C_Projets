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
void drawHorizontalLine(unsigned long xCoordinate, unsigned long yCoordinate, int size, sRGB ** data);
void drawVerticalLine(unsigned long xCoordinate, unsigned long yCoordinate, int size, sRGB ** data);
void drawPoint(double x_value, double y_value, double minX, double maxX, double stepX, double minY, double maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin);
void drawGrid(double minX, double maxX, double stepX, double minY, double maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin);

//	File Functions
void fileWrite(unsigned long width, unsigned long height, sRGB ** data);

//	Error function
void errorThrow(int errNo);
int errorInputCheck(double minX, double maxX, double stepX, double alternateStepX, double minY, double maxY, double stepY, double alternateStepY, unsigned long width, unsigned long height, unsigned int margin);