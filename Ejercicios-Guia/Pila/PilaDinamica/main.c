#include <stdio.h>
#include <stdlib.h>
#include "pilaDinamica.h"
int main()
{
    t_pila mi_pila;

    crear_pila(&mi_pila);


    printf("%p",&mi_pila);
    return 0;
}
