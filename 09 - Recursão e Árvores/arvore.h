#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include "aluno.h"

typedef struct arvore Arv;

//Cria uma arvore binaria vazia
Arv* CriaArvVazia (void);

//Cria uma arvore binaria com o aluno do nó raiz e com as subarvores da esquerda e da direita
Arv* CriaArv (Aluno* a, Arv* e, Arv* d);

//Retorna verdadeiro se a árvore estiver vazia e falso caso contrário
int ArvVazia (Arv* a);

//Libera o espaço de memória de uma árvore binaria
Arv* DestroiArv (Arv* a);

//Retorna verdadeiro caso o aluno pertença à arvore e falso caso contrário
int ArvPertence (Arv* arv, char* nome);

//Imprime uma árvore binaria
void ImprimeArv (Arv* a);

//Retorna o pai de um dado aluno
Arv* ArvPai (Arv* arv, char* nome);

//Retorna o número de folhas de uma arvore binaria
int Folhas (Arv* a); 

//Retorna o número de vezes que o aluno aparece na árvore
int Ocorrencias (Arv* a , char* nome); 

//Função auxiliar para calculo da altura
static int max2 (int a, int b);

//Função auxiliar (retorna aluno contido na arvore)
Aluno* info (Arv* a);

//Retorna a altura da árvore binaria
int Altura (Arv* a); 

#endif /* ARVORE_H */