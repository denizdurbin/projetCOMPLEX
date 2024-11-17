#include <stdio.h>
#include "arbrecartesien.h"

int main(){
    noeud_t* A = creernoeud("A", 5);
    noeud_t* B = creernoeud("B", 3);
    noeud_t* C = creernoeud("C", 8);
    noeud_t* D = creernoeud("D", 2);
    noeud_t* E = creernoeud("E", 6);
    noeud_t* F = creernoeud("F", 7);
    noeud_t* G = creernoeud("G", 9);
    noeud_t* H = creernoeud("H", 1);
    noeud_t* I = creernoeud("I", 10);
    noeud_t* J = creernoeud("J", 12);
    arbre_t* arbre = initarbre(E);
    insertionarbre(arbre, H);
    insertionarbre(arbre, B);
    insertionarbre(arbre, D);
    insertionarbre(arbre, C);
    insertionarbre(arbre, F);
    insertionarbre(arbre, G);
    insertionarbre(arbre, J);
    insertionarbre(arbre, A);
    insertionarbre(arbre, I);

    suppressionarbre(arbre, 'A');
    suppressionarbre(arbre, 'B');
    suppressionarbre(arbre, 'H');
    printparniveau(arbre, 0);

    freearbre(arbre);
    return 0;
}