#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct dict {
	int cle;
    int val;
    struct dict * next;
} dict;

dict* creer_dict(){
	dict * Dict=(dict *)malloc(sizeof(dict));
	Dict->next=NULL;
	return Dict  ;
}

dict* inserer_couple_dict(dict *Dict,int cle,int valeur){
	dict *temp=creer_dict();
	temp->cle=cle;
	temp->val=valeur;
	temp->next=Dict;
	return temp;
}
int trouver_valeur(dict *Dict,int cle){
	dict *temp=Dict;
	while(temp!=NULL){
		if(cle==temp->cle){
			return temp->val;
		}
		temp=temp->next;
	}
	return -1;
}
int trouver_cle(dict *Dict,int  valeur){
	dict *temp=Dict;
	while(temp!=NULL){
		if(temp->val==valeur){
			return temp->cle;
		}
		temp=temp->next;
	}
	return -1;
}
void categories_cle(dict *Dict,int valeur){
	int a=trouver_cle(Dict,valeur);
	
	
		if(a==0) printf("action");
		if(a==1) printf("crime");
		if(a==2) printf("thriller");
		if(a==3)printf("drama");
		if(a==4) printf("fantasy");
		if(a==5) printf("romance");
		if(a==6) printf("comedy");
		if(a==7) printf("family");
		if(a==8) printf("animation");
		if(a==9) printf("scifi");
		if(a==10) printf("horror");
		if(a==11) printf("adventure");
	
}

int main(){
	dict* Dict=creer_dict();
	Dict=inserer_couple_dict(Dict,0,1);
	Dict=inserer_couple_dict(Dict,2,7);
	Dict=inserer_couple_dict(Dict,5,3);

}