#include "arbrecartesien.h"
#include <stdio.h>


int main(){

    noeud_t* H = creernoeud("H", 1);
    arbre_t* arbre = initarbre(H);
    noeud_t* D = creernoeud("D", 2);
    noeud_t* I = creernoeud("I", 10);
    noeud_t* B = creernoeud("B", 3);
    noeud_t* E = creernoeud("E", 6);
    noeud_t* J = creernoeud("J", 12);
    noeud_t* A = creernoeud("A", 5);
    noeud_t* C = creernoeud("C", 8);
    noeud_t* F = creernoeud("F", 7);
    noeud_t* G = creernoeud("G", 9);

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
    printinfixe(arbre);
    printpostfixe(arbre);
    printprefixe(arbre);

    //Test de la recherche
    /*
    printf("Recherche de la cle F : \n");
    noeud_t* res = recherchearbre(arbre, 'F');
    if(res != NULL){
        printnoeud(res);
    }
    else{
        printf("Cle non trouvee.\n");
    }

    printf("Recherche de la cle I : \n");
    noeud_t* res2 = recherchearbre(arbre, 'I');
    if(res2 != NULL){
        printnoeud(res2);
    }
    else{
        printf("Cle non trouvee.\n");
    }
    printf("Recherche de la cle Z : \n");
    noeud_t* res3 = recherchearbre(arbre, 'Z');
    if(res3 != NULL){
        printnoeud(res3);
    }
    else{
        printf("Cle non trouvee.\n");
    }
    */  
    freearbre(arbre);


    return 0;
}