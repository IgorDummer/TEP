/* Igor Wandermurem Dummer
 * Matricula: 2019109389 */
/* Head file especifico do tipo */
#include "D_complexo.h"

/* Libera para que nao ocorra erro caso ja tenham sidos usados anteriormente */
#undef TIPO_
#undef TIPADO_
#undef FORMAT_

/* Define o tipo e o tipado */
#define TIPO_ double
#define FORMAT_ "lf"
#define TIPADO_(THING) THING ## _D

/* Instancia o complexo.c para o tipo especifico de dados */
#include "complexo.c"

#undef FORMAT_
#undef TIPADO_
#undef TIPO_