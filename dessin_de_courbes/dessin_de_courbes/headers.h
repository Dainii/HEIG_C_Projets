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
void drawChar(unsigned long x_origin_coordinate, unsigned long y_origin_coordinate, sRGB ** data, char character);
void drawString(unsigned long x_coord, unsigned long y_coord, sRGB ** data, char * string, int sizeOfString, unsigned long width, unsigned long height);

//	TXT Functions
void writeTitle(unsigned long width, unsigned long height, unsigned long margin, char * title, char sizeOfTitle, sRGB ** data);
void writeLabel(unsigned long width, unsigned long height, double minX, double maxX, double minY, double maxY, long margin, char * x_label, unsigned long x_labelSize, char * y_label, unsigned long y_labelSize, sRGB ** data);

//	File Functions
void fileWrite(unsigned long width, unsigned long height, sRGB ** data);

//	Error function
void errorThrow(int errNo);
int errorInputCheck(double minX, double maxX, double stepX, double alternateStepX, double minY, double maxY, double stepY, double alternateStepY, unsigned long width, unsigned long height, unsigned int margin);