#include "arbrecartesien.h"
#include <stdio.h>

int main(){
   
   /*
    noeud_t* new = creernoeud("A", 5);
    printnoeud(new);
    arbre_t* arbre = initArbre(new);
    freearbre(arbre);
    */
    arbre_t* arbre = initarbre(creernoeud("H", 1));
    noeud_t* D = creernoeud("D", 2);
    noeud_t* I = creernoeud("I", 10);
    noeud_t* B = creernoeud("B", 3);
    noeud_t* E = creernoeud("E", 6);
    noeud_t* J = creernoeud("J", 12);
    noeud_t* A = creernoeud("A", 5);
    noeud_t* C = creernoeud("C", 8);
    noeud_t* F = creernoeud("F", 7);
    noeud_t* G = creernoeud("G", 9);

    noeud_t* H = getracine(arbre);
    H->filsgauche = D;
    H->filsdroit = I;
    D->filsgauche = B;
    D->filsdroit = E;
    I->filsdroit = J;
    B->filsgauche = A;
    B->filsdroit = C;
    E->filsdroit = F;
    F->filsdroit = G;
    printnoeud(getfilsgauche(arbre));
    printnoeud(getfilsdroit(arbre));
    printf("%s \n", E->filsdroit->etiquette);
    printf("%s \n", I->filsdroit->etiquette);
    freearbre(arbre);
    
}