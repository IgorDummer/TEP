#include "polinomio.h"
#include <stdio.h>
#include <math.h>

void imprimePolinomio(double complex* polinomio, int tam){
    int i;
    for(i=0; i<tam; i++){
        if(i!=0){
            if(cimag(polinomio[i]) < 0){
                printf("+ (%.2lf %+.2lf*I)*X^%d ", creal(polinomio[i]), cimag(polinomio[i]), tam-1-i);
            }
            else{
                printf("+ (%.2lf +%.2lf*I)*X^%d ", creal(polinomio[i]), cimag(polinomio[i]), tam-1-i);
            }
        }
        else{
            if(cimag(polinomio[i]) < 0){
                printf("(%.2lf %.2lf*I)*X^%d ", creal(polinomio[i]), cimag(polinomio[i]), tam-1-i);
            }
            else{
                printf("(%.2lf +%.2lf*I)*X^%d ", creal(polinomio[i]), cimag(polinomio[i]), tam-1-i);
            }
        }
    }
    printf("\n");
}

double complex calculaPolinomio(double complex* polinomio, double complex x){
    double complex resultado;
    double complex a0, a1, a2, a3, a4;

    a0 = polinomio[4];
    a1 = polinomio[3];
    a2 = polinomio[2];
    a3 = polinomio[1];
    a4 = polinomio[0];

    /*resultado = a4 * cpow (x,4.0) +
                a3 * cpow (x,3.0) +
                a2 * cpow (x,2.0) +
                a1 * cpow (x,1.0) +
                a0;*/

    resultado =   ((((((a4 * x) + a3) * x) + a2) * x)+ a1) * x + a0 ;
    return resultado;
}

/* Durand Kerner de grau 4 */
void DurandKerner(double complex* polinomio){
    double complex p_novo, q_novo, r_novo, s_novo,
                    p_velho, q_velho, r_velho, s_velho;

    p_velho = cpow(0.4 + 0.9 * I,0);
    q_velho = cpow(0.4 + 0.9 * I,1);
    r_velho = cpow(0.4 + 0.9 * I,2);
    s_velho = cpow(0.4 + 0.9 * I,3);

    int iteracao;
    for (iteracao = 0; iteracao < 10; iteracao++)
    {
        p_novo = p_velho - (calculaPolinomio(polinomio, p_velho))
                           /((p_velho - q_velho) *
                             (p_velho - r_velho) * (p_velho - s_velho));

        q_novo = q_velho - (calculaPolinomio(polinomio, q_velho))
                           /((q_velho - p_novo) *
                             (q_velho - r_velho) * (q_velho - s_velho));

        r_novo = r_velho - (calculaPolinomio(polinomio, r_velho))
                           /((r_velho - p_novo) *
                             (r_velho - q_novo) * (r_velho - s_velho));

        s_novo = s_velho - (calculaPolinomio(polinomio, s_velho))
                            /((s_velho - p_novo) *
                            (s_velho - q_novo) * (s_velho - r_velho));


        printf("p  = %.3f%+.3fi\n", creal(p_novo), cimag(p_novo));
        printf("q  = %.3f%+.3fi\n", creal(q_novo), cimag(q_novo));
        printf("r  = %.3f%+.3fi\n", creal(r_novo), cimag(r_novo));
        printf("s  = %.3f%+.3fi\n\n", creal(s_novo), cimag(s_novo));

        p_velho = p_novo;
        q_velho = q_novo;
        r_velho = r_novo;
        s_velho = s_novo;
    }
}