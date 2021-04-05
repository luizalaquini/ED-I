#include <stdio.h>
#include <stdlib.h>
#include "pilhaDupla.h"

#define MaxTam 10

struct indicePilha{
    int base;
    int topo;
};

struct pilhaDupla{
    Aluno* alunos[MaxTam];
    IndicePilha P1; //cr>=7
    IndicePilha P2; //cr<7
};

PilhaDupla* IniciaPilhaDupla (){
    PilhaDupla* p = (PilhaDupla*) malloc(sizeof(PilhaDupla));
    //define que P1 crescerá para a direita e P2 para a esquerda
    p->P1.base = 0;
    p->P1.topo = 0;
    p->P2.base = MaxTam-1;
    p->P2.topo = MaxTam-1;

    return p;
}

void Push (PilhaDupla* p, Aluno* aluno){

    //verifica condições antes de implementar
    if (!p || !aluno){
        printf ("Pilha ou aluno não existe!\n");
        return; //sai da função
    }
    else if (p->P1.topo-1 == (p->P2.topo)+1){
        printf("Overflow: Pilha cheia\n");
        return;
    }

    //Continuando no caso de não haver nenhum doss problemas acima
    float cr = retornaCR(aluno);
    //verifica cr
    if(cr>=7.0){
        p->alunos[p->P1.topo] = aluno;
        p->P1.topo++;
    }
    else{
        p->alunos[p->P2.topo] = aluno;
        p->P2.topo--;
    }
}

Aluno* Pop (PilhaDupla* p, int indice){

    //verifica condições antes de retirar
    if (!p || p->P1.topo == 0 && p->P2.topo == MaxTam-1){
        printf("Pilha vazia ou não existe!\n");
        return NULL; 
    }
    if (indice != 1 && indice!= 2){
        printf("ERRO\n");
        return NULL;
    }

    Aluno* a; 
    
    if(indice==1){
        p->P1.topo--;
        a = p->alunos[p->P1.topo];
    }
    else if(indice==2){
        p->P2.topo++;
        a = p->alunos[p->P2.topo];
    }

    return a;
}

void ImprimePilhaDupla (PilhaDupla* p){

    if (!p || p->P1.topo == 0 && p->P2.topo == MaxTam-1){
        printf("Pilha vazia ou não existe!\n");
    }
    else {
        int i;
        printf("----------P1----------\n");
        for (i = (p->P1.topo)-1; i>=0; i--){
            imprimeAluno(p->alunos[i]);
        }
        printf("----------P2----------\n");
        for (i = (p->P2.topo)+1; i<MaxTam; i++){
            imprimeAluno(p->alunos[i]);
        }
    }
}

void DestroiPilhaDupla (PilhaDupla* p){
    free(p);
}