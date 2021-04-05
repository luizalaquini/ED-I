#ifndef listaMat_h
#define listaMat_h

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

//tipo Lista (tipo opaco)
typedef struct lista Lista;

/*Inicializa uma lista com sentinela
 * inputs: -
 * output: ponteiro para a sentinela
 * pre-condicao: -
 * pos-condicao: lista de retorno existe e contem sentinela com dois ponteiros (prim e ult)
 */
Lista* IniciaLista();

/*Insere uma matriz na lista
 * inputs: lista a ser alterada e matriz a ser inserida
 * output: -
 * pre-condicao: lista e matriz devem existir
 * pos-condicao: matriz é acrescentada na primeira posição da lista
 */
void InsereLista (Lista* lista, Matriz* mat);

/*Retira uma matriz da lista
 * inputs: lista a ser alterada e posição da matriz na lista
 * output: matriz retirada 
 * pre-condicao: lista deve existir
 * pos-condicao: matriz é retirada da lista (reorganizada)
 */
Matriz* RetiraLista (Lista* lista, int chave);

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

#endif /*listaMat_h*/