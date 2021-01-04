#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "preference.h"





void ajoutPreference(film* movie, nodeCnum * preference){
	nodeC* categorie = movie->categorie;
	while(categorie != NULL){
		pushCnum(categorie->categorie, preference);
		categorie=categorie->next;
	}

}

nodeCnum * preference(int ** vu, int len, nodeF* catalogue){
	nodeCnum * preference;
	preference = NULL;
	len = 100;
	for( int i=0 ; i < len ; i++){
		if (vu[i][1]!=-1){
			ajoutPreference(idToFilm(i+1,catalogue), preference);			
		}
	}
	return preference;
}

char * categoriePrefere(int ** vu, int len, nodeF* catalogue){
	nodeCnum* prefe =preference(vu, len, catalogue);
	char * nomCategorie;
	int occurence =0;
	while(prefe != NULL){
		if (occurence<prefe->compteur){
			nomCategorie = prefe->categorie;
			occurence= prefe->compteur;
		}
	}
	return nomCategorie;
}

int estPresent(char* categorie, nodeC* node){
	if(node==NULL){
		return 1;
	}else if(strcmp(node->categorie,categorie)==0){
		return 0;
	}else{
		return estPresent(categorie, node->next);
	}
}

nodeF* filmReco(int ** vu, int len, nodeF* catalogue){
	nodeF* bonFilm = NULL;
	char* categoriePref = categoriePrefere(vu, len, catalogue);
	while(catalogue != NULL){
		if(estPresent(categoriePref, (catalogue->movie)->categorie)){
			pushF(catalogue->movie, bonFilm);	
		}
	}

	return bonFilm;
}
