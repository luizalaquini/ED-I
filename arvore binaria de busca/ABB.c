#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

struct abb {
    int chave; //informação contida na raiz atual
    Abb* esq; //sub-árvore da esquerda
    Abb* dir; //sub-árvore da direita
};

Abb* criaVazia (void){
    return NULL;
}

Abb* insereChave (Abb* a, int chave){
    if (a == NULL){ // Caso primário
        a = (Abb*) malloc (sizeof(Abb));
        a->chave = chave;
        a->esq = a->dir = NULL;
    } 
    else if (chave < a->chave) // Recursividade à esquerda
        a->esq = insereChave(a->esq, chave);
    
    else if (chave > a->chave) // Recursividade à direita
        a->dir = insereChave(a->dir, chave);
    
    return a;
}

Abb* destroi (Abb* a){
    if (a==NULL) // Caso primário
        return NULL;
    destroi(a->esq); // Libera sae por recursividade
    destroi(a->dir); // Libera sad por recursividade
    free(a); //libera raiz
}

int abbVazia (Abb* a){
    if (a==NULL)
        return 1;
    else
        return 0;
}

static int max2 (int a, int b){
    return (a > b) ? a : b;
}

int altura (Abb* a){
    if(abbVazia(a))
        return -1;
    else
        return 1 + max2 (altura(a->esq), altura(a->dir));
}
