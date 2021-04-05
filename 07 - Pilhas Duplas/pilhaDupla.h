#ifndef PILHADUPLA_H
#define PILHADUPLA_H

#include <stdio.h>
#include "aluno.h"

typedef struct indicePilha IndicePilha;

typedef struct pilhaDupla PilhaDupla;

//Inicializa a estrutura da pilha
PilhaDupla* IniciaPilhaDupla (void);

//Acrescenta no topo
void Push (PilhaDupla* p, Aluno* aluno);

//Retira do topo. O indice serve para selecionar a pilha P1(1) ou P2(2)
Aluno* Pop (PilhaDupla* p, int indice);

//Imprime do topo para a base
void ImprimePilhaDupla (PilhaDupla* p);

//Libera a pilha, mas nÃ£o os alunos!
void DestroiPilhaDupla (PilhaDupla* p);

#endif /* PILHADUPLA_H */