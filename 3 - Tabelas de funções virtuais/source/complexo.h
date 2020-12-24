#ifndef COMPLEXO_H
#define COMPLEXO_H
#include <stdbool.h>

/* typedef enum bool {false=0; true=1;} bool; */

struct complexoVtbl;

typedef struct complexo{
    double real;
    double imaginario;
}Complexo_t;

struct complexoVtbl{
    bool (*Construtor) (Complexo_t** complexo);
    bool (*Destrutor)  (Complexo_t* complexo);
};

bool Construtor(Complexo_t** complexo);

bool Destrutor(Complexo_t** complexo);

Complexo_t* CopiaComplexo(Complexo_t* complexo, Complexo_t* new);

Complexo_t* ConverteComplexo(Complexo_t* me, Complexo_t* outro);

Complexo_t SomaComplexos(Complexo_t* num1, Complexo_t* num2);

long double ModuloComplexo(Complexo_t* num);

void CrieVetorComplexo(Complexo_t** vetor, int tamanho);

void InicializaComplexo(Complexo_t* num);

void PreencheComplexoDeReais(Complexo_t* numero, double real, double imaginario);

Complexo_t ProdutoComplexos(Complexo_t* num1, Complexo_t* num2);

Complexo_t SubtracaoComplexos(Complexo_t* num1, Complexo_t* num2);

Complexo_t DivisaoComplexos(Complexo_t* num1, Complexo_t* num2);

Complexo_t ProdutoInternoVetComplexo(Complexo_t *vet1, Complexo_t* vet2, int num);

Complexo_t SomaElementosVetComplexo(Complexo_t *vet, int tamanho);

void ApresentaComplexo(Complexo_t num, char* string);

void LiberaComplexo(Complexo_t** numero);

#endif //COMPLEXO_H
