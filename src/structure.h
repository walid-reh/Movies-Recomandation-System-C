#ifndef _STRUCTUREH_
#define _STRUCTUREH_

typedef struct nodeC{
	char * categorie;
	struct nodeC * next;
} nodeC;

typedef struct film{
	int id;
	char * nom;
	nodeC* categorie;
} film;


typedef struct nodeF{
	film* movie;
	struct nodeF * next;
} nodeF;



typedef struct nodeCnum{
	char * categorie;
	int compteur;
	struct nodeCnum * next;
} nodeCnum;




film* newFilm(int id, char*nom, nodeC* node);




nodeF* pushF(film*  movie, nodeF * node);

nodeC* pushC(char* categorie, nodeC * node);

nodeCnum* pushCnum(char* categorie, nodeCnum * node);

int nomToID(char * nom, nodeF * node);

film* idToFilm(int id, nodeF* node);

// void regardeCata(nodeF* node);

// void regardeFilm(film* movie);

// void regardeCategorie(nodeC* node);
#endif