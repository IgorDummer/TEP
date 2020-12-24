#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

//As funcoes comentadas seriam levando em consideração que fosse um vetor do tipo double.

struct Vetor_s{
    unsigned int pos;
    unsigned int tam_max;
    int* v;
    //double* v;
};

/* aloca o struct de vetor e retorna ele */
Vetor_t* ConstroiVetor(unsigned int tam){
    Vetor_t* vet = (Vetor_t *) malloc (sizeof (Vetor_t));
    vet->pos = 0;
    vet->tam_max = tam;
    vet->v = (int*) calloc (tam ,sizeof (int));
    return vet;
}

/*Vetor_t* ConstroiVetor(unsigned int n){
    Vetor_t* vet = (Vetor_t *) malloc (sizeof (Vetor_t));
    vet->pos = 0;
    vet->tam_max = n;
    vet->v = (double*) calloc (n ,sizeof (double));
    return vet;
}*/

/* Le e preenche o vetor com os dados fornecidos pelo terminal */
void PreencheVetor(Vetor_t *vetor){
    printf("\nDigite os valores do vetor:\n");
    for(unsigned int i=0; i<vetor->tam_max; i++){
        scanf("%d", &vetor->v[i]);
    }
}

/*void PreencheVetor(Vetor_t *vetor){
    printf("\nDigite os valores do vetor:\n");
    for(int i=0; i<vetor->tam_max; i++){
        scanf("%lf", &vetor->v[i]);
    }
}*/

/* Faz a soma entre cada posicao do vetor */
int somaVetor(Vetor_t *vetor){
    int soma=0;
    for(unsigned int i=0;i<vetor->tam_max;i++){
        soma += vetor->v[i];
    }
    return soma;
}

/*double somaVetor(Vetor_t *vetor){
    double soma=0;
    for(int i=0;i<vetor->tam_max;i++){
        soma += vetor->v[i];
    }
    return soma;
}*/

/* Armazena a soma entre a mesma posicao em dois vetores */
Vetor_t* somaVetores(Vetor_t* vetor1, Vetor_t* vetor2){
    Vetor_t *vetorSoma;
    vetorSoma = ConstroiVetor(vetor1->tam_max);
    for(unsigned int i=0;i<vetor1->tam_max;i++){
        vetorSoma->v[i] = vetor1->v[i] + vetor2->v[i];
    }
    return vetorSoma;
}

/* Exibe o vetor via terminal */
void exibeVetor(Vetor_t* vetor){
    for(unsigned int i=0;i<vetor->tam_max;i++){
        printf(" %d", vetor->v[i]);
    }
    printf("\n");
}

/* Calcula e retorna o produto interno dentre dois vetores */
int ProdutoInterno(Vetor_t* vetor1, Vetor_t* vetor2){
    int produto = 0;
    for(unsigned int i=0; i<vetor1->tam_max;i++){
        produto = produto + (vetor1->v[i] * vetor2->v[i]);
    }
    return produto;
}

/*double ProdutoInterno(Vetor_t* vetor1,Vetor_t* vetor2){
    double produto = 0;
    for(int i=0; i<vetor1->tam_max;i++){
        produto = produto + (vetor1->v[i] * vetor2->v[i]);
    }
    return produto;
}*/

/* Libera o espaco alocado na memoria para o vetor de struct */
void liberaVetor(Vetor_t* vetor){
    free(vetor->v);
    free(vetor);
}

/* chama a funcao liberaVetor para liberar o espaco de 3 vetores
 * funcao auxiliar
 */
void DestroiVetores(Vetor_t* vetor1, Vetor_t* vetor2, Vetor_t* soma){
    liberaVetor(vetor1);
    liberaVetor(vetor2);
    liberaVetor(soma);
}

/* Chama todas as operacoes do programa (A intencao eh nao "poluir" a main)*/
void PreencheEOpera(Vetor_t* vetor1, Vetor_t* vetor2){
    PreencheVetor(vetor1);
    PreencheVetor(vetor2);
    printf("\nA soma do vetor 1 eh: %d\n", somaVetor(vetor1));
    printf("A soma do vetor 2 eh: %d\n", somaVetor(vetor2));
    /*
    printf("A soma do vetor 1 eh: %lf", somaVetor(vetor1));
    printf("A soma do vetor 2 eh: %lf", somaVetor(vetor2));
     */
    Vetor_t* soma;
    soma = somaVetores(vetor1,vetor2);
    printf("O vetor soma eh:");
    exibeVetor(soma);
    printf("O produto interno entre o vetor 1 e o vetor 2 eh: %d\n", ProdutoInterno(vetor1,vetor2));
    printf("O produto interno entre o vetor 1 e o vetor soma eh: %d\n", ProdutoInterno(vetor1, soma));
    printf("O produto interno entre o vetor 2 e o vetor soma eh: %d\n", ProdutoInterno(vetor2, soma));
    DestroiVetores(vetor1,vetor2,soma);
}