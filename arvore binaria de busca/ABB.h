#include <stdio.h>
#include <stdlib.h>

typedef struct abb Abb;

Abb* criaVazia ();

Abb* insereChave (Abb* a, int chave);

Abb* destroi (Abb* a);

//Retorna verdadeiro se a árvore estiver vazia e falso caso contrário
int ArvVazia (Abb* a);

//Função auxiliar para calculo da altura da arvore
static int max2 (int a, int b);

//Retorna a altura da árvore 
int altura (Abb* a); 
