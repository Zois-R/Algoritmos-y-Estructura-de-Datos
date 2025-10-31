#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define minimo(x,y) ( x < y ? x : y)
typedef struct s_nodo
{
  void *info;
  unsigned tam_info;
  struct s_nodo *sig;
}t_nodo;

typedef t_nodo *t_pila;

void crear_pila(t_pila *pc);
int pila_llena(const t_pila *pc, unsigned cant_bytes);
int pila_vacia(const t_pila *pc);

int apilar(t_pila *pc, const void *dato, unsigned cant_bytes);
int desapilar(t_pila *pc, void *dato, unsigned cant_bytes);
int ver_tope(const t_pila *pc,void *dato,unsigned cant_bytes);
void vaciar_pila(t_pila *pc);
#endif // PILADINAMICA_H_INCLUDED
