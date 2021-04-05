#ifndef aluno_h
#define aluno_h

#include <stdio.h>

typedef struct aluno Aluno;

Aluno* IniciaAluno (int mat, char* nome, float cr);

void imprimeAluno (Aluno* aluno);

int retornaMat (Aluno* aluno);

char* retornaNomeAluno (Aluno* aluno);

float retornaCR (Aluno* aluno);

void destroiAluno (Aluno* aluno);

#endif /* aluno_h */