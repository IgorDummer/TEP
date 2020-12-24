#ifndef ARRAY_H
#define ARRAY_H

typedef struct matriz Matriz;

Matriz* inicializaMatriz(int nlinhas, int ncolunas);

void modificaElemento(Matriz* mat, int linha, int coluna, int elem);

int recuperaElemento(Matriz* mat, int linha, int coluna);

int recuperaNColunas(Matriz* mat);

int recuperaNLinhas(Matriz* mat);

void imprimeMatriz(Matriz* mat);

void destroiMatriz(Matriz* mat);

#endif //ARRAY_H
