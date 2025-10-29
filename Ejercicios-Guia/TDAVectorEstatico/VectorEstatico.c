#include "VectorEstatico.h"



void crearVector(t_vectore *vec,unsigned tam_dato, unsigned ce)
{
  vec->ce = (ce * tam_dato) <= TAM_MAX ? ce : 0;
  vec->tam_dato = tam_dato;
  vec->tope = 0;
}

int insertarEnVector(t_vectore *vec, unsigned tam_dato, void *dato)
{
  if(vec->tope == TAM_MAX || vec->tope + tam_dato > TAM_MAX)
    {
      printf("Vector lleno\n");
      return 0;
    }

  memcpy(vec->vec + vec->tope,dato,tam_dato);
  vec->tope += tam_dato;
  return 1;

}


int vectorLleno(const t_vectore *vec, unsigned tam_dato)
{
  return vec->tope == TAM_MAX;
}

int vectorVacio(const t_vectore *vec)
{
  return vec->tope == 0;
}

int insertarElementoEnOrden(t_vectore *vec, unsigned tam_dato, void *dato,
                            int (*cmp)(const void *,const void*))
{
  int rc;
  int indice = 0;
  if(vec->tope == TAM_MAX)
    return 0;
  //Moverme al lugar de inserción
  //Me faltó la comparación para no comparar elementos de más
  while( indice < vec->tope && (rc = cmp(dato,&vec->vec[indice])) > 0 )
    indice += tam_dato;

  //Acá hago espacio para insertar el nuevo dato
  memmove(vec->vec + indice + tam_dato,vec->vec + indice,vec->tope - indice);
  //Hago la inserción
  memcpy((&vec->vec[indice]),dato,tam_dato);
  vec->tope +=tam_dato;
  return 1;
}



int cmpInt(const void *a,const void*b)
{
  const int *num1 = (const int*)a;
  const int *num2 = (const int*)b;
  return *num1-*num2;
}

void * verElementoPorPos(const t_vectore *vec, unsigned tam_dato, unsigned pos)
{
  if(pos > vec->ce) //Posición fuera de rango
    return NULL;

  //Debería validar esta cuenta
  const void *valor_obtenido = (vec->vec + (pos * vec->tam_dato));

  return (void*)valor_obtenido;
}

void destruir_vector(t_vectore *vec)
{
  vec->ce = 0;
  vec->tam_dato = 0;
  vec->tope = 0;
}

int eliminar_elemento(t_vectore *vec, void *dato_a_eliminar, unsigned tam_dato,
                      int (*cmp)(const void*,const void *))
{
  unsigned indice = 0;
  int bloque_a_mover;
  if(vec->tope == 0) // vector vacío
    return 0;

  while(indice < vec->tope && cmp(vec->vec + indice,dato_a_eliminar) != 0)
    {
      indice += tam_dato;
    }
  ///POR CONVENCIÓN Y PORQUE ES IMPLEMENTACIÓN MIA SE BORRA CON UN CERO

  bloque_a_mover = vec->tope - indice;
  memmove(vec->vec + indice , vec->vec + indice + tam_dato, bloque_a_mover -tam_dato );

  //Para mi implementación siempre el último elemento va a quedar como un cero

  vec->vec[TAM_MAX - tam_dato] = 0;
  return 1;
}

