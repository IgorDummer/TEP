#ifndef POLINOMIO_H
#define POLINOMIO_H
#include "complex.h"

void imprimePolinomio(double complex* polinomio, int tam);

double complex calculaPolinomioGrau2(double complex* polinomio, double complex x);
double complex calculaPolinomioGrau3(double complex* polinomio, double complex x);
double complex calculaPolinomioGrau4(double complex* polinomio, double complex x);
double complex calculaPolinomioGrau5(double complex* polinomio, double complex x);
double complex calculaPolinomioGrau6(double complex* polinomio, double complex x);
double complex calculaPolinomioGrau7(double complex* polinomio, double complex x);
double complex calculaPolinomioGrau8(double complex* polinomio, double complex x);
double complex calculaPolinomioGrau9(double complex* polinomio, double complex x);

void Grau2(double complex* polinomio);
void Grau3(double complex* polinomio);
void Grau4(double complex* polinomio);
void Grau5(double complex* polinomio);
void Grau6(double complex* polinomio);
void Grau7(double complex* polinomio);
void Grau8(double complex* polinomio);
void Grau9(double complex* polinomio);

void DurandKerner(double complex* polinomio, int grau);

#endif //POLINOMIO_H
