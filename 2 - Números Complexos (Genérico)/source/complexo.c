/* Igor Wandermurem Dummer
 * Matricula: 2019109389 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#ifdef TIPO_
#ifdef TIPADO_

void TIPADO_(CrieNumeroComplexo) (TIPADO_(complexo_t) **complexo) {
    *complexo = (TIPADO_(complexo_t)*) malloc(sizeof (TIPADO_(complexo_t)));
    if(complexo == NULL){
        printf("Erro: Falta de memoria para alocacao.\nEncerrando o programa.\n");
        exit(1);
    }
}

void TIPADO_(CrieVetorComplexo) (TIPADO_(complexo_t) **vetor, int tamanho){
    *vetor = (TIPADO_(complexo_t) *) malloc(tamanho * sizeof (TIPADO_(complexo_t)));
    if(vetor == NULL){
        printf("Erro: Falta de memoria para alocacao.\nEncerrando o programa.\n");
        exit(1);
    }
}

void TIPADO_(InicializaComplexo) (TIPADO_(complexo_t) *num){
    num->imaginario = 0;
    num->real = 0;
}

void TIPADO_(PreencheComplexoDeReais) (TIPADO_(complexo_t) *numero, TIPO_ real, TIPO_ imaginario){
    numero->real = real;
    numero->imaginario = imaginario;
}

/* num1 = a + bi
 * num2 = c + di
 * num1 + num2 = (a + c) + (b + d)i
 * soma (real) = (a + c)
 * soma (imaginario) = (b + d)i           */
TIPADO_(complexo_t) TIPADO_(SomaComplexos) (TIPADO_(complexo_t) *num1, TIPADO_(complexo_t) *num2){
    TIPADO_(complexo_t) soma;
    TIPADO_(InicializaComplexo)(&soma);

    soma.real = num1->real + num2->real; /* (a + c) */
    soma.imaginario = num1->imaginario + num2->imaginario; /* (b + d)i */

    return soma;
}

/* num1 = a + bi
 * num2 = c + di
 * num1 * num2 = (a*c - b*d) + (a*d + b*c)i
 * produto (real) = (a*c - b*d)
 * produto (imaginario) = (a*d + b*c)i   */
TIPADO_(complexo_t) TIPADO_(ProdutoComplexos) (TIPADO_(complexo_t) *num1, TIPADO_(complexo_t) *num2){
    TIPADO_(complexo_t) produto;
    TIPADO_(InicializaComplexo)(&produto);

    produto.real = ((num1->real * num2->real) - (num1->imaginario * num2->imaginario)); /* (a * c - b * d) */
    produto.imaginario = ((num1->real * num2->imaginario) + (num1->imaginario * num2->real)); /* (a * d + b * c)i */

    return produto;
}

/* num1 = a + bi
 * num2 = c + di
 * num1 - num2 = (a - c) + (b - d)i
 * subtração (real) = (a - c)
 * subtração (imaginario) = (b - d)i     */
TIPADO_(complexo_t) TIPADO_(SubtracaoComplexos)(TIPADO_(complexo_t) *num1, TIPADO_(complexo_t) *num2){
    TIPADO_(complexo_t) subtracao;
    TIPADO_(InicializaComplexo)(&subtracao);

    subtracao.real = num1->real - num2->real; /* (a - c) */
    subtracao.imaginario = num1->imaginario - num2->imaginario; /* (b - d)i */

    return subtracao;
}

/* num1 = a + bi
 * num2 = c + di
 * num1 - num2 = (((a * c) + (b * d))/c²+d²) + ((((c * b) + (a * d))i)/c²+d²)
 * divisao (real) = ((a * c) + (b * d))/c²+d²
 * divisao (imaginario) = (((c * b) + (a * d))i)/c²+d²  */
TIPADO_(complexo_t) TIPADO_(DivisaoComplexos)(TIPADO_(complexo_t) *num1, TIPADO_(complexo_t) *num2){
    TIPADO_(complexo_t) divisao;
    TIPADO_(InicializaComplexo)(&divisao);
    /* Variavel auxiliar para armazenar o divisor da formula */
    TIPO_ divisor = 0;

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
TIPO_ TIPADO_(ModuloComplexo)(TIPADO_(complexo_t) *num){
    TIPO_ modulo = 0;
    modulo = sqrt((pow(num->real,2))+(pow(num->imaginario,2))); /* sqrt(a²+b²) */

    return modulo;
}

TIPADO_(complexo_t) TIPADO_(ProdutoInternoVetComplexo)(TIPADO_(complexo_t) *vet1, TIPADO_(complexo_t) *vet2, int tamanho){
    TIPADO_(complexo_t) produto, auxiliar;
    TIPADO_(InicializaComplexo)(&auxiliar);
    TIPADO_(InicializaComplexo)(&produto);

    for(int i=0; i < tamanho; i++){
        auxiliar = TIPADO_(ProdutoComplexos)(&vet1[i], &vet2[i]); /* aux = vet1[i] + vet2[i] */
        produto = TIPADO_(SomaComplexos)(&auxiliar, &produto); /* produto = produto + auxiliar -> Soma pra nao perder o valor */
    }

    return produto;
}

TIPADO_(complexo_t) TIPADO_(SomaElementosVetComplexo)(TIPADO_(complexo_t) *vet, int tamanho){
    TIPADO_(complexo_t) somatorio;
    TIPADO_(InicializaComplexo)(&somatorio);

    for(int i=0; i < tamanho; i++){
        somatorio = TIPADO_(SomaComplexos)(&somatorio, &vet[i]); /* somatorio = somatorio + vet[i] */
    }

    return somatorio;
}

void TIPADO_(ApresentaComplexo)(TIPADO_(complexo_t) num, char* string){
    char formato[20];
    strcpy(formato,"");
    strcat(formato, " %");
    strcat(formato, "s");
    strcat(formato, " %");
    strcat(formato, FORMAT_);
    if ((num.imaginario) >= 0 ){
        strcat(formato, " +");
    }
    strcat(formato," %");
    strcat(formato, FORMAT_);
    strcat(formato, "i");
    strcat(formato, "\n");
    /*" %s%f - %fi" */
    printf (formato, string, num.real, num.imaginario);
}

void TIPADO_(LiberaComplexo)(TIPADO_(complexo_t) **numero){
    free(*numero);
}

#undef TIPO_
#undef TIPADO_

#endif /* TIPADO_ */
#endif /* TIPO_ */