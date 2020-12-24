#include "polinomio.h"
#include <stdio.h>
#include <stdlib.h>

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
double complex calculaPolinomioGrau2(double complex* polinomio, double complex x){
    double complex resultado;
    double complex a0, a1, a2;

    a0 = polinomio[2];
    a1 = polinomio[1];
    a2 = polinomio[0];


    resultado = (((x* a2) * x)+ a1) * x + a0 ;
    return resultado;
}
double complex calculaPolinomioGrau3(double complex* polinomio, double complex x){
    double complex resultado;
    double complex a0, a1, a2, a3;

    a0 = polinomio[3];
    a1 = polinomio[2];
    a2 = polinomio[1];
    a3 = polinomio[0];

    resultado = (((((x * a3) * x) + a2) * x)+ a1) * x + a0 ;
    return resultado;
}
double complex calculaPolinomioGrau4(double complex* polinomio, double complex x){
    double complex resultado;
    double complex a0, a1, a2, a3, a4;

    a0 = polinomio[4];
    a1 = polinomio[3];
    a2 = polinomio[2];
    a3 = polinomio[1];
    a4 = polinomio[0];

    resultado = ((((((a4 * x) + a3) * x) + a2) * x)+ a1) * x + a0 ;
    return resultado;
}
double complex calculaPolinomioGrau5(double complex* polinomio, double complex x){
    double complex resultado;
    double complex a0, a1, a2, a3, a4, a5;

    a0 = polinomio[5];
    a1 = polinomio[4];
    a2 = polinomio[3];
    a3 = polinomio[2];
    a4 = polinomio[1];
    a5 = polinomio[0];

    resultado = ((((((((a5 * x)+a4)* x) + a3) * x) + a2) * x)+ a1) * x + a0 ;
    return resultado;
}
double complex calculaPolinomioGrau6(double complex* polinomio, double complex x){
    double complex resultado;
    double complex a0, a1, a2, a3, a4, a5, a6;

    a0 = polinomio[6];
    a1 = polinomio[5];
    a2 = polinomio[4];
    a3 = polinomio[3];
    a4 = polinomio[2];
    a5 = polinomio[1];
    a6 = polinomio[0];

    resultado = ((((((((((a6 * x)+ a5)* x)+ a4)* x) + a3) * x) + a2) * x)+ a1) * x + a0 ;
    return resultado;
}
double complex calculaPolinomioGrau7(double complex* polinomio, double complex x){
    double complex resultado;
    double complex a0, a1, a2, a3, a4, a5, a6, a7;

    a0 = polinomio[7];
    a1 = polinomio[6];
    a2 = polinomio[5];
    a3 = polinomio[4];
    a4 = polinomio[3];
    a5 = polinomio[2];
    a6 = polinomio[1];
    a7 = polinomio[0];

    resultado =  ((((((((((((a7 * x)+ a6)* x)+ a5)* x)+ a4)* x) + a3) * x) + a2) * x)+ a1) * x + a0 ;
    return resultado;
}
double complex calculaPolinomioGrau8(double complex* polinomio, double complex x){
    double complex resultado;
    double complex a0, a1, a2, a3, a4, a5, a6, a7, a8;

    a0 = polinomio[8];
    a1 = polinomio[7];
    a2 = polinomio[6];
    a3 = polinomio[5];
    a4 = polinomio[4];
    a5 = polinomio[3];
    a6 = polinomio[2];
    a7 = polinomio[1];
    a8 = polinomio[0];

    resultado = ((((((((((((((a8 * x)+ a7)* x)+ a6)* x)+ a5)* x)+ a4)* x) + a3) * x) + a2) * x)+ a1) * x + a0 ;
    return resultado;
}
double complex calculaPolinomioGrau9(double complex* polinomio, double complex x){
    double complex resultado;
    double complex a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;

    a0 = polinomio[9];
    a1 = polinomio[8];
    a2 = polinomio[7];
    a3 = polinomio[6];
    a4 = polinomio[5];
    a5 = polinomio[4];
    a6 = polinomio[3];
    a7 = polinomio[2];
    a8 = polinomio[1];
    a9 = polinomio[0];

    resultado = ((((((((((((((((a9 * x)+ a8)* x)+ a7)* x)+ a6)* x)+ a5)* x)+ a4)* x) + a3) * x) + a2) * x)+ a1) * x + a0 ;
    return resultado;
}

void Grau2(double complex* polinomio){
    double complex r0_novo, r1_novo, r0_velho, r1_velho;

    r0_velho = cpow(0.4 + 0.9 * I,0);
    r1_velho = cpow(0.4 + 0.9 * I,1);

    int interacao;
    for (interacao = 0; interacao < 20; interacao++){
        r0_novo = r0_velho - (calculaPolinomioGrau2(polinomio, r0_velho))
                           /(r0_velho - r1_velho);
        r1_novo = r1_velho - (calculaPolinomioGrau2(polinomio, r1_velho))
                           /(r1_velho - r0_novo);

        printf("r0  = %.3f%+.3fi\n", creal(r0_novo), cimag(r0_novo));
        printf("r1  = %.3f%+.3fi\n\n", creal(r1_novo), cimag(r1_novo));

        r0_velho = r0_novo;
        r1_velho = r1_novo;
    }
}
void Grau3(double complex* polinomio){
    double complex r0_novo, r1_novo, r2_novo, r0_velho, r1_velho, r2_velho;

    r0_velho = cpow(0.4 + 0.9 * I,0);
    r1_velho = cpow(0.4 + 0.9 * I,1);
    r2_velho = cpow(0.4 + 0.9 * I,2);

    int interacao;
    for (interacao = 0; interacao < 20; interacao++){
        r0_novo = r0_velho - (calculaPolinomioGrau3(polinomio, r0_velho))
                             /((r0_velho - r1_velho) * (r0_velho - r2_velho));
        r1_novo = r1_velho - (calculaPolinomioGrau3(polinomio, r1_velho))
                             /((r1_velho - r0_novo) * (r1_velho - r2_velho));
        r2_novo = r2_velho - (calculaPolinomioGrau3(polinomio, r2_velho))
                             /((r2_velho - r0_novo) * (r2_velho - r1_novo));

        printf("r0  = %.3f%+.3fi\n", creal(r0_novo), cimag(r0_novo));
        printf("r1  = %.3f%+.3fi\n\n", creal(r1_novo), cimag(r1_novo));
        printf("r2  = %.3f%+.3fi\n\n", creal(r2_novo), cimag(r2_novo));

        r0_velho = r0_novo;
        r1_velho = r1_novo;
        r2_velho = r2_novo;
    }
}
void Grau4(double complex* polinomio){
    double complex r0_novo, r1_novo, r2_novo, r3_novo, r0_velho, r1_velho, r2_velho, r3_velho;

    r0_velho = cpow(0.4 + 0.9 * I,0);
    r1_velho = cpow(0.4 + 0.9 * I,1);
    r2_velho = cpow(0.4 + 0.9 * I,2);
    r3_velho = cpow(0.4 + 0.9 * I,3);

    int interacao;
    for (interacao = 0; interacao < 20; interacao++){
        r0_novo = r0_velho - (calculaPolinomioGrau4(polinomio, r0_velho))
                             /((r0_velho - r1_velho)*(r0_velho - r2_velho)*(r0_velho - r3_velho));
        r1_novo = r1_velho - (calculaPolinomioGrau4(polinomio, r1_velho))
                             /((r1_velho - r0_novo) * (r1_velho - r2_velho)*(r1_velho - r3_velho));
        r2_novo = r2_velho - (calculaPolinomioGrau4(polinomio, r2_velho))
                             /((r2_velho - r0_novo) * (r2_velho - r1_novo)* (r2_velho - r3_velho));
        r3_novo = r3_velho - (calculaPolinomioGrau4(polinomio, r3_velho))
                             /((r3_velho - r0_novo) * (r3_velho - r1_novo)* (r3_velho - r2_novo));

        printf("r0  = %.3f%+.3fi\n", creal(r0_novo), cimag(r0_novo));
        printf("r1  = %.3f%+.3fi\n", creal(r1_novo), cimag(r1_novo));
        printf("r2  = %.3f%+.3fi\n", creal(r2_novo), cimag(r2_novo));
        printf("r3  = %.3f%+.3fi\n\n", creal(r3_novo), cimag(r3_novo));

        r0_velho = r0_novo;
        r1_velho = r1_novo;
        r2_velho = r2_novo;
        r3_velho = r3_novo;
    }
}
void Grau5(double complex* polinomio){
    double complex r0_novo, r1_novo, r2_novo, r3_novo, r4_novo, r0_velho, r1_velho, r2_velho, r3_velho, r4_velho;

    r0_velho = cpow(0.4 + 0.9 * I,0);
    r1_velho = cpow(0.4 + 0.9 * I,1);
    r2_velho = cpow(0.4 + 0.9 * I,2);
    r3_velho = cpow(0.4 + 0.9 * I,3);
    r4_velho = cpow(0.4 + 0.9 * I,4);

    int interacao;
    for (interacao = 0; interacao < 20; interacao++){
        r0_novo = r0_velho - (calculaPolinomioGrau5(polinomio, r0_velho))
                             /((r0_velho-r1_velho)*(r0_velho-r2_velho)*(r0_velho-r3_velho)*(r0_velho-r4_velho));
        r1_novo = r1_velho - (calculaPolinomioGrau5(polinomio, r1_velho))
                             /((r1_velho - r0_novo) * (r1_velho - r2_velho)*(r1_velho - r3_velho)*(r1_velho-r4_velho));
        r2_novo = r2_velho - (calculaPolinomioGrau5(polinomio, r2_velho))
                             /((r2_velho - r0_novo) * (r2_velho - r1_novo)* (r2_velho - r3_velho)*(r2_velho-r4_velho));
        r3_novo = r3_velho - (calculaPolinomioGrau5(polinomio, r3_velho))
                             /((r3_velho - r0_novo) * (r3_velho - r1_novo)* (r3_velho - r2_novo)*(r3_velho-r4_velho));
        r4_novo = r4_velho - (calculaPolinomioGrau5(polinomio, r4_velho))
                             /((r4_velho - r0_novo) * (r4_velho - r1_novo)* (r4_velho - r2_novo)*(r4_velho-r3_novo));

        printf("r0  = %.3f%+.3fi\n", creal(r0_novo), cimag(r0_novo));
        printf("r1  = %.3f%+.3fi\n", creal(r1_novo), cimag(r1_novo));
        printf("r2  = %.3f%+.3fi\n", creal(r2_novo), cimag(r2_novo));
        printf("r3  = %.3f%+.3fi\n", creal(r3_novo), cimag(r3_novo));
        printf("r4  = %.3f%+.3fi\n\n", creal(r4_novo), cimag(r4_novo));

        r0_velho = r0_novo;
        r1_velho = r1_novo;
        r2_velho = r2_novo;
        r3_velho = r3_novo;
        r4_velho = r4_novo;
    }
}
void Grau6(double complex* polinomio){
    double complex r0_novo, r1_novo, r2_novo, r3_novo, r4_novo, r5_novo,
                    r0_velho, r1_velho, r2_velho, r3_velho, r4_velho, r5_velho;

    r0_velho = cpow(0.4 + 0.9 * I,0);
    r1_velho = cpow(0.4 + 0.9 * I,1);
    r2_velho = cpow(0.4 + 0.9 * I,2);
    r3_velho = cpow(0.4 + 0.9 * I,3);
    r4_velho = cpow(0.4 + 0.9 * I,4);
    r5_velho = cpow(0.4 + 0.9 * I,5);

    int interacao;
    for (interacao = 0; interacao < 20; interacao++){
        r0_novo = r0_velho - (calculaPolinomioGrau6(polinomio, r0_velho))
                             /((r0_velho-r1_velho)*(r0_velho-r2_velho)*(r0_velho-r3_velho)*(r0_velho-r4_velho)
                             *(r0_velho-r5_velho));
        r1_novo = r1_velho - (calculaPolinomioGrau6(polinomio, r1_velho))
                             /((r1_velho - r0_novo) * (r1_velho - r2_velho)*(r1_velho - r3_velho)*(r1_velho-r4_velho)
                             *(r1_velho-r5_velho));
        r2_novo = r2_velho - (calculaPolinomioGrau6(polinomio, r2_velho))
                             /((r2_velho - r0_novo) * (r2_velho - r1_novo)* (r2_velho - r3_velho)*(r2_velho-r4_velho)
                             *(r2_velho-r5_velho));
        r3_novo = r3_velho - (calculaPolinomioGrau6(polinomio, r3_velho))
                             /((r3_velho - r0_novo) * (r3_velho - r1_novo)* (r3_velho - r2_novo)*(r3_velho-r4_velho)
                             *(r3_velho-r5_velho));
        r4_novo = r4_velho - (calculaPolinomioGrau6(polinomio, r4_velho))
                             /((r4_velho - r0_novo) * (r4_velho - r1_novo)* (r4_velho - r2_novo)*(r4_velho-r3_novo)
                             *(r4_velho-r5_velho));
        r5_novo = r5_velho - (calculaPolinomioGrau6(polinomio, r5_velho))
                             /((r5_velho - r0_novo) * (r5_velho - r1_novo)* (r5_velho - r2_novo)*(r5_velho - r3_novo)
                             *(r5_velho - r4_novo));

        printf("r0  = %.3f%+.3fi\n", creal(r0_novo), cimag(r0_novo));
        printf("r1  = %.3f%+.3fi\n", creal(r1_novo), cimag(r1_novo));
        printf("r2  = %.3f%+.3fi\n", creal(r2_novo), cimag(r2_novo));
        printf("r3  = %.3f%+.3fi\n", creal(r3_novo), cimag(r3_novo));
        printf("r4  = %.3f%+.3fi\n", creal(r4_novo), cimag(r4_novo));
        printf("r5  = %.3f%+.3fi\n\n", creal(r5_novo), cimag(r5_novo));

        r0_velho = r0_novo;
        r1_velho = r1_novo;
        r2_velho = r2_novo;
        r3_velho = r3_novo;
        r4_velho = r4_novo;
        r5_velho = r5_novo;
    }
}
void Grau7(double complex* polinomio){
    double complex r0_novo, r1_novo, r2_novo, r3_novo, r4_novo, r5_novo, r6_novo,
            r0_velho, r1_velho, r2_velho, r3_velho, r4_velho, r5_velho, r6_velho;

    r0_velho = cpow(0.4 + 0.9 * I,0);
    r1_velho = cpow(0.4 + 0.9 * I,1);
    r2_velho = cpow(0.4 + 0.9 * I,2);
    r3_velho = cpow(0.4 + 0.9 * I,3);
    r4_velho = cpow(0.4 + 0.9 * I,4);
    r5_velho = cpow(0.4 + 0.9 * I,5);
    r6_velho = cpow(0.4 + 0.9 * I,6);

    int interacao;
    for (interacao = 0; interacao < 20; interacao++){
        r0_novo = r0_velho - (calculaPolinomioGrau7(polinomio, r0_velho))
                             /((r0_velho-r1_velho)*(r0_velho-r2_velho)*(r0_velho-r3_velho)*(r0_velho-r4_velho)
                               *(r0_velho-r5_velho)*(r0_velho-r6_velho));
        r1_novo = r1_velho - (calculaPolinomioGrau7(polinomio, r1_velho))
                             /((r1_velho - r0_novo) * (r1_velho - r2_velho)*(r1_velho - r3_velho)*(r1_velho-r4_velho)
                               *(r1_velho-r5_velho)*(r1_velho-r6_velho));
        r2_novo = r2_velho - (calculaPolinomioGrau7(polinomio, r2_velho))
                             /((r2_velho - r0_novo) * (r2_velho - r1_novo)* (r2_velho - r3_velho)*(r2_velho-r4_velho)
                               *(r2_velho-r5_velho)*(r2_velho-r6_velho));
        r3_novo = r3_velho - (calculaPolinomioGrau7(polinomio, r3_velho))
                             /((r3_velho - r0_novo) * (r3_velho - r1_novo)* (r3_velho - r2_novo)*(r3_velho-r4_velho)
                               *(r3_velho-r5_velho)*(r3_velho-r6_velho));
        r4_novo = r4_velho - (calculaPolinomioGrau7(polinomio, r4_velho))
                             /((r4_velho - r0_novo) * (r4_velho - r1_novo)* (r4_velho - r2_novo)*(r4_velho-r3_novo)
                               *(r4_velho-r5_velho)*(r4_velho-r6_velho));
        r5_novo = r5_velho - (calculaPolinomioGrau7(polinomio, r5_velho))
                             /((r5_velho - r0_novo) * (r5_velho - r1_novo)* (r5_velho - r2_novo)*(r5_velho - r3_novo)
                               *(r5_velho - r4_novo)*(r5_velho-r6_velho));
        r6_novo = r6_velho - (calculaPolinomioGrau7(polinomio, r6_velho))
                             /((r6_velho - r0_novo) * (r6_velho - r1_novo)* (r6_velho - r2_novo)*(r6_velho - r3_novo)
                               *(r6_velho - r4_novo)*(r6_velho-r5_novo));

        printf("r0  = %.3f%+.3fi\n", creal(r0_novo), cimag(r0_novo));
        printf("r1  = %.3f%+.3fi\n", creal(r1_novo), cimag(r1_novo));
        printf("r2  = %.3f%+.3fi\n", creal(r2_novo), cimag(r2_novo));
        printf("r3  = %.3f%+.3fi\n", creal(r3_novo), cimag(r3_novo));
        printf("r4  = %.3f%+.3fi\n", creal(r4_novo), cimag(r4_novo));
        printf("r5  = %.3f%+.3fi\n", creal(r5_novo), cimag(r5_novo));
        printf("r6  = %.3f%+.3fi\n\n", creal(r6_novo), cimag(r6_novo));

        r0_velho = r0_novo;
        r1_velho = r1_novo;
        r2_velho = r2_novo;
        r3_velho = r3_novo;
        r4_velho = r4_novo;
        r5_velho = r5_novo;
        r6_velho = r6_novo;
    }
}
void Grau8(double complex* polinomio){
    double complex r0_novo, r1_novo, r2_novo, r3_novo, r4_novo, r5_novo, r6_novo, r7_novo,
            r0_velho, r1_velho, r2_velho, r3_velho, r4_velho, r5_velho, r6_velho, r7_velho;

    r0_velho = cpow(0.4 + 0.9 * I,0);
    r1_velho = cpow(0.4 + 0.9 * I,1);
    r2_velho = cpow(0.4 + 0.9 * I,2);
    r3_velho = cpow(0.4 + 0.9 * I,3);
    r4_velho = cpow(0.4 + 0.9 * I,4);
    r5_velho = cpow(0.4 + 0.9 * I,5);
    r6_velho = cpow(0.4 + 0.9 * I,6);
    r7_velho = cpow(0.4 + 0.9 * I,7);

    int interacao;
    for (interacao = 0; interacao < 20; interacao++){
        r0_novo = r0_velho - (calculaPolinomioGrau8(polinomio, r0_velho))
                             /((r0_velho-r1_velho) * (r0_velho-r2_velho) * (r0_velho-r3_velho) * (r0_velho-r4_velho)
                               *(r0_velho-r5_velho) * (r0_velho-r6_velho) * (r0_velho-r7_velho));
        r1_novo = r1_velho - (calculaPolinomioGrau8(polinomio, r1_velho))
                             /((r1_velho - r0_novo) * (r1_velho - r2_velho) * (r1_velho - r3_velho) * (r1_velho-r4_velho)
                               *(r1_velho-r5_velho) * (r1_velho-r6_velho) * (r1_velho-r7_velho));
        r2_novo = r2_velho - (calculaPolinomioGrau8(polinomio, r2_velho))
                             /((r2_velho - r0_novo) * (r2_velho - r1_novo) * (r2_velho - r3_velho) * (r2_velho-r4_velho)
                               *(r2_velho-r5_velho) * (r2_velho-r6_velho) * (r2_velho-r7_velho));
        r3_novo = r3_velho - (calculaPolinomioGrau8(polinomio, r3_velho))
                             /((r3_velho - r0_novo) * (r3_velho - r1_novo) * (r3_velho - r2_novo) * (r3_velho-r4_velho)
                               *(r3_velho-r5_velho) * (r3_velho-r6_velho) * (r3_velho-r7_velho));
        r4_novo = r4_velho - (calculaPolinomioGrau8(polinomio, r4_velho))
                             /((r4_velho - r0_novo) * (r4_velho - r1_novo) * (r4_velho - r2_novo) * (r4_velho-r3_novo)
                               *(r4_velho-r5_velho) * (r4_velho-r6_velho) * (r4_velho-r7_velho));
        r5_novo = r5_velho - (calculaPolinomioGrau8(polinomio, r5_velho))
                             /((r5_velho - r0_novo) * (r5_velho - r1_novo) * (r5_velho - r2_novo)*(r5_velho - r3_novo)
                               *(r5_velho - r4_novo) * (r5_velho-r6_velho) * (r5_velho-r7_velho));
        r6_novo = r6_velho - (calculaPolinomioGrau8(polinomio, r6_velho))
                             /((r6_velho - r0_novo) * (r6_velho - r1_novo) * (r6_velho - r2_novo) * (r6_velho - r3_novo)
                               *(r6_velho - r4_novo) * (r6_velho-r5_novo) * (r6_velho-r7_velho));
        r7_novo = r7_velho - (calculaPolinomioGrau8(polinomio, r7_velho))
                             /((r7_velho - r0_novo) * (r7_velho - r1_novo) * (r7_velho - r2_novo) * (r7_velho - r3_novo)
                               *(r7_velho - r4_novo) * (r7_velho - r5_novo) * (r7_velho - r6_novo));

        printf("r0  = %.3f%+.3fi\n", creal(r0_novo), cimag(r0_novo));
        printf("r1  = %.3f%+.3fi\n", creal(r1_novo), cimag(r1_novo));
        printf("r2  = %.3f%+.3fi\n", creal(r2_novo), cimag(r2_novo));
        printf("r3  = %.3f%+.3fi\n", creal(r3_novo), cimag(r3_novo));
        printf("r4  = %.3f%+.3fi\n", creal(r4_novo), cimag(r4_novo));
        printf("r5  = %.3f%+.3fi\n", creal(r5_novo), cimag(r5_novo));
        printf("r6  = %.3f%+.3fi\n\n", creal(r6_novo), cimag(r6_novo));
        printf("r7  = %.3f%+.3fi\n\n", creal(r7_novo), cimag(r7_novo));

        r0_velho = r0_novo;
        r1_velho = r1_novo;
        r2_velho = r2_novo;
        r3_velho = r3_novo;
        r4_velho = r4_novo;
        r5_velho = r5_novo;
        r6_velho = r6_novo;
        r7_velho = r7_novo;
    }
}
void Grau9(double complex* polinomio){
    double complex r0_novo, r1_novo, r2_novo, r3_novo, r4_novo, r5_novo, r6_novo, r7_novo, r8_novo,
            r0_velho, r1_velho, r2_velho, r3_velho, r4_velho, r5_velho, r6_velho, r7_velho, r8_velho;

    r0_velho = cpow(0.4 + 0.9 * I,0);
    r1_velho = cpow(0.4 + 0.9 * I,1);
    r2_velho = cpow(0.4 + 0.9 * I,2);
    r3_velho = cpow(0.4 + 0.9 * I,3);
    r4_velho = cpow(0.4 + 0.9 * I,4);
    r5_velho = cpow(0.4 + 0.9 * I,5);
    r6_velho = cpow(0.4 + 0.9 * I,6);
    r7_velho = cpow(0.4 + 0.9 * I,7);
    r8_velho = cpow(0.4 + 0.9 * I,8);

    int interacao;
    for (interacao = 0; interacao < 10; interacao++){
        r0_novo = r0_velho - (calculaPolinomioGrau9(polinomio, r0_velho))
                             /((r0_velho-r1_velho) * (r0_velho-r2_velho) * (r0_velho-r3_velho) * (r0_velho-r4_velho)
                               *(r0_velho-r5_velho) * (r0_velho-r6_velho) * (r0_velho-r7_velho) * (r0_velho-r8_velho));
        r1_novo = r1_velho - (calculaPolinomioGrau9(polinomio, r1_velho))
                             /((r1_velho - r0_novo) * (r1_velho - r2_velho) * (r1_velho - r3_velho) * (r1_velho-r4_velho)
                               *(r1_velho-r5_velho) * (r1_velho-r6_velho) * (r1_velho-r7_velho) * (r1_velho-r8_velho));
        r2_novo = r2_velho - (calculaPolinomioGrau9(polinomio, r2_velho))
                             /((r2_velho - r0_novo) * (r2_velho - r1_novo) * (r2_velho - r3_velho) * (r2_velho-r4_velho)
                               *(r2_velho-r5_velho) * (r2_velho-r6_velho) * (r2_velho-r7_velho) * (r2_velho-r8_velho));
        r3_novo = r3_velho - (calculaPolinomioGrau9(polinomio, r3_velho))
                             /((r3_velho - r0_novo) * (r3_velho - r1_novo) * (r3_velho - r2_novo) * (r3_velho-r4_velho)
                               *(r3_velho-r5_velho) * (r3_velho-r6_velho) * (r3_velho-r7_velho) * (r3_velho-r8_velho));
        r4_novo = r4_velho - (calculaPolinomioGrau9(polinomio, r4_velho))
                             /((r4_velho - r0_novo) * (r4_velho - r1_novo) * (r4_velho - r2_novo) * (r4_velho-r3_novo)
                               *(r4_velho-r5_velho) * (r4_velho-r6_velho) * (r4_velho-r7_velho) * (r4_velho-r8_velho));
        r5_novo = r5_velho - (calculaPolinomioGrau9(polinomio, r5_velho))
                             /((r5_velho - r0_novo) * (r5_velho - r1_novo) * (r5_velho - r2_novo)*(r5_velho - r3_novo)
                               *(r5_velho - r4_novo) * (r5_velho-r6_velho) * (r5_velho-r7_velho) * (r5_velho-r8_velho));
        r6_novo = r6_velho - (calculaPolinomioGrau9(polinomio, r6_velho))
                             /((r6_velho - r0_novo) * (r6_velho - r1_novo) * (r6_velho - r2_novo) * (r6_velho - r3_novo)
                               *(r6_velho - r4_novo) * (r6_velho-r5_novo) * (r6_velho-r7_velho) * (r6_velho-r8_velho));
        r7_novo = r7_velho - (calculaPolinomioGrau9(polinomio, r7_velho))
                             /((r7_velho - r0_novo) * (r7_velho - r1_novo) * (r7_velho - r2_novo) * (r7_velho - r3_novo)
                               *(r7_velho - r4_novo) * (r7_velho - r5_novo) * (r7_velho - r6_novo) * (r7_velho-r8_velho));
        r8_novo = r8_velho - (calculaPolinomioGrau9(polinomio, r8_velho))
                             /((r8_velho - r0_novo) * (r8_velho - r1_novo) * (r8_velho - r2_novo) * (r8_velho - r3_novo)
                               *(r8_velho - r4_novo) * (r8_velho - r5_novo) * (r8_velho - r6_novo) * (r8_velho-r7_novo));

        printf("r0  = %.3f%+.3fi\n", creal(r0_novo), cimag(r0_novo));
        printf("r1  = %.3f%+.3fi\n", creal(r1_novo), cimag(r1_novo));
        printf("r2  = %.3f%+.3fi\n", creal(r2_novo), cimag(r2_novo));
        printf("r3  = %.3f%+.3fi\n", creal(r3_novo), cimag(r3_novo));
        printf("r4  = %.3f%+.3fi\n", creal(r4_novo), cimag(r4_novo));
        printf("r5  = %.3f%+.3fi\n", creal(r5_novo), cimag(r5_novo));
        printf("r6  = %.3f%+.3fi\n", creal(r6_novo), cimag(r6_novo));
        printf("r7  = %.3f%+.3fi\n", creal(r7_novo), cimag(r7_novo));
        printf("r8  = %.3f%+.3fi\n\n", creal(r8_novo), cimag(r8_novo));

        r0_velho = r0_novo;
        r1_velho = r1_novo;
        r2_velho = r2_novo;
        r3_velho = r3_novo;
        r4_velho = r4_novo;
        r5_velho = r5_novo;
        r6_velho = r6_novo;
        r7_velho = r7_novo;
        r8_velho = r8_novo;
    }
}
void DurandKerner(double complex* polinomio, int grau){
    switch(grau){
        case 0:
            printf("Grau 0 inserido.\n");
            exit(1);
        case 1:
            printf("Grau 1 inserido.\n");
            exit(1);
        case 2:
            Grau2(polinomio);
            break;
        case 3:
            Grau3(polinomio);
            break;
        case 4:
            Grau4(polinomio);
            break;
        case 5:
            Grau5(polinomio);
            break;
        case 6:
            Grau6(polinomio);
            break;
        case 7:
            Grau7(polinomio);
            break;
        case 8:
            Grau8(polinomio);
            break;
        case 9:
            Grau9(polinomio);
            break;
        default:
            printf("O grau inserido nao eh aceito.\n");
    }
}
