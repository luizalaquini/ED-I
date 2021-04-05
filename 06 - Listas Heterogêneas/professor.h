#ifndef professor_h
#define professor_h

#include <stdio.h>

typedef struct professor Professor;

Professor* iniciaProfessor (int siape, char* nome, float salario);

void imprimeProfessor (Professor* prof);

int retornaSiape (Professor* prof);

char* retornaNomeProfessor (Professor* prof);

float retornaSalario (Professor* prof);

void destroiProfessor (Professor* prof);

#endif /* professor_h */