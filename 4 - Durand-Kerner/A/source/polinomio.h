#ifndef POLINOMIO_H
#define POLINOMIO_H
#include "complex.h"

void imprimePolinomio(double complex* polinomio, int tam);

double complex calculaPolinomio(double complex* polinomio, double complex x);

void DurandKerner(double complex* polinomio);

#endif //POLINOMIO_H
