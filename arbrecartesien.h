#ifndef ARBRECARTESIEN_H
#define ARBRECARTESIEN_H

//STRUCTS
typedef struct _noeudCartesien {
        char* etiquette;
        int cle;
        struct _noeudCartesien* filsgauche;
        struct _noeudCartesien* filsdroit;
} noeud_t;

typedef noeud_t* arbre_t;


//FONCTIONS SUR LES NOEUDS
noeud_t* creernoeud(char* etiquette, int cle);
void freenoeud(noeud_t* noeud);
void printnoeud(noeud_t* noeud);
void noeudinfixe(noeud_t* noeud);
void noeudpostfixe(noeud_t* noeud);
void noeudprefixe(noeud_t* noeud);


//FONCTIONS SUR LES ARBRES
arbre_t* creerarbre();
int estvidearbre(arbre_t* arbre);
noeud_t* getfilsdroit(arbre_t* arbre);
noeud_t* getfilsgauche(arbre_t* arbre);
void freearbre(arbre_t* arbre);
arbre_t* initarbre(noeud_t* noeud);
noeud_t* getracine (arbre_t* arbre);
void printinfixe(arbre_t* arbre);
void printpostfixe(arbre_t* arbre);
void printprefixe(arbre_t* arbre);

#endif