#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct arv {
    Aluno* aluno;
    Arv* esq;
    Arv* dir;
};

Arv* abb_cria (){
    return NULL;
}

void abb_imprime (Arv* a){
    
    if(a != NULL){
        abb_imprime(a->esq);
        imprimeAluno(a->aluno);
        abb_imprime(a->dir);
    }
}

Arv* abb_busca (Arv* a, int chave){
    if (a == NULL)
        return NULL;
    else if (retornaMat(a->aluno) > chave)
        return abb_busca (a->esq, chave);
    else if (retornaMat(a->aluno) < chave)
        return abb_busca (a->dir, chave);
    else
        return a;
}

Arv* abb_insere (Arv* a, Aluno* alu){
    if (a == NULL){
        a = (Arv*) malloc(sizeof(Arv));
        a->aluno = alu;
        a->esq = a->dir = NULL;
    }
    //procura onde inserir
    else if (retornaMat(alu) < retornaMat(a->aluno))
        a->esq = abb_insere(a->esq, alu);
    else
        a->dir = abb_insere(a->dir, alu);
    return a;
}

Arv* abb_retira (Arv* a, int chave){
    if(a==NULL)
        return NULL;
    else if (retornaMat(a->aluno) > chave)
        a->esq = abb_retira(a->esq, chave);
    else if (retornaMat(a->aluno) < chave)
        a->dir = abb_retira(a->dir, chave);
    else { //achou
        
        //(1)caso comum: nó é folha
        if (a->esq == NULL && a->dir == NULL){
            free(a);
            a = NULL;
        }

        //(2.1)nó com somente filho à direita
        else if (a->esq == NULL){
            Arv* t = a;
            a = a->dir;
            free(t);
        }
        //(2.2)nó com somente filho à esquerda 
        else if (a->dir == NULL){
            Arv* t = a;
            a = a->esq;
            free(t);
        }

        //(3)nó tem filhos dos dois lados
        else{
            //acha o antecessor do nó
            Arv* f = a->esq;
            while(a->dir != NULL)
                f = f->dir;
            //realiza a troca de informação
            Aluno* t = a->aluno;
            a->aluno = f->aluno;
            f->aluno = t;
            //chama recursivamente a função que agora vai cair em um dos casos anteriores
            a->esq = abb_retira(a->esq, chave);
        }
    }
    return a;
}

Arv* abb_libera (Arv* a){
    if (a == NULL)
        return NULL;
    abb_libera(a->esq); //libera sae
    abb_libera(a->dir); //libera sad
    free(a); //libera raiz
}