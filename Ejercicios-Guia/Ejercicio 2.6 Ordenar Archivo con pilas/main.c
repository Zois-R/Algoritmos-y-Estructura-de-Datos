#include <stdio.h>
#include <stdlib.h>
#include "pilaDinamica.h"
#include "archivos.h"
int main()
{
    char nombre_archivo[] = "Productos.dat";

    FILE *pf;

    t_pila pila1,pila2;

    crear_pila(&pila1);
    crear_pila(&pila2);


    pf = fopen(nombre_archivo,"wb");
    if(!pf)
      return -1;

    crear_archivo(&pf);
    fclose(pf);

    pf = fopen(nombre_archivo,"rb");
    if(!pf)
      return -1;

    leer_archivo(&pf);
    fclose(pf);

    ordenar_archivo_con2_pilas(&pila1,&pila2,&pf,nombre_archivo);
    printf("ARCHIVO ORDENADO CON 2 PILAS!!\n");
    pf = fopen(nombre_archivo,"rb");
    if(!pf)
      return -1;

    leer_archivo(&pf);
    fclose(pf);




    return 0;

}
