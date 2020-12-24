#include <stdio.h>
#include "matriz.h"

#define NLINHAS 5
#define NCOLUNAS 6

int main() {
    Matriz* mat;

    mat = inicializaMatriz(NLINHAS, NCOLUNAS);
    int i, j;

    for (i = 0; i < NLINHAS; i++) {
        for (j = 0; j < NCOLUNAS; j++) {
            modificaElemento(mat, i, j, i + j);
        }
    }
    imprimeMatriz(mat);

    Matriz* trp = transposta(mat);
    printf("A matriz transposta eh: \n");
    imprimeMatriz(trp);

    Matriz* mlt = multiplicacao(mat, trp);
    printf("A matriz multiplicacao eh: \n");
    imprimeMatriz(mlt);

    destroiMatriz(mat);
    destroiMatriz(trp);
    destroiMatriz(mlt);
}
