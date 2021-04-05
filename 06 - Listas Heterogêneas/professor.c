#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

struct professor{
    int siape;
    char* nome;
    float salario;
};

Professor* iniciaProfessor (int siape, char* nome, float salario){
    Professor* p = (Professor*) malloc (sizeof(Professor));

    p->siape = siape;
    p->nome = strdup(nome);
    p->salario = salario;

    return p;
}

void imprimeProfessor (Professor* prof){
    printf("siape: %d, nome: %s, salario: R$%.2f\n", prof->siape, prof->nome, prof->salario);
}

int retornaSiape (Professor* prof){
    return prof->siape;
}

char* retornaNomeProfessor (Professor* prof){
    return prof->nome;
}

float retornaSalario (Professor* prof){
    return prof->salario;
}

void destroiProfessor (Professor* prof){
    free(prof->nome);
    free(prof);
}