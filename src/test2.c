#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void underscore(char* film){
	char *p=film;
	for(int i=0;i<strlen(p);i++){
		if (*(p+i)==' '){
			*(p+i)='_';
			//printf("%c",film[i]);
		}
	}
}


int main(int argc, char *argv[]){
	char s[50];
	//char* s=(char*)malloc(50*sizeof(char));
	//char ** ps=s;
	printf("Chaine : ");
	fgets(s,sizeof s,stdin);
	//printf("%s",s);
	underscore(s);
	printf("%s",s);

}