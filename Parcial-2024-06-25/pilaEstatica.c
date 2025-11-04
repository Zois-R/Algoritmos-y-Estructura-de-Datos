#include "pilaEstatica.h"

void crear_pila(t_pila *p)
{
  p->tope  = TAM_PILA;
}
int pila_llena(const t_pila *p, unsigned cant_bytes)
{
  return p->tope < cant_bytes + sizeof(unsigned);
}
int pila_vacia(const t_pila *p)
{
  return p->tope == TAM_PILA;
}

int apilar(t_pila *p,const void *d, unsigned cant_bytes)
{
  if(p->tope < cant_bytes + sizeof(unsigned))
    return 0;

  p->tope -= cant_bytes;
  memcpy(p->pila + p->tope, d,cant_bytes);
  p->tope -= sizeof(unsigned);
  memcpy(p->pila + p->tope,&cant_bytes,sizeof(unsigned));
  return 1;
}

int desapilar(t_pila *p, void *d, unsigned cant_bytes)
{
  unsigned tam_info;
  if(p->tope == TAM_PILA)
    return 0;

  memcpy(&tam_info,p->pila+p->tope,sizeof(unsigned));
  p->tope += sizeof(unsigned);
  memcpy(d,p->pila+p->tope,minimo(cant_bytes,tam_info));
  p->tope += tam_info;
  return 1;

}

int ver_tope(const t_pila *p, void *d, unsigned cant_bytes)
{
  unsigned tam_info;
  if(p->tope == TAM_PILA)
    return 0;
  memcpy(&tam_info,p->pila + p->tope,sizeof(unsigned));
  memcpy(d,p->pila+p->tope + sizeof(unsigned),minimo(cant_bytes,tam_info));
  return 1;

}
void vaciar_pila(t_pila *p)
{
  p->tope = TAM_PILA;
}
