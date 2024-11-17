#ifndef ARBRECARTESIEN_H
#define ARBRECARTESIEN_H

//STRUCTS
typedef struct _noeudCartesien {
        char* cle;
        int priorite;
        struct _noeudCartesien* filsgauche;
        struct _noeudCartesien* filsdroit;
} noeud_t;

typedef noeud_t* arbre_t;


//FONCTIONS SUR LES NOEUDS
noeud_t* creernoeud(char* cle, int priorite);
void freenoeud(noeud_t* noeud);
void printnoeud(noeud_t* noeud);
void noeudinfixe(noeud_t* noeud);
void noeudpostfixe(noeud_t* noeud);
void noeudprefixe(noeud_t* noeud);
noeud_t* rotationgauche(noeud_t* noeud);
noeud_t* rotationdroite(noeud_t* noeud);

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
void printparniveau(arbre_t* arbre, int niveau);
noeud_t* recherchearbre(arbre_t* arbre, char cle);
void insertionarbre(arbre_t* arbre, noeud_t* noeud);
void suppressionarbre(arbre_t* arbre, char cle);

#endif