#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dynamique4.h"

int appartient_horror(int id){
	int a;
	a=id+1;
	int t[]={2,13,17,33,36,50,54,81};
	for(int i=0;i<8;i++){
		if (a==t[i]) {
			return 1;
		}
	}return 0;
}
int appartient_adventure(int id){
	int a;
	a=id+1;
	int t[]={3,5,6,7,8,9,11,12,14,16,20,21,23,27,28,40,51,48,59,63,86,98,55,56};
	for(int i=0;i<24;i++){
		if (a==t[i]) {
			return 1;
		}
	}return 0;
}
int appartient_action(int id){
	int a;
	a=id+1;
	int t[]={1,3,6,11,12,14,15,16,21,27,32,40,41,42,44,48,55,56,65,66,70,71,76,80,85,88,89,90,97,98,100};
	for(int i=0;i<31;i++){
		if (a==t[i]) {
			return 1;
		}
	}return 0;
}
int appartient_crime(int id){
	int a;
	a=id+1;
	int t[]={1,14,19,21,26,34,36,41,49,57,61,65,67,71,76,79,84,87,88,90,91,95,99,100};
	for(int i=0;i<24;i++){
		if (a==t[i]) {
			return 1;
		}
	}return 0;
}
int appartient_thriller(int id){
	int a;
	a=id+1;
	int t[]={1,3,6,7,16,18,27,28,31,32,34,39,41,49,50,54,57,58,61,67,70,71,76,81,83,84,85,88,90,94,95,98,100};
	for(int i=0;i<33;i++){
		if (a==t[i]) {
			return 1;
		}
	}return 0;
}
int appartient_drama(int id){
	int a;
	a=id+1;
	int t[]={2,4,5,12,14,15,17,18,22,25,29,33,35,37,39,44,49,50,51,52,79,82,83,84,87,88,90,91,92,93,99,94,96,53,54,55,57,58,60,61,62,67,71,72,73,74,75,78};
	for(int i=0;i<48;i++){
		if (a==t[i]) {
			return 1;
		}
	}return 0;
}
int appartient_fantasy(int id){
	int a;
	a=id+1;
	int t[]={4,5,9,11,12,20,23,33,48,54,56,59};
	for(int i=0;i<12;i++){
		/*printf("%d\n",a==t[i] );*/
		if (a==t[i]) {

			return 1;
		}
	}return 0;
}
int appartient_romance(int id){
	int a;
	a=id+1;
	int t[]={4,20,22,26,29,37,52,54,69,72,82};
	for(int i=0;i<11;i++){
		if (a==t[i]) {
			return 1;
		}
	}return 0;
}
int appartient_comedy(int id){
	int a;
	a=id+1;
	int t[]={9,10,21,26,30,32,31,36,42,45,46,47,52,64,65,66,68,69,74,77,79,86,96};
	for(int i=0;i<23;i++){
		if (a==t[i]) {
			return 1;
		}
	}return 0;
}
int appartient_family(int id){
	int a;
	a=id+1;
	int t[]={4,9,18,42,51,76,81};
	for(int i=0;i<7;i++){
		if (a==t[i]) {
			return 1;
		}
	}return 0;
}
int appartient_animation(int id){
	int a;
	a=id+1;
	int t[]={9,42,86};
	for(int i=0;i<3;i++){
		if (a==t[i]) {
			return 1;
		}
	}return 0;
}
int appartient_scifi(int id){
	int a;
	a=id+1;
	int t[]={6,7,8,9,11,12,14,27,28,32,36,40,42,43,44,48,62,63,70,80,89};
	for(int i=0;i<21;i++){
		if (a==t[i]) {
			return 1;
		}
	}return 0;
}
void remplissage_categories(int *t,int id){
	
	t[0]=t[0]+appartient_action(id);
	t[1]+=appartient_crime(id);
	t[2]+=appartient_thriller(id);
	t[3]+=appartient_drama(id);
	t[4]+=appartient_fantasy(id);
	t[5]+=appartient_romance(id);
	t[6]+=appartient_comedy(id);
	t[7]+=appartient_family(id);
	t[8]+=appartient_animation(id);
	t[9]+=appartient_scifi(id);
	t[10]+=appartient_horror(id);
	t[11]+=appartient_adventure(id);
	
	
}


int max1(int *t){
	int ind=0;
	int max=0;
	for(int i=0;i<10;i++){
		if(t[i]>max){
			max=t[i];
			ind=i;
		}
	}t[ind]=-1;
	return ind;
}
int max2(int *t,int indmax1){
	int ind=0;
	int max=0;
	for(int i=0;i<10;i++){
		if((t[i]>max)&&(indmax1!=i)){
			max=t[i];
			ind=i;
		}
	}return ind;
}

int appartient_categories(int a,int id){
		int v=0;
		if(a==0)  v= appartient_action(id);
		if(a==1)  v= appartient_crime(id);
		if(a==2)  v= appartient_thriller(id);
		if(a==3) v= appartient_drama(id);
		if(a==4)  v= appartient_fantasy(id);
		if(a==5)  v= appartient_romance(id);
		if(a==6)  v= appartient_comedy(id);
		if(a==7)  v= appartient_family(id);
		if(a==8)  v= appartient_animation(id);
		if(a==9)  v= appartient_scifi(id);
		if(a==10)  v= appartient_horror(id);
		if(a==11)  v= appartient_adventure(id);
	return v;
}

void categories_cle(int a){	
		if(a==0) printf("action ");
		if(a==1) printf("crime ");
		if(a==2) printf("thriller ");
		if(a==3)printf("drama ");
		if(a==4) printf("fantasy ");
		if(a==5) printf("romance ");
		if(a==6) printf("comedy " );
		if(a==7) printf("family ");
		if(a==8) printf("animation ");
		if(a==9) printf("scifi ");
		if(a==10) printf("horror ");
		if(a==11) printf("adventure ");
	
}






matrice* allouer_matrice(int l, int c)
{
  matrice *m=(matrice*)malloc(sizeof(matrice));
  m->l=l;
  m->c=c;
  m->element=(double **) malloc(sizeof(double *)*l);
  for(int i=0;i<l;i++){
      m->element[i]=(double *)malloc(sizeof(double )*c);
   }
  return m;
}

void ajouter_utilisateur(matrice* m,int t[]){
	m->l=m->l+1;
	m->element=(double**)realloc(m->element,sizeof(double*)*(m->l));
	m->element[m->l-1]=(double *)malloc(sizeof(double )*(m->c));
	for(int i=0;i<100;i++){
		m->element[m->l-1][i]=t[i];
	}
}

void liberer_matrice(matrice *m)
{
 for(int i=0;i<m->l;i++){
  free(m->element[i]);
 }
 free(m->element);
 free(m);
}
double avg(double t[],int k){
	double s=0.0;
	for(int i=k;i<=k+9;i++){
		s=s+t[i];
		
	}
	s=s/10.0;
	return s;
}

double abs2(double d){
	if (d>=0){
		return d;
	}else {
		return -d;
	}
}

double avg2(double t[]){
	double s=0.0;
	for(int i=0;i<99;i++){
		s=s+t[i];
		
	}
	s=s/100.0;
	return s;
}

double distance(matrice* m,matrice *n){
	double k=0;
	for (int i = 0; i <m->l; ++i)
	{
		for (int j = 0; j < m->c; ++j)
		{
			k=k+(m->element[i][j]-n->element[i][j])*(m->element[i][j]-n->element[i][j]);
		}
	}
	
	return k;
}

void print_matrice(matrice* m){
	for (int i = 0; i <m->l; ++i)
	{
		for (int j = 0; j < m->c; ++j)
		{
			printf("%f ",m->element[i][j]);
		}
		printf(" \n");
	}

}
void affecter_note(matrice* m,double r,int j){
	srand(time(NULL));
	int i=0;

	double mj[100];
		while(i<=99){
			m->element[i][j]=rand()%11;
			mj[i]=m->element[i][j];
			if(((i-(i/10)*10)==9)&(i!=0)){
				if(abs2(r-avg(mj,i-9))>0.1){
					i=i-10;
				}
			}i=i+1;
		};	

}
matrice* produit_matriciel(matrice* m1,matrice *m2){
	double w;
	matrice *n=allouer_matrice(m1->l,m2->c);
	for (int i=0;i<m1->l;i++){
		for(int j=0;j<m2->c;j++){
			w=0;
			for(int l=0;l<m1->c;l++){
				w=w+m1->element[i][l]*m2->element[l][j];
			}
			n->element[i][j]=w;
			
		}
	}
	return n;
}

void traitement_m1(matrice* m,matrice* m1,matrice *m2){
	double t1,t2,t3;
	for (int i=0;i<m1->l;i++){
		for(int j=0;j<m1->c;j++){
			t2=0;
			t3=0;
			for(int f=0;f<m2->c;f++){
				t1=0;
				for(int k=0; k<m1->c;k++){
					if(k!=j){
						t1=t1+(m1->element[i][k])*(m2->element[k][f]);
					}
				}if(m->element[i][f]!=-1){
				t2=t2+(m->element[i][f]-t1)*m2->element[j][f];
				t3=t3+m2->element[j][f]*m2->element[j][f];
				}
			}
		m1->element[i][j]=t2/t3;
		}
	}
}
void initialisation(matrice* m1,matrice *m2){
	for (int i=0;i<m1->l;i++){
		for(int j=0;j<m1->c;j++){
			m1->element[i][j]=1;
			
		}
	}
	for (int i=0;i<m2->l;i++){
		for(int j=0;j<m2->c;j++){
			
			m2->element[i][j]=1;
		}
	}
}

void traitement_m2(matrice* m,matrice* m1,matrice *m2){
	double t1,t2,t3;
	for (int i=0;i<m2->l;i++){
		for(int j=0;j<m2->c;j++){
			t2=0;
			t3=0;
			for(int f=0;f<m1->l;f++){
				t1=0;
				for(int k=0; k<m1->c;k++){
					if(k!=i){
						t1=t1+(m1->element[f][k])*(m2->element[k][j]);
					}
				}
				if(m->element[f][j]!=-1){
				t2=t2+m->element[f][j]-t1;
				t3=t3+m1->element[f][i];
			}
			}
		m2->element[i][j]=t2/t3;

		}
	}
}


tas * recommender(matrice *m,int a,int b){
	tas * heap;
	heap=creer_tas(100);
	heap->capacite=100;
	matrice* m1=allouer_matrice(m->l,100);
	matrice* m2=allouer_matrice(100,100);
	initialisation(m1,m2);
	traitement_m1(m,m1,m2);
	traitement_m2(m,m1,m2);
	matrice *n=produit_matriciel(m1,m2);
	liberer_matrice(m1);
	liberer_matrice(m2);
	couple c1;
	for (int i=0;i<n->c;i++){
		c1.id=i+1;
		c1.note=n->element[n->l-1][i] ;
		printf("%f ",m->element[m->l-1][i]);

		if((m->element[m->l-1][i]==-1)&&((appartient_categories(a,i)==1)||(appartient_categories(b,i)==1))){
		    inserer_couple(c1,heap);
		}
	}
	
	liberer_matrice(n);
	return heap;
	
}

// int main(int argc, char *argv[]){
// 	matrice* m=allouer_matrice(100,100);

// 	affecter_note(m,7.2,0);
// 	affecter_note(m,8.4,1);
// 	affecter_note(m,6.8,2);
// 	affecter_note(m,6.9,3);
// 	affecter_note(m,9.5,4);
// 	affecter_note(m,7.4,5);
// 	affecter_note(m,6.2,6);
// 	affecter_note(m,8.6,7);
// 	affecter_note(m,6.7,8);
// 	affecter_note(m,6,9);
// 	affecter_note(m,6.6,10);
// 	affecter_note(m,8.0,11);
// 	affecter_note(m,6.9,12);
// 	affecter_note(m,7.8,13);
// 	affecter_note(m,8.6,14);
// 	affecter_note(m,8.1,15);
// 	affecter_note(m,7,16);
// 	affecter_note(m,8.1,17);
// 	affecter_note(m,8.7,18);
// 	affecter_note(m,7.8,19);
// 	affecter_note(m,7.7,20);
// 	affecter_note(m,4.1,21);
// 	affecter_note(m,6,22);
// 	affecter_note(m,8.9,23);
// 	affecter_note(m,7.4,24);
// 	affecter_note(m,6.6,25);
// 	affecter_note(m,7,26);
// 	affecter_note(m,6.7,27);
// 	affecter_note(m,8.5,28);
// 	affecter_note(m,8.3,29);
// 	affecter_note(m,8,30);
// 	affecter_note(m,7.4,31);
// 	affecter_note(m,8.5,32);
// 	affecter_note(m,9.5,33);
// 	affecter_note(m,4.6,34);
// 	affecter_note(m,8.0,35);
// 	affecter_note(m,7.6,36);
// 	affecter_note(m,8.6,37);
// 	affecter_note(m,7.6,38);
// 	affecter_note(m,8.1,39);
// 	affecter_note(m,7.1,40);
// 	affecter_note(m,7.8,41);
// 	affecter_note(m,7.8,42);
// 	affecter_note(m,7.5,43);
// 	affecter_note(m,7.8,44);
// 	affecter_note(m,6.5,45);
// 	affecter_note(m,8.7,46);
// 	affecter_note(m,8,47);
// 	affecter_note(m,8.1,48);
// 	affecter_note(m,8.1,49);
// 	affecter_note(m,8.3,50);
// 	affecter_note(m,7.7,51);
// 	affecter_note(m,8.5,52);
// 	affecter_note(m,7.8,53);
// 	affecter_note(m,6.1,54);
// 	affecter_note(m,5.5,55);
// 	affecter_note(m,7.9,56);
// 	affecter_note(m,8.1,57);
// 	affecter_note(m,7.4,58);
// 	affecter_note(m,7.2,59);
// 	affecter_note(m,8.6,60);
// 	affecter_note(m,7.7,61);
// 	affecter_note(m,6.7,62);
// 	affecter_note(m,5.0,63);
// 	affecter_note(m,5.8,64);
// 	affecter_note(m,7.0,65);
// 	affecter_note(m,7.5,66);
// 	affecter_note(m,4.1,67);
// 	affecter_note(m,8.9,68);
// 	affecter_note(m,6.8,69);
// 	affecter_note(m,6.1,70);
// 	affecter_note(m,7.1,71);
// 	affecter_note(m,7.9,72);
// 	affecter_note(m,8.6,73);
// 	affecter_note(m,7.1,74);
// 	affecter_note(m,6.7,75);
// 	affecter_note(m,8.5,76);
// 	affecter_note(m,7.7,77);
// 	affecter_note(m,8.2,78);
// 	affecter_note(m,4.3,79);
// 	affecter_note(m,4.9,80);
// 	affecter_note(m,7.7,81);
// 	affecter_note(m,8.2,82);
// 	affecter_note(m,8.1,83);
// 	affecter_note(m,5.9,84);
// 	affecter_note(m,6.0,85);
// 	affecter_note(m,5.7,86);
// 	affecter_note(m,6.6,87);
// 	affecter_note(m,8.7,88);
// 	affecter_note(m,7.0,89);
// 	affecter_note(m,9.0,90);
// 	affecter_note(m,7.5,91);
// 	affecter_note(m,8.1,92);
// 	affecter_note(m,7.1,93);
// 	affecter_note(m,7.9,94);
// 	affecter_note(m,7.2,95);
// 	affecter_note(m,8.0,96);
// 	affecter_note(m,7.4,97);
// 	affecter_note(m,9.2,98);
// 	affecter_note(m,8.6,99);
// 	int t[100];
// 	int tid[100];
// 	for(int i=0;i<100;i++){
// 		t[i]=-1;
// 	}
// 	int c[12];
// 	for(int i=0; i<12;i++){
// 		c[i]=0;
// 	}

	
// 	int cont=1;
// 	int i=0;
// 	printf("tapez l'id du %d eme film ",cont );
// 	scanf("%d",&tid[0]);
// 	printf("tapez la note du %d eme film ",cont );
// 	scanf("%d",&t[tid[0]]);
// 	while(tid[i]!=-1){
// 		i=i+1;
// 		cont=cont+1;
// 		printf("tapez l'id du %d eme film tapez -1 a la fin ",cont );
// 		scanf("%d",&tid[i]);
// 		if(tid[i]!=-1){
// 			printf("tapez la note du %d eme film ",cont );
// 			scanf("%d",&t[tid[i]]);
// 		}
		
// 	}
// 	tas* heap;
// 	ajouter_utilisateur(m,t);
// 	for(int i=0;i<100;i++){
// 			if(t[i]!=-1){
// 				remplissage_categories(c,i);
// 			}
// 	}
// 	int m1=max1(c);
// 	int m2 =max2(c,m1);
// 	printf("Vos catégories préférées sont ");
// 	categories_cle(m1);
// 	printf("et " );
// 	categories_cle(m2);
// 	printf("\n");
// 	heap =recommender(m,m1,m2);
	
	
// 	for(int i=0;i<5;i++){
// 		print_tas(heap,i);
// 	}










	

// }