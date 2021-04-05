#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definicao da estrutura
typedef struct aluno {
    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
} Aluno;

void imprime_aprovados (int n, Aluno** turma){
    float mediaAluno;
    printf("\nAPROVADOS:\n");
    for(int i=0; i<n; i++){
        mediaAluno = ((turma[i]->p1 + turma[i]->p2 + turma[i]->p3)/3);
        if (mediaAluno >= 7){
            printf("%s\n", turma[i]->nome);
        }
    }
}

float media_turma (int n, Aluno** turma){
    float mediaTurma=0, mediaAluno;
    for(int i=0; i<n; i++){
        mediaAluno = ((turma[i]->p1 + turma[i]->p2 + turma[i]->p3)/3);
        mediaTurma += mediaAluno;
    }
    mediaTurma = (mediaTurma/n);
    return mediaTurma;
}

int main (){
    int n;

    printf("Informe o numero de alunos da turma: ");
    scanf("%d", &n);

    Aluno** turma = (Aluno**) malloc (n * sizeof(Aluno*)); //aloca vetor de structs

    for(int i=0; i<n; i++){
        turma[i] = (Aluno*) malloc (sizeof(Aluno)); //aloca cada aluno
    }

    printf("Preencha as informacoes para cada aluno da turma:\n");

    for(int i=0; i<n; i++){
        char* nome = (char*) malloc (30*sizeof(char)); //variavel para capturar nome

        printf("\nALUNO %d:\n",(i+1));
        printf("Nome: ");
        scanf(" %30[^\n]", nome);
        turma[i]->nome = strdup(nome); //aloca e copia
        printf("Matricula: ");
        scanf("%d", &turma[i]->matricula);
        printf("Nota P1: ");
        scanf("%f", &turma[i]->p1);
        printf("Nota P2: ");
        scanf("%f", &turma[i]->p2);
        printf("Nota P3: ");
        scanf("%f", &turma[i]->p3);
    }
    printf("\nDados Carregados!\n");
    printf("\nTURMA:\n");
    for(int i=0; i<n; i++){ //imprime dados da turma, um aluno por linha
        printf("%s | %d | P1=%.2f, P2=%.2f, P3=%.2f\n", turma[i]->nome, turma[i]->matricula, turma[i]->p1, turma[i]->p2, turma[i]->p3);
    }
    imprime_aprovados(n, turma);
    float media = media_turma(n, turma);
    printf("\nMEDIA DA TURMA: %.2f\n", media);

    //libera memoria antes de fechar o programa:
    for(int i=0; i<n; i++){ 
        free (turma[i]->nome);
        free (turma[i]);
    }
    free(turma);

    return 0;
}