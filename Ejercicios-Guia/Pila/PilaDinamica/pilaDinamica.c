#include "pilaDinamica.h"



void crear_pila(t_pila *pc)
{
  *pc = NULL;
}

int pila_llena(const t_pila *pc, unsigned cant_bytes)
{
  void *dato = malloc(cant_bytes);
  t_nodo *nue = (t_nodo*)malloc(sizeof(t_nodo));

  free(dato);
  free(nue);

  return nue == NULL || dato == NULL;
}

int pila_vacia(const t_pila *pc)
{
  return *pc == NULL;
}


int apilar(t_pila *pc, const void *dato, unsigned cant_bytes)
{
  t_nodo *nue;
  if( (nue = (t_nodo*)malloc(sizeof(t_nodo))) == NULL || (nue->info = malloc(cant_bytes)) == NULL )
  {
    free(nue);
    return 0;
  }

  memcpy(nue->info,dato,cant_bytes);
  nue->tam_info = cant_bytes;
  nue->sig = *pc;
  *pc = nue;
  return 1;
}

int desapilar(t_pila *pc, void *dato, unsigned cant_bytes)
{
    if(*pc == NULL)
      return 0;

    t_nodo *elim = *pc;
    memcpy(dato,elim->info,minimo(cant_bytes, elim->tam_info));
    *pc = elim->sig;

    free(elim->info);
    free(elim);

    return 1;

}

int ver_tope(const t_pila *pc,void *dato,unsigned cant_bytes)
{
  if(*pc == NULL)
    return 0;

  memcpy(dato,(*pc)->info,minimo(cant_bytes,(*pc)->tam_info));
  return 1;
}


void vaciar_pila(t_pila *pc)
{
  while(*pc)
    {
      t_nodo *elim = *pc;
      *pc = elim->sig;
      free(elim->info);
      free(elim);
    }
}
