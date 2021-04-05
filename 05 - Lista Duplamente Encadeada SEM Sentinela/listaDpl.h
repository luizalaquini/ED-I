#ifndef listaDpl_h
#define listaDpl_h

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

//tipo Lista (tipo opaco)
typedef struct lista Lista;

/*Inicializa uma lista sem sentinela
 * inputs: -
 * output: ponteiro para NULL (lista vazia)
 * pre-condicao: -
 * pos-condicao: lista de retorno existe e contem tres ponteiros para mat, prox e ant.
 */
Lista* IniciaLista(void);

/*Insere uma matriz na lista
 * inputs: lista a ser alterada e matriz a ser inserida
 * output: -
 * pre-condicao: lista e matriz devem existir
 * pos-condicao: matriz é acrescentada na primeira posição da lista
 */
Lista* InsereLista (Lista* lista, Matriz* mat);

/*Retira uma matriz da lista
 * inputs: lista a ser alterada e posição da matriz na lista
 * output: matriz retirada 
 * pre-condicao: lista deve existir
 * pos-condicao: matriz é retirada da lista (reorganizada)
 */
Lista* RetiraLista (Lista* lista, int chave);

/*Imprime a lista
 * inputs: lista a ser imprimida
 * output: -
 * pre-condicao: lista existe
 * pos-condicao: -
 */
void ImprimeLista (Lista* lista);

/*Libera memória alocada para a lista
 * inputs: lista a ser destruida
 * output:-
 * pre-condicao: lista existe
 * pos-condicao: memória alocada para a lista foi liberada
 */
void DestroiLista (Lista* lista);

#endif /*listaDpl_h*/