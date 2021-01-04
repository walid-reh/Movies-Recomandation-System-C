#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"



int main(int argc, char *argv[]){
	for(int i=0; i<12;i++){
		c[i]=0;
	}
	m=allouer_matrice(100,100);

	affecter_note(m,7.2,0);
	affecter_note(m,8.4,1);
	affecter_note(m,6.8,2);
	affecter_note(m,6.9,3);
	affecter_note(m,9.5,4);
	affecter_note(m,7.4,5);
	affecter_note(m,6.2,6);
	affecter_note(m,8.6,7);
	affecter_note(m,6.7,8);
	affecter_note(m,6,9);
	affecter_note(m,6.6,10);
	affecter_note(m,8.0,11);
	affecter_note(m,6.9,12);
	affecter_note(m,7.8,13);
	affecter_note(m,8.6,14);
	affecter_note(m,8.1,15);
	affecter_note(m,7,16);
	affecter_note(m,8.1,17);
	affecter_note(m,8.7,18);
	affecter_note(m,7.8,19);
	affecter_note(m,7.7,20);
	affecter_note(m,4.1,21);
	affecter_note(m,6,22);
	affecter_note(m,8.9,23);
	affecter_note(m,7.4,24);
	affecter_note(m,6.6,25);
	affecter_note(m,7,26);
	affecter_note(m,6.7,27);
	affecter_note(m,8.5,28);
	affecter_note(m,8.3,29);
	affecter_note(m,8,30);
	affecter_note(m,7.4,31);
	affecter_note(m,8.5,32);
	affecter_note(m,9.5,33);
	affecter_note(m,4.6,34);
	affecter_note(m,8.0,35);
	affecter_note(m,7.6,36);
	affecter_note(m,8.6,37);
	affecter_note(m,7.6,38);
	affecter_note(m,8.1,39);
	affecter_note(m,7.1,40);
	affecter_note(m,7.8,41);
	affecter_note(m,7.8,42);
	affecter_note(m,7.5,43);
	affecter_note(m,7.8,44);
	affecter_note(m,6.5,45);
	affecter_note(m,8.7,46);
	affecter_note(m,8,47);
	affecter_note(m,8.1,48);
	affecter_note(m,8.1,49);
	affecter_note(m,8.3,50);
	affecter_note(m,7.7,51);
	affecter_note(m,8.5,52);
	affecter_note(m,7.8,53);
	affecter_note(m,6.1,54);
	affecter_note(m,5.5,55);
	affecter_note(m,7.9,56);
	affecter_note(m,8.1,57);
	affecter_note(m,7.4,58);
	affecter_note(m,7.2,59);
	affecter_note(m,8.6,60);
	affecter_note(m,7.7,61);
	affecter_note(m,6.7,62);
	affecter_note(m,5.0,63);
	affecter_note(m,5.8,64);
	affecter_note(m,7.0,65);
	affecter_note(m,7.5,66);
	affecter_note(m,4.1,67);
	affecter_note(m,8.9,68);
	affecter_note(m,6.8,69);
	affecter_note(m,6.1,70);
	affecter_note(m,7.1,71);
	affecter_note(m,7.9,72);
	affecter_note(m,8.6,73);
	affecter_note(m,7.1,74);
	affecter_note(m,6.7,75);
	affecter_note(m,8.5,76);
	affecter_note(m,7.7,77);
	affecter_note(m,8.2,78);
	affecter_note(m,4.3,79);
	affecter_note(m,4.9,80);
	affecter_note(m,7.7,81);
	affecter_note(m,8.2,82);
	affecter_note(m,8.1,83);
	affecter_note(m,5.9,84);
	affecter_note(m,6.0,85);
	affecter_note(m,5.7,86);
	affecter_note(m,6.6,87);
	affecter_note(m,8.7,88);
	affecter_note(m,7.0,89);
	affecter_note(m,9.0,90);
	affecter_note(m,7.5,91);
	affecter_note(m,8.1,92);
	affecter_note(m,7.1,93);
	affecter_note(m,7.9,94);
	affecter_note(m,7.2,95);
	affecter_note(m,8.0,96);
	affecter_note(m,7.4,97);
	affecter_note(m,9.2,98);
	affecter_note(m,8.6,99);
	regFile = fopen("regfile.txt","a+"); //On ouvre le fichier contenant les données, et un tampon
    regFile2 = fopen("regfile2.txt","a+");
	char test[10];
	//int test2;
	//FILE* bd=fopen("BDCSD.txt","r");
	tas* heap; 
	cata=parser("BDCSD.txt");
	printf("User Name : ");

	fgets(u,sizeof u,stdin);
	//purger();
	registration(regFile,regFile2,u);
	ajouter_utilisateur(m,t);
	fprintf(regFile,"%s","\n");
	fclose(regFile2);
	for(int i=0;i<100;i++){
			printf("%d",t[i]);
			printf("%c",',');
	}
	for(int i=0;i<100;i++){
			if(t[i]!=-1){
			   /*si t[i]!=1 alors l'utilisateur a note ce film donc on va verifier aux quels categories il appartient et on va ajouter des +1 a ces categories dans le tableau c*/ 
				remplissage_categories(c,i);
			}
	}
	
	int m1=max1(c);
	int m2 =max2(c,m1);
	printf("Vos catégories préférées sont ");
	categories_cle(m1);
	printf("et " );
	categories_cle(m2);
	printf("\n");
	heap =recommender(m,m1,m2);
	for(int i=0;i<5;i++){
		if(i==0){
			printf("Nous vous recommandons : %s\n",idToFilm(return_tas(heap,i),cata)->nom);

		}
		else{
			printf("%s\n",idToFilm(return_tas(heap,i),cata)->nom);
		}
	}

	








	//printf("Film : ");
	




	//fgets(test,sizeof test,stdin);
	
	//printf("%s",test);
	//test2=nomToID(f,cata);
	//printf("%i",test2);

	
	
	// regFile = fopen("regfile.txt","a+"); //On ouvre le fichier contenant les données, et un tampon
 //    regFile2 = fopen("regfile2.txt","a+");

	// printf("User Name : ");

	// fgets(u,sizeof u,stdin);
	// registration(regFile,regFile2,u);
	// fprintf(regFile,"%s","\n");
	// fclose(regFile2);
	// heap =recommender(m);
	
	// for(int i=0;i<5;i++){
	// 	print_tas(heap,i);
	// }


	/*
	PJ Partie
	*/

	//int nb = nbFilm("../res/BDCSD.txt");
	//parser("../res/BDCSD.txt");


	//int nb = nbFilm("../res/BDCSD.txt");
	
	//printf("%s\n", cata->next->movie->nom); 
	
	//printf("%s\n", idToFilm(2,cata)->nom); 
	//printf("%d\n", nomToID("The Walking Dead",cata)); 
	
	//regardeCata(cata);
	/*
	Test
	*/
	// nodeC* cata = NULL;
	// nodeC* pepe = NULL;
	// nodeC * lolo = NULL;
	// cata=pushC("a", cata);
	// cata=pushC("b", cata);
	// cata=pushC("c", cata);
	// pepe=pushC("a", pepe);
	// pepe=pushC("e", pepe);
	// pepe=pushC("f", pepe);
	// pepe=pushC("g", pepe);
	// lolo=pushC("a", lolo);
	// lolo=pushC("e", lolo);
	// lolo=pushC("e", lolo);
	// lolo=pushC("g", lolo);
	// // regardeCategorie(cata);
	// // printf("pepe:\n");
	// // regardeCategorie(pepe);
	// film* movie1 = newFilm(1,"papa",cata);
	// film* movie2 = newFilm(2,"maman",pepe);
	// film* movie3 = newFilm(3,"plop",lolo);
	// // regardeFilm(movie1);
	// // regardeFilm(movie2);
	// nodeF* catalogue = NULL;
	// catalogue=pushF(movie1, catalogue);
	// catalogue=pushF(movie2, catalogue);
	// catalogue=pushF(movie3, catalogue);	
	// //printf("%s\n",catalogue->next->movie->nom );
	// regardeCata(catalogue);

	// return(0);

	

}