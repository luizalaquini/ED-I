#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Lista.h"

#define TAM 4

struct fila{
    Lista* lista;
    int n; //numero de alunos presentes na fila
};

Fila* IniciaFila(void){
    Fila* f = (Fila*) malloc (sizeof(Fila));
    f->lista = IniciaLista();
    f->n = 0;
    return f;
}

void InsereFila (Fila* f, Aluno* a){
    //testa se fila existe e se possui espaço
    if(!f || f->n == TAM){
        printf("(InsereFila): Fila não existe ou está cheia!\n");
        return;
    }
    InsereListaUlt(f->lista, a); //insere aluno
    f->n++; //atualiza numero de alunos
}

Aluno* RetiraFila (Fila* f){
    //testa se a fila existe e se contem pelo menos 1 aluno
    if(!f || f->n == 0){
        printf("(RetiraFila): Fila não existe ou está vazia!\n");
        return NULL;
    }
    f->n--; //atualiza numero de alunos
    return RetiraLista(f->lista, 1); //retira aluno
}

void ImprimeFila (Fila* f){
    if(!f || f->n == 0){
        printf("(ImprimeFila): Fila não existe ou está vazia!\n");
        return;
    }
    ImprimeLista(f->lista);
}

void DestroiFila (Fila* f){
    DestroiLista(f->lista);
    free(f);
}