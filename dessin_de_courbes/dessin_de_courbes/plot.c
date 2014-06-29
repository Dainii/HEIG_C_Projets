/*
Auteur: Etienne Ischer & Thomas Jolain
Date :
Titre : Travail Personnel
But : Dessin de courbes
*/

#define _CRT_SECURE_NO_WARNINGS

//	Zone Include
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//	Zone Define
#define GRAD_SIZE 10
#define OUTPUTFILENAME "test.bmp"
#define CONFIG_FILENAME "config.txt"
#define IMG_WIDTH 1024
#define IMG_HEIGHT 768
#define IMG_MARGIN 100

// En-tetes et inclure
#include "typedef.h"
#include "character.xbm"

//	Fonction bitmap
sRGB **bitmapCreateData(unsigned long width, unsigned long height)
{
	//	Crée un tableau de pointeur
	sRGB **DataLine = (sRGB **)malloc(sizeof(sRGB*)*height);

	//	Crée un tableau avec la taille totale
	sRGB *DataColumn = (sRGB *)malloc(sizeof(sRGB)*width*height);

	//	Allocation d'adresse
	for (unsigned int i = 0; i < height; i++){
		DataLine[i] = &DataColumn[i*width];
	}

	//Return
	return DataLine;
}
void bitmapFreeData(sRGB **Data){
	free(Data[0]);
	free(Data);
}
sFileInfoHeader bitmapCreateFileInfoHeader(unsigned int totalSize)
{
	sFileInfoHeader bfh;

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
sBitmapInfoHeader bitmapCreateBitmapInfoHeader(unsigned long width, unsigned long height)
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

//	Fonction de dessin
void drawChar(unsigned long x_origin_coordinate, unsigned long y_origin_coordinate, sRGB ** data, char character)
{
	char table[CHAR_HEIGHT];

	//Decode character
	switch (character)
	{

	case 'A':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = A_bits[y];
		}
		break;

	case 'B':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = B_bits[y];
		}
		break;

	case 'C':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = C_bits[y];
		}
		break;

	case 'D':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = D_bits[y];
		}
		break;

	case 'E':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = E_bits[y];
		}
		break;

	case 'F':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = F_bits[y];
		}
		break;

	case 'G':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = G_bits[y];
		}
		break;

	case 'H':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = H_bits[y];
		}
		break;

	case 'I':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = I_bits[y];
		}
		break;

	case 'J':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = J_bits[y];
		}
		break;

	case 'K':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = K_bits[y];
		}
		break;

	case 'L':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = L_bits[y];
		}
		break;

	case 'M':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = M_bits[y];
		}
		break;

	case 'N':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = N_bits[y];
		}
		break;

	case 'O':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = O_bits[y];
		}
		break;

	case 'P':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = P_bits[y];
		}
		break;

	case 'Q':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = Q_bits[y];
		}
		break;

	case 'R':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = R_bits[y];
		}
		break;

	case 'S':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = S_bits[y];
		}
		break;

	case 'T':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = T_bits[y];
		}
		break;

	case 'U':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = U_bits[y];
		}
		break;

	case 'V':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = V_bits[y];
		}
		break;

	case 'W':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = W_bits[y];
		}
		break;

	case 'X':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = X_bits[y];
		}
		break;

	case 'Y':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = Y_bits[y];
		}
		break;

	case 'Z':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = Z_bits[y];
		}
		break;

	case 'a':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = a_bits[y];
		}
		break;

	case 'b':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = b_bits[y];
		}
		break;

	case 'c':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = c_bits[y];
		}
		break;

	case 'd':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = d_bits[y];
		}
		break;

	case 'e':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = e_bits[y];
		}
		break;

	case 'f':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = f_bits[y];
		}
		break;

	case 'g':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = g_bits[y];
		}
		break;

	case 'h':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = h_bits[y];
		}
		break;

	case 'i':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = i_bits[y];
		}
		break;

	case 'j':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = j_bits[y];
		}
		break;

	case 'k':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = k_bits[y];
		}
		break;

	case 'l':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = l_bits[y];
		}
		break;

	case 'm':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = m_bits[y];
		}
		break;

	case 'n':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = n_bits[y];
		}
		break;

	case 'o':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = o_bits[y];
		}
		break;

	case 'p':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = p_bits[y];
		}
		break;

	case 'q':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = q_bits[y];
		}
		break;

	case 'r':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = r_bits[y];
		}
		break;

	case 's':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = s_bits[y];
		}
		break;

	case 't':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = t_bits[y];
		}
		break;

	case 'u':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = u_bits[y];
		}
		break;

	case 'v':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = v_bits[y];
		}
		break;

	case 'w':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = w_bits[y];
		}
		break;

	case 'x':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = x_bits[y];
		}
		break;

	case 'y':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = y_bits[y];
		}
		break;

	case 'z':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = z_bits[y];
		}
		break;

	case '0':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = zero_bits[y];
		}
		break;

	case '1':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = un_bits[y];
		}
		break;

	case '2':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = deux_bits[y];
		}
		break;

	case '3':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = trois_bits[y];
		}
		break;

	case '4':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = quatre_bits[y];
		}
		break;

	case '5':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = cinq_bits[y];
		}
		break;

	case '6':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = six_bits[y];
		}
		break;

	case '7':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = sept_bits[y];
		}
		break;

	case '8':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = huit_bits[y];
		}
		break;

	case '9':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = neuf_bits[y];
		}
		break;

		//	HandMade Character
	case ' ':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = 0x00;
		}
		break;

	case '.':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = POINT_bits[y];
		}
		break;

	case '-':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = MINUS_bits[y];
		}
		break;

	case '+':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = PLUS_bits[y];
		}
		break;

	case ')':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = LEFT_P_bits[y];
		}
		break;

	case '(':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = RIGHT_P_bits[y];
		}
		break;

		//	Si aucun caractère n'a été reconnu, alors on écrit un espace
	default:
		for (int i = 0; i < CHAR_HEIGHT; i++)
		{
			table[i] = 0x00;
		}
		break;
	};

	//	Write Character
	for (unsigned char y = 0; y < CHAR_HEIGHT; y++)
	{
		char line = table[y];
		for (unsigned char x = 0; x < CHAR_WIDTH; x++)
		{
			if ((line & 0x00000001) == 0x00000001)
			{
				data[y_origin_coordinate + y][x_origin_coordinate + x] = _BLACK;
			}
			line = line >> 1;
		}
	}
}
void drawString(unsigned long x_coord, unsigned long y_coord, sRGB ** data, char * string, int sizeOfString, unsigned long width, unsigned long height)
{
	for (int i = 0; i < sizeOfString; i++)
	{
		if (x_coord + i*CHAR_WIDTH < width && y_coord + CHAR_HEIGHT < height)
		{
			drawChar(x_coord + i*CHAR_WIDTH, y_coord, data, string[i]);
		}
	}
}
void drawVerticalLine(unsigned long xCoordinate, unsigned long yCoordinate, int size, sRGB ** data)
{
	for (int line = -size; line <= size; line++)
	{
		data[yCoordinate + line][xCoordinate] = _BLACK;
	}
}
void drawHorizontalLine(unsigned long xCoordinate, unsigned long yCoordinate, int size, sRGB ** data)
{
	for (int line = -size; line <= size; line++)
	{
		data[yCoordinate][xCoordinate + line] = _BLACK;
	}
}
void drawAxe(double minX, double maxX, double stepX, double minY, double maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin)
{
	//	Find Origin coordinate
	int xorigin = (int)floor((fabs(minX) / (fabs(minX) + fabs(maxX))) * (width - (2 * margin)));
	int yorigin = (int)floor((fabs(minY) / (fabs(minY) + fabs(maxY))) * (height - (2 * margin)));

	//	Find number of grade to draw
	unsigned long numberOfYGrade = (unsigned long)round((fabs(minY) + fabs(maxY)) / stepY);
	unsigned long numberOfXGrade = (unsigned long)round((fabs(minX) + fabs(maxX)) / stepX);

	//	Find size in pixel between graduation
	double xStepInPixel = ((width - (2 * margin)) / (fabs(minX) + fabs(maxX)));
	double yStepInPixel = ((height - (2 * margin)) / (fabs(minY) + fabs(maxY)));

	//	Draw Axe
	for (unsigned long y = 0; y < height; y++)
	{
		for (unsigned long x = 0; x < width; x++)
		{
			//if (((x == margin || x == width - margin) && y>margin && y < height - margin) || ((y == margin || y == height - margin) && x > margin && x < width - margin))
			if ((x == (xorigin + margin) && y >= margin && y <= height - margin) || (y == (yorigin + margin) && x >= margin && x <= width - margin))
			{
				data[y][x] = _BLACK;
			}
		}
	}


	//	Graduate X
	for (unsigned int i = 0; i <= numberOfXGrade; i++)
	{
		//	To prevent minor imprecision when approaching origin. It will prevent an additional line to be drawn just after the origin
		if (i * stepX - fabs(minX) != 0)
		{
			//	Write Graduation
			int x_coordinate = (unsigned long)round(i * xStepInPixel * stepX) + margin;
			char buffer[10];
			if (minX + i * stepX > 0)
			{
				sprintf(buffer, "+%.2lf", minX + i * stepX);
			}
			else
			{
				sprintf(buffer, "%.2lf", minX + i * stepX);
			}
			drawString(x_coordinate - (CHAR_WIDTH * strlen(buffer) / 2), yorigin + CHAR_HEIGHT + margin, data, buffer, strlen(buffer), width, height);
			drawVerticalLine(x_coordinate, yorigin + margin, GRAD_SIZE, data);
		}
	}

	//	Graduate Y
	for (unsigned int i = 0; i <= numberOfYGrade; i++)
	{
		//	To prevent minor imprecision when approaching origin. It will prevent an additional line to be drawn just after the origin
		if (i * stepY - fabs(minY) != 0)
		{
			//	Write Graduation
			int y_coordinate = (unsigned long)round(i * yStepInPixel * stepY) + margin;
			char buffer[10];

			//Inwarding result of (minY + i * stepY) because of bitmap structure
			sprintf(buffer, "%.2lf", -(minY + i * stepY));
			drawString(xorigin + margin - (strlen(buffer) * CHAR_WIDTH), y_coordinate - CHAR_HEIGHT, data, buffer, strlen(buffer), width, height);
			drawHorizontalLine(xorigin + margin, y_coordinate, GRAD_SIZE, data);
		}
	}

	//	Draw Axe Origin Point

	for (int crossSize = -5; crossSize <= 5; crossSize++)
	{
		data[yorigin + margin + crossSize][xorigin + margin + crossSize] = _BLUE;
		data[yorigin + margin + crossSize][xorigin + margin - crossSize] = _BLUE;
	}

	return;
}
void drawGrid(double minX, double maxX, double stepX, double minY, double maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin)
{
	//	Trouver les coordonnées d'origine
	int xorigin = (int)floor((fabs(minX) / (fabs(minX) + fabs(maxX))) * (width - (2 * margin)));
	int yorigin = (int)floor((fabs(minY) / (fabs(minY) + fabs(maxY))) * (height - (2 * margin)));

	//	Calculer le nombre de graduation à dessiner
	unsigned long numberOfYGrade = (unsigned long)round((fabs(minY) + fabs(maxY)) / stepY);
	unsigned long numberOfXGrade = (unsigned long)round((fabs(minX) + fabs(maxX)) / stepX);

	//	Trouver la largeur entre chaque graduation
	double xStepInPixel = ((width - (2 * margin)) / (fabs(minX) + fabs(maxX)));
	double yStepInPixel = ((height - (2 * margin)) / (fabs(minY) + fabs(maxY)));

	//	Colonnes
	for (unsigned int i = 0; i <= numberOfXGrade; i++)
	{
		//	Afin de prévenir une légère imprecision à l'approche de la graduation (0,0), nous ne dessinerons pas celle-ci
		if (i * stepX - fabs(minX) != 0)
		{
			for (unsigned long y = margin; y < (height - margin); y++)
			{
				data[y][(unsigned long)round(i * xStepInPixel * stepX) + margin] = _GREY;
			}
		}
	}

	//	Lignes
	for (unsigned int i = 0; i <= numberOfYGrade; i++)
	{
		//	Afin de prévenir une légère imprecision à l'approche de la graduation (0,0), nous ne dessinerons pas celle-ci
		if (i * stepY - fabs(minY) != 0)
		{
			for (unsigned long x = margin; x < (width - margin); x++)
			{
				data[(unsigned long)round(i * yStepInPixel * stepY) + margin][x] = _GREY;
			}
		}
	}

	return;
}
void drawMargin(unsigned int margin, sRGB ** data, unsigned long width, unsigned long height)
{
	for (unsigned long y = 0; y < height; y++)
	{
		for (unsigned long x = 0; x < width; x++)
		{
			if (((x == margin || x == width - margin) && y>margin && y < height - margin) || ((y == margin || y == height - margin) && x > margin && x < width - margin))
			{
				data[y][x] = _GREY;
			}
		}
	}

	return;
}
void drawPoint(double x_value, double y_value, double minX, double maxX, double stepX, double minY, double maxY, double stepY, sRGB ** data, unsigned long width, unsigned long height, unsigned int margin)
{
	//Inversion de la valeur Y à cause de la structure d'un fichier bitmap
	y_value = -y_value;

	if (y_value > minY && y_value < maxY)
	{

		//	Calcule des coordonnées du point
		unsigned int xCoordinate = (unsigned int)ceil((((x_value + fabs(minX)) * (width - (2 * margin))) / (fabs(minX) + fabs(maxX)))) + margin;
		unsigned int yCoordinate = (unsigned int)ceil((((y_value + fabs(minY)) * (height - (2 * margin))) / (fabs(minY) + fabs(maxY)))) + margin;

		//	Ecriture du pixel
		data[yCoordinate][xCoordinate] = _RED;
	}

	return;
}


//	Gestion d'erreur
void errorThrow(int errNo)
{
	switch (errNo)
	{
	case 1001:
		puts("ERROR : Les graduations doivent être > 0");
		break;
	case 1002:
		puts("ERROR : Les valeurs minimums de X et Y doivent être <= 0");
		break;
	case 1003:
		puts("ERROR : Les valeurs maximums de X et Y doivent être => 0");
		break;
	case 1004:
		puts("ERROR : WIDTH and HEIGHT must be greater than 2*MARGIN");
		break;
	case 1005:
		puts("ERROR : Size of BMP : (height * width) <= 65535");
		break;
	case 1006:
		puts("ERROR : Les marges doivent être supérieurs > 0");
		break;
	case 1007:
		puts("ERROR : Les valeurs minimums de X ou Y doivent être différentes des valeurs maximums de X ou Y");
		break;
	case 2001:
		puts("ERROR : La mémoire n'a pas pu être allouée");
		break;
	case 2002:
		puts("ERROR : Le fichier bitmap n'a pas pu etre ecrit correctement sur le disque");
		break;
	default:
		break;
	}

	return;
}
int errorInputCheck(double minX, double maxX, double stepLabelX, double alternateStepLabelX, double minY, double maxY, double stepLabelY, double alternateStepLabelY, unsigned long width, unsigned long height, unsigned int margin)
{
	if (stepLabelX <= 0 || stepLabelY <= 0 || alternateStepLabelX <= 0 || alternateStepLabelY <= 0)
	{
		return 1001;
	}

	if (minX > 0 || minY > 0)
	{
		return 1002;
	}

	if (maxX < 0 || maxY < 0)
	{
		return 1003;
	}

	if (height < (2 * margin) || width < (2 * margin))
	{
		return 1004;
	}

	if ((width * height) < 65535)
	{
		return 1005;
	}

	if (margin <= 0)
	{
		return 1006;
	}
	if (minX == maxX || minY == maxY)
	{
		return 1007;
	}

	return 0;
}

//	Gestion de fichier
void saveImage(unsigned long width, unsigned long height, sRGB ** data)
{
	//	Ouverture du fichier
	FILE * file = NULL;
	file = fopen(OUTPUTFILENAME, "wb");

	//	Génération du header
	sBitmapInfoHeader sbih = bitmapCreateBitmapInfoHeader(width, height);
	sFileInfoHeader sfih = bitmapCreateFileInfoHeader(((width * height) * sizeof(sRGB)) + sizeof(sFileInfoHeader)+sizeof(sBitmapInfoHeader));

	//	Si le fichier a correctement été ouvert
	if (file != NULL)
	{
		//	Ecriture des headers
		fwrite(&sfih, sizeof(sFileInfoHeader), 1, file);
		fwrite(&sbih, sizeof(sBitmapInfoHeader), 1, file);

		//	Ecriture des data
		for (unsigned y = 0; y < height; y++)
		{
			for (unsigned x = 0; x < width; x++)
			{
				//	Ecriture des données
				unsigned int writtenBits;
				writtenBits = fwrite(&data[(height - 1) - y][x], sizeof(sRGB), 1, file);

				//	Verifier
				if (writtenBits != 1)
				{
					errorThrow(2002);
				}
			}
		}

		//	Fermeture du fichier
		fclose(file);
	}
}
sConfig readConfigFile(){
	// Crée une structure de configuration
	sConfig config;

	//	Ouverture du fichier
	FILE * file = NULL;
	file = fopen(CONFIG_FILENAME, "r");

	char c;

	// Test si l'ouverture s'est faite correctement
	// file est null en cas d'erreur
	if (file == 0)
	{
		//fopen returns 0, the NULL pointer, on failure
		perror("Cannot open input file\n");
		exit(-1);
	}
	else
	{
		// Déclare les variables nécessaire

		char key[20];
		char value[20];
		int refKey = 0;
		int refValue = 0;
		short step = 1;

		// Parcours toutes les lignes
		while ((c = fgetc(file)) != EOF)
		{
			switch (step){
			case 1:
				// Si la ligne commence par un #, il l'ignore
				if (c == '#'){
					step = 2;
				}
				else{
					if (c != '='){
						key[refKey] = c;
						refKey++;
					}
					step = 3;
				}
				break;
			case 2:
				// tant qu'il ne détecte pas la fin de la ligne, ne fait rien
				if (c == '\n')
					step = 1;
				break;
			case 3:
				// Si ce n'est pas un "="
				if (c != '='){
					key[refKey] = c;
					refKey++;
				}
				else {
					// termine la chaine
					key[refKey] = '\0';

					step = 4;
				}
				break;
			case 4:
				// Tant que le caractère n'est pas un retour à la ligne, lis la valeur
				if (c != '\n'){
					value[refValue] = c;
					refValue++;
				}
				else {
					// termine la chaine 
					/*value[refValue] = '\n';
					value[refValue+1] = '\0';*/
					value[refValue] = '\0';

					char *ptr;

					// compare la clé avec les différentes parties de la config
					// Compare avec les différents paramètres
					if (!strcmp(key, "XMIN")){
						config.xmin = strtod(value, &ptr);
					}
					else if (!strcmp(key, "XMAX")){
						config.xmax = strtod(value, &ptr);
					}
					else if (!strcmp(key, "YMIN")){
						config.ymin = strtod(value, &ptr);
					}
					else if (!strcmp(key, "YMAX")){
						config.ymax = strtod(value, &ptr);
					}
					else if (!strcmp(key, "STEPX")){
						config.stepX = strtod(value, &ptr);
					}
					else if (!strcmp(key, "STEPLABELX")){
						config.stepLabelX = strtod(value, &ptr);
					}
					else if (!strcmp(key, "STEPLABELY")){
						config.stepLabelY = strtod(value, &ptr);
					}
					else if (!strcmp(key, "XLABEL")){
						strncpy(config.xLabel, value, refValue + 1);
					}
					else if (!strcmp(key, "YLABEL")){
						strncpy(config.yLabel, value, refValue + 1);
					}
					else if (!strcmp(key, "TITLE")){
						strncpy(config.title, value, refValue + 1);
					}
					else
					{
					}

					// Vide les tableaux et réinitialise les variables
					value[0] = '\0';
					key[0] = '\0';

					refKey = 0;
					refValue = 0;

					step = 1;
				}
				break;
			}


		}
	}

	//	Fermeture du fichier
	fclose(file);

	printf("\n");


	return config;
}

//	Gestion de texte
void writeLabel(unsigned long width, unsigned long height, double minX, double maxX, double minY, double maxY, long margin, char * x_label, unsigned long x_labelSize, char * y_label, unsigned long y_labelSize, sRGB ** data)
{
	//	Trouver les coordonnées d'origine
	int xorigin = (int)floor((fabs(minX) / (fabs(minX) + fabs(maxX))) * (width - (2 * margin)));
	int yorigin = (int)floor((fabs(minY) / (fabs(minY) + fabs(maxY))) * (height - (2 * margin)));

	//	Trouver les premières coordonnées pour label X, en ajoutant une petite marge
	unsigned long x1_x_coordinate = width - margin + (CHAR_WIDTH / 2);
	unsigned long x2_y_coordinate = yorigin + margin - (CHAR_HEIGHT / 2);

	//	Trouver les premières coordonnées pour label X, en ajoutant une petite marge
	unsigned long y1_x_coordinate = (unsigned long)round(xorigin - ((CHAR_WIDTH * y_labelSize) / 2) + margin);
	unsigned long y2_y_coordinate = margin - (2 * CHAR_HEIGHT);

	//	Trouver la taille du label X
	long x_width = x_labelSize * CHAR_WIDTH;

	//	Ecrire le label si'l n'est pas trop long
	if (x_width <= margin)
	{
		drawString(x1_x_coordinate, x2_y_coordinate, data, x_label, x_labelSize, width, height);
	}
	else
	{
		puts("Label X trop grand pour passer dans la marge");
	}

	//	Calculer la taille du label Y
	long y_width = y_labelSize * CHAR_WIDTH;

	//	Ecrire le label si'l n'est pas trop long
	if ((unsigned long)x_width <= width)
	{
		drawString(y1_x_coordinate, y2_y_coordinate, data, y_label, y_labelSize, width, height);
	}
	else
	{
		puts("Label Y trop grand pour passer dans la marge");
	}

}
void writeTitle(unsigned long width, unsigned long height, unsigned long margin, char * title, char sizeOfTitle, sRGB ** data)
{
	unsigned int x_middle = width / 2;
	unsigned int y_coordinate = margin / 2;

	unsigned int totalLength = sizeOfTitle * CHAR_WIDTH;
	unsigned int totalHeight = CHAR_HEIGHT;

	unsigned int x_firstLetter = x_middle - (totalLength / 2);
	unsigned int y_firstletter = margin / 3;

	if ((margin / 2) > CHAR_HEIGHT)
	{
		drawString(x_firstLetter, y_firstletter, data, title, sizeOfTitle, width, height);
	}

}

//	Création de l'image
void createImage(unsigned long width, unsigned long height, long margin, double minX, double maxX, double minY, double maxY, sRGB ** data, double stepLabelX, double alternateStepLabelX, double stepLabelY, double alternateStepLabelY, double stepX, char x_label[10], char y_label[10], char title[50])
{
	//	Initialisation des DATA en blanc
	for (unsigned long y = 0; y < height; y++)
	{
		for (unsigned long x = 0; x < width; x++)
		{
			data[y][x] = _WHITE;
		}
	}

	//	Dessine la marge, la grille alternative et les axes de coordonnées
	drawMargin(margin, data, width, height);
	drawGrid(minX, maxX, alternateStepLabelX, minY, maxY, alternateStepLabelY, data, width, height, margin);
	drawAxe(minX, maxX, stepLabelX, minY, maxY, stepLabelY, data, width, height, margin);

	//	Dessine la courbe
	for (double i = minX; i <= maxX; i += stepX)
	{
		double y = i*sin(i);

		drawPoint(i, y, minX, maxX, stepLabelX, minY, maxY, stepLabelY, data, width, height, margin);
	}

	//	Ecrit le titre et les labels
	writeTitle(width, height, margin, title, strlen(title), data);
	writeLabel(width, height, minX, maxX, minY, maxY, margin, x_label, strlen(x_label), y_label, strlen(y_label), data);

}

// Programme principal
int main(){

	//	Taille de l'image
	unsigned long width = IMG_WIDTH;
	unsigned long height = IMG_HEIGHT;

	// crée la structure de config
	sConfig config;

	// Remplis la config
	config = readConfigFile();

	//	valeurs minimums et maximums pour X et Y
	double minX = config.xmin;
	double maxX = config.xmax;
	double minY = config.ymin;
	double maxY = config.ymax;

	//	Définis la précision de la graduation
	double stepLabelX = config.stepLabelX;
	double stepLabelY = config.stepLabelY;

	//	Définis une graduation alternative pour un résultat plus lisible
	double alternateStepLabelX = config.stepLabelX / 4;
	double alternateStepLabelY = config.stepLabelY / 4;

	//	Définis les marges
	unsigned long margin = IMG_MARGIN;

	//	Définis la précision
	double stepX = config.stepX;

	//	Définis le titre du graphique
	char title[50];
	strncpy(title, config.title, 50);

	//	Définis les labels X et Y
	char x_label[10];
	char y_label[10];
	strncpy(x_label, config.xLabel, 10);
	strncpy(y_label, config.yLabel, 10);

	//	CHECK des données introduites
	int errorNbr = errorInputCheck(minX, maxX, stepLabelX, alternateStepLabelX, minY, maxY, stepLabelY,alternateStepLabelY, width, height, margin);
	if (errorNbr != 0)
	{
		errorThrow(errorNbr);
		return errorNbr;
	}

	//	Création de la zone contenant les données bitmap
	sRGB** data = bitmapCreateData(width, height);

	//	Création de l'image et dessin de la courbe
	createImage(width, height, margin, minX, maxX, minY, maxY, data, stepLabelX, alternateStepLabelX, stepLabelY, alternateStepLabelY, stepX, x_label, y_label, title);

	//	Ecrit le fichier
	saveImage(width, height, data);

	//	Libère les données allouées dynamiquement
	bitmapFreeData(data);
	return 0;
}