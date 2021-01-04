#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tas.h"

int t[100];
int tid[100];
typedef struct matrice {
  int l,c;
  double **element;
} matrice;

int appartient_horror(int id);

int appartient_adventure(int id);

int appartient_action(int id);

int appartient_crime(int id);

int appartient_thriller(int id);

int appartient_drama(int id);

int appartient_fantasy(int id);

int appartient_romance(int id);
int appartient_comedy(int id);
int appartient_family(int id);
int appartient_animation(int id);
int appartient_scifi(int id);
void remplissage_categories(int *t,int id);


int max1(int *t);
int max2(int *t,int indmax1);

int appartient_categories(int a,int id);

void categories_cle(int a);

matrice* m;

matrice* allouer_matrice(int l, int c);


void ajouter_utilisateur(matrice* m,int t[]);

void liberer_matrice(matrice *m);
double avg(double t[],int k);

double abs2(double d);

double avg2(double t[]);

double distance(matrice* m,matrice *n);

void print(matrice* m);
void affecter_note(matrice* m,double r,int j);
matrice* produit_matriciel(matrice* m1,matrice *m2);

void traitement_m1(matrice* m,matrice* m1,matrice *m2);
void initialisation(matrice* m1,matrice *m2);
void traitement_m2(matrice* m,matrice* m1,matrice *m2);



tas* recommender(matrice *m,int a,int b);












	

