/* Igor Wandermurem Dummer
 * Matricula: 2019109389 */
#ifndef LD_COMPLEXO_H
#define LD_COMPLEXO_H

/* Libera para que nao ocorra erro caso ja tenham sidos usados anteriormente */
#undef TIPO_
#undef TIPADO_
#undef FORMAT_

/* Define o tipo e o tipado */
#define TIPO_ long double
#define FORMAT_ "Lf"
#define TIPADO_(THING) THING ## _Ld

/* Pre compila e compila complexo.h */
#include "complexo.h"

#undef FORMAT_
#undef TIPADO_
#undef TIPO_

#endif //LD_COMPLEXO_H
