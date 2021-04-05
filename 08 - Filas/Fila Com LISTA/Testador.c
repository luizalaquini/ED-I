#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main (){

    //criando alunos para teste
    Aluno* guilherme = IniciaAluno (2019123, "Guilherme", 10.0);
    Aluno* bruno = IniciaAluno (2019321, "Bruno", 8.0);
    Aluno* joana = IniciaAluno (2019213, "Joana", 7.2);
    Aluno* mirelly = IniciaAluno (2019231, "Mirelly", 7.5);
    Aluno* luiza = IniciaAluno (2019456, "Luiza", 9.0);

    //iniciando duas filas
    Fila* f = IniciaFila();
    Fila* f2 = IniciaFila();

    InsereFila(f, guilherme);
    InsereFila(f, bruno);
    InsereFila(f, joana);
    InsereFila(f, mirelly);
    InsereFila(f, luiza); //nao vai caber (TAM=4) exibe mensagem

    //Imprimindo f
    printf("Imprimindo a fila f:\n");
    ImprimeFila(f);

    //Separando meninas em f e meninos em f2
    InsereFila(f2, RetiraFila(f));
    InsereFila(f2, RetiraFila(f));
    InsereFila(f, luiza);

    //Imprimindo f e f2
    printf("Imprimindo a fila f:\n");
    ImprimeFila(f);
    printf("Imprimindo a fila f2:\n");
    ImprimeFila(f2);    

    //esvaziando filas
    RetiraFila(f);
    RetiraFila(f);
    RetiraFila(f);
    RetiraFila(f); //fila já está vazia, exibir mensagem
    RetiraFila(f2);
    RetiraFila(f2);

    //Imprimindo f e f2 vazias
    printf("Imprimindo a fila f:\n");
    ImprimeFila(f);
    printf("Imprimindo a fila f2:\n");
    ImprimeFila(f2); 
    
    //liberando filas
    DestroiFila(f);  
    DestroiFila(f2);

    //liberando alunos
    destroiAluno(guilherme);
    destroiAluno(bruno);
    destroiAluno(joana);
    destroiAluno(mirelly);
    destroiAluno(luiza);

    return 0;
}