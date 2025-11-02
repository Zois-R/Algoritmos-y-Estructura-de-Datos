#include "pilaEstatica.h"


void crear_pila(t_pila *pp)
{
  pp->tope = TAM_PILA;
}

int pila_llena(const t_pila *pp,unsigned cant_bytes)
{
  return pp->tope < cant_bytes + sizeof(unsigned);
}

int pila_vacia(const t_pila *pp)
{
  return pp->tope == TAM_PILA;
}

int apilar(t_pila *pp, const void *d, unsigned cant_bytes)
{
  if( pp->tope < cant_bytes + sizeof(unsigned))
    return 0;

  pp->tope -= cant_bytes;
  memcpy(pp->pila+pp->tope,d,cant_bytes);

  pp->tope -= sizeof(unsigned);
  memcpy(pp->pila+pp->tope,&cant_bytes,sizeof(unsigned));

  return 1;

}


int desapilar(t_pila *pp, void *d, unsigned cant_bytes)
{
  unsigned tam_info;
  if(pp->tope == TAM_PILA)
    return 0;

  memcpy(&tam_info,pp->pila+pp->tope,sizeof(unsigned));
  pp->tope += sizeof(unsigned);

  memcpy(d,pp->pila+pp->tope,minimo(tam_info,cant_bytes));
  pp->tope += tam_info;

  return 1;

}

int ver_tope(const t_pila *pp, void *d, unsigned cant_bytes)
{
  unsigned tam_info;
  if(pp->tope == TAM_PILA)
    return 0;

  memcpy(&tam_info,pp->pila+pp->tope,sizeof(unsigned));
  memcpy(&d,pp->pila+pp->tope+sizeof(unsigned),minimo(cant_bytes,tam_info));
  return 1;
}
void vaciar_pila(t_pila *pp)
{
  pp->tope = TAM_PILA;
}

