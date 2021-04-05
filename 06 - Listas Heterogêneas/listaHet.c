#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaHet.h"

#define PROF 0
#define ALUNO 1

typedef struct celula Celula;

struct celula{
    Celula* prox;
    void* item;
    int tipo;
};

//sentinela
struct listaHet {
    Celula* prim;
    Celula* ult;
};

ListaHet* iniciaLista (void){
    ListaHet* lista = (ListaHet*) malloc (sizeof(ListaHet));
    lista->prim = NULL;
    lista->ult = NULL;
    
    return lista;
}

void insereAluno (ListaHet* lista, Aluno* aluno){
    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->item = aluno;
    nova->tipo = ALUNO;
    //encadeamento:
    nova->prox = lista->prim;
    lista->prim = nova;
    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void insereProfessor (ListaHet* lista, Professor* prof){
    Celula* nova = (Celula*) malloc (sizeof(Celula));
    nova->item = prof;
    nova->tipo = PROF;
    //encadeamento:
    nova->prox = lista->prim;
    lista->prim = nova;
    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void imprimeListaHet (ListaHet* lista){
    Celula* p;

    for (p = lista->prim; p != NULL; p = p->prox){
        if(p->tipo == ALUNO){
            printf("ALUNO: ");
            imprimeAluno((Aluno*)p->item);
        }
        if(p->tipo == PROF){
            printf("PROFESSOR: ");
            imprimeProfessor((Professor*)p->item);
        }
    }
}

//Valor do Churrasco!
//Professor contribui com 2% do salario
//Aluno contribui com taxa fixa de R$30,00
float valorChurrasco (ListaHet* lista){
    Celula* p;
    float valor = 0.0;

    for (p = lista->prim; p != NULL; p = p->prox){
        if(p->tipo == ALUNO){
            valor += 30.0;
        }
        if(p->tipo == PROF){
            valor += 0.02*retornaSalario((Professor*)p->item);
        }
    }

    return valor;
}

void destroiListaHet (ListaHet* lista){
    Celula* p = lista->prim;
    Celula* t;

    while(p != NULL){
        t = p->prox;
        free (p);
        p = t;
    }
    free(lista);
}