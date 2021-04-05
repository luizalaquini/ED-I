#include <stdio.h>

void mostraValores (int a, int b, int c, int d){
    printf ("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
}

void modifica (int *p, int x){
    *p=x;
}

int main(){
    int a=0, b=0, c=0, d=0;
    int *pa, *pb, *pc, *pd;
    int x;

    pa=&a;
    pb=&b;
    pc=&c;
    pd=&d;

    int i=0;
    char escolha;
    while(i==0){
        mostraValores(a, b, c, d);
        printf("Deseja modificar alguma variavel? S/N\n");
        scanf("%c", &escolha);
        if(escolha=='s'||escolha== 'S'){
            scanf("%*c");
            printf("Qual variavel? a/b/c/d\n");
            scanf("%c", &escolha);
            printf("Digite um novo valor para %c: ", escolha);
            scanf("%d", &x);
            if(escolha=='a'||escolha=='A'){
                modifica(pa, x);
            }
            if(escolha=='b'||escolha=='B'){
                modifica(pb, x);
            }
            if(escolha=='c'||escolha=='C'){
                modifica(pc, x);
            }
            if(escolha=='d'||escolha=='D'){
                modifica(pd, x);
            } 
            scanf("%*c");
        }
        else i++;
    }
    
    return 0;
}