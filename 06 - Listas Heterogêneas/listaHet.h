#ifndef listaHet_h
#define listaHet_h

#include <stdio.h>
#include "aluno.h"
#include "professor.h"

typedef struct listaHet ListaHet;

ListaHet* iniciaLista (void);

void insereAluno (ListaHet* lista, Aluno* aluno);

void insereProfessor (ListaHet* lista, Professor* prof);

void imprimeListaHet (ListaHet* lista);

float valorChurrasco (ListaHet* lista);

void destroiListaHet (ListaHet* lista);

#endif /* listaHet_h */

