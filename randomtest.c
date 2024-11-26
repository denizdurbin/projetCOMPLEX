#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbrecartesien.h"

int height(noeud_t* node) {
    if (node == NULL) return 0;
    int left_height = height(node->filsgauche);
    int right_height = height(node->filsdroit);
    return 1 + (left_height > right_height ? left_height : right_height);
}

/**
 *Insertion d'un noeud dans un arbre
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

// Fisher-Yates shuffle to randomize the keys
void shuffle_keys(char* keys, int num_keys) {
    for (int i = num_keys - 1; i > 0; i--) {
        int j = rand() % (i + 1);  // Random index from 0 to i
        char temp = keys[i];
        keys[i] = keys[j];
        keys[j] = temp;
    }
}
void test_cartesien(int num_insertions, int iterations) {
    srand(time(NULL));
    int overall_max_height = 0;
    int total_height = 0;
    int total_batches = 0;

    for (int iter = 0; iter < iterations; iter++) {
        for (int batch = 0; batch < num_insertions; batch++) {
            // Initialize the array of keys
            char keys[95];
            for (char c = '!'; c <= '~'; c++) {
                keys[c - '!'] = c;
            }

            // Shuffle all 95 keys to randomize the order
            shuffle_keys(keys, 95);

            // The first key is chosen from the shuffled keys
            char cle1[1] = {keys[0]};  // Take the first shuffled key
            double priorite_initiale = (double)rand() / RAND_MAX; 
            noeud_t* noeud = creernoeud(cle1, priorite_initiale);
            arbre_t* arbre = initarbre(noeud);

            // Insert the rest of the keys in the shuffled order
            for (int i = 1; i < 95; i++) {  // Start from 1 since cle1 is already inserted
                double priorite = (double)rand() / RAND_MAX; 
                char cle[1] = {keys[i]}; 
                noeud_t* noeud = creernoeud(cle, priorite);
                insertionarbre(arbre, noeud);
            }

            // Calculate the height of the tree
            int h = height(getracine(arbre));
            total_height += h;
            if (h > overall_max_height) {
                overall_max_height = h;
            }

            freearbre(arbre, 1);
            total_batches++;
        }
    }

    double avg_height = total_height / (double)total_batches;

    printf("Overall Max Height: %d\n", overall_max_height);
    printf("Overall Average Height: %.2f\n", avg_height);
}


void test_ABR(int num_insertions, int iterations) {
    srand(time(NULL));
    int overall_max_height = 0;
    int total_height = 0;
    int total_batches = 0;

    for (int iter = 0; iter < iterations; iter++) {
        for (int batch = 0; batch < num_insertions; batch++) {
            // Initialize the array of keys
            char keys[95];
            for (char c = '!'; c <= '~'; c++) {
                keys[c - '!'] = c;
            }

            // Shuffle all 95 keys to randomize the order
            shuffle_keys(keys, 95);

            // The first key is chosen from the shuffled keys
            char cle1[1] = {keys[0]};  // Take the first shuffled key
            noeud_t* noeud = creernoeud(cle1, 0);
            arbre_t* arbre = initarbre(noeud);

        
            for (int i = 1; i < 95; i++) {  
                char cle[1] = {keys[i]}; 
                noeud_t* noeud = creernoeud(cle, 0);
                insertionABR(arbre, noeud);
            }

            // Calculate the height of the tree
            int h = height(getracine(arbre));
            total_height += h;
            if (h > overall_max_height) {
                overall_max_height = h;
            }

            freearbre(arbre, 1);
            total_batches++;
        }
    }

    double avg_height = total_height / (double)total_batches;

    printf("Overall Max Height: %d\n", overall_max_height);
    printf("Overall Average Height: %.2f\n", avg_height);
}


int main() {
    printf("\n--- Batch 1, 10 Cles, 10000 Iterations ---\n");
    printf("Cartesien:\n");
    test_cartesien(10, 10000);
    printf("ABR:\n");
    test_ABR(10, 10000);

    printf("\n--- Batch 2, 50 Cles, 10000 Iterations ---\n");
    printf("Cartesien:\n");
    test_cartesien(50, 10000);
    printf("ABR:\n");
    test_ABR(50, 10000);

    printf("\n--- Batch 3, 95 Cles, 10000 Iterations ---\n");
    printf("Cartesien:\n");
    test_cartesien(95, 10000);
    printf("ABR:\n");
    test_ABR(95, 10000);

    return 0;
}