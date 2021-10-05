#include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"

struct celula {
    int dado; // Número da pessoa
    Celula *prox; // Ponteiro para a próxima celula da lista
};

Celula* retornaMesima (Celula* p, int M){
    for(int i=0; i<M; i++){
        p = p->prox;
    }
    
    return p;
}

int retornaDado (Celula* cel){
    return cel->dado;
}

struct lista {
    int n; // Número de células
    Celula *prim; // Ponteiro pra primeira célula
    Celula *ult; // Ponteiro pra ultima célula
};

Lista* iniciaLista(void){
    Lista* lista = (Lista*) malloc (sizeof(Lista));
    lista->n = 0;
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereDado (Lista* lista, int dado){
    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->dado = dado;

    // Se a lista circular estiver vazia
    if (lista->n==0){
        lista->prim = nova;
        lista->ult = nova;
        nova->prox = nova;
    }
    // Se a lista circular ja possui elementos
    else {
        lista->ult = nova;
        nova->prox = lista->prim;

        Celula *anterior = lista->prim;

        for(int i=1; i<lista->n; i++)
            anterior = anterior->prox;
        anterior->prox = nova;
    }

    lista->n++; 
}

Celula* removeDado (Lista* lista, Celula* p, int M){
    Celula *atual = lista->prim; //define o ponteiro atual para a primeira celula da lista circular
    Celula *anterior = lista->ult; //define o ponteiro anterior para a ultima celula da lista circular

    //BUSCAR
    for(int i=0; i<M; i++){
        p = p->prox;
    }

    //1- Caso lista vazia
    if (atual==NULL){
        printf("Erro, lista vazia!\n");
        return NULL;
    }

    //2- Caso elemento seja o unico da lista
    else if (atual->prox == atual){
        free(atual);
        lista->prim = NULL;
        lista->ult = NULL;
        lista->n--; // Atualiza numero de elementos na lista
        return NULL;
    }

    //3- Caso lista contenha mais de um elemento
    //3.1- Elemento é o primeiro da lista
    else if (lista->prim->dado == p->dado){
        atual = atual->prox; //caminha com o ponteiro atual para a 2a celula
        anterior = lista->prim; //caminha com o ponteiro anterior para a 1a celula
        lista->prim = atual; //atualiza o ponteiro do primeiro elemento da lista
        free(anterior); //libera a celula
        lista->ult->prox = atual; //atualiza o circulo da lista
        lista->n--; // Atualiza numero de elementos na lista
        return atual;
    }

    //3.2- Elemento é o último
    else if (lista->ult->dado == p->dado){
        atual = p; //caminha com o ponteiro atual para a celula que queremos retirar
        while (p->dado != anterior->prox->dado){ 
            anterior = anterior->prox; //caminha com o ponteiro anterior para a ultima celula antes da que queremos retirar
        }
        anterior->prox = lista->prim; //atualiza o circulo da lista
        free(atual); //libera a celula
        lista->ult = anterior; //atualiza o ponteiro do ultimo elemento da lista
        lista->n--; // Atualiza numero de elementos na lista
        return anterior->prox;
    }

    //3.3- Elemento não é nem o primeiro, nem o último (caso comum)
    else {
        atual = p; //caminha com o ponteiro atual para a celula que queremos retirar
        while (p->dado != anterior->prox->dado){ 
            anterior = anterior->prox; //caminha com o ponteiro anterior para a ultima celula antes da que queremos retirar
        }
        anterior->prox = atual->prox; //atualiza o circulo da lista
        free(atual); //libera a celula
        lista->n--; // Atualiza numero de elementos na lista
        return anterior->prox;
    }
}