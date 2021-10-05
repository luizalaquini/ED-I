#include <stdio.h>
#include "abb.h"

int main (){

    //Cria alunos para teste
    Aluno* guilherme = IniciaAluno (2019123, "Guilherme", 10.0);
    Aluno* bruno = IniciaAluno (2019321, "Bruno", 8.0);
    Aluno* joana = IniciaAluno (2019213, "Joana", 6.9);
    Aluno* mirelly = IniciaAluno (2019231, "Mirelly", 7.0);
    Aluno* luiza = IniciaAluno (2019456, "Luiza", 6.7);

    //Cria abb para teste
    Arv* a = abb_cria();

    //Insere os alunos na arvore
    a = abb_insere(a, guilherme);
    a = abb_insere(a, bruno);
    a = abb_insere(a, joana);
    a = abb_insere(a, mirelly);
    a = abb_insere(a, luiza);

    //Imprime pra ver se inseriu na ordem correta
    printf("Imprimindo abb:\n");
    abb_imprime(a);

    //Retira um aluno em caso comum (1)
    a = abb_retira(a, 2019456); //luiza
    //Retira um aluno em caso (3)
    a = abb_retira(a, 2019123); //guilherme

    //Imprime para conferir as retiradas
    printf("Imprimindo abb:\n");
    abb_imprime(a);

    //Insere de volta os alunos retirados
    a = abb_insere(a, luiza);
    a = abb_insere(a, guilherme);

    //Imprime para conferir a inserção
    printf("Imprimindo abb:\n");
    abb_imprime(a);

    //Retira um aluno em caso (2)
    a = abb_retira(a, 2019231); //mirelly

    //Imprime para conferir a ultima retirada
    printf("Imprimindo abb:\n");
    abb_imprime(a);

    //Retira todos os alunos e libera arvore
    a = abb_retira(a, 2019456); //luiza
    a = abb_retira(a, 2019321); //bruno
    a = abb_retira(a, 2019213); //joana
    a = abb_retira(a, 2019123); //guilherme
    a = abb_libera(a);

    //Libera alunos
    destroiAluno(guilherme);
    destroiAluno(bruno);
    destroiAluno(joana);
    destroiAluno(mirelly);
    destroiAluno(luiza);

    return 0;
}