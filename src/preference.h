#ifndef _PREFERENCEH_
#define _PREFERENCEH_

#include "structure.h"
#include "parser.h"



void ajoutPreference(film* movie, nodeCnum * preference);

nodeCnum * preference(int ** vu, int len, nodeF* catalogue);

char * categoriePrefere(int ** vu, int len, nodeF* catalogue);

int estPresent(char* categorie, nodeC* node);

nodeF* filmReco(int ** vu, int len, nodeF* catalogue);

#endif