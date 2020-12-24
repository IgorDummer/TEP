/* Igor Wandermurem Dummer
 * Matricula: 2019109389 */
#include <stdio.h>
#include "complexo.h"
#include "durandKerner.h"

int main(){
    complexo_t *p, *q, *r, *s, *a;
    CrieNumeroComplexo(&p);
    CrieNumeroComplexo(&q);
    CrieNumeroComplexo(&r);
    CrieNumeroComplexo(&s);
    CrieNumeroComplexo(&a);

    PreencheComplexoDeReais(p, 1.0 , 2.0);
    PreencheComplexoDeReais(q, -3.0 , 3.0);
    PreencheComplexoDeReais(r, 5.0 , -2.0);
    PreencheComplexoDeReais(s, 2.0 , 3.0);
    PreencheComplexoDeReais(a, 1.0 , 0.0);

    complexo_t polinomio[5];
    polinomio[0] = *a;
    polinomio[1] = *s;
    polinomio[2] = *r;
    polinomio[3] = *q;
    polinomio[4] = *p;
    DurandKerner(polinomio);

    LiberaComplexo(&p);
    LiberaComplexo(&q);
    LiberaComplexo(&r);
    LiberaComplexo(&s);
    LiberaComplexo(&a);

    return 0;
}
