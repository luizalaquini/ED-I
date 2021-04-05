#include <stdlib.h>
#include <string.h>
#include "palavra.h"

struct palavra {
    char* string;
    int n; //numero de ocorrências
    Palavra* prox;
};

Palavra* inicPalavra(char* str) {
    Palavra* pal = (Palavra*) malloc(sizeof(Palavra));
    pal->string = strdup(str);
    pal->n = 0;
    pal->prox = NULL;

    return pal;
}

char* retornaString(Palavra* pal) {
    return pal->string;
}

void atualizaOcorrencias(Palavra* pal) {
    pal->n++;
}

int retornaOcorrencias(Palavra* pal){
    return pal->n;
}

Palavra* buscaPalavra(Palavra* pal, char* string){
    Palavra* p;
    //busca a palavra na Lista de Colisão
    for (p = pal; p != NULL; p = p->prox) {
        if (strcmp(string, p->string) == 0)
            return p;
    }

    return NULL;
}

Palavra* inserePalavralista(Palavra* lista, Palavra* p) {
    p->prox = lista;
    return p;
}

int contaPalavraslista(Palavra* p) {
    Palavra* pal;
    int i = 0;

    for (pal = p; pal != NULL; pal = pal->prox){
        i++;
    }

    return i;
}

void imprimelista(Palavra* p){
    Palavra* aux;

    for (aux = p; aux != NULL; aux = aux->prox){
        printf("String: %s - Ocorrencias: %d \n", aux->string, aux->n);
    }
}

void liberalistaPalavra(Palavra* pal){
    Palavra* aux = pal;
    Palavra* t;

    while (aux != NULL){
        t = aux->prox;

        free(aux->string);
        free(aux);

        aux = t;
    }
}