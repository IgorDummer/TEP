/* Igor Wandermurem Dummer
 * Matricula: 2019109389 */
#ifndef D_COMPLEXO_H
#define D_COMPLEXO_H

/* Libera para que nao ocorra erro caso ja tenham sidos usados anteriormente */
#undef TIPO_
#undef TIPADO_
#undef FORMAT_

/* Define o tipo e o tipado */
#define TIPO_ double
#define FORMAT_ "lf"
#define TIPADO_(THING) THING ## _D

/* Pre compila e compila complexo.h */
#include "complexo.h"

#undef TIPO_
#undef TIPADO_
#undef FORMAT_

#endif //D_COMPLEXO_H
