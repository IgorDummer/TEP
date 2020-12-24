//Igor Wandermurem Dummer - 2019109389
#ifndef _LISTAMAT_H
#define _LISTAMAT_H

#include "matriz.h"

typedef struct lista Lista;

Lista *iniciaLista();

void insereLista(Lista *lista, int valor, int linha, int coluna);

void imprimeLista(Lista *lista);

void destroiLista(Lista *lista);

#endif //_LISTAMAT_H
