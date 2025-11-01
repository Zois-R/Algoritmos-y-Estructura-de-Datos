#include "archivo.h"



void crear_archivo_prods(FILE **pf)
{
  t_producto vec_prods[] = {{"111110","Manzana","Carlitos"},
                            {"933111","Banana","Carlitos"},
                            {"000213","Televisor","Samsung"},
                            {"101449","Chirimoya","Ernesto"},
                            {"904811","Escopeta","Bush"},
                            {"003256","Enduido","Alba"},
                            {"588191","Gas napalm","Black wather"},
                            };

  fwrite(vec_prods,sizeof(vec_prods),1,*pf);

}


void leer_archivo_y_cargar_pila(FILE **pf,t_pila *pc)
{
  t_producto prod;

  printf("COD PROD    DESCRIPCION       PROVEEDOR\n");
  fread(&prod,sizeof(t_producto),1,*pf);

  while(!feof(*pf))
    {
      apilar(pc,&prod,sizeof(t_producto));
      printf("%s %15s %15s\n",prod.cod_prod,prod.descripcion,prod.proveedor);
      fread(&prod,sizeof(t_producto),1,*pf);
    }
}



int menu(t_pila *pc,FILE **pf)
{
  t_producto prod;
  int opc;






    do{

      printf("\n--- MENÚ DE STOCK ---\n");
    printf("1. Apilar producto\n");
    printf("2. Ver tope de la pila\n");
    printf("3. Desapilar producto\n");
    printf("4. Limpiar pantalla\n");
    printf("5. Salir y Guardar\n");

     printf("Ingrese opcion:\n");
      scanf("%d",&opc);
      switch(opc)
      {
      case 1:
        fflush(stdin);
        printf("Ingrese codigo prod\n");
        scanf("%[^\n]",prod.cod_prod);
        fflush(stdin);
        printf("Ingrese descripcion\n");
        scanf("%[^\n]",prod.descripcion);
        printf("Ingrese proveedor del producto\n");
        fflush(stdin);
        scanf("%[^\n]",prod.proveedor);
        apilar(pc,&prod,sizeof(t_producto));

        break;
      case 2:
        ver_tope(pc,&prod,sizeof(t_producto));
        printf("Producto solicitado:\n%s %s %s\n",prod.cod_prod,prod.descripcion,prod.proveedor);
        break;
      case 3:
        desapilar(pc,&prod,sizeof(t_producto));
        printf("Producto eliminado de stock:\n %s %s %s\n",prod.cod_prod,
               prod.descripcion,prod.proveedor);
        break;
      case 4:
        system("cls");
        break;


      case 5:
         printf("Saliendo del programa...\n");

        break;
      default:
        printf("Opcion no valida, intente de nuevo\n");
        break;

      }

    }while(opc != 5);

    *pf = fopen("Productos.dat","wb");
    desapilar_y_cargar_archivo(pc,pf);
    fclose(*pf);

    return 1;
}



void desapilar_y_cargar_archivo(t_pila *pc, FILE **pf)
{
  t_producto prod;
  while(!pila_vacia(pc))
    {
      desapilar(pc,&prod,sizeof(t_producto));
      fwrite(&prod,sizeof(t_producto),1,*pf);
    }
}


void leer_archivo(FILE **pf)
{
  t_producto prod;

  printf("COD PROD    DESCRIPCION       PROVEEDOR\n");
  fread(&prod,sizeof(t_producto),1,*pf);

  while(!feof(*pf))
    {

      printf("%s %15s %15s\n",prod.cod_prod,prod.descripcion,prod.proveedor);
      fread(&prod,sizeof(t_producto),1,*pf);
    }
}
