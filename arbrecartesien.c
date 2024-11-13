#include "arbrecartesien.h"
#include <stdio.h>
#include <stdlib.h>

noeud_t* creernoeud(char* etiquette, int cle){
    noeud_t* res = (noeud_t*)malloc(sizeof(noeud_t));
    if(res == NULL){
        printf("Erreur: creernoeud(), erreur d'allocation de memoire.\n");
        exit(1);
    }
    res->cle = cle;
    res->etiquette = etiquette;
    res->filsgauche = NULL;
    res->filsdroit = NULL;
    return res;
}

void freenoeud(noeud_t* noeud){
    if(noeud->filsgauche != NULL){
        freenoeud(noeud->filsgauche);
    }
    
    if(noeud->filsdroit != NULL){
        freenoeud(noeud->filsdroit);
    }
    free(noeud);
}

void printnoeud(noeud_t* noeud){
    printf("Noeud %s : %d \n", noeud->etiquette, noeud->cle);
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
    printf("%s ", noeud->etiquette);
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

    printf("%s ", noeud->etiquette);
 
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
    printf("%s ", noeud->etiquette);
    if(noeud->filsgauche != NULL){
        noeudprefixe(noeud->filsgauche);
    }

    if(noeud->filsdroit != NULL){
        noeudprefixe(noeud->filsdroit);
    }
}

void freearbre(arbre_t* arbre){
    noeud_t* noeud = getracine(arbre);
    freenoeud(noeud);
    free(arbre);
}


