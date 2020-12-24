//Igor Wandermurem Dummer - 2019109389
#include "listaMat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula{
    int valor;
    int coluna;
    int linha;
    Celula *prox;
};

struct lista{
    Celula *prim;
    Celula *ult;
};

Lista *iniciaLista(void){
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void imprimeLista(Lista *lista){
    Celula *p;
    for (p = lista->prim; p != NULL; p = p->prox)
    {
        printf("| Valor:%-2d| Linha: %-2d| Coluna: %-2d|\n", p->valor, p->linha, p->coluna);
    }
}

void insereLista(Lista *lista, int valor, int linha, int coluna){
    if(valor != 0){
        Celula *nova = (Celula *) malloc(sizeof(Celula));
        nova->valor = valor;
        nova->coluna = coluna;
        nova->linha = linha;
        nova->prox = lista->prim;
        lista->prim = nova;

        if (lista->ult == NULL) {
            lista->ult = nova;
        }
    }
}

void destroiLista(Lista *lista){
    Celula* p = lista->prim;
    Celula* t;
    while (p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }
    free(lista);
}