#ifndef ARBRECARTESIEN_H
#define ARBRECARTESIEN_H

//STRUCTS
typedef struct _noeudCartesien {
        char* cle;
        double priorite;
        struct _noeudCartesien* filsgauche;
        struct _noeudCartesien* filsdroit;
} noeud_t;

typedef noeud_t* arbre_t;

typedef enum {
        INFIXE,
        PREFIXE,
        POSTFIXE
} Parcours;

//FONCTIONS SUR LES NOEUDS
noeud_t* creernoeud(char* cle, double priorite);
void freenoeud(noeud_t* noeud);
void printnoeud(noeud_t* noeud);
void parcourir(noeud_t* noeud, Parcours enumParcours);
noeud_t* rotationgauche(noeud_t* noeud);
noeud_t* rotationdroite(noeud_t* noeud);

//FONCTIONS SUR LES ARBRES
arbre_t* initarbre(noeud_t* noeud);
int estvidearbre(arbre_t* arbre);
noeud_t* getfilsdroit(arbre_t* arbre);
noeud_t* getfilsgauche(arbre_t* arbre);
void freearbre(arbre_t* arbre, int is_racine);
noeud_t* getracine (arbre_t* arbre);
arbre_t* getfilsgauchearbre(arbre_t* arbre);
arbre_t* getfilsdroitarbre(arbre_t* arbre);
void printparcours(arbre_t* arbre, Parcours enumParcours);
void printparniveau(arbre_t* arbre, int niveau);
noeud_t* recherchearbre(arbre_t* arbre, char cle);
void insertionarbre(arbre_t* arbre, noeud_t* noeud);
void suppressionarbre(arbre_t* arbre, char cle);

#endif