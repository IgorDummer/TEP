/* Igor Wandermurem Dummer
 * Matricula: 2019109389 */
#ifdef TIPO_
#ifdef TIPADO_

struct TIPADO_(complexo){
    TIPO_ real;
    TIPO_ imaginario;
};

typedef struct TIPADO_(complexo) TIPADO_(complexo_t);

void TIPADO_(CrieNumeroComplexo) (TIPADO_(complexo_t) **complexo);

void TIPADO_(CrieVetorComplexo) (TIPADO_(complexo_t) **vetor, int tamanho);

void TIPADO_(InicializaComplexo) (TIPADO_(complexo_t) *num);

void TIPADO_(PreencheComplexoDeReais) (TIPADO_(complexo_t) *numero, TIPO_ real, TIPO_ imaginario);

TIPADO_(complexo_t) TIPADO_(SomaComplexos) (TIPADO_(complexo_t) *num1, TIPADO_(complexo_t) *num2);

TIPADO_(complexo_t) TIPADO_(ProdutoComplexos) (TIPADO_(complexo_t) *num1, TIPADO_(complexo_t) *num2);

TIPADO_(complexo_t) TIPADO_(SubtracaoComplexos)(TIPADO_(complexo_t) *num1, TIPADO_(complexo_t) *num2);

TIPADO_(complexo_t) TIPADO_(DivisaoComplexos)(TIPADO_(complexo_t) *num1, TIPADO_(complexo_t) *num2);

TIPO_ TIPADO_(ModuloComplexo)(TIPADO_(complexo_t) *num);

TIPADO_(complexo_t) TIPADO_(ProdutoInternoVetComplexo)(TIPADO_(complexo_t) *vet1, TIPADO_(complexo_t) *vet2, int tamanho);

TIPADO_(complexo_t) TIPADO_(SomaElementosVetComplexo)(TIPADO_(complexo_t) *vet, int tamanho);

void TIPADO_(ApresentaComplexo)(TIPADO_(complexo_t) num, char* string);

void TIPADO_(LiberaComplexo)(TIPADO_(complexo_t)** numero);

#undef TIPADO_
#undef TIPO_

#endif /* TIPADO_ */
#endif /* TIPO_ */
