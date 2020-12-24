/* Igor Wandermurem Dummer
 * Matricula: 2019109389 */
/* Head file especifico do tipo */
#include "LD_complexo.h"

/* Libera para que nao ocorra erro caso ja tenham sidos usados anteriormente */
#undef TIPO_
#undef TIPADO_
#undef FORMAT_

/* Define o tipo e o tipado */
#define TIPO_ long double
#define FORMAT_ "Lf"
#define TIPADO_(THING) THING ## _Ld

/* Instancia o complexo.c para o tipo especifico de dados */
#include "complexo.c"

#undef FORMAT_
#undef TIPADO_
#undef TIPO_