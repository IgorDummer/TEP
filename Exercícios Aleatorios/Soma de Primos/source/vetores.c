#include "vetores.h"
#include "primos.h"

void armazenaPrimosVet(int* vet, int n){
    int j = 0;
    for(int i=2; j<n; i++){
        if(ehprimo(i)){
            vet[j] = i;
            j++;
        }
    }
}

int somaVetor(int* vet, int n){
    int soma=0;
    for(int i=0; i<n; i++){
        soma += vet[i];
    }
    return soma;
}