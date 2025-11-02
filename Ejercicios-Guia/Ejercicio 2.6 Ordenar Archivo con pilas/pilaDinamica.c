#include "pilaDinamica.h"


void crear_pila(t_pila *pp)
{
  *pp = NULL;
}

int pila_vacia(const t_pila *pp)
{
  return *pp == NULL;
}

int pila_llena(const t_pila *pp, unsigned cant_bytes)
{
  void *info = malloc(cant_bytes);
  t_nodo *nue = (t_nodo*)malloc(sizeof(t_nodo));

  free(info);
  free(nue);

  return nue == NULL || info == NULL;
}



int apilar(t_pila *pp, const void *d, unsigned cant_bytes)
{
    t_nodo *nue;

    if( (nue = (t_nodo*)malloc(sizeof(t_nodo))) == NULL || (nue->info = malloc(cant_bytes)) == NULL)
      {
        free(nue);
        return 0;
      }

    memcpy(nue->info,d,cant_bytes);
    nue->tam_info = cant_bytes;
    nue->sig = *pp;
    *pp = nue;
    return 1;

}


int desapilar(t_pila *pp, void *d, unsigned cant_bytes)
{
  t_nodo *elim = *pp;
  if(elim == NULL)
    return 0;

  memcpy(d,elim->info,minimo(cant_bytes,elim->tam_info));
  *pp = elim->sig;
  free(elim->info);
  free(elim);
  return 1;
}

int ver_tope(const t_pila *pp, void *d, unsigned cant_bytes)
{
    if(*pp == NULL)
      return 0;

    memcpy(d,(*pp)->info,minimo(cant_bytes,(*pp)->tam_info));
    return 1;
}
void vaciar_pila(t_pila *pp)
{
  while(*pp)
    {
      t_nodo *elim = *pp;
      *pp = elim->sig;
      free(elim->info);
      free(elim);
    }
}
