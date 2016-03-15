#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automate.h"

void init_par_defaut(automate *A) {
int i, j ;
	A-> nb_etats = NB_MAX_ETATS ;
	A-> etat_initial = 0 ;
	for (i=0 ; i<NB_MAX_ETATS ; i++)
		A->etats_finals[i]=0 ;
	for (i=0 ; i<NB_MAX_ETATS ; i++) 
		for (j=0 ; j<NB_MAX_ENTREES ; j++)
			A->transitions[i][j]=i ;
	for (i=0 ; i<NB_MAX_ETATS ; i++) 
		for (j=0 ; j<NB_MAX_ENTREES ; j++)
                        strcpy(A->sortie[i][j], "entree_invalide") ;
}
	
	
void init_mon_automate(automate *A) {
	init_par_defaut(A) ;
	A->nb_etats = 2 ;
	A->transitions[0]['2'] = 1 ;
	A->transitions[0]['r'] = 0 ;
	A->transitions[0]['c'] = 0 ;
	A->transitions[1]['2'] = 1 ;
	A->transitions[1]['r'] = 0 ;
	A->transitions[1]['c'] = 0 ;

	strcpy(A->sortie[0]['2'], "credit:20c") ;
	strcpy(A->sortie[0]['r'], "") ;
	strcpy(A->sortie[0]['c'], "") ;
	strcpy(A->sortie[1]['2'], "CLING!-credit:20c") ;
	strcpy(A->sortie[1]['r'], "CLING!") ;
	strcpy(A->sortie[1]['c'], "Boisson_servie") ;
}



void lecture_automate(automate *A, FILE *f){
	int depart, arrivee, i;
	char entree;
        char msg[128];
	int etats_finals, nb_trans;
	int etat, nb_sortie;

	init_par_defaut(A);

	fscanf(f, "%i", &(A->nb_etats));
	fscanf(f, "%i", &etats_finals);
	for(i = 0; i < etats_finals ; i++){
		fscanf(f, "%i", &etat);
		A->etats_finals[i] = etat;
	}
	
	fscanf(f, "%i", &nb_trans);
	for(i=1; i<= nb_trans; i++){
		fscanf(f, "%d %c %d", &depart, &entree, &arrivee);
		A->transitions[depart][(int)entree] = arrivee;
		A->sortie[depart][(int)entree][0] = '\0'; 
	}

	fscanf(f, "%d", &nb_sortie);
	for(i=1; i<=nb_sortie;i++){
		fscanf(f, "%d %c %s", &depart, &entree, msg);
		strcpy(A->sortie[depart][(int)entree], msg);
	}
	


}


char lire_entree(int *s) {
char c ;
	scanf("\n%c", &c) ;
	*s=(int)c ;
return c;
}

void ecrire_sortie(char message[]) {
	printf("%s\n", message) ;
}



void simule_automate(automate *A) {
int etat_courant, etat_suivant ;
int symbole_entree= ' ' ;

	etat_courant = A->etat_initial ;
	while (lire_entree(&symbole_entree) != 'q' && A->etats_finals[etat_courant] != 1) {
		etat_suivant = A->transitions[etat_courant][symbole_entree];
		ecrire_sortie(A->sortie[etat_courant][symbole_entree]);
                etat_courant = etat_suivant; 
	}
}











