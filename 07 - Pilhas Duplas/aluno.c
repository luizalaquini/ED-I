#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno {
    int mat;
    char* nome;
    float cr;
};

Aluno* IniciaAluno (int mat, char* nome, float cr){
    Aluno* a = (Aluno*) malloc(sizeof(Aluno));

    a->mat = mat;
    a->nome = strdup(nome);
    a->cr = cr;

    return a;
}

void imprimeAluno (Aluno* aluno){
    printf("matricula: %d, nome: %s, CR: %.2f\n", aluno->mat, aluno->nome, aluno->cr);
}

int retornaMat (Aluno* aluno){
    return aluno->mat;
}

char* retornaNomeAluno (Aluno* aluno){
    return aluno->nome;
}

float retornaCR (Aluno* aluno){
    return aluno->cr;
}

void destroiAluno (Aluno* aluno){
    free(aluno->nome);
    free(aluno);
}