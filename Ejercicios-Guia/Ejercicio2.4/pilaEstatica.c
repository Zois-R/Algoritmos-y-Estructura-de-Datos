#include "pilaEstatica.h"


void crear_pila(t_pila *pc)
{
  pc->tope = TAM_PILA;
}


int pila_vacia(const t_pila *pc)
{
  return pc->tope == TAM_PILA;
}

int pila_llena(const t_pila *pc, unsigned cant_bytes)
{
  return pc->tope < cant_bytes + sizeof(unsigned);
}


int apilar(t_pila *pc, const void *dato, unsigned cant_bytes)
{
  if(pc->tope < cant_bytes + sizeof(unsigned))
    return 0;

  pc->tope -= cant_bytes;
  memcpy(pc->pila + pc->tope, dato, cant_bytes);

  pc->tope -= sizeof(unsigned);
  memcpy(pc->pila + pc->tope,&cant_bytes,sizeof(unsigned));

  return 1;
}


int desapilar(t_pila *pc, void *dato, unsigned cant_bytes)
{
  unsigned tam_info;
  if(pc->tope == TAM_PILA)
    return 0;

  memcpy(&tam_info,pc->pila + pc->tope, sizeof(unsigned));
  pc->tope += sizeof(unsigned);
  memcpy(dato,pc->pila + pc->tope, minimo(cant_bytes,tam_info));
  pc->tope += tam_info;
  return 1;
}

int ver_tope(const t_pila *pc, void *dato, unsigned cant_bytes)
{
  unsigned tam_info;
  if( pc->tope == TAM_PILA)
    return 0;

  memcpy(&tam_info,pc->pila+pc->tope,sizeof(unsigned));
  memcpy(dato,pc->pila+pc->tope+sizeof(unsigned),minimo(tam_info,cant_bytes));
  return 1;
}
void vaciar_pila(t_pila *pc)
{
  pc->tope = TAM_PILA;
}
