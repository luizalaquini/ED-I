#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaMat.h"

typedef struct celula Celula;

struct celula {
    Matriz* mat;
    Celula* prox;
};

struct lista {
    Celula* prim;
    Celula* ult;
};

Lista* IniciaLista(void){
    Lista* lista = (Lista*) malloc (sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void InsereLista (Lista* lista, Matriz* mat){
    Celula* nova = (Celula*) malloc (sizeof(Celula));

    nova->mat = mat;
    nova->prox = lista->prim;
    lista->prim = nova;
    if(lista->ult==NULL){
        lista->ult = nova;
    }
}

Matriz* RetiraLista (Lista* lista, int chave){
    Celula* p = lista->prim;
    Celula* ant = NULL;
    Matriz* mat;
    int cont = 1;

    //busca
    while(p!=NULL && cont!=chave){
        ant = p;
        p = p->prox;
        cont++;
    }

    //FIM DA BUSCA; CASOS:

    //1- Lista vazia ou matriz não encontrada
    if(p==NULL){
        return NULL;
    }

    //2- Encontrou matriz
    mat = p->mat;

    ////2.1 matriz é única
    if(p==lista->prim && p==lista->ult){
        lista->prim = NULL;
        lista->ult = NULL;
    }
    ////2.2 matriz é a primeira
    else if(p==lista->prim){
        lista->prim = p->prox;
    }
    ////2.3 matriz é a última
    else if(p==lista->ult){
        lista->ult = ant;
        //ant->prox = NULL;
        lista->ult->prox = NULL;
    }
    ////2.4 caso comum 
    else{
        ant->prox = p->prox;
    }

    //libera a celula que foi retirada
    free(p);

    return mat;
}

void ImprimeLista (Lista* lista){ 
    Celula* p;

    for (p = lista->prim; p!=NULL; p = p->prox){
        imprimeMatriz(p->mat);
    }

}

void DestroiLista (Lista* lista){
    Celula* p = lista->prim;
    Celula* t;

    while(p!=NULL){
        t = p->prox;
        free(p);
        p = t;
    }
    free(lista);
}