#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"

int main(){
    Complexo_t *p, *q;

    bool x;
    x = Construtor(&p);
    if(x == false){
        printf("Memoria nao foi alocada.\n");
        exit(1);
    }
    x = Construtor(&q);
    if(x == false){
        printf("Memoria nao foi alocada.\n");
        exit(1);
    }

    PreencheComplexoDeReais(p, 1, 2);
    PreencheComplexoDeReais(q, 2, 3);
    SomaComplexos(p, q);

    x = Destrutor(&q);
    if(x == false){
        printf("Memoria nao foi liberada corretamente.\n");
    }
    x = Construtor(&q);
    if(x == false){
        printf("Memoria nao foi liberada corretamente.\n");
    }

    return 0;
}