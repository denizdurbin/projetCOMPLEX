#include "arbrecartesien.h"
#include <stdio.h>

int main(){
    
    arbre_t* arbre=initarbre(creernoeud("C", 1));
    noeud_t* B=creernoeud("B", 2);
    noeud_t* A=creernoeud("A", 3);
    noeud_t* C=getracine(arbre);
    printnoeud(getracine(arbre));
    insertionarbre(arbre, A);
    printnoeud(getracine(arbre));
    printinfixe(arbre);
    insertionarbre(arbre, B);
    printinfixe(arbre);
    printnoeud(C->filsgauche);
    printparniveau(arbre, 0);
    freearbre(arbre);   

    return 0;
}