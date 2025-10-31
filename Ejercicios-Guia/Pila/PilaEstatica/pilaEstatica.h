#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAM_MAX 300
#define minimo(x,y) ( x < y ? x : y)
typedef struct
{
  char pila[TAM_MAX];
  unsigned tope;

}t_pila;

void crear_pila(t_pila *pc);
int pilla_llena(const t_pila *pc, unsigned cantBytes);
int pila_vacia(const t_pila *pc);
int poner_en_pila(t_pila *pc, void *dato, unsigned cant_bytes);
int sacar_de_pila(t_pila *pc, void *d, unsigned cantBytes);
void vaciar_pila(t_pila *pc);
int ver_tope(const t_pila *pc, void *dato,unsigned cant_bytes);



#endif // PILAESTATICA_H_INCLUDED
