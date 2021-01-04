#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"


//fct non utilisé
int with(FILE * fread, fpos_t pos){

	fsetpos(fread, &pos);
	char c=0;
	if ((c=fgetc(fread))=='W'){
		if ((c=fgetc(fread))=='i'){
			if ((c=fgetc(fread))=='t'){
				if( (c=fgetc(fread))=='h'){
					if ((c=fgetc(fread))==' '){
						if ((c=fgetc(fread))==':'){
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

//Problème dans certain cas (pas avec les valeurs données), voir si pertinent de réaliser une autre implémentation
int nbFilm(char* file){
	FILE * fread;
	fread = fopen(file, "r");
	int compteur =0;
	int c=0;
	while((c = fgetc(fread)) != EOF) {
		if (c<58 & c>47){
			c=fgetc(fread);
			if(c<58 & c>47){
				c=fgetc(fread);
				if(c=='.'){
					compteur += 1;
				}
			} else if (c=='.'){
				compteur +=1;
			}
		}
	}
	return compteur;
}



nodeF* parser(char* file){
	FILE * fread;
	fread = fopen(file, "r");
	fpos_t pos;
	fpos_t posW;
	char * str;
	char c = 0;
	int i = 0;
	int debut;
	int fin;
	int len;
	int boucle =0;
	int compteur=0;
	int idFilm=1;
	char* nomFilm;
	nodeF* catalogue = NULL;
	film* movieTampon = NULL;
	nodeC* catTampon = NULL;




	while(!(boucle)){
		/*
		Titre
		*/
		
		c=fgetc(fread);

		fgetpos(fread, &pos);
		

		while((c = fgetc(fread)) != '('){}// du titre

		fin = ftell(fread);
		

		

		fsetpos(fread, &pos);
		while((c=fgetc(fread)) != '.'){}

		debut = ftell(fread);
		len = fin - debut -3;
		nomFilm = (char *)malloc(sizeof(char)*(len));

	   	fgetc(fread);
		fgetc(fread);


		fgets(nomFilm, len, fread);
		/*
		Vision Sortie
		puts(str);
		*/

		/*
		Penser à le faire à la fin
		free(nomFilm);
		*/

		/*
		On avance jusqu'au catégories
		*/

		int bol=0;
		int memeLigne=0;

		/*
		On avance jusqu'à la ligne With : 
		*/
		while((c = fgetc(fread)) != '\n'){}
		while((c = fgetc(fread)) != '\n'){}
		while(bol==0){
			//while((c = fgetc(fread)) != '\n'){}
			/*
			On reconnait With : après une fin de ligne
			*/
			// fgetpos(fread, &posW);
			// if (with(fread, posW)){
			// 	bol=1;
			// }
			// fsetpos(fread, &posW);
			fgetpos(fread,&pos);


			int n = 200;
			char * str;
			str = (char *)malloc(sizeof(char)*(n));
			fgets(str, n, fread);

			char * test;
			char * prst;
			test=strstr(str, "With :");
			prst=strchr(str, '|');
			if (test!=NULL){
				bol=1;
				if (prst!=NULL){
					memeLigne=1;
				}
			}
		}
		

		//while((c = fgetc(fread)) != '\n'){}
		if (memeLigne){
			fsetpos(fread,&pos);
			while((c=fgetc(fread)) != '|'){}
			fseek(fread,-11,SEEK_CUR);
			//printf("je passe la\n");
			//J'ai pris "Biography" comme la catégorie avec le plus de lettre
			
			c=fgetc(fread);
			//printf("%c\n",c );
			while(c>90 || c<65){
				//printf("je passe la2\n");
				c=fgetc(fread);
				//printf("%c\n",c );
			}
			fseek(fread,-1,SEEK_CUR);
		}
		
		
		bol = 0;

		fgetpos(fread, &pos);
		c=fgetc(fread);


		/* Catégories */

		while(bol==0){
			

			c=fgetc(fread);
			while(c != '|' & c != '\n'){

				c=fgetc(fread);
			}

			if ( c == '\n'){

				bol=1;

			} else if ( c== '|'){
				fin = ftell(fread);

				fsetpos(fread, &pos);

				debut = ftell(fread);
				len = fin - debut -1;

				str = (char *)malloc(sizeof(char)*(len));

				fgets(str, len, fread);

				catTampon=pushC(str, catTampon);
				free(str);


				fgetc(fread);
				fgetc(fread);
				fgetc(fread);
				fgetpos(fread, &pos);

			}
		}
		fseek(fread,-2,SEEK_CUR);
		c=fgetc(fread);
		
		
		if (c == '.'){

			fsetpos(fread, &pos);
			debut = ftell(fread);

			c = fgetc(fread);
			while(c < 47 || c > 58){
				c = fgetc(fread);
			}

			fin = ftell(fread);
			len = fin - debut -1;

			str = (char *)malloc(sizeof(char)*(len));

			fsetpos(fread, &pos);
			fgets(str, len, fread);
			catTampon=pushC(str, catTampon);

			free(str);
		} else{
			fgetc(fread);
			fin = ftell(fread);

			fsetpos(fread, &pos);
			debut = ftell(fread);
			len = fin - debut;

			str = (char *)malloc(sizeof(char)*(len));

			fgets(str, len, fread);
			catTampon=pushC(str, catTampon);

			free(str);
		}

		/* On avance jusqu'au prochain film*/

		while((c = fgetc(fread)) != '\n'){}
		while((c = fgetc(fread)) != '\n'){}

		/*
		Fin de fichier 
		*/
		c=fgetc(fread);
		c=fgetc(fread);
		if (c==EOF){
			boucle=1;

		}else{
			fseek(fread,-2,SEEK_CUR);
		}
		compteur+=1;

		movieTampon=newFilm(idFilm, nomFilm, catTampon);
		//regardeFilm(movieTampon);
		//regardeCategorie(catTampon);

		catalogue=pushF(movieTampon, catalogue);
		//regardeCata(catalogue);
		free(nomFilm);
		movieTampon = NULL;
		catTampon = NULL;
		idFilm+=1;


	}

	return catalogue;
}

// int main () {
// 	int nb = nbFilm("../res/BDCSD.txt");
//    parser("../res/BDCSD.txt");


//    return(0);
// }