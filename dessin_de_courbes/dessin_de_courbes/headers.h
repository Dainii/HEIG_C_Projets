#include "typedef.h"
// liste des fonctions utilisées dans le programme

sBitmapInfoHeader createBitmapInfoHeader(unsigned long width, unsigned long height);
sBitmapFileHeader createBitmapFileHeader(unsigned int totalSize);
void createBitmapCanvas(unsigned long width, unsigned long height);