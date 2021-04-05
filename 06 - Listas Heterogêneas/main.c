#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaHet.h"

int main (int argc, const char* argv[]){

    //criando alunos para teste
    Aluno* guilherme = IniciaAluno (2019123, "Guilherme", 10.0);
    Aluno* bruno = IniciaAluno (2019321, "Bruno", 8.0);
    Aluno* joana = IniciaAluno (2019213, "Joana", 7.2);
    Aluno* mirelly = IniciaAluno (2019231, "Mirelly", 7.5);

    //criando professores para teste
    Professor* roberta = iniciaProfessor (785612, "Roberta", 9435.00);
    Professor* patricia = iniciaProfessor (481926, "Patricia", 7432.00);

    //inicializando Lista
    ListaHet* churrasco = iniciaLista();

    //inserindo alunos e professores na lista
    insereAluno(churrasco, guilherme);
    insereProfessor(churrasco, patricia);
    insereAluno(churrasco, bruno);
    insereAluno(churrasco, joana);
    insereProfessor(churrasco, roberta);
    insereAluno(churrasco, mirelly);

    //imprimindo a lista
    printf("-------------LISTA-DO-CHURRAS-------------\n");
    imprimeListaHet(churrasco);

    //conferindo quanto temos para fazer o churrasco
    printf("VALOR: %.2f\n", valorChurrasco(churrasco));

    //liberando memoria da lista
    destroiListaHet(churrasco);

    //liberando memoria dos alunos
    destroiAluno(guilherme);
    destroiAluno(bruno);
    destroiAluno(joana);
    destroiAluno(mirelly);

    //liberando memoria dos professores
    destroiProfessor(roberta);
    destroiProfessor(patricia);

    return 0;
}
