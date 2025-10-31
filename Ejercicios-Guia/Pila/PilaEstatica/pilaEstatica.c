#include "pilaEstatica.h"


void crear_pila(t_pila *pc)
{
  pc->tope = TAM_MAX;
}



int pilla_llena(const t_pila *pc, unsigned cantBytes)
{
  return pc->tope < cantBytes + sizeof(unsigned);  //los bytes que quiero meter mas un byte para guardar el número de bytes que voy a guardar
}

int pila_vacia(const t_pila *pc)
{
  return pc->tope == TAM_MAX;
}

int poner_en_pila(t_pila *pc, void *dato, unsigned cant_bytes)
{


  if(pc->tope < cant_bytes + sizeof(unsigned))
    {
      return 0;
    }

  pc->tope -= cant_bytes;
  memcpy(pc->pila + pc->tope, &dato,cant_bytes);

  pc->tope -= sizeof(unsigned);
  memcpy(pc->pila + pc->tope,&cant_bytes,sizeof(unsigned));

  return 1;
}

int sacar_de_pila(t_pila *pc, void *d, unsigned cantBytes)
{
  unsigned tam_info;
  if(pc->tope == TAM_MAX)
    {
      return 0;
    }

  memcpy(&tam_info,pc->pila+pc->tope,sizeof(unsigned));
  pc->tope += sizeof(unsigned);

  memcpy(dato,pc->pila + pc->tope, minimo(tam_info,cantBytes));
  pc->tope += tam_info;

  return 1;

}


void vaciar_pila(t_pila *pc)
{
  pc->tope = TAM_MAX;
}
int ver_tope(const t_pila *pc, void *dato,unsigned cant_bytes)
{
  unsigned tam_info;
  if(pc->tope == TAM_MAX)
    return 0;

  memcpy(&tam_info,pc->pila +pc->tope,sizeof(unsigned));
  memcpy(dato,pc->pila+pc->tope+sizeof(unsigned),minimo(tam_info,cant_bytes));
  return 1;
}
