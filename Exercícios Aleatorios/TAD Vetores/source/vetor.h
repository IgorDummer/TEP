#ifndef TEP1_VETOR_H
#define TEP1_VETOR_H

typedef struct Vetor_s Vetor_t;
Vetor_t* ConstroiVetor(unsigned int);
void PreencheVetor(Vetor_t*);
int somaVetor(Vetor_t*);
//double somaVetor(Vetor_t*);
Vetor_t* somaVetores(Vetor_t*, Vetor_t*);
void exibeVetor(Vetor_t*);
int ProdutoInterno(Vetor_t*, Vetor_t*);
//double ProdutoInterno(Vetor_t*, Vetor_t*);
void liberaVetor(Vetor_t*);
void DestroiVetores(Vetor_t*, Vetor_t*, Vetor_t*);
void PreencheEOpera(Vetor_t*, Vetor_t*);

#endif //TEP1_VETOR_H
