#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct arvore{
    Aluno* aluno;
    Arv* esq;
    Arv* dir;
};

Arv* CriaArvVazia (void){
    return NULL;
}

Arv* CriaArv (Aluno* a, Arv* e, Arv* d){
    Arv* arv = (Arv*) malloc (sizeof(Arv));

    arv->aluno = a;
    arv->esq = e;
    arv->dir = d;

    return arv;
}

int ArvVazia (Arv* a){
    if (a==NULL)
        return 1;
    else
        return 0;
}

Arv* DestroiArv (Arv* a){
    if(!ArvVazia(a)){
        DestroiArv(a->esq); //libera sae
        DestroiArv(a->dir); //libera sad
        free(a); //libera raiz
    }
    return NULL;
}

int ArvPertence (Arv* arv, char* nome){
    if(ArvVazia(arv))
        return 0;
    else{
        if(!strcmp(retornaNomeAluno(arv->aluno), nome)|| ArvPertence(arv->esq, nome) || ArvPertence(arv->dir, nome))
            return 1;
    }
}

void ImprimeArv (Arv* a){
    printf("<");
    if(!ArvVazia(a)){
        printf("%s", retornaNomeAluno(a->aluno)); //mostra raiz
        ImprimeArv(a->esq); //mostra sae
        ImprimeArv(a->dir); //mostra sad
    }
    printf(">");
}

Arv* ArvPai (Arv* arv, char* nome){
    if (ArvVazia(arv))
        return NULL;

    else if(!ArvVazia(arv->esq) && (strcmp(retornaNomeAluno(arv->esq->aluno), nome)==0) || !ArvVazia(arv->dir) && (strcmp(retornaNomeAluno(arv->esq->aluno), nome)==0))
        return arv;
    
    Arv* aux = ArvPai (arv->esq, nome);
    if(aux == NULL)
        aux = ArvPai (arv->dir, nome);
    return aux;
}

int Folhas (Arv* a){
    int cont = 0;
    if(ArvVazia(a->esq) && ArvVazia(a->dir))
        return 1;
    else if (!ArvVazia(a->esq) && ArvVazia(a->dir))
        return Folhas(a->esq);
    else if (ArvVazia(a->esq) && !ArvVazia(a->dir))
        return Folhas(a->dir);
    else
        return Folhas(a->esq)+Folhas(a->dir);
}

int Ocorrencias (Arv* a , char* nome){
  
    if(ArvVazia(a))
        return 0;
    else if((strcmp(retornaNomeAluno(a->aluno), nome) == 0))
        return (1 + Ocorrencias(a->esq, nome) + Ocorrencias(a->dir, nome));
    else
        return (Ocorrencias(a->esq, nome) + Ocorrencias(a->dir, nome));
    
}

static int max2 (int a, int b){
    return (a > b) ? a : b;
}

Aluno* info (Arv* a){
    return a->aluno;
}

int Altura (Arv* a){
    if(ArvVazia(a))
        return -1;
    else
        return 1 + max2 (Altura(a->esq), Altura(a->dir));
    
}

