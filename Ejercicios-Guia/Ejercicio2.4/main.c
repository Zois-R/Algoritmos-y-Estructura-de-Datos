#include <stdio.h>
#include <stdlib.h>
#include "pilaEstatica.h"
#include "archivo.h"
/**
La finalidad del ejercicio es usar mi archivo binario como memoria persistente en mi programa
Y la pila que está en RAM como un modificador de estado de mi programa. Es decir, en el archivo yo lo
voy a bajar a la pila para luego hacer cosas con el menú y cuando salgo volver a guardar todos los cambios
en mi archivo de nuevo sobreescribiendolo.
*/


int main()
{
    FILE *pf;
    t_pila pila_prods;

    crear_pila(&pila_prods);

    pf = fopen("Productos.dat","wb");
    if(!pf)
      return -1;
    crear_archivo_prods(&pf);
    fclose(pf);

    pf = fopen("Productos.dat","rb");
    if(!pf)
      return -1;
    leer_archivo_y_cargar_pila(&pf,&pila_prods);
    fclose(pf);

    menu(&pila_prods,&pf);

    pf = fopen("Productos.dat","rb");
    if(!pf)
      return -1;
    leer_archivo(&pf);
    fclose(pf);
    return 0;
}
