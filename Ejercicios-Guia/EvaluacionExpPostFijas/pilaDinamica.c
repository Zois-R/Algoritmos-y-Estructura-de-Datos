#include "pilaDinamica.h"


void crear_pila(t_pila *p)
{
  *p = NULL;
}

int pila_llena(const t_pila *p, unsigned cant_bytes)
{
  t_nodo *nue = (t_nodo*)malloc(sizeof(t_nodo));
  void *info = malloc(cant_bytes);

  free(nue);
  free(info);

  return nue == NULL || info == NULL;
}


int pila_vacia(const t_pila *p)
{
  return *p == NULL;
}
int apilar(t_pila *p, const void *d, unsigned cant_bytes)
{
  t_nodo *nue;

  if( (nue = (t_nodo*)malloc(sizeof(t_nodo))) == NULL || (nue->info = malloc(cant_bytes)) == NULL)
    {
      free(nue);
      return 0;
    }

  memcpy(nue->info,d,cant_bytes);
  nue->tam_info = cant_bytes;
  nue->sig = *p;
  *p = nue;
  return 1;

}
int desapilar(t_pila *p, void *d, unsigned cant_bytes)
{
  t_nodo *elim = *p;
  if(elim == NULL)
    return 0;

  *p = elim->sig;
  memcpy(d,elim->info,minimo(cant_bytes,elim->tam_info));
  free(elim->info);
  free(elim);
  return 1;
}


void vaciar_pila(t_pila *p)
{
  while(*p)
    {
      t_nodo *elim = *p;
      *p = elim->sig;
      free(elim->info);
      free(elim);
    }
}
int ver_tope(const t_pila *p, void *d, unsigned cant_bytes)
{
  if(*p == NULL)
    return 0;

  memcpy(d,(*p)->info,minimo(cant_bytes,(*p)->tam_info));
  return 1;
}


