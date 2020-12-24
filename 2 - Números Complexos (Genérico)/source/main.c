/* Igor Wandermurem Dummer
 * Matricula: 2019109389 */
#include <stdio.h>
#include "D_complexo.h"
#include "LD_complexo.h"

int main() {
    complexo_t_D *a, *b, soma1, produto1, divisao1, subtracao1;
    complexo_t_Ld *c, *d, soma2, produto2, divisao2, subtracao2;
    /* ----------------------------------- Operacoes com double --------------------------- */

    CrieNumeroComplexo_D (&a);
    CrieNumeroComplexo_D (&b);
    PreencheComplexoDeReais_D(a, 1.0 , 2.0);
    PreencheComplexoDeReais_D(b, 3.0 , 4.0);

    soma1 = SomaComplexos_D(a, b);
    produto1 = ProdutoComplexos_D(a, b);
    subtracao1 = SubtracaoComplexos_D(a, b);
    divisao1 = DivisaoComplexos_D(a, b);

    ApresentaComplexo_D(soma1, "p + q = ");
    ApresentaComplexo_D(produto1, "p * q = ");
    ApresentaComplexo_D(divisao1, "p / q = ");
    ApresentaComplexo_D(subtracao1, "p - q = ");

    LiberaComplexo_D(&a);
    LiberaComplexo_D(&b);

    /* ----------------------------------- Operacoes com long double --------------------------- */

    CrieNumeroComplexo_Ld(&c);
    CrieNumeroComplexo_Ld(&d);
    PreencheComplexoDeReais_Ld(c, 1.0 , 2.0);
    PreencheComplexoDeReais_Ld(d, 3.0 , 4.0);

    soma2 = SomaComplexos_Ld(c, d);
    produto2 = ProdutoComplexos_Ld(c, d);
    subtracao2 = SubtracaoComplexos_Ld(c, d);
    divisao2 = DivisaoComplexos_Ld(c, d);

    ApresentaComplexo_Ld(soma2, "p + q = ");
    ApresentaComplexo_Ld(produto2, "p * q = ");
    ApresentaComplexo_Ld(divisao2, "p / q = ");
    ApresentaComplexo_Ld(subtracao2, "p - q = ");

    LiberaComplexo_Ld(&c);
    LiberaComplexo_Ld(&d);

    return 0;
}
