#include <stdio.h>
#include <stdlib.h>
#include "vetores.h"
#include "primos.h"

int main() {
    int n;
    char c='S';
    while(c=='S'){
        printf("Digite a quantidade de primos a serem somados: ");
        scanf("%d", &n);

        int* vet = (int*) malloc (n * sizeof(int));

        armazenaPrimosVet(vet,n);
        printf("\nA soma dos %d numeros primos eh: %d\n", n, somaVetor(vet, n));

        free(vet);
        printf("Digite 'S' se deseja reiniciar o programa ou qualquer tecla se deseja interromper.\n");
        scanf(" %c", &c);
    }
    return 0;
}