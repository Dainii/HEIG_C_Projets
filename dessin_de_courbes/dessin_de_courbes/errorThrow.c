#include <stdio.h>

void errorThrow(int errNo)
{
	switch (errNo)
	{
		case 1001:
			puts("ERROR : Steps must be > 0");
			break;
		case 1002:
			puts("ERROR : X and Y minimum value must be <= 0");
			break;
		case 1003:
			puts("ERROR : X and Y maximum value must be => 0");
			break;
		case 1004:
			puts("ERROR : WIDTH and HEIGHT must be greater than 2*MARGIN");
			break;
		case 1005:
			puts("ERROR : Size of BMP : (height * width) <= 65535");
			break;
		case 1006:
			puts("ERROR : MARGIN must be > 0");
			break;
		case 1007:
			puts("ERROR : X or Y minimum value can't have the same value as X or Y maximum value > 0");
			break;
		case 2001:
			puts("ERROR : Couldn't allocate memory");
			break;
		case 2002:
			puts("ERROR : Couldn't write image to disk correctly");
			break;
		default:
			break;
	}

	return;
}