#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

//tipo Lista (tipo opaco)
typedef struct lista Lista;

//Inicializa uma lista com sentinela
Lista* IniciaLista();

//Insere um aluno na lista
void InsereLista (Lista* lista, Aluno* aluno);

//Insere um aluno no FINAL da lista
void InsereListaUlt (Lista* lista, Aluno* aluno);

//Retira um aluno da lista
Aluno* RetiraLista (Lista* lista, int chave);

//Imprime a lista
void ImprimeLista (Lista* lista);

//Libera memória alocada para a lista
void DestroiLista (Lista* lista);

#endif /* LISTA_H */