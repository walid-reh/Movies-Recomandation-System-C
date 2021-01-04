#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct couple{
	int id;
	double note;
}couple ;


typedef struct tas {
  couple * tab;
  int capacite;
  int taille;
} tas;

int parent(int i);

int fils_gauche(int i);

int flis_droit(int i);

tas* creer_tas(int capacite);

void permuter_parent_fils(couple *p,couple *f);

tas* inserer_couple(couple c,tas* heap);

int return_tas(tas *heap,int i);

