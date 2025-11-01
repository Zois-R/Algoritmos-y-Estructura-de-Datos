#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "pilaEstatica.h"
typedef struct
{
  char cod_prod[8];
  char descripcion[16];
  char proveedor[16];
}t_producto;



void crear_archivo_prods(FILE **pf);
void leer_archivo_y_cargar_pila(FILE **pf,t_pila *pc);

int menu(t_pila *pc,FILE **pf);
void desapilar_y_cargar_archivo(t_pila *pc, FILE **pf);
void leer_archivo(FILE **pf);


#endif // ARCHIVO_H_INCLUDED
