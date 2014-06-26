/*
Auteur: Etienne Ischer & Thomas Jolain
Date :	16.06.2014
Titre : Travail Personnel

But:
Fonction permettant de lire le fichier de configuration et de stocker les informations s'y trouvant

*/
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "typedef.h"

#define PATH "config.txt"

sConfig readConfig(){
	// Crée une structure de configuration
	sConfig config;

	//	Open File
	FILE * file = NULL;
	file = fopen(PATH, "r");

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

		char key[10];
		char value[10];
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

					// Vide les tableaux et réinitialise les varaibels
					value[0] = "\0";
					key[0] = "\0";

					refKey = 0;
					refValue = 0;

					step = 1;
				}
				break;
			}

			
		}
	}

	fclose(file);

	printf("\n");


	return config;
}