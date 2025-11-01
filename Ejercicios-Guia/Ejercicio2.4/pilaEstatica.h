#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PILA 1024
#define minimo(x,y) (x < y ? x : y)


typedef struct
{
  char pila[TAM_PILA];
  unsigned tope;
}t_pila;


void crear_pila(t_pila *pc);
int pila_vacia(const t_pila *pc);
int pila_llena(const t_pila *pc, unsigned cant_bytes);
int apilar(t_pila *pc, const void *dato, unsigned cant_bytes);
int desapilar(t_pila *pc, void *dato, unsigned cant_bytes);
int ver_tope(const t_pila *pc, void *dato, unsigned cant_bytes);
void vaciar_pila(t_pila *pc);


#endif // PILAESTATICA_H_INCLUDED
