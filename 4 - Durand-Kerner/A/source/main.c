#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "polinomio.h"

/* Durand Kerner com grau qualquer, menor ou igual a 10 */
int main() {


    double complex polinomio[5];
    double real, imaginario;
    int i = 0;

    printf("Digite os valores do polinomio de grau 4:\n");
    printf("Obs: Dois dígitos para representar numeros complexos (real imaginario).\n");

    /* A leitura eh feita de modo a ser o a0 primeiro, ate o a4 */
    for(i=0; i < 5; i++){
        scanf("%lf %lf", &real, &imaginario);
        polinomio[i] = (real + imaginario*I);
    }
    //polinomio[5] = 1;

    printf("O polinomio: ");
    imprimePolinomio(polinomio, 5);

    DurandKerner(polinomio);

    return 0;
}
