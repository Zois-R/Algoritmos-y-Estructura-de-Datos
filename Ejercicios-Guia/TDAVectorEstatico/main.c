#include <stdio.h>
#include <stdlib.h>
#include "VectorEstatico.h"



int main()
{

    t_vectore vector;
    int *valor;
    int n1 = 1, n2 = 2, n3 = 5, n4 = 7;
    int test = 4;

    crearVector(&vector,sizeof(int),5);
    insertarEnVector(&vector,sizeof(int),&n1);
    insertarEnVector(&vector,sizeof(int),&n2);
    insertarEnVector(&vector,sizeof(int),&n3);
    insertarEnVector(&vector,sizeof(int),&n4);


    insertarElementoEnOrden(&vector,sizeof(int),&test,cmpInt);
    for(int i= 0; i<vector.tope/sizeof(int);i++)
      {
        int *elemento_actual = (int*)(vector.vec + (i * vector.tam_dato));
        printf("[%d] ",*elemento_actual);
      }


    valor = (int*)verElementoPorPos(&vector,sizeof(int),3);
    printf("\nValor obtenido por pos %d\n",*valor);


    eliminar_elemento(&vector,&n1,sizeof(int),cmpInt);

    for(int i= 0; i<vector.tope/sizeof(int);i++)
      {
        int *elemento_actual = (int*)(vector.vec + (i * vector.tam_dato));
        printf("[%d] ",*elemento_actual);
      }
    return 0;
}

/**
Es un vector de char
No puedo imrpimir con $d
Y cantidad de elementos en mi implementación me indica cantidad de numeros totales no de los que realmente tengo.
Con vector->tope verifico actuales
   for(int i= 0; i<vector.ce;i++)
      {
        printf("[%d]",vector.vec[i]);
      }
*/





