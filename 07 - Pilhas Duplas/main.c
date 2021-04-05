#include <stdio.h>
#include <stdlib.h>
#include "pilhaDupla.h"

int main (){

    //criando alunos para teste
    Aluno* guilherme = IniciaAluno (2019123, "Guilherme", 10.0);
    Aluno* bruno = IniciaAluno (2019321, "Bruno", 8.0);
    Aluno* joana = IniciaAluno (2019213, "Joana", 6.9);
    Aluno* mirelly = IniciaAluno (2019231, "Mirelly", 7.0);
    Aluno* luiza = IniciaAluno (2019456, "Luiza", 6.7);

    //inicializando pilha 
    PilhaDupla* p = IniciaPilhaDupla();

    //Adicionando alunos na pilha
    Push(p, guilherme);
    Push(p, bruno);
    Push(p, joana);
    Push(p, mirelly);
    Push(p, luiza);

    //Imprime pilha
    ImprimePilhaDupla(p); 

    //retira alguns alunos
    Pop(p, 1);
    Pop(p, 2);
    Pop(p, 2);

    //acrescenta novamente luiza e joana trocando a ordem na pilha
    Push(p, luiza);
    Push(p, joana);

    //Imprime pilha
    ImprimePilhaDupla(p);

    //adiciona novamente mirelly
    Push(p, mirelly);

    //criando mais 5 alunos para testar pilha cheia (10 alunos)
    Aluno* andre = IniciaAluno (2019654, "AndrÃ©", 8.9);
    Aluno* emerson = IniciaAluno (2019564, "Emerson", 6.2);
    Aluno* victoria = IniciaAluno (2019465, "Victoria", 5.9);
    Aluno* joao = IniciaAluno (2019645, "JoÃ£o", 5.5);
    Aluno* maria = IniciaAluno (2019789, "Maria", 6.0);

    //adicionando os alunos recÃ©m criados na pilha 
    Push(p, andre);
    Push(p, emerson);
    Push(p, victoria);
    Push(p, joao);
    Push(p, maria);

    //Imprime pilha
    ImprimePilhaDupla(p);

    //Retira todos os alunos da pilha
    Pop(p, 1);
    Pop(p, 1);
    Pop(p, 1);
    Pop(p, 1);
    Pop(p, 2);
    Pop(p, 2);
    Pop(p, 2);
    Pop(p, 2);
    Pop(p, 2);
    Pop(p, 2);

    //Libera pilha
    DestroiPilhaDupla(p);

    //Libera os alunos
    destroiAluno(guilherme);
    destroiAluno(bruno);
    destroiAluno(joana);
    destroiAluno(mirelly);
    destroiAluno(luiza);
    destroiAluno(andre);
    destroiAluno(emerson);
    destroiAluno(victoria);
    destroiAluno(joao);
    destroiAluno(maria);

    return 0;
}