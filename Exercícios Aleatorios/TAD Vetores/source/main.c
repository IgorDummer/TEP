/*
Implementacao                                                                         Estado
1) pergunte qual o tamamnho desejado;                                                   Ok
2) preencha dois vetores deste mesmo tamanho                                            Ok
3) determine os seguintes resultados:                                                   Ok
    3.1) soma dos valores do vetor (primeiro e segundo)                                 Ok
    3.2) vetor "soma" dos dois vetores iniciais                                         Ok
    3.3) o produto interno dos dois vetores iniciais                                    Ok
    3.4) o produto interno do primeiro vetor com o vetor "soma"                         Ok
façam outras brincadeiras ...                                                           --
pensem, agora, como fazer tudo isso para vetores de double                              Fiz comentado
e pensem como fazer para termos coisas parecidas para matrizes em 2 dimensoes           Nao entendi
e pensem como fazer se estivessemos trabalhando com vetores esparsos                    Nao entendi tambem
 */

#include <stdio.h>
#include "vetor.h"

int main(){
    Vetor_t *vetor1, *vetor2;
    unsigned int tam;
    printf("Digite o tamanho dos vetores: ");
    scanf("%u", &tam);
    vetor1 = ConstroiVetor(tam);
    vetor2 = ConstroiVetor(tam);
    PreencheEOpera(vetor1,vetor2);
    return 0;
}