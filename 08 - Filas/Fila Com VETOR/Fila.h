#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include "aluno.h"

//tipo celula
typedef struct celula Celula;

//tipo fila
typedef struct fila Fila;

//Inicializa tipo fila
Fila* IniciaFila(void);

//Insere aluno (sempre no final da fila)
void InsereFila (Fila* f, Aluno* a);

//Retira aluno (sempre do inicio da fila)
Aluno* RetiraFila (Fila* f);

//imprime a fila (do inicio ao fim)
void ImprimeFila (Fila* f);

//libera memoria da fila
void DestroiFila (Fila* f);

#endif /* FILA_H */
