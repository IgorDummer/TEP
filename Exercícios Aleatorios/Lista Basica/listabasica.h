//Igor Wandermurem Dummer - 2019109389
#ifndef _LISTABASICA_H
#define _LISTABASICA_H

typedef struct CelulaListaBasicaVtbl CelulaListaBasica_t;

struct CelulaListaBasicaVtbl{
    struct CelulaListaBasicaVtbl const *prox;
    void* pt_valor;
};

struct ListaBasicaVtbl;

typedef struct{
    CelulaListaBasica_t *prim_noh;
    CelulaListaBasica_t *ult_noh;
}ListaBasica_t;

/* ----- Tabela de funções virtuais da Lista ------- */

struct ListaBasicaVtbl{
    void (* set) (struct CelulaListaBasicaVtbl * prim, struct CelulaListaBasicaVtbl * ult);
    void (* get) (struct CelulaListaBasicaVtbl * prim, struct CelulaListaBasicaVtbl * ult);
};

/* -------------- Operações da Lista -------------- */

void List_Construtor(ListaBasica_t* lista);

void List_Insere(ListaBasica_t* lista, void* valor);

void* Lista_Retira(ListaBasica_t* lista, void* valor);

void List_Apresenta(ListaBasica_t* lista);

void List_Destroi(ListaBasica_t* lista);


#endif //_LISTAMAT_H
