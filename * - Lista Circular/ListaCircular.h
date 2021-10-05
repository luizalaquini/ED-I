#include <stdio.h>
#include <stdlib.h>

typedef struct celula Celula;

/*Retorna M-esima celula a partir da passada como parametro
*/
Celula* retornaMesima (Celula* p, int M);

int retornaDado (Celula* cel);

typedef struct lista Lista;

/* Inicializa uma nova lista VAZIA
*/
Lista* iniciaLista();

/* Insere uma nova celula na lista, com dado passado por parâmetro
*/
void insereDado (Lista* lista, int dado);

/*Remove um dado da lista e retorna o ponteiro do dado seguinte ao que foi removido
*/
Celula* removeDado (Lista* lista, Celula* p, int M);