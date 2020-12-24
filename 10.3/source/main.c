//Igor Wandermurem Dummer - 2019109389
#include <stdio.h>
#include "listaMat.h"

//Define o tam das linhas e das colunas das matrizes usadas
#define TAM_linhas 9
#define TAM_colunas 7

int main(){
    int i, j;
    Matriz *mat;

    mat = inicializaMatriz(TAM_linhas, TAM_colunas);

    //Cria matriz zerada
    for (i = 0; i < TAM_linhas; i++) {
        for (j = 0; j < TAM_colunas; j++) {
            modificaElemento(mat, i, j, 0);
        }
    }
    /* Insere valores diferentes de zero */
    modificaElemento(mat, 1, 2, 4);
    modificaElemento(mat, 3, 3, 7);
    modificaElemento(mat, 2, 1, 4);
    modificaElemento(mat, 2, 4, 9);
    modificaElemento(mat, 5, 5, 4);
    modificaElemento(mat, 7, 6, 7);
    modificaElemento(mat, 3, 2, 4);
    modificaElemento(mat, 8, 0, 9);

    printf("Matriz esparsa:\n");
    imprimeMatriz(mat);

    Lista *lista;
    lista = iniciaLista();

    for (i = 0; i < TAM_linhas; i++) {
        for (j = 0; j < TAM_colunas; j++) {
            insereLista(lista, recuperaElemento(mat,i,j), i, j);
        }
    }

    printf("\nLista de valores diferentes de 0 da matriz:\n");
    imprimeLista(lista);


    destroiLista(lista);
    destroiMatriz(mat);


    return 0;
}
