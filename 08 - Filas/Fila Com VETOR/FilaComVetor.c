#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

#define TAM 4

struct fila {
    int inicio; //indice do inicio da fila
    int n; //numero de alunos presentes na fila
    Aluno* alunos[TAM]; //vetor de alunos
};

Fila* IniciaFila(void){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = 0;
    f->n = 0;

    return f;
}

void InsereFila (Fila* f, Aluno* a){
    //testa se fila existe e se possui espaço
    if(!f || f->n >= TAM){
        printf("(InsereFila): Fila não existe ou está cheia!\n");
        return;
    }

    //declarando variavel que guarda o fim da fila
    int pos = (f->inicio + f->n)%TAM;
    //insere (sempre no final)
    f->alunos[pos] = a;
    //atualiza numero de alunos
    f->n++;

}

Aluno* RetiraFila (Fila* f){
    //testa se a fila existe e se contem pelo menos 1 aluno
    if(!f || f->n == 0){
        printf("(RetiraFila): Fila não existe ou está vazia!\n");
        return NULL;
    }

    Aluno* a = f->alunos[f->inicio];

    //faz incremento circular do indice que aponta pro inicio
    f->inicio = (f->inicio+1)%TAM;

    //atualiza numero de alunos
    f->n--;

    return a;
}

void ImprimeFila (Fila* f){
    int pos = 0;

    if(!f){
        printf("(ImprimeFila): Fila não existe\n");
        return;
    }

    for (int i=0; i<f->n; i++){
        pos = (f->inicio+i)%TAM;
        imprimeAluno(f->alunos[pos]);
    }
}

void DestroiFila (Fila* f){
    if(!f)  
        return;
    free(f);
}
