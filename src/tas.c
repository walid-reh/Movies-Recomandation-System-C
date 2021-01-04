#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tas.h"


int parent(int i){
	return (i-1)/2;
}

int fils_gauche(int i){
	return (2*i+1);
}

int flis_droit(int i){
	return (2*i+2);
}

tas* creer_tas(int capacite){
	tas * heap=(tas *)malloc(sizeof(tas)); 
	 heap->tab=(couple *)malloc(capacite*sizeof(couple));
	 heap->taille=0;
	return heap ;
}

void permuter_parent_fils(couple *p,couple *f){
	couple temp=*p;
	*p=*f;
	*f=temp;
}

tas* inserer_couple(couple c,tas* heap){
	int i;
	i=heap->taille;
	heap->tab[i]=c;
	heap->taille=heap->taille+1;
	while((i!=0)&&(heap->tab[parent(i)].note<heap->tab[i].note)){
		couple temp;
		temp=heap->tab[parent(i)];
		heap->tab[parent(i)]=heap->tab[i];
		heap->tab[i]=temp;
		i=parent(i);
	}
	return heap;
}

int return_tas(tas *heap,int i){
	return heap->tab[i].id;
}

// int main(){
// 	tas * heap;
// 	heap=creer_tas(100);
// 	heap->capacite=100;
// 	for(int i=0;i<heap->capacite;i++){
// 		heap->tab[i].id=i+1;
// 		heap->tab[i].note=-1;
// 	}
// 	couple c1,c2,c3;
// 	c1.id=10;
// 	c1.note=12;
// 	inserer_couple(c1,heap);
// 	c2.id=4;
// 	c2.note=16;
// 	inserer_couple(c2,heap);
// 	c3.id=1;
// 	c2.note=20;
// 	inserer_couple(c3,heap);
// 	print(heap,0);
// 	print(heap,1);
// 	print(heap,2);
// 	printf("%f",heap->tab[1].note);
// 	srand(time(NULL));
// 	srand(time(NULL));
// 	for(int i=0;i<100;i++){
// 		c1.id=i+1;
// 		c1.note=rand()%11;
// 		inserer_couple(c1,heap);
// 	}
// 	for(int i=0;i<5;i++){
// 		print_tas(heap,i);
// 	}

// }