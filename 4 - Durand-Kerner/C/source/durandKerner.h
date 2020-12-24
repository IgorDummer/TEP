/* Igor Wandermurem Dummer
 * Matricula: 2019109389 */
#ifndef DURANDKERNER_H
#define DURANDKERNER_H

#include "complexo.h"

complexo_t calculaPolinomio(complexo_t* polinomio, complexo_t x);

void elevaComplexo(complexo_t* complexo, int expoente);

void elevaQuadrado(complexo_t* complexo);

void elevaCubo(complexo_t* complexo);

void DurandKerner(complexo_t* polinomio);

#endif //DURANDKERNER_H
