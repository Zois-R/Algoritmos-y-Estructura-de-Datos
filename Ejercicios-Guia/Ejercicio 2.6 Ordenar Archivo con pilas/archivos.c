#include "archivos.h"
#include "pilaDinamica.h"

void crear_archivo(FILE **pf)
{
  t_producto prods[] = {
    {"111110", "Manzana", "Carlitos"},
    {"933111", "Banana", "Carlitos"},
    {"000213", "Televisor", "Samsung"},
    {"101449", "Chirimoya", "Ernesto"},
    {"904811", "Escopeta", "Bush"},
    {"003256", "Enduido", "Alba"},
    {"588191", "Gas napalm", "Black wather"},
    {"222333", "Mouse", "Logitech"}
      };

  fwrite(prods,sizeof(prods),1,*pf);
}

void leer_archivo(FILE **pf)
{
  t_producto prod;

  fread(&prod,sizeof(t_producto),1,*pf);
  while(!feof(*pf))
    {
      printf("%s %s %s\n",prod.cod_prod,prod.desc,prod.proov);
      fread(&prod,sizeof(t_producto),1,*pf);
    }
}


void ordenar_archivo_con2_pilas(t_pila *pp1,t_pila *pp2, FILE **pf, const char *nombre_archivo)
{
  t_producto prod;
  t_producto prodpila1;
  t_producto prodpila2;

  *pf = fopen(nombre_archivo,"rb");
  if(!*pf)
    return;

  fread(&prod,sizeof(t_producto),1,*pf);
  apilar(pp1,&prod,sizeof(t_producto));
  while(!feof(*pf))
    {
      fread(&prod,sizeof(t_producto),1,*pf);
      ver_tope(pp1,&prodpila1,sizeof(t_producto));
      if( strcmp(prod.cod_prod,prodpila1.cod_prod) < 0 && (pila_vacia(pp2)))
        {
          apilar(pp1,&prod,sizeof(t_producto));
        }
        else if( strcmp(prod.cod_prod,prodpila1.cod_prod) < 0 && (!pila_vacia(pp2)))
      {
        ver_tope(pp2,&prodpila2,sizeof(t_producto));
        while( strcmp(prod.cod_prod,prodpila2.cod_prod) < 0 && !pila_vacia(pp2))
          {
            desapilar(pp2,&prodpila2,sizeof(t_producto));
            apilar(pp1,&prodpila2,sizeof(t_producto));
            ver_tope(pp2,&prodpila2,sizeof(t_producto));
          }
        apilar(pp2,&prod,sizeof(t_producto));
      }

      if(  strcmp(prod.cod_prod,prodpila1.cod_prod) > 0 && (pila_vacia(pp2)) )
      {
        while(!pila_vacia(pp1))
          {
            desapilar(pp1,&prodpila1,sizeof(t_producto));
            apilar(pp2,&prodpila1,sizeof(t_producto));
          }
        apilar(pp1,&prod,sizeof(t_producto));

      }
      else if(strcmp(prod.cod_prod,prodpila1.cod_prod) > 0 && (!pila_vacia(pp2)) )
        {
          desapilar(pp1,&prodpila1,sizeof(t_producto));
          apilar(pp2,&prodpila1,sizeof(t_producto));
        }


    }

    while(!pila_vacia(pp2))
      {
        desapilar(pp2,&prodpila2,sizeof(t_producto));
        apilar(pp1,&prodpila2,sizeof(t_producto));
      }

   fclose(*pf);

   *pf = fopen(nombre_archivo,"wb");
   if(!*pf)
        return;

   while(!pila_vacia(pp1))
    {
      desapilar(pp1,&prodpila1,sizeof(t_producto));
      fwrite(&prodpila1,sizeof(t_producto),1,*pf);
    }

    fclose(*pf);
}
