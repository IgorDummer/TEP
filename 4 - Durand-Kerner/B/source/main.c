#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "polinomio.h"

#define MAX 10

int main() {
    int grau;
    printf("Digite o grau do polinomio: ");
    scanf("%d", &grau);

    double complex polinomio[MAX];
    double real, imaginario;
    int i = 0;

    printf("Digite os valores do polinomio de grau %d:\n", grau);
    printf("Obs: Dois dígitos para representar numeros complexos (real imaginario).\n");

    for(i=0; i < grau+1; i++){
        scanf("%lf %lf", &real, &imaginario);
        polinomio[i] = (real + imaginario*I);
    }

    printf("O polinomio: ");
    imprimePolinomio(polinomio, grau);

    DurandKerner(polinomio, grau);

}
