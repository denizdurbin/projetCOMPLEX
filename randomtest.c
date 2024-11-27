#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbrecartesien.h"


/**
 *Calcul de la hauteur d'un noeud
 *@param node : Le noeud dont on veut calculer la hauteur
 *@return La hauteur du noeud
 */
int height(noeud_t* node) {
    if (node == NULL){
        return 0;
        }
    int left_height = height(node->filsgauche);
    int right_height = height(node->filsdroit);
    return 1 + (left_height > right_height ? left_height : right_height);
}

/*
 *Parcourt un arbre et compte le nombre de noeuds ayant un seul fils
 *@param node : Le noeud a partir duquel on veut commencer le parcourt
 *@return Le nombre de noeuds ayant un seul fils 
 */

int nbfilsunique(noeud_t* node) {
    if (node == NULL) {
        return 0;
    }
    int left_filsunique = nbfilsunique(node->filsgauche);
    int right_filsunique = nbfilsunique(node->filsdroit);
  
    if ((node->filsgauche != NULL && node->filsdroit == NULL) || 
        (node->filsgauche == NULL && node->filsdroit != NULL)) {
        return 1 + left_filsunique + right_filsunique;
    }
    
    return left_filsunique + right_filsunique;
}
/**
 *Insertion d'un noeud dans un arbre binaire de recherce
 *@param arbre : L'arbre dans lequel on veut inserer
 *@param noeud : Le noeud a inserer
 */
void insertionABR(arbre_t* arbre, noeud_t* noeud) {
    if (estvidearbre(arbre)) {
        *arbre = noeud;
        return;
    }

    noeud_t* racine = getracine(arbre);
    if (noeud->cle[0] < racine->cle[0]) {
        if (racine->filsgauche == NULL) {
            racine->filsgauche = noeud;
        } else {
            insertionABR(getfilsgauchearbre(arbre), noeud);
        }
    } else {
        if (racine->filsdroit == NULL) {
            racine->filsdroit = noeud;
        } else {
            insertionABR(getfilsdroitarbre(arbre), noeud);
        }
    
    }
}

/**
 *Test de profondeur max et moyen d'un arbre cartesien
 *@param num_insertions : Nombre d'insertions a effectuer
 *@param iterations : Nombre d'iterations
 */
void test_cartesien(int num_insertions, int iterations) {
    srand(time(NULL));
    int overall_max_height = 0;
    int total_height = 0;
    int total_fils_unique = 0;
    //compteurs pour nos metriques (profondeur max, profondeur moyenne, nombre de noeuds avec un seul fils)
    for (int iter = 0; iter < iterations; iter++) {
        
        char cle1[1] = {'!'};
        double priorite_initiale = (double)rand() / RAND_MAX;
        noeud_t* noeud = creernoeud(cle1, priorite_initiale);
        arbre_t* arbre = initarbre(noeud);

        //L'arbre le plus grand possible avec les char ASCII imprimables
        int count = 1; 
        for (char c = '!'; c <= '~' && count < num_insertions; c++, count++) {
            double priorite = (double)rand() / RAND_MAX;
            char cle[1] = {c};
            noeud_t* noeud = creernoeud(cle, priorite);
            insertionarbre(arbre, noeud);
        }

        
        int h = height(getracine(arbre));
        total_height += h;
        total_fils_unique += nbfilsunique(getracine(arbre));
        if (h > overall_max_height) {
            overall_max_height = h;
        }

        
        freearbre(arbre, 1);
    }

    double avg_height = total_height / (double)iterations;
    double avg_fils_unique = total_fils_unique / (double)iterations;

    printf("Overall Max Height: %d\n", overall_max_height);
    printf("Overall Average Height: %.2f\n", avg_height);
    printf("Overall Average Number of Nodes with One Child: %.2f\n", avg_fils_unique);
}

/**
 *Test de profondeur max et moyen d'un arbre binaire de recherche
 *@param num_insertions : Nombre d'insertions a effectuer
 *@param iterations : Nombre d'iterations
 */
void test_ABR(int num_insertions, int iterations) {
    srand(time(NULL));
    int overall_max_height = 0;
    int total_height = 0;
    int total_fils_unique = 0;

    for (int iter = 0; iter < iterations; iter++) {
        
        char cle1[1] = {'!'};
        double priorite_initiale = (double)rand() / RAND_MAX;
        noeud_t* noeud = creernoeud(cle1, priorite_initiale);
        arbre_t* arbre = initarbre(noeud);

        
        int count = 1; 
        for (char c = '!'; c <= '~' && count < num_insertions; c++, count++) {
            double priorite = (double)rand() / RAND_MAX;
            char cle[1] = {c};
            noeud_t* noeud = creernoeud(cle, priorite);
            insertionABR(arbre, noeud);
        }

        
        int h = height(getracine(arbre));
     
        total_height += h;
        total_fils_unique += nbfilsunique(getracine(arbre));
        if (h > overall_max_height) {
            overall_max_height = h;
        }

        freearbre(arbre, 1);
    }

    double avg_height = total_height / (double)iterations;
    double avg_fils_unique = total_fils_unique / (double)iterations;

    printf("Overall Max Height: %d\n", overall_max_height);
    printf("Overall Average Height: %.2f\n", avg_height);
    printf("Overall Average Number of Nodes with One Child: %.2f\n", avg_fils_unique);
}


int main() {
    printf("\n--- Batch 1, 10 Cles, 10000 Iterations ---\n");
    printf("Cartesien:\n");
    test_cartesien(10, 10000);
    printf("ABR:\n");
    test_ABR(10, 1);

    printf("\n--- Batch 2, 50 Cles, 10000 Iterations ---\n");
    printf("Cartesien:\n");
    test_cartesien(50, 10000);
    printf("ABR:\n");
    test_ABR(50, 1);

    printf("\n--- Batch 3, 95 Cles, 10000 Iterations ---\n");
    printf("Cartesien:\n");
    test_cartesien(95, 10000);
    printf("ABR:\n");
    test_ABR(95, 1);

    return 0;
}