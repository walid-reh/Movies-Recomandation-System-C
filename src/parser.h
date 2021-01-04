#ifndef _PARSERH_
#define _PARSERH_

#include "structure.h"

	
int with(FILE * fread, fpos_t pos);
int nbFilm(char* file);
nodeF* parser(char* file);

#endif