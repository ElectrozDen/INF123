#include <stdio.h>
#include "automate.h"

int main(int argc, char *argv[]) {

automate A ;
FILE *f;

	if(argc != 2){
		printf("Code Erreur 1 : Vous devez donnez qu'un argument");
		return 1;
	}
	f = fopen(argv[1], "r");
	if(f == NULL){
		printf("Code Erreur 2 : Impossible d'ouvrir en lecture votre fichier");
		return 2;
	}
//	init_mon_automate(&A) ;
	lecture_automate(&A, f);
	fclose(f);
	simule_automate(&A) ;
	return 0 ;
}	
