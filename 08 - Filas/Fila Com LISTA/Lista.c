#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

typedef struct celula Celula;

struct celula {
    Aluno* aluno;
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

void InsereLista (Lista* lista, Aluno* aluno){
    Celula* nova = (Celula*) malloc (sizeof(Celula));

    nova->aluno = aluno;
    nova->prox = lista->prim;
    lista->prim = nova;
    if(lista->ult==NULL){
        lista->ult = nova;
    }
}

void InsereListaUlt (Lista* lista, Aluno* aluno){
    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->aluno = aluno;
    nova->prox = NULL;

    //caso lista vazia
    if(lista->prim == NULL){
        lista->prim = nova;
        lista->ult = nova;
        return;
    }

    lista->ult->prox = nova;
    lista->ult = nova;
}

Aluno* RetiraLista (Lista* lista, int chave){
    Celula* p = lista->prim;
    Celula* ant = NULL;
    Aluno* aluno;
    int cont = 1;

    //busca
    while(p!=NULL && cont!=chave){
        ant = p;
        p = p->prox;
        cont++;
    }

    //FIM DA BUSCA; CASOS:

    //1- Lista vazia ou aluno não encontrado
    if(p==NULL){
        return NULL;
    }

    //2- Encontrou aluno 
    aluno = p->aluno;

    ////2.1 aluno é única
    if(p==lista->prim && p==lista->ult){
        lista->prim = NULL;
        lista->ult = NULL;
    }
    ////2.2 aluno é a primeira
    else if(p==lista->prim){
        lista->prim = p->prox;
    }
    ////2.3 aluno é a última
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

    return aluno;
}

void ImprimeLista (Lista* lista){ 
    Celula* p;

    for (p = lista->prim; p!=NULL; p = p->prox){
        imprimeAluno(p->aluno);
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