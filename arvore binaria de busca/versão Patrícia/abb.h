#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include "aluno.h"

//tipo opaco
typedef struct arv Arv;

//cria uma arvore binaria de busca sem conteudo
Arv* abb_cria (void);

//imprime a arvore binaria de busca
void abb_imprime (Arv* a);

//Se encontrar, retorna o nó que contém o aluno, caso contrário, retorna NULLL
Arv* abb_busca (Arv* a, int chave);

//Insere aluno sempre como folha da arvore
Arv* abb_insere (Arv* a, Aluno* alu);

//Retira um aluno da arvore binaria de busca (possui 3 casos)
Arv* abb_retira (Arv* a, int chave);

//Libera a memoria alocada pra arvore binaria de busca
Arv* abb_libera (Arv* a);

#endif /* ABB_H */