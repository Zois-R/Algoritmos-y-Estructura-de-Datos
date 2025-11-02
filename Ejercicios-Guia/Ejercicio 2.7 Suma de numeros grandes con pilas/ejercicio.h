#ifndef EJERCICIO_H_INCLUDED
#define EJERCICIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilaEstatica.h"


void volcar_numeros_desde_final(t_pila *p1, t_pila *p2, const char *n1, const char *n2,
                                size_t tam_n1, size_t tam_n2);

void sumar_pilas(t_pila *p1, t_pila *p2, t_pila *ptemp);

#endif // EJERCICIO_H_INCLUDED
