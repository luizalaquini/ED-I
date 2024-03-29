#include <stdlib.h>
#include <string.h>
#include "hash.h"

struct hash {
    Palavra **vet;
    int tamanho;
};

//Função de Hash (função local)
static int hash(char* s, int tamanho){
    int total = 0;

    for (int i = 0; s[i] != '\0'; i++){
        total += s[i];
    }

    return (total % tamanho);
}

Hash* inicHash(int tamanho){

    Hash* h = (Hash*) malloc(sizeof(Hash));
    h->tamanho = tamanho;
    h->vet = (Palavra**) malloc(tamanho*sizeof(Palavra*));
    //preenchendo a tabela com NULL (importante!)
    for (int i = 0; i < tamanho; i++){
        h->vet[i] = NULL;
    }

    return h;
}

Palavra* acessa(Hash* h, char* string){
    Palavra* p;
    //aplica hash
    int indice = hash(string, h->tamanho);
    p = buscaPalavra(h->vet[indice], string);

    if (p) //atualiza ocorrência caso encontre
        return p;

    //inicia e insere caso não tenha sido encontrada
    p = inicPalavra(string); 
    h->vet[indice] = inserePalavralista(h->vet[indice], p);

    return p;
}

void imprimeHash(Hash* h){

    for (int i = 0; i < h->tamanho; i++){
        printf("\nPosição vet[%d]:\n", i);
        imprimelista(h->vet[i]);
    }
}

void liberaHash(Hash* h){

    for (int i = 0; i < h->tamanho; i++){
        liberalistaPalavra(h->vet[i]);
    }
    free(h->vet);
    free(h);
}