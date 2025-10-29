#ifndef VECTORESTATICO_H_INCLUDED
#define VECTORESTATICO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 20
typedef struct
{
  unsigned tam_dato;
  unsigned ce;
  char vec[TAM_MAX];
  unsigned tope;
}
t_vectore;

void crearVector(t_vectore *vec,unsigned tam_dato, unsigned ce);
int insertarEnVector(t_vectore *vec, unsigned tam_dato, void *dato);
int vectorLleno(const t_vectore *vec, unsigned tam_dato);
int vectorVacio(const t_vectore *vec);
int insertarElementoEnOrden(t_vectore *vec, unsigned tam_dato, void *dato,
                            int (*cmp)(const void *,const void*));

int cmpInt(const void *a,const void*b);

void * verElementoPorPos(const t_vectore *vec, unsigned tam_dato, unsigned pos);
void destruir_vector(t_vectore *vec);
int eliminar_elemento(t_vectore *vec, void *dato_a_eliminar, unsigned tam_dato,
                      int (*cmp)(const void*,const void *));

#endif // VECTORESTATICO_H_INCLUDED
