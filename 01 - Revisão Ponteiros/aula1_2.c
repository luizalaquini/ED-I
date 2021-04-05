#include <stdio.h>
#include <math.h>

float pi =3.14;

void calc_esfera (float r, float* area, float* volume){
    *area = (4*pi*(pow(r,2)));
    *volume = ((4*pi*(pow(r,3)))/3);
}

int raizes (float a, float b, float c, float* x1, float* x2){
    int delta;

    delta = (pow(b,2))-(4*a*c);
    *x1 = (-b + sqrt(delta))/2*a;
    *x2 = (-b - sqrt(delta))/2*a;
}

int pares (int n, int* vet){
    int pares=0;
    for (int i=0; i<n; i++){
        if((vet[i]%2)==0){
            pares++;
        }
    }
    return pares;
}

void inverte (int n, int* vet){
    int aux;

    for(int i=0, j=n-1; i<(n/2); i++, j--){
        aux=vet[i];
        vet[i]=vet[j];
        vet[j]=aux;
    }
}

double avalia (double* poli, int grau, double x){
    double aux=0;
    
    for(int i=grau, j=0; i>=0; i--, j++){
        aux+=(poli[j]*(pow(x, i)));
    }
    return aux;
}

// //main para a funcao calc_esfera
// int main (){
//     float r, a, v;
//     float *pa, *pv;
    
//     pa=&a;
//     pv=&v;

//     printf("Digite o valor do raio do circulo para obter sua area e seu volume: ");
//     scanf("%f", &r);
//     calc_esfera(r, pa, pv);
//     printf("area=%.2f, volume=%.2f\n", a, v);

//     return 0;
// }

// //main para a funcao raizes
// int main (){
//     float a, b, c, x1, x2;
//     float *px1, *px2;

//     px1=&x1;
//     px2=&x2;

//     printf("Entre com os valores da funcao de segundo grau para calcular suas raizes: (valor+'ENTER')\na = ");
//     scanf("%f", &a);
//     printf("b = ");
//     scanf("%f", &b);
//     printf("c = ");
//     scanf("%f", &c);

//     raizes(a, b, c, px1, px2);

//     printf("As raizes sao: x'=%.2f e x''=%.2f\n", x1, x2);
//     return 0;
// }

// //main para a funcao pares
// int main (){
//     int n, x;

//     printf("Quantos valores possui o vetor? ");
//     scanf("%d", &n);
    
//     int vetor[n];
//     int *pv;

//     pv = &vetor[0];

//     printf("Insira os valores do vetor separados por espaco: ");
//     for(int i=0; i<n; i++){
//         scanf("%d", &vetor[i]);
//     }
    
//     x = pares(n, pv);

//     printf("Total de numeros pares presentes no vetor: %d\n", x);

//     return 0;
// }

// //main para a funcao inverte
// int main(){
//     int n;

//     printf("Quantos valores possui o vetor? ");
//     scanf("%d", &n);
    
//     int vetor[n];
//     int *pv;

//     pv = &vetor[0];

//     printf("Insira os valores do vetor separados por espaco: ");
//     for(int i=0; i<n; i++){
//         scanf("%d", &vetor[i]);
//     }

//     inverte (n, pv);

//     printf("O vetor invertido e: ");

//     for(int i=0; i<n; i++){
//         printf("%d ", vetor[i]);
//     }
//     printf("\n");

//     return 0;
// }

//main para a funcao avalia
int main (){
    int grau;
    double x, result;

    printf("Digite o grau do polinomio: ");
    scanf("%d", &grau);

    double poli[grau];
    double *p;

    p=&poli[0];

    printf("Digite os coeficientes do polinomio separados por espaco: ");

    for(int i=0; i<=grau; i++){
        scanf("%lf", &poli[i]);
    }

    printf("Digite o valor a ser avaliado: ");
    scanf("%lf", &x);

    result = avalia (p, grau, x);

    printf("O resultado e %.2f\n", result);

    return 0;
}