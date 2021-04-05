#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz {
    int *inicio;
    int nlinhas;
    int ncolunas;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz* mat = (Matriz*) malloc(sizeof(Matriz));

    mat->inicio = (int *)malloc(nlinhas * ncolunas * sizeof(int));
    mat->nlinhas = nlinhas;
    mat->ncolunas = ncolunas;

    if(mat==NULL){
        printf("Memoria insufucuente!\n");
        exit(1);
    }

    return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->inicio[linha * mat->ncolunas + coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->inicio[linha * mat->ncolunas + coluna];
}

int recuperaNColunas (Matriz* mat){
    return mat->ncolunas;
}

int recuperaNLinhas (Matriz* mat){
    return mat->nlinhas;
}

Matriz* transposta (Matriz* mat){
    Matriz *trp = inicializaMatriz(mat->ncolunas, mat->nlinhas);

    for(int i=0;i<mat->nlinhas;i++){
        for(int j=0;j<mat->ncolunas;j++){
            modificaElemento(trp, j, i, mat->inicio[i*mat->ncolunas+j]);
        }   
    }

    return trp;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    Matriz* mat3;
  
    mat3 = inicializaMatriz(mat1->nlinhas, mat2->ncolunas);

    int elem=0;

    for(int i=0;i<mat3->nlinhas;i++){
        for(int j=0;j<mat3->ncolunas;j++){
            for(int k=0;k<mat1->ncolunas;k++){
                elem += (mat1->inicio[i*mat1->ncolunas+k] * mat2->inicio[k*mat2->ncolunas +j]);
            }
            modificaElemento(mat3, i, j, elem);
            elem=0;
        }
    }
    
    return mat3;
}

void imprimeMatriz(Matriz* mat){
    for(int i=0; i<(mat->nlinhas*mat->ncolunas); i++){
        if(i%(mat->ncolunas)==0){
            printf("\n");
        }
        printf("%d ", mat->inicio[i]);
    }
    printf("\n\n");
}

void destroiMatriz(Matriz* mat){
    free(mat->inicio);
    free(mat);
}