#ifndef TEP2_MATRIZ_H
#define TEP2_MATRIZ_H

float** Alocar_matriz_real(int, int);
float* MatrizRealCont(int, int);
void leMatrizFloat(float**, float*, int, int);
void liberaMatrizesFloat(float**, float*, int);
char*** Alocar_matriz_string(int, int);
char** MatrizStringCont(int, int);
char* leString(void);
void leMatrizString(char***, char**, int, int);
void liberaMatrizesString(char***, char**, int);
double** Alocar_matriz_double(int, int);
double* MatrizDoubleCont(int, int);
void leMatrizDouble(double**, double*, int, int);
void liberaMatrizesDouble(double**, double*, int);
int** Alocar_matriz_inteiro(int, int);
int* MatrizIntCont(int, int);
void leMatrizInt(int**, int*, int, int);
void liberaMatrizesInt(int**, int*, int);

#endif //TEP2_MATRIZ_H
