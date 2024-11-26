#include "arbrecartesien.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 *Creation d'un noeud
 *@param cle : La cle du noeud a creer, exemple : "A"
 *@param priorite : La priorite du noeud a creer, exemple : 1
 *@return res : Le noeud cree
 */
noeud_t* creernoeud(char* cle, int priorite){
    noeud_t* res = (noeud_t*)malloc(sizeof(noeud_t));
    if(res == NULL){
        printf("Erreur: creernoeud(), erreur d'allocation de memoire.\n");
        exit(1);
    }
    res->cle = strdup(cle);
    if (res->cle == NULL) {
        printf("Erreur: creernoeud(), erreur d'allocation de memoire pour cle.\n"); 
        free(res);
        exit(1);
    }
    res->priorite = priorite;
    res->filsgauche = NULL;
    res->filsdroit = NULL;
    return res;
}


/**
 *Libere la memoire allouee pour un noeud
 *@param noeud : Le noeud a liberer
 */
void freenoeud(noeud_t* noeud) {
    if(noeud != NULL) {
        free(noeud->cle);
        free(noeud);
    }
}

/**
 *Affiche les informations d'un noeud
 *@param noeud : Le noeud a afficher
 */
void printnoeud(noeud_t* noeud){
    printf("Noeud %s : %d \n", noeud->cle, noeud->priorite);
}

/**
 *Initialise un arbre avec un noeud racine
 *@param noeud : Le noeud racine de l'arbre
 *@return arbre : L'arbre cree
 */
arbre_t* initarbre(noeud_t* noeud){
    arbre_t* arbre = (arbre_t*)malloc(sizeof(arbre_t));
    if(arbre == NULL){
        printf("Erreur: creerarbre(), erreur d'allocation de memoire. \n");
        exit(1);
    }
    *arbre = noeud;
    return arbre;
}

/**
 *Verifie si un arbre est vide
 *@param arbre : L'arbre a verifier
 *@return 1 si l'arbre est vide, 0 sinon
 */
int estvidearbre(arbre_t* arbre){
    if(arbre == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

/**
 *Recupere la racine d'un arbre
 *@param arbre : L'arbre dont on veut recuperer la racine
 *@return res : La racine de l'arbre
 */
noeud_t* getracine (arbre_t* arbre){
    return *arbre;
}

/**
 *Recupere sous arbre gauche d'un arbre
 *@param arbre : L'arbre dont on veut recuperer le sous arbre gauche
 *@return res : Le sous arbre gauche de l'arbre 
 */
arbre_t* getfilsgauchearbre(arbre_t* arbre) {
    return estvidearbre(arbre) ? NULL : &(getracine(arbre)->filsgauche);
}

/**
 *Recupere sous arbre droit d'un arbre
 *@param arbre : L'arbre dont on veut recuperer le sous arbre droit
 *@return res : Le sous arbre droit de l'arbre 
 */
arbre_t* getfilsdroitarbre(arbre_t* arbre) {
    return estvidearbre(arbre) ? NULL : &(getracine(arbre)->filsdroit);
}

/**
 *Parcours l'arbre selon un type de parcours
 *@param noeud : Le noeud a parcourir
 *@param type : Le type de parcours a effectuer(PREFIXE, INFIXE, POSTFIXE)
 */
void parcourir(noeud_t* noeud, Parcours type) {
    if (noeud == NULL) {
        return;
    }

    if (type == PREFIXE) {
        printf("(%s, %d) ", noeud->cle, noeud->priorite);
    }

    parcourir(noeud->filsgauche, type);

    if (type == INFIXE) {
        printf("(%s, %d) ", noeud->cle, noeud->priorite);
    }

    parcourir(noeud->filsdroit, type);

    if (type == POSTFIXE) {
        printf("(%s, %d) ", noeud->cle, noeud->priorite);
    }
}

/**
 *Affiche un arbre selon un type de parcours
    *@param arbre : L'arbre a afficher
    *@param type : Le type de parcours a effectuer(PREFIXE, INFIXE, POSTFIXE)
 */
void printparcours(arbre_t* arbre, Parcours type ) {
    if (estvidearbre(arbre)) {
        return;
    }
    printf("[ ");
    parcourir(getracine(arbre), type);
    printf("]\n");
}

/**
 *Affiche un arbre par niveau
 *@param arbre : L'arbre a afficher
 *@param niveau : Le niveau de l'arbre a afficher (0 pour commencer au racine)
 */
void printparniveau(arbre_t* arbre, int niveau){
    if(estvidearbre(arbre)){
        return;
    }
    noeud_t* noeud = getracine(arbre);
    printf("Niveau %d : \n", niveau);
    printnoeud(noeud);
    if(noeud->filsgauche != NULL){
        printparniveau(getfilsgauchearbre(arbre), niveau+1);
    }
    if(noeud->filsdroit != NULL){
        printparniveau(getfilsdroitarbre(arbre), niveau+1);
    }
}


/**
 *Libere la memoire allouee pour un arbre recursivement
 *@param arbre : L'arbre a liberer
 */
void freearbre(arbre_t* arbre, int is_racine) {
    if (estvidearbre(arbre) || arbre == NULL) {
        return;
    }
    noeud_t* noeud = getracine(arbre);
    if (noeud->filsgauche != NULL) {
        freearbre(getfilsgauchearbre(arbre), 0);
    }
    
    if (noeud->filsdroit != NULL) {
        freearbre(getfilsdroitarbre(arbre), 0);
    }
    freenoeud(noeud);
    *arbre = NULL;
    if (is_racine){
        free(arbre);
    }
    }


/**
 *Recherche un noeud dans un arbre
 *@param arbre : L'arbre dans lequel on veut rechercher
 *@param cle : La cle du noeud a rechercher
 *@return res : Le noeud recherche, NULL si non trouve
 */
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
        return recherchearbre(getfilsdroitarbre(arbre), cle);
    }
    else{
        if(noeud->filsgauche == NULL){
            return NULL;
        }
        return recherchearbre(getfilsgauchearbre(arbre), cle);
    }
}

/**
 *Effectue une rotation gauche sur un noeud
 *@param noeud : Le noeud sur lequel on veut effectuer la rotation
 *@return temp : Le noeud apres la rotation
  */
noeud_t* rotationgauche(noeud_t* noeud){
    if (noeud == NULL || noeud->filsdroit == NULL) {
        return noeud;
    }
    noeud_t* temp = noeud->filsdroit;
    noeud->filsdroit = temp->filsgauche;
    temp->filsgauche = noeud;
    return temp;
}

/**
 *Effectue une rotation droite sur un noeud
 *@param noeud : Le noeud sur lequel on veut effectuer la rotation
 *@return temp : Le noeud apres la rotation
  */
noeud_t* rotationdroite(noeud_t* noeud){
    if (noeud == NULL || noeud->filsgauche == NULL) {
        return noeud; 
    }
    noeud_t* temp = noeud->filsgauche;
    noeud->filsgauche = temp->filsdroit;
    temp->filsdroit = noeud;
    return temp;
}


/**
 *Insertion d'un noeud dans un arbre
 *@param arbre : L'arbre dans lequel on veut inserer
 *@param noeud : Le noeud a inserer
 */
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
            insertionarbre(getfilsgauchearbre(arbre), noeud);
        }
        if (racine->filsgauche->priorite < racine->priorite) {
            *arbre = rotationdroite(racine);
        }
    } else {
        if (racine->filsdroit == NULL) {
            racine->filsdroit = noeud;
        } else {
            insertionarbre(getfilsdroitarbre(arbre), noeud);
        }
        if (racine->filsdroit->priorite < racine->priorite) {
            *arbre = rotationgauche(racine);
        }
    }
}


/**
 *Suppression d'un noeud dans un arbre
 *@param arbre : L'arbre dans lequel on veut supprimer
 *@param cle : La cle du noeud a supprimer
 */
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
                suppressionarbre(getfilsdroitarbre(arbre), cle);
            }
            else{
                *arbre = rotationgauche(racine);
                suppressionarbre(getfilsgauchearbre(arbre), cle);
            }
        }
    }
    else if(racine->cle[0] < cle){
        suppressionarbre(getfilsdroitarbre(arbre), cle);
    }
    else{
        suppressionarbre(getfilsgauchearbre(arbre), cle);
    }
}