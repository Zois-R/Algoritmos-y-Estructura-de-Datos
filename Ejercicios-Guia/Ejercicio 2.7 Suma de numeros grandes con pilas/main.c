#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio.h"


int main()
{
    char num1[] = "0000000";
    char num2[] = "1";

    t_pila pila1;
    t_pila pila2;
    t_pila pila_temp;

    crear_pila(&pila1);
    crear_pila(&pila2);
    crear_pila(&pila_temp);
    int num;
   volcar_numeros_desde_final(&pila1,&pila2,num1,num2,strlen(num1),strlen(num2));

   sumar_pilas(&pila1,&pila2,&pila_temp);

   while(!pila_vacia(&pila_temp))
    {
      desapilar(&pila_temp,&num,sizeof(int));
      printf("[%d] ",num);
    }

    return 0;
}
