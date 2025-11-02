#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PILA 300
#define minimo(x,y) ( x < y ? x : y)
typedef struct
{
  char pila[TAM_PILA];
  unsigned tope;
}t_pila;


void crear_pila(t_pila *pp);
int pila_llena(const t_pila *pp,unsigned cant_bytes);
int pila_vacia(const t_pila *pp);
int apilar(t_pila *pp, const void *d, unsigned cant_bytes);
int desapilar(t_pila *pp, void *d, unsigned cant_bytes);
int ver_tope(const t_pila *pp, void *d, unsigned cant_bytes);
void vaciar_pila(t_pila *pp);


#endif // PILAESTATICA_H_INCLUDED
