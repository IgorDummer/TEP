/* Igor Wandermurem Dummer
 * Matricula: 2019109389 */
#include "complexo.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Obs: Eu quis fazer de forma opaca, mas por algum motivo, quando
 * deixo a struct no .h, somente variaveis do tipo ponteiro funcionam
 * na main. (Todas as variaveis teriam que ser ponteiros)
struct complexo{
    double real;
    double imaginario;
};*/

void CrieNumeroComplexo (complexo_t** complexo) {
    *complexo = (complexo_t*) malloc(sizeof (complexo_t));
    if(complexo == NULL){
        printf("Erro: Falta de memoria para alocacao.\nEncerrando o programa.\n");
        exit(1);
    }
}

void CrieVetorComplexo(complexo_t** vetor, int tamanho){
    *vetor = (complexo_t*) malloc (tamanho * sizeof(complexo_t));
    if(vetor == NULL){
        printf("Erro: Falta de memoria para alocacao.\nEncerrando o programa.\n");
        exit(1);
    }
}

void InicializaComplexo(complexo_t* num){
    num->imaginario = 0;
    num->real = 0;
}

void PreencheComplexoDeReais(complexo_t* numero, double real, double imaginario){
    numero->real = real;
    numero->imaginario = imaginario;
}

/* num1 = a + bi
 * num2 = c + di
 * num1 + num2 = (a + c) + (b + d)i
 * soma (real) = (a + c)
 * soma (imaginario) = (b + d)i           */
complexo_t SomaComplexos(complexo_t* num1, complexo_t* num2){
    complexo_t soma;
    InicializaComplexo(&soma);

    soma.real = num1->real + num2->real; /* (a + c) */
    soma.imaginario = num1->imaginario + num2->imaginario; /* (b + d)i */

    return soma;
}

/* num1 = a + bi
 * num2 = c + di
 * num1 * num2 = (a*c - b*d) + (a*d + b*c)i
 * produto (real) = (a*c - b*d)
 * produto (imaginario) = (a*d + b*c)i   */
complexo_t ProdutoComplexos(complexo_t* num1, complexo_t* num2){
    complexo_t produto;
    InicializaComplexo(&produto);

    produto.real = ((num1->real * num2->real) - (num1->imaginario * num2->imaginario)); /* (a * c - b * d) */
    produto.imaginario = ((num1->real * num2->imaginario) + (num1->imaginario * num2->real)); /* (a * d + b * c)i */

    return produto;
}

/* num1 = a + bi
 * num2 = c + di
 * num1 - num2 = (a - c) + (b - d)i
 * subtração (real) = (a - c)
 * subtração (imaginario) = (b - d)i     */
complexo_t SubtracaoComplexos(complexo_t* num1, complexo_t* num2){
    complexo_t subtracao;
    InicializaComplexo(&subtracao);

    subtracao.real = num1->real - num2->real; /* (a - c) */
    subtracao.imaginario = num1->imaginario - num2->imaginario; /* (b - d)i */

    return subtracao;
}

/* num1 = a + bi
 * num2 = c + di
 * num1 - num2 = (((a * c) + (b * d))/c²+d²) + ((((c * b) + (a * d))i)/c²+d²)
 * divisao (real) = ((a * c) + (b * d))/c²+d²
 * divisao (imaginario) = (((c * b) + (a * d))i)/c²+d²  */
complexo_t DivisaoComplexos(complexo_t* num1, complexo_t* num2){
    complexo_t divisao;
    InicializaComplexo(&divisao);
    /* Variavel auxiliar para armazenar o divisor da formula */
    double divisor = 0;

    if(num2->real == 0 && num2->imaginario == 0){
        printf("Erro: Nao eh possivel dividir por 0.\nEncerrando o programa.\n");
        exit (1);
    }

    divisor = ((num2->real*num2->real) + (num2->imaginario*num2->imaginario)); /* c² + d² */
    divisao.real = ((num1->real * num2->real) + (num1->imaginario * num2->imaginario)) / divisor; /* ((a * c) + (b * d))/c²+d² */
    divisao.imaginario = ((num2->real * num1->imaginario) + (num1->real * num2->imaginario)) / divisor; /* (((c * b) + (a * d))i)/c²+d²  */

    return divisao;
}

/* num = a + bi
 * modulo = sqrt(a²+b²) */
long double ModuloComplexo(complexo_t* num){
    long double modulo = 0;
    modulo = sqrt((pow(num->real,2))+(pow(num->imaginario,2))); /* sqrt(a²+b²) */

    return modulo;
}

complexo_t ProdutoInternoVetComplexo(complexo_t *vet1, complexo_t* vet2, int tamanho){
    complexo_t produto, auxiliar;
    InicializaComplexo(&auxiliar);
    InicializaComplexo(&produto);

    for(int i=0; i < tamanho; i++){
        auxiliar = ProdutoComplexos(&vet1[i], &vet2[i]); /* aux = vet1[i] + vet2[i] */
        produto = SomaComplexos(&auxiliar, &produto); /* produto = produto + auxiliar -> Soma pra nao perder o valor */
    }

    return produto;
}

complexo_t SomaElementosVetComplexo(complexo_t *vet, int tamanho){
    complexo_t somatorio;
    InicializaComplexo(&somatorio);

    for(int i=0; i < tamanho; i++){
        somatorio = SomaComplexos(&somatorio, &vet[i]); /* somatorio = somatorio + vet[i] */
    }

    return somatorio;
}

void ApresentaComplexo(complexo_t num, char* string){
    printf("%s", string);
    
    if(num.imaginario < 0){
        printf("%.2lf - %.2lfi\n", num.real, num.imaginario*(-1));
        return;
    }
    printf("%.2lf + %.2lfi\n", num.real, num.imaginario);
}

void LiberaComplexo(complexo_t** numero){
    free(*numero);
}
