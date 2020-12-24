/* Igor Wandermurem Dummer
 * Matricula: 2019109389 */
#ifndef COMPLEXO_H
#define COMPLEXO_H


struct complexo{
    double real;
    double imaginario;
};

typedef struct complexo complexo_t;

void CrieNumeroComplexo (complexo_t** p);

void CrieVetorComplexo(complexo_t** vetor, int tamanho);

void InicializaComplexo(complexo_t* num);

void PreencheComplexoDeReais(complexo_t* numero, double real, double imaginario);

complexo_t SomaComplexos(complexo_t* num1, complexo_t* num2);

complexo_t ProdutoComplexos(complexo_t* num1, complexo_t* num2);

complexo_t SubtracaoComplexos(complexo_t* num1, complexo_t* num2);

complexo_t DivisaoComplexos(complexo_t* num1, complexo_t* num2);

long double ModuloComplexo(complexo_t* num);

complexo_t ProdutoInternoVetComplexo(complexo_t *vet1, complexo_t* vet2, int num);

complexo_t SomaElementosVetComplexo(complexo_t *vet, int tamanho);

void ApresentaComplexo(complexo_t num, char* string);

void LiberaComplexo(complexo_t** numero);

#endif //COMPLEXO_H
