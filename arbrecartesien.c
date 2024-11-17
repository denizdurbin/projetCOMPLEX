#include "arbrecartesien.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

noeud_t* creernoeud(char* cle, int priorite){
    noeud_t* res = (noeud_t*)malloc(sizeof(noeud_t));
    if(res == NULL){
        printf("Erreur: creernoeud(), erreur d'allocation de memoire.\n");
        exit(1);
    }
    res->cle = cle;
    res->priorite = priorite;
    res->filsgauche = NULL;
    res->filsdroit = NULL;
    return res;
}

void freenoeud(noeud_t* noeud) { free(noeud); }

void printnoeud(noeud_t* noeud){
    printf("Noeud %s : %d \n", noeud->cle, noeud->priorite);
}


arbre_t* creerarbre(){
    arbre_t* new = (arbre_t*)malloc(sizeof(arbre_t));
    if(new == NULL){
        printf("Erreur: creerarbre(), erreur d'allocation de memoire. \n");
        exit(1);
    }

    *new = NULL;
    return new;
}

arbre_t* initarbre(noeud_t* noeud){
    arbre_t* arbre = creerarbre();
    *arbre = noeud;
    return arbre;
}

int estvidearbre(arbre_t* arbre){
    if(arbre == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

noeud_t* getracine (arbre_t* arbre){
    return *arbre;
}

noeud_t* getfilsdroit(arbre_t* arbre){
    if(estvidearbre(arbre)){
        printf("Arbre vide");
        return NULL;
    }
    else{
        noeud_t* noeud = getracine(arbre);
        if(noeud->filsdroit != NULL){
            return noeud->filsdroit;
        }
        else{
            printf("Arbre ne contient pas de fils droit");
            return NULL;
        }
    }
}
noeud_t* getfilsgauche(arbre_t* arbre){
        if(estvidearbre(arbre)){
        printf("Arbre vide");
        return NULL;
    }
    else{
        noeud_t* noeud = getracine(arbre);
        if(noeud->filsgauche != NULL){
            return noeud->filsgauche;
        }
        else{
            printf("Arbre ne contient pas de fils gauche");
            return NULL;
        }
    }
}


void printinfixe(arbre_t* arbre){
    
    if(estvidearbre(arbre)){
        return;  
    }
    noeud_t* noeud = getracine(arbre);
    printf("[ ");
    noeudinfixe(noeud);
    printf("]\n");
}
void noeudinfixe(noeud_t* noeud){
    if(noeud->filsgauche != NULL){
        noeudinfixe(noeud->filsgauche);
    }
    printf("(%s, %d) ", noeud->cle, noeud->priorite);
    if(noeud->filsdroit != NULL){
        noeudinfixe(noeud->filsdroit);
    }
}

void printpostfixe(arbre_t* arbre){
    
    if(estvidearbre(arbre)){
        return;  
    }
    noeud_t* noeud = getracine(arbre);
    printf("[ ");
    noeudpostfixe(noeud);
    printf("]\n");
}
void noeudpostfixe(noeud_t* noeud){
    if(noeud->filsgauche != NULL){
        noeudpostfixe(noeud->filsgauche);
    }
    if(noeud->filsdroit != NULL){
        noeudpostfixe(noeud->filsdroit);
    }

    printf("(%s, %d) ", noeud->cle, noeud->priorite);
 
}

void printprefixe(arbre_t* arbre){
    
    if(estvidearbre(arbre)){
        return;  
    }
    noeud_t* noeud = getracine(arbre);
    printf("[ ");
    noeudprefixe(noeud);
    printf("]\n");
}
void noeudprefixe(noeud_t* noeud){
    printf("(%s, %d) ", noeud->cle, noeud->priorite);
    if(noeud->filsgauche != NULL){
        noeudprefixe(noeud->filsgauche);
    }

    if(noeud->filsdroit != NULL){
        noeudprefixe(noeud->filsdroit);
    }
}

void printparniveau(arbre_t* arbre, int niveau){
    if(estvidearbre(arbre)){
        return;
    }
    noeud_t* noeud = getracine(arbre);
    printf("Niveau %d : \n", niveau);
    printnoeud(noeud);
    if(noeud->filsgauche != NULL){
        printparniveau(&(noeud->filsgauche), niveau+1);
    }
    if(noeud->filsdroit != NULL){
        printparniveau(&(noeud->filsdroit), niveau+1);
    }
}

void freearbre(arbre_t* arbre) {
    if (*arbre == NULL) {
        return;
    }
    noeud_t* noeud = getracine(arbre);
    if (noeud->filsgauche != NULL) {
        freearbre(&(noeud->filsgauche));
    }
    
    if (noeud->filsdroit != NULL) {
        freearbre(&(noeud->filsdroit));
    }

    freenoeud(*arbre);
    *arbre = NULL;
}

noeud_t* recherchearbre(arbre_t* arbre, char cle){
    if(estvidearbre(arbre)){
        return NULL;
    }
    noeud_t* noeud = getracine(arbre);
    if(noeud->cle[0] == cle){
        return noeud;
    }
    else if(noeud->cle[0] < cle){
        if(noeud->filsdroit == NULL){
            return NULL;
        }
        return recherchearbre(&(noeud->filsdroit), cle);
    }
    else{
        if(noeud->filsgauche == NULL){
            return NULL;
        }
        return recherchearbre(&(noeud->filsgauche), cle);
    }
}

noeud_t* rotationgauche(noeud_t* noeud){
    noeud_t* temp = noeud->filsdroit;
    noeud->filsdroit = temp->filsgauche;
    temp->filsgauche = noeud;
    return temp;
}

noeud_t* rotationdroite(noeud_t* noeud){
    noeud_t* temp = noeud->filsgauche;
    noeud->filsgauche = temp->filsdroit;
    temp->filsdroit = noeud;
    return temp;
}

void insertionarbre(arbre_t* arbre, noeud_t* noeud) {
    if (estvidearbre(arbre)) {
        *arbre = noeud;
        return;
    }

    noeud_t* racine = getracine(arbre);
    if (noeud->cle[0] < racine->cle[0]) {
        if (racine->filsgauche == NULL) {
            racine->filsgauche = noeud;
        } else {
            insertionarbre(&(racine->filsgauche), noeud);
        }
        if (racine->filsgauche->priorite < racine->priorite) {
            *arbre = rotationdroite(racine);
        }
    } else {
        if (racine->filsdroit == NULL) {
            racine->filsdroit = noeud;
        } else {
            insertionarbre(&(racine->filsdroit), noeud);
        }
        if (racine->filsdroit->priorite < racine->priorite) {
            *arbre = rotationgauche(racine);
        }
    }
}

void suppressionarbre(arbre_t* arbre, char cle){
    if(estvidearbre(arbre)){
        return;
    }
    noeud_t* racine = getracine(arbre);
    if(racine->cle[0] == cle){
        if(racine->filsgauche == NULL && racine->filsdroit == NULL){
            freenoeud(racine);
            *arbre = NULL;
        }
        else if(racine->filsgauche == NULL){
            noeud_t* temp = racine->filsdroit;
            freenoeud(racine);
            *arbre = temp;
        }
        else if(racine->filsdroit == NULL){
            noeud_t* temp = racine->filsgauche;
            freenoeud(racine);
            *arbre = temp;
        }
        else{
            if(racine->filsgauche->priorite < racine->filsdroit->priorite){
                *arbre = rotationdroite(racine);
                suppressionarbre(&((*arbre)->filsdroit), cle);
            }
            else{
                *arbre = rotationgauche(racine);
                suppressionarbre(&((*arbre)->filsgauche), cle);
            }
        }
    }
    else if(racine->cle[0] < cle){
        suppressionarbre(&(racine->filsdroit), cle);
    }
    else{
        suppressionarbre(&(racine->filsgauche), cle);
    }
}