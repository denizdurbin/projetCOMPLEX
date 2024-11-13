int main(){
    arbre_t* arbre = initarbre(creernoeud("H", 1));
    noeud_t* D = creernoeud("D", 2);
    getracine(arbre)->filsgauche = D;
    printnoeud(getfilsgauche(arbre));
    freearbre(arbre);
}