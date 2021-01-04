#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UserReg.h"

void notesUser(int lc){ //construit t correspondant aux notes donné par l'utilisateurs aux films qu'il a vu.. permet de mettre à jour la matrice
	regFile=fopen("regfile.txt","a+");
	char n1[2];
	char mv[50];
	int j;
	int k;
	int note;
	int cpt1=0;

	
	//printf("%i",lc);
	for(int i=0;i<lc-1;i++){
		fgets(fi,sizeof fi,regFile);
		//printf("%s",fi);
	}

	

	car=fgetc(regFile);
	

	
	
	while(car!=':'){
		car=fgetc(regFile);
		
		
	}
	while(car!='\n'){
		j=0;
		k=0;
		car=fgetc(regFile);
		

		while(car!='=' && car!='\n'){
			//printf("%c",car);
			mv[j]=car;
			
			j++;
			car=fgetc(regFile);

			
		}
		mv[j]='\0';
	
		//printf(",");
		//printf("%s",mv);
		Nunderscore(mv);
		id=nomToID(mv,cata);
		//printf("id : %i\n",id );
		


		car=fgetc(regFile);
		while(car!=','&&car!='\n'){
			//printf("%c",car);
			n1[k]=car;
			k++;

			car=fgetc(regFile);


	 	}
		note=atoi(n1);
		//printf("note : %i\n",note);
		tid[cpt1]=id;
		
		t[tid[cpt1]-1]=note;
		cpt1++;
		



	}
	// for(int i=0;i<100;i++){
	// 	printf("%i",t[i]);
	// }
	
	
	

}

void underscore(char* film){ //transforme tout les espaces d'un nom de film composé en underscore
	char *p=film;
	for(int i=0;i<strlen(p);i++){
		if (*(p+i)==' '){
			*(p+i)='_';
			
		}
	}
}


void Nunderscore(char* film){
	char *p=film;
	for(int i=0;i<strlen(p);i++){
		if (*(p+i)=='_'){
			*(p+i)=' ';
			
		}
	}
}







void searchdel(char *chaine){ //supprime le 1er '\n' de chaine
	char *r=strchr(chaine,'\n');
	if(r){
		*r=0;
	}
}

void purger(void) //purge du buffer
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
	{}
}

int searchUser(FILE *fil,char m[500]){ //Recherche si l'utilisateur est déjà present
	int k;
	k=0;
	while(fgets(F,sizeof F,fil)!=NULL){
		k=k+1;
		if (strstr(F,m)!=NULL){
			printf("%i",k);
			return k;
		}
	}
   return 0;


}



int RegFilm(char mes[100], FILE* fil,int Deb,int k){ //Enregistre un film et sa note
	
	int cpt=0;
	printf("%s",mes);

	//scanf("%s",F);
	fgets(F,sizeof F,stdin);
	if(F[0]!='\n'){
		searchdel(F);

	}
	//searchdel(F);
	while (nomToID(F,cata)==0 && F[0]!='\n'){
		printf("Saisie incorrecte, veuillez verifier l'orthographe ou entrer un nom de film existant : ");

		fgets(F,sizeof F,stdin);
		if(F[0]!='\n'){
			searchdel(F);

		}
		//printf("%s",F);
		//printf("%i",nomToID(F,cata));

	}
	//printf("test2");
	underscore(F);
	


	if(F[0]=='\n'){ //si on appuie sur entrée sans rien avoir entré, la saisie est terminée
		return 0;
	}
	else{
		if(Deb==0){ //on ajoute une virgule seulement si l'utilisateur n'est pas nouveau(=seulement si on est pas en début de ligne)
			fprintf(fil,"%c",',');
		}
	
		searchdel(F);




		fprintf(fil,"%s",F);
		fprintf(fil,"%s","=");


		printf("Note : ");
		fgets(n,sizeof n,stdin);

		//printf("%c",n[0]);
		//printf("%c",n[1]);

		//printf("%i",atoi(n));

		purger();
		//printf("test2");

		searchdel(n);
		

		while(atoi(n)<0 || atoi(n)>10){
			printf("Veuillez entrer une note entre 0 et 10 \n");
			printf("Note : ");
			fgets(n,sizeof n,stdin);

			purger();
			searchdel(n);
		}
		if(Deb=1){
			Nunderscore(F);
			tid[k]=nomToID(F,cata);
			//printf("ID:%i",tid[k]);
			// tid[k]=cpt;
			// cpt++;
			t[tid[k]-1]=atoi(n);
			

		}
		fprintf(fil,"%s",n);
		RegFilm("Autre film visionné ? : ",fil,0,k++); //appel récursif, tant que l'utilisateur entre un autre film, on continue à écrire
		return 1;
	}


}

void registration(FILE *fil,FILE *fil2,char ut[500]){ //Enregistre le film et la note à la bonne place dans le fichier
 	searchdel(ut);
 	l=searchUser(fil,ut);
	rewind(fil);
	for(int i=0;i<100;i++){
			t[i]=-1;
	}

	if(l!=0){ //si l'utilisateur existe déjà
		for(int i=0;i<l-1;i++){
			fgets(F,sizeof F,fil); //On copie ligne par ligne le fichier dans le tampon, jusqu'à la ligne de l'utilisateur
			fprintf(fil2,"%s",F);

		}
		fgets(F,sizeof F,fil);
		searchdel(F);
		fprintf(fil2,"%s",F);
	

		RegFilm("Film visionné ? : ",fil2,0,0); //on enregistre le(s) film(s) en bout de ligne

		fprintf(fil2,"%c",'\n');
		while(fgets(F,sizeof F,fil)!=NULL){ //on copie le reste du fichier dans le tampon
			fprintf(fil2,"%s",F);
		}
		rewind(fil2);
		
		system("rm regfile.txt"); //On supprime l'ancien fichier...
		system("mv regfile2.txt regfile.txt"); //et renomme le tampon
		fclose(regFile);
		notesUser(l);




	}
	else{
		

		fprintf(fil,"%s",ut);
		fprintf(fil,"%s",":");
		RegFilm("Film visionné ? : ",fil,1,0); //enregistrement d'un nouvel utilisateur
		//ajouter_utilisateur(m,t);


	

	}

}
