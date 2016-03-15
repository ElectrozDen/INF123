# Roquet Denys && Barrucand Robin

# TP7 INF123

## Reponses : 

[a] Par défaut l'état obtenu à partir de l'etat i est l'etat i, lui-même(boucle)

[b] Les caractéres d'entrés sont :

'r' (etat 0) -> rien ne se passe

'r' (etat 1) -> la machine retourne la monnaie

'c' (etat 0) -> rien ne se passe

'c' (etat 1) -> la machine sert la boisson

'2' (etat 0) -> le client donne 20c à la machine (premiere fois)

'2' (etat 1) -> le client rajoute 20c à la machine

[c] Si je rentre un caractère d'entrée non prévu alors cela affiche "entree_invalide"

Nous devons faire ctrl+c pour quitter l'automate

[d]

char lire_entree(int *s) {

char c ;

scanf("\n%c", &c) ;

*s=(int)c ;

return c;

}

void simule_automate(automate *A) {

int etat_courant, etat_suivant ;

int symbole_entree= ' ' ;

etat_courant = A->etat_initial ;

while (lire_entree(&symbole_entree) != 'q') {

etat_suivant = A->transitions[etat_courant][symbole_entree];

ecrire_sortie(A->sortie[etat_courant][symbole_entree]);

etat_courant = etat_suivant;

}

}

[e] Sans cette instruction, la sortie serait "entree_invalide"

[f]

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

[g] Taille d'un automate : (taille int)*2 + (taille int)*NB_MAX_ETATS + (taille int)

*NB_MAX_ETATS*NB_MAX_ENTREES +

(taille char)*LG_MAX_SORTIES*NB_MAX_ETATS*NB_MAX_ENTREES

= 4*2 + 4*128 + 4*128*128 + 1*128*128*128 = 2163208 octets

[i] L'etat final de cet automate est l'etat 2
