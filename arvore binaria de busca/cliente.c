#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ABB.h"

int main () {
    int N = 1000000, alt;

    //scanf("%d", &N);

    Abb* arvore = criaVazia();

    srand(time(NULL)); // should only be called once

    for (int i=0; i<N; i++){
        int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX
        arvore = insereChave(arvore, r);
    }
    
    alt = altura(arvore);

    printf("altura = %d\n", alt);

    arvore = destroi(arvore);

    return 0;
}