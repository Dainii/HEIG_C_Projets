#include "typedef.h"

sBitmapFileHeader createBitmapFileHeader(unsigned int totalSize)
///<SUMMARY>
///	This function is specifically created to return a sBitmapFileHeader specifically created for the project
///	It only need the the total size of the file to generate the header
///
///</SUMMARY
{
	sBitmapFileHeader bfh;

	//	Type
	bfh.bfType = 0x4D42;
	
	//	Reserved offsets
	bfh.bfReserved1 = 0x0000;
	bfh.bfReserved2 = 0x0000;

	//	total size
	bfh.bfSize = totalSize;

	//	Offset Address that contains the BitmapHeader
	bfh.bfOffBits = 0x00000036;
	
	return bfh;
}