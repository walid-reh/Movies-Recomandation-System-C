#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamique4.h"
#include "parser.h"






nodeF* cata;
char F[500]; //stockage des chaines(film;utilisateur,etc...)
char u[500];
char f[120];
char n[3];
char car;
int l;
char fi[500];
int id;
int c[12];


FILE *regFile;
FILE *regFile2;
	
void notesUser(int l);

void underscore(char* film);
void Nunderscore(char* film);



void searchdel(char *chaine);

void purger(void);

int searchUser(FILE *fil,char m[500]);

int RegFilm(char mes[100], FILE* fil,int Deb,int k);

void registration(FILE *fil,FILE *fil2,char ut[500]);
	
	
	


