#include <stdlib.h>
#include <stdio.h>
#include "typedef.h"


void bitmapFreeData(sRGB **Data){
	free(Data[0]);
	free(Data);
}