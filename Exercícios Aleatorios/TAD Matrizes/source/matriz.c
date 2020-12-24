#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Aloca e retorna a matriz float (A matriz nao eh alocada de forma continua na memoria) */
float** Alocar_matriz_real(int m, int n){
    char c;
    float **v;
    printf("Eh uma matriz de linhas com tamanhos diferentes? (S) pra sim e (N) pra nao: ");
    scanf(" %c", &c);
    /* So fiz essa parte nessa funcao, mas o ideal era fazer em varias
     * isso eh pra saber se a funcao vai ter numero de linhas desiguais */
    if(c == 'S'){ // Linhas Desiguais
        if (m < 1) {
            printf("** Erro: Parametro invalido **\n");
            return (NULL);
        }
        /* aloca as linhas da matriz */
        v = (float **) calloc(m, sizeof(float *));
        if (v == NULL) {
            printf("** Erro: Memoria Insuficiente **");
            return (NULL);
        }
        /* aloca as colunas da matriz */
        for (int i = 0; i < m; i++) {
            printf("\nDiga o tamanho da linha %d: ", i);
            scanf("%d", &n);
            v[i] = (float *) calloc(n, sizeof(float));
            if (v[i] == NULL) {
                printf("** Erro: Memoria Insuficiente **");
                return (NULL);
            }
        }
    }
    else if(c == 'N'){ //Linhas Iguais
        if (m < 1 || n < 1) {
            printf("** Erro: Parametro invalido **\n");
            return (NULL);
        }
        /* aloca as linhas da matriz */
        v = (float **) calloc(m, sizeof(float *));
        if (v == NULL) {
            printf("** Erro: Memoria Insuficiente **");
            return (NULL);
        }
        /* aloca as colunas da matriz */
        for (int i = 0; i < m; i++) {
            v[i] = (float *) calloc(n, sizeof(float));
            if (v[i] == NULL) {
                printf("** Erro: Memoria Insuficiente **");
                return (NULL);
            }
        }
    }
    else{ //Caso nao digite nem S nem N, encerra o programa
        printf("Parametro invalido\n");
        exit(1);
    }
    return (v); //Retorna a matriz float
}

//Aloca a matriz float de forma continua na memoria
float* MatrizRealCont(int m, int n){
    float *v;
    if (m < 1 || n < 1) {
        printf ("** Erro: Parametro invalido **\n");
        return (NULL);
    }
    /* aloca as linhas da matriz */
    v = (float *) calloc (m*n, sizeof(float));
    if (v == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
    }
    return (v);
}

//Recebe os valores das matrizes pelo teclado
void leMatrizFloat(float** matriz1, float* matriz2, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%f", &matriz1[i][j]); //Le a matriz que nao e continua na memoria
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int k=0;
            k = (i * n) + j; //Existe outra forma mais simples
            scanf("%f", &matriz2[k]); //Le a matriz que eh continua na memoria
        }
    }
}

//Libera a matriz
void liberaMatrizesFloat(float** matriz1, float* matriz2, int m){
    for(int i=0;i<m ;i++){
        free(matriz1[i]); //Como a matriz que nao é continua precisou alocar varias vezes, precisa dar free todas
                          //as vezes que foi alocada
    }
    free(matriz1);
    free(matriz2); //A matriz continua na memoria funciona como um vetor, entao so eh necessario liberar uma vez
}

//Aloca a matriz de string
char*** Alocar_matriz_string(int m, int n){
    char ***v; //Como a string eh um ponteiro pra char (*c)
               //um vetor de strings seria *(*c) e, portanto, uma matriz de strings seria *(*(*c))) ou ***c.
    if (m < 1 || n < 1) {
        printf ("** Erro: Parametro invalido **\n");
        return (NULL);
    }
    /* aloca as linhas da matriz */
    v = (char ***) calloc (m, sizeof(char **));
    if (v == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
    }
    /* aloca as colunas da matriz */
    for (int i = 0; i < m; i++ ) {
        v[i] = (char**) calloc (n, sizeof(char*));
        if (v[i] == NULL) {
            printf ("** Erro: Memoria Insuficiente **");
            return (NULL);
        }
    }
    return (v);
}

char** MatrizStringCont(int m, int n){
    char **v;
    if (m < 1 || n < 1){
        printf ("** Erro: Parametro invalido **\n");
        return (NULL);
    }
    /* aloca as linhas da matriz */
    v = (char **) calloc (m*n, sizeof(char*));
    if (v == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
    }
    return (v);
}

char* leString(void){
    char string[161];
    scanf(" %160[^\n]", string);

    return strdup(string);
}

void leMatrizString(char*** matriz1, char** matriz2, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            matriz1[i][j] = leString();
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int k=0;
            k = (i * n) + j;
            matriz2[k] = leString();
        }
    }
}

void liberaMatrizesString(char*** matriz1, char** matriz2, int m){
    for(int i=0;i<m ;i++){
        free(matriz1[i]);
    }
    free(matriz1);
    free(matriz2);
}

double** Alocar_matriz_double(int m, int n){
    double **v;
    if (m < 1 || n < 1) {
        printf ("** Erro: Parametro invalido **\n");
        return (NULL);
    }
    /* aloca as linhas da matriz */
    v = (double **) calloc (m, sizeof(double *));
    if (v == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
    }
    /* aloca as colunas da matriz */
    for (int i = 0; i < m; i++ ) {
        v[i] = (double*) calloc (n, sizeof(double));
        if (v[i] == NULL) {
            printf ("** Erro: Memoria Insuficiente **");
            return (NULL);
        }
    }
    return (v);
}

double* MatrizDoubleCont(int m, int n){
    double *v;
    if (m < 1 || n < 1) {
        printf ("** Erro: Parametro invalido **\n");
        return (NULL);
    }
    /* aloca as linhas da matriz */
    v = (double *) calloc (m*n, sizeof(double));
    if (v == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
    }
    return (v);
}

void leMatrizDouble(double** matriz1, double* matriz2, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%lf", &matriz1[i][j]);
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int k=0;
            k = (i * n) + j;
            scanf("%lf", &matriz2[k]);
        }
    }
}

void liberaMatrizesDouble(double** matriz1, double* matriz2, int m){
    for(int i=0;i<m ;i++){
        free(matriz1[i]);
    }
    free(matriz1);
    free(matriz2);
}

int** Alocar_matriz_inteiro(int m, int n){
    int **v;
    if (m < 1 || n < 1) {
        printf ("** Erro: Parametro invalido **\n");
        return (NULL);
    }
    /* aloca as linhas da matriz */
    v = (int **) calloc (m, sizeof(int *));
    if (v == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
    }
    /* aloca as colunas da matriz */
    for (int i = 0; i < m; i++ ) {
        v[i] = (int*) calloc (n, sizeof(int));
        if (v[i] == NULL) {
            printf ("** Erro: Memoria Insuficiente **");
            return (NULL);
        }
    }
    return (v);
}

int* MatrizIntCont(int m, int n){
    int *v;
    if (m < 1 || n < 1) {
        printf ("** Erro: Parametro invalido **\n");
        return (NULL);
    }
    /* aloca as linhas da matriz */
    v = (int *) calloc (m*n, sizeof(int));
    if (v == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
    }
    return (v);
}

void leMatrizInt(int** matriz1, int* matriz2, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matriz1[i][j]);
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int k=0;
            k = (i * n) + j;
            scanf("%d", &matriz2[k]);
        }
    }
}

void liberaMatrizesInt(int** matriz1, int* matriz2, int m){
    for(int i=0;i<m ;i++){
        free(matriz1[i]);
    }
    free(matriz1);
    free(matriz2);
}