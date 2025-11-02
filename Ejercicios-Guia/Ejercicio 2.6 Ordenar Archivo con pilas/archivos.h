#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "pilaDinamica.h"
typedef struct
{
  char cod_prod[7];
  char desc[16];
  char proov[16];
}t_producto;

void crear_archivo(FILE **pf);
void leer_archivo(FILE **pf);
void ordenar_archivo_con2_pilas(t_pila *pp1,t_pila *pp2, FILE **pf, const char *nombre_archivo);

#endif // ARCHIVOS_H_INCLUDED
