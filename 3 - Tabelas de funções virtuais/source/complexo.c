#include "complexo.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define typeof(var) _Generic( (var),\
double: "Double",\
long double: "Long Double",\
default: "Undefined")

bool Construtor(Complexo_t** complexo){
    assert(0);
    *complexo = (Complexo_t*) malloc(sizeof (Complexo_t));
    if(complexo == NULL){
        printf("Erro: Falta de memoria para alocacao.\n");
        return false;
    }
    return true;
}

bool Destrutor(Complexo_t** complexo){
    assert(0);
    free(*complexo);
    if(complexo == NULL){
        return true;
    }
    return false;
}

Complexo_t* CopiaComplexo(Complexo_t* complexo, Complexo_t* new){
    if(new != NULL){
        bool x = Destrutor(&new);
        if(x == false){
            printf("A memoria nao foi liberada com exito.\nEncerrando o programa.\n");
            exit(1);
        }
    }
    Construtor(&new);
    new->imaginario = complexo->imaginario;
    new->real = complexo->real;

    return new;
}

Complexo_t* ConverteComplexo(Complexo_t* me, Complexo_t* outro){
    if(outro != NULL){
        bool x = Destrutor(outro);
        if(x == false){
            printf("A memoria nao foi liberada com exito.\nEncerrando o programa.\n");
            exit(1);
        }
    }
    if(strcmp(typeof(me->real), "Double") == 0){
        outro->real = (long double)me->real;
        outro->imaginario = (long double)me->imaginario;
    }
    else if (strcmp(typeof(me->real), "Long Double") == 0){
        outro->real = (double)me->real;
        outro->imaginario = (double)me->imaginario;
    }
    else{
        printf("Tipo de dados nao eh long double nem double.\nEncerrando o programa\n");
        exit(1);
    }
    return outro;
}

/* num1 = a + bi
 * num2 = c + di
 * num1 + num2 = (a + c) + (b + d)i
 * soma (real) = (a + c)
 * soma (imaginario) = (b + d)i           */
Complexo_t SomaComplexos(Complexo_t* num1, Complexo_t* num2){
    Complexo_t soma;
    InicializaComplexo(&soma);

    soma.real = num1->real + num2->real; /* (a + c) */
    soma.imaginario = num1->imaginario + num2->imaginario; /* (b + d)i */

    return soma;
}

/* num = a + bi
 * modulo = sqrt(a²+b²) */
long double ModuloComplexo(Complexo_t* num){
    long double modulo = 0;
    modulo = sqrt((pow(num->real,2))+(pow(num->imaginario,2))); /* sqrt(a²+b²) */

    return modulo;
}

void PreencheComplexoDeReais(Complexo_t* numero, double real, double imaginario){
    numero->real = real;
    numero->imaginario = imaginario;
}

void InicializaComplexo(Complexo_t* num){
    num->imaginario = 0;
    num->real = 0;
}

void CrieVetorComplexo(Complexo_t** vetor, int tamanho){
    *vetor = (Complexo_t*) malloc (tamanho * sizeof(Complexo_t));
    if(vetor == NULL){
        printf("Erro: Falta de memoria para alocacao.\nEncerrando o programa.\n");
        exit(1);
    }
}

/* num1 = a + bi
 * num2 = c + di
 * num1 * num2 = (a*c - b*d) + (a*d + b*c)i
 * produto (real) = (a*c - b*d)
 * produto (imaginario) = (a*d + b*c)i   */
Complexo_t ProdutoComplexos(Complexo_t* num1, Complexo_t* num2){
    Complexo_t produto;
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
Complexo_t SubtracaoComplexos(Complexo_t* num1, Complexo_t* num2){
    Complexo_t subtracao;
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
Complexo_t DivisaoComplexos(Complexo_t* num1, Complexo_t* num2){
    Complexo_t divisao;
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

Complexo_t ProdutoInternoVetComplexo(Complexo_t *vet1, Complexo_t* vet2, int tamanho){
    Complexo_t produto, auxiliar;
    InicializaComplexo(&auxiliar);
    InicializaComplexo(&produto);

    for(int i=0; i < tamanho; i++){
        auxiliar = ProdutoComplexos(&vet1[i], &vet2[i]); /* aux = vet1[i] + vet2[i] */
        produto = SomaComplexos(&auxiliar, &produto); /* produto = produto + auxiliar -> Soma pra nao perder o valor */
    }

    return produto;
}

Complexo_t SomaElementosVetComplexo(Complexo_t *vet, int tamanho){
    Complexo_t somatorio;
    InicializaComplexo(&somatorio);

    for(int i=0; i < tamanho; i++){
        somatorio = SomaComplexos(&somatorio, &vet[i]); /* somatorio = somatorio + vet[i] */
    }

    return somatorio;
}

void ApresentaComplexo(Complexo_t num, char* string){
    printf("%s", string);
    if(num.imaginario < 0){
        printf("%.2lf - %.2lfi\n", num.real, num.imaginario*(-1));
        return;
    }
    printf("%.2lf + %.2lfi\n", num.real, num.imaginario);
}

void LiberaComplexo(Complexo_t** numero){
    free(*numero);
}