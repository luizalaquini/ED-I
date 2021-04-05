/*
 *************************************
 * Programa testador do TAD listaDpl *
 *************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDpl.h"

int main (void){

    //Inicializando 3 matrizes 3x3
    Matriz* sergio = inicializaMatriz (3, 3);
    Matriz* raphael = inicializaMatriz (3, 3);
    Matriz* luiza = inicializaMatriz (3, 3);

    //Preenchendo as 3 matrizes com valores para teste
    int s=1, r=2, l=3;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            modificaElemento(sergio, i, j, s);
            modificaElemento(raphael, i, j, r);
            modificaElemento(luiza, i, j, l);
            s++;
            r+=2;
            l+=3;
        }
    }

    //Inicializando uma lista encadeada (lista1)
    Lista* lista1 = IniciaLista();

    //Inserindo as 3 matrizes na lista1
    lista1 = InsereLista(lista1, sergio);
    lista1 = InsereLista(lista1, raphael);
    lista1 = InsereLista(lista1, luiza);

    //Inicializando outra lista encadeada (lista2)
    Lista* lista2 = IniciaLista();

    //Inserindo as 3 matrizes TRANSPOSTAS na lista2
    Matriz* sergioTrp = transposta(sergio);
    Matriz* raphaelTrp = transposta(raphael);
    Matriz* luizaTrp = transposta(luiza);
    lista2 = InsereLista(lista2, sergioTrp);
    lista2 = InsereLista(lista2, raphaelTrp);
    lista2 = InsereLista(lista2, luizaTrp);

    //TESTE DOS 4 CASOS DA FUNÇÃO RETIRA
    ////1- Teste do retira com caso comum: retirando raphael(chave = 2, pois está na segunda célula) da lista1
    lista1 = RetiraLista(lista1, 2);

    ////2- Teste do retira com ultima posição: retirando sergioTrp(chave = 3, pois está na terceira célula) da lista2
    lista2 = RetiraLista(lista2, 3);

    ////3- Teste do retira com primeira posição: retirando luiza(chave = 1, pois está na primeira célula) da lista1
    lista1 = RetiraLista(lista1, 1);

    ////4- Teste do retira com primeira E ÚNICA posição: retirando sergio(chave = 1, pois está na primeira célula) da lista1
    lista1 = RetiraLista(lista1, 1);

    //Inserindo novamente as 4 matrizes retiradas (sergio, raphael e luiza na lista1 e sergioTrp na lista2)  para verificar se o retira não "quebrou" as listas
    lista1 = InsereLista(lista1, sergio);
    lista1 = InsereLista(lista1, raphael);
    lista1 = InsereLista(lista1, luiza);
    lista2 = InsereLista(lista2, sergioTrp);

    //Retirando tudo das duas listas
    lista1 = RetiraLista(lista1, 1);
    lista1 = RetiraLista(lista1, 2);
    lista1 = RetiraLista(lista1, 3);
    lista2 = RetiraLista(lista2, 1);
    lista2 = RetiraLista(lista2, 2);
    lista2 = RetiraLista(lista2, 3);

    //Liberando as Listas
    DestroiLista(lista1);
    DestroiLista(lista2);
    
    //Liberando as Matrizes
    destroiMatriz(sergio);
    destroiMatriz(raphael);
    destroiMatriz(luiza);
    destroiMatriz(sergioTrp);
    destroiMatriz(raphaelTrp);
    destroiMatriz(luizaTrp);
   
    //Imprimindo listas
    //ImprimeLista(lista1);
    //ImprimeLista(lista2);

    return 0;
}