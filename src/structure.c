#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

film* newFilm(int id, char*nom, nodeC * node){
	film * item;
	item = (film*)malloc(sizeof(film));
	item->id=id;
	item->nom = (char*)malloc(sizeof(char) * strlen(nom));
	strcpy(item->nom,nom);
	item->categorie=node;
	return item;
}


nodeF* pushF(film* movie, nodeF* node){
	if (node==NULL){


		node = (nodeF*)malloc(sizeof(nodeF));
	
		node->movie=movie;

		node->next=NULL;
		return node;

	}

	nodeF* current=node;
	while (current->next!=NULL){
		current=current->next;
		
	}


	current->next = (nodeF*)malloc(sizeof(nodeF));
	current->next->movie=movie;


	current->next->next=NULL;
	return node;
}

nodeC* pushC(char* categorie, nodeC* node){

	if (node==NULL){


		node = (nodeC*)malloc(sizeof(nodeC));

		node->categorie = (char*)malloc(sizeof(char)*strlen(categorie));
		strcpy(node->categorie,categorie);


		node->next=NULL;
		return node;

	}else if(strcmp(node->categorie,categorie)==0){
		return node;
	}

	nodeC* current=node;
	while (current->next!=NULL){

		if(strcmp(current->next->categorie,categorie)==0){
			return current;
		}else{
			current=current->next;
		}
	}


	current->next = (nodeC*)malloc(sizeof(nodeC));
	current->next->categorie = (char*)malloc(sizeof(char)*strlen(categorie));
	strcpy(current->next->categorie,categorie);


	current->next->next=NULL;
	return node;

}

nodeCnum* pushCnum(char* categorie, nodeCnum* node){
	if (node==NULL){

		node = (nodeCnum*)malloc(sizeof(nodeCnum));
		node->categorie = (char*)malloc(sizeof(char)*strlen(categorie));
		strcpy(node->categorie, categorie);
		node->compteur=1;
		node->next=NULL;
		return node;

	} else if(strcmp(node->categorie,categorie)==0){
		node->compteur+=1;
		return node;
	}
	nodeCnum* current = node;
	while(current->next!=NULL){
		if(strcmp(current->next->categorie,categorie)==0){
			current->next->compteur+=1;
			return node;
		}else{
			current=current->next;
		}
	}

	current->next = (nodeCnum*)malloc(sizeof(nodeCnum));
	current->next->categorie = (char*)malloc(sizeof(char)*strlen(categorie));
	strcpy(current->next->categorie, categorie);
	current->next->compteur=1;
	current->next->next=NULL;
	return node;
}

int nomToID(char * nom, nodeF * node){

	nodeF* current = node;
	while (current != NULL) {
        if (strcmp(current->movie->nom,nom)==0){
        	return current->movie->id;
        }else{
        	current = current->next;
        }
    }

	return 0;
}

film* idToFilm(int id, nodeF* node){


	nodeF* current = node;
	while (current != NULL) {
        if (current->movie->id==id){
        	return current->movie;
        }else{
        	current = current->next;
        }
    }
	
	return NULL;

	
}


// void regardeCata(nodeF* node){
// 	nodeF* current =node;


// 	while (current != NULL){
// 		printf("%p\n",current->movie->nom );
// 		printf("%s\n", node->movie->nom);
// 		printf("%p\n",current );
// 		printf("%p\n",current->next );
// 		current=current->next;
// 		printf("%p\n",current );

// 	}
	
// }

// void regardeFilm(film* movie){
// 	int compteur = 0;

// 	if (movie != NULL){

// 		printf("%d %s\n", movie->id, movie->nom);
// 	}
// }

// void regardeCategorie(nodeC* node){

// 	nodeC* current =node;

// 	while (current != NULL){

// 		printf("%s\n", current->categorie);
// 		current=current->next;
// 	}
	
// }


// nodeF* newListF(film * movie){
// 	nodeF* liste;

// 	liste = (nodeF*)malloc(sizeof(nodeF));
	
// 	liste->movie=movie;

// 	liste->next=NULL;
// 	return liste;
// }

// nodeC* newListC(char* categorie){
// 	nodeC* liste;
// 	liste = (nodeC*)malloc(sizeof(nodeC));
// 	liste->categorie = (char*)malloc(sizeof(char)*strlen(categorie));
// 	strcpy(liste->categorie,categorie);


// 	liste->next=NULL;
// 	return liste;
// }

// nodeCnum* newListCnum(char* categorie, nodeCnum* liste){

// 	liste = (nodeCnum*)malloc(sizeof(nodeCnum));
// 	liste->categorie = (char*)malloc(sizeof(char)*strlen(categorie));
// 	strcpy(liste->categorie, categorie);
// 	liste->compteur=1;


// 	liste->next=NULL;
// 	return liste;
// }

// void addC(char* categorie, nodeC* node){

// 	if (node==NULL){
// 		node=newListC(categorie);
// 	}

// 	nodeC* current=node;
// 	while (current->next!=NULL){

// 		if(strcmp(current->next->categorie,categorie)==0){
// 			return;
// 		}else{
// 			current=current->next;
// 		}
// 	}

// 	current->next=newListC(categorie);
// }








