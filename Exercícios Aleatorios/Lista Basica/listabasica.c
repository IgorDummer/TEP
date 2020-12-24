//Igor Wandermurem Dummer - 2019109389
//Tentei criar uma lista basica mas, por conta de falta de pratica, nao consegui
#include"listabasica.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* lista basica */
static void List_set (CelulaListaBasica_t * prim, CelulaListaBasica_t * ult);
static void List_get (CelulaListaBasica_t * prim, CelulaListaBasica_t * ult);

/* celula lista basica */
static void Cel_set (CelulaListaBasica_t const * prox, void* valor);
static void Cel_get (CelulaListaBasica_t const * prox, void* valor);

/*----------------------------------------------------------------------------------------------------------*/
void List_Construtor(ListaBasica_t* lista){
    static struct ListaBasicaVtbl const vtbl{
        &List_set, &List_get;
    };
    lista->prim_noh = lista->ult_noh = NULL;
}

void List_Insere(ListaBasica_t* lista, void* valor){
    static struct CelulaListaBasicaVtbl const vtbl{
            &Cel_set, &Cel_get; //problema aqui, nao ta alocando a memoria
    };
    CelulaListaBasica_t* nova;
    nova->pt_valor = valor;
    nova->prox = lista->prim_noh;
    lista->prim_noh = nova;

    if (lista->ult_noh == NULL){
        lista->ult_noh = nova;
    }
}

void List_Apresenta(ListaBasica_t* lista){
    static struct CelulaListaBasicaVtbl const vtbl{
            &Cel_set, &Cel_get; //problema aqui, nao ta alocando a memoria
    };
    CelulaListaBasica_t* p;
    for (p = lista->prim_noh; p != NULL; p = p->prox)
    {
        //??
    }
}

void* Lista_Retira(ListaBasica_t* lista, void* valor){
    CelulaListaBasica_t * p = lista->prim_noh;
    CelulaListaBasica_t * ant;

    for(int i=0;  p!= NULL && i != valor; i++){ //n da pra comparar pq eh void
        ant = p;
        p = p->prox;
    }

    //lista vazia ou não encontrou o matriz
    if (p == NULL)
        return NULL;

    //se for uma unica matriz
    if (p == lista->prim_noh && p == lista->ult_noh){ //Lista fica vazia
        lista->prim_noh = lista->ult_noh = NULL;
    }
    else if (p == lista->prim_noh ){
        lista->prim_noh = p->prox; //se for a primeira
    }
    else if (p == lista->ult_noh){ //se for a ultima
        lista->ult_noh = ant;
        lista->ult_noh->prox = NULL; //ou ant->prox = NULL
    }
    else{ //caso comum
        ant->prox = p->prox;
    }

    free(p); //Libera a celula
}

void List_Destroi(ListaBasica_t* lista){
    CelulaListaBasica_t * p = lista->prim_noh;
    CelulaListaBasica_t * t;
    while (p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }
    free(lista);
}