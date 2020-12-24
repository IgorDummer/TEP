/* Igor Wandermurem Dummer
 * Matricula: 2019109389 */
#include "durandKerner.h"
#include <stdio.h>
#include <complex.h>

complexo_t calculaPolinomio(complexo_t* polinomio, complexo_t x){
    complexo_t resultado;
    complexo_t a0, a1, a2, a3, a4;
    InicializaComplexo(&resultado);

    a0 = polinomio[4];
    a1 = polinomio[3];
    a2 = polinomio[2];
    a3 = polinomio[1];
    a4 = polinomio[0];

    //resultado =   ((((((a4 * x) + a3) * x) + a2) * x)+ a1) * x + a0 ;
    resultado = ProdutoComplexos(&a4, &x);
    resultado = SomaComplexos(&resultado, &a3);
    resultado = ProdutoComplexos(&resultado, &x);
    resultado = SomaComplexos(&resultado, &a2);
    resultado = ProdutoComplexos(&resultado, &x);
    resultado = SomaComplexos(&resultado, &a1);
    resultado = ProdutoComplexos(&resultado, &x);
    resultado = SomaComplexos(&resultado, &a0);

    return resultado;
}

void elevaComplexo(complexo_t* complexo, int expoente){
    double complex aux;
    aux = cpow(0.4 + 0.9 * I, expoente);
    complexo->real = creal(aux);
    complexo->imaginario = cimag(aux);
}

/* Tentei implementar sem usar a biblioteca complexo, mas nao deu */
//void elevaQuadrado(complexo_t* complexo){
//    complexo->real = (0.4*0.4)-0.9;
//    complexo->imaginario = 2*(0.4*0.9);
//}
//void elevaCubo(complexo_t* complexo){
//    /*(0.4+0.9i)³ = 3*0.4 + 3*(0.4)²*(0.9i) + 3*(0.4)*(0.9i)² + (0.9i)³ */
//    complexo->real = (3*0.4)-(3*0.4*0.9*0.9);
//    complexo->imaginario = (3*0.4*0.4*0.9) + (0.9*0.9*0.9);
//}

void DurandKerner(complexo_t* polinomio){
    complexo_t p_novo, q_novo, r_novo, s_novo, p_velho, q_velho, r_velho, s_velho;
    complexo_t aux, aux2, aux3;
    InicializaComplexo(&aux2);
    InicializaComplexo(&aux3);

    elevaComplexo(&p_velho, 0);
    elevaComplexo(&q_velho, 1);
    elevaComplexo(&r_velho, 2);
    elevaComplexo(&s_velho, 3);

    InicializaComplexo(&aux);
    InicializaComplexo(&aux2);
    InicializaComplexo(&aux3);
    int interacao;
    for (interacao = 0; interacao < 10; interacao++){
        /*p_novo = p_velho - (calculaPolinomio(polinomio, p_velho))
                           /((p_velho - q_velho) *
                             (p_velho - r_velho) * (p_velho - s_velho));*/
        aux = SubtracaoComplexos(&p_velho, &q_velho);
        aux2 = SubtracaoComplexos(&p_velho, &r_velho);
        aux3 = SubtracaoComplexos(&p_velho, &s_velho);
        aux = ProdutoComplexos(&aux, &aux2);
        aux = ProdutoComplexos(&aux, &aux3); //((p_velho - q_velho)*(p_velho - r_velho)*(p_velho - s_velho));
        aux2 = calculaPolinomio(polinomio, p_velho);
        aux3 = DivisaoComplexos(&aux2, &aux);
        p_novo = SubtracaoComplexos(&p_velho, &aux3);

        InicializaComplexo(&aux);
        InicializaComplexo(&aux2);
        InicializaComplexo(&aux3);
        /*q_novo = q_velho - (calculaPolinomio(polinomio, q_velho))
                           /((q_velho - p_novo) *
                             (q_velho - r_velho) * (q_velho - s_velho));*/
        aux = SubtracaoComplexos(&q_velho, &p_novo);
        aux2 = SubtracaoComplexos(&q_velho, &r_velho);
        aux3 = SubtracaoComplexos(&q_velho, &s_velho);
        aux = ProdutoComplexos(&aux, &aux2);
        aux = ProdutoComplexos(&aux, &aux3); //((q_velho - p_novo)*(q_velho - r_velho)*(q_velho - s_velho));
        aux2 = calculaPolinomio(polinomio, q_velho);
        aux3 = DivisaoComplexos(&aux2, &aux);
        q_novo = SubtracaoComplexos(&q_velho, &aux3);

        InicializaComplexo(&aux);
        InicializaComplexo(&aux2);
        InicializaComplexo(&aux3);
        /*r_novo = r_velho - (calculaPolinomio(polinomio, r_velho))
                           /((r_velho - p_novo) *
                             (r_velho - q_novo) * (r_velho - s_velho));*/
        aux = SubtracaoComplexos(&r_velho, &p_novo);
        aux2 = SubtracaoComplexos(&r_velho, &q_novo);
        aux3 = SubtracaoComplexos(&r_velho, &s_velho);
        aux = ProdutoComplexos(&aux, &aux2);
        aux = ProdutoComplexos(&aux, &aux3); //((r_velho - p_novo)*(r_velho - q_novo)*(r_velho - s_velho));
        aux2 = calculaPolinomio(polinomio, r_velho);
        aux3 = DivisaoComplexos(&aux2, &aux);
        r_novo = SubtracaoComplexos(&r_velho, &aux3);

        InicializaComplexo(&aux);
        InicializaComplexo(&aux2);
        InicializaComplexo(&aux3);
        /*s_novo = s_velho - (calculaPolinomio(polinomio, s_velho))
                           /((s_velho - p_novo) *
                             (s_velho - q_novo) * (s_velho - r_novo));*/
        aux = SubtracaoComplexos(&s_velho, &p_novo);
        aux2 = SubtracaoComplexos(&s_velho, &q_novo);
        aux3 = SubtracaoComplexos(&s_velho, &r_novo);
        aux = ProdutoComplexos(&aux, &aux2);
        aux = ProdutoComplexos(&aux, &aux3); //((s_velho - p_novo)*(s_velho - q_novo)*(s_velho - r_novo));
        aux2 = calculaPolinomio(polinomio, s_velho);
        aux3 = DivisaoComplexos(&aux2, &aux);
        s_novo = SubtracaoComplexos(&s_velho, &aux3);

        InicializaComplexo(&aux);
        InicializaComplexo(&aux2);
        InicializaComplexo(&aux3);

        ApresentaComplexo(p_novo, "p = ");
        ApresentaComplexo(q_novo, "q = ");
        ApresentaComplexo(r_novo, "r = ");
        ApresentaComplexo(s_novo, "s = ");
        printf("\n");

        p_velho = p_novo;
        q_velho = q_novo;
        r_velho = r_novo;
        s_velho = s_novo;
    }
}