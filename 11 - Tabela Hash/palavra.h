#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdio.h>

typedef struct palavra Palavra;

Palavra* inicPalavra(char* str);

char* retornaString(Palavra* pal);

void atualizaOcorrencias(Palavra* pal);

int retornaOcorrencias(Palavra* pal);

Palavra* buscaPalavra(Palavra* pal, char* string);

Palavra* inserePalavralista(Palavra* lista, Palavra* p);

int contaPalavraslista(Palavra* p);

void imprimelista(Palavra* p);

void liberalistaPalavra(Palavra* pal);

#endif /* PALAVRA_H */