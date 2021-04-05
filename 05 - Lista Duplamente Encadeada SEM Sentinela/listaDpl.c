#include <stdio.h>
#include <stdlib.h>
#include "listaDpl.h"

struct lista {
    Matriz* mat;
    Lista* prox;
    Lista* ant;
};

Lista* IniciaLista(void){
    return NULL;
}

Lista* InsereLista (Lista* lista, Matriz* mat){
    Lista* nova = (Lista*) malloc(sizeof(Lista));
    
    nova->mat = mat;
    nova->ant = NULL;
    nova->prox = lista;
    if(lista != NULL){
        lista->ant = nova;
    }

    return nova;
}

Lista* RetiraLista (Lista* lista, int chave){
    Lista* p;
    int cont = 1;

    p = lista;

    //faz a busca
    while (p!=NULL && cont!=chave){
        p = p->prox;
        cont++;
    }

    //FIM DA BUSCA; CASOS:

    //1- Lista vazia ou matriz não encontrada, retorna lista sem alterações
    if(p==NULL){
        return lista;
    }

    //2- Encontrou matriz
    if (lista == p) /* testa se é o primeiro elemento */
        lista = p->prox;
    else
        p->ant->prox = p->prox;
    if (p->prox != NULL) /* testa se é o último elemento */
        p->prox->ant = p->ant;
    
    free(p);
    
    return lista;
}

void ImprimeLista (Lista* lista){
    Lista* p;

    for (p = lista; p!=NULL; p = p->prox){
        imprimeMatriz(p->mat);
    }
}

void DestroiLista (Lista* lista){
    Lista* p = lista;
    Lista* t;

    while(p!=NULL){
        t = p->prox;
        free(p);
        p = t;
    }
}