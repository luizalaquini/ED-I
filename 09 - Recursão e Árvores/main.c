#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main (){

    //Cria alunos para teste
    Aluno* guilherme = IniciaAluno (2019123, "Guilherme", 10.0);
    Aluno* bruno = IniciaAluno (2019321, "Bruno", 8.0);
    Aluno* joana = IniciaAluno (2019213, "Joana", 6.9);
    Aluno* mirelly = IniciaAluno (2019231, "Mirelly", 7.0);
    Aluno* luiza = IniciaAluno (2019456, "Luiza", 6.7);

    //Cria uma arvore para teste
    Arv* a = CriaArv(guilherme, CriaArv(bruno, CriaArvVazia(), CriaArv(joana, CriaArvVazia(), CriaArvVazia())), CriaArv(mirelly, CriaArv(luiza, CriaArvVazia(), CriaArvVazia()), CriaArvVazia()));

    ImprimeArv(a);
    printf("\n");

    //Verifica se "Bruno" pertence à árvore
    int pertence = ArvPertence(a, "Bruno");
    printf("Bruno pertence? %d\n", pertence);

    //Verifica se "Patricia" pertence à árvore
    pertence = pertence = ArvPertence(a, "Patricia");
    printf("Patricia pertence? %d\n", pertence);

    //Retorna o pai de Bruno (Guilherme)
    Arv* pai = ArvPai(a, "Bruno");
    printf("Pai do Bruno: %s\n", retornaNomeAluno(info(pai)));

    //Retorna o número de folhas da árvore ()
    int f = Folhas(a);
    printf("Numero de folhas da arvore: %d\n", f);

    //Retorna o número de ocirrencias de "Luiza" (1)
    int o = Ocorrencias(a, "Luiza");
    printf("Numero de ocorrencias de Luiza: %d\n", o);

    //Retorna altura da arvore (2)
    int alt = Altura(a);
    printf("Altura da arvore: %d\n", alt);

    //Libera a memória alocada
    a = DestroiArv(a);
    destroiAluno(guilherme);
    destroiAluno(bruno);
    destroiAluno(joana);
    destroiAluno(mirelly);
    destroiAluno(luiza);

    return 0;
}