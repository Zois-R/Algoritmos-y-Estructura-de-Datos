#include "ejercicio.h"



void volcar_numeros_desde_final(t_pila *p1, t_pila *p2, const char *n1, const char *n2,
                                size_t tam_n1, size_t tam_n2)
{
  while(*n1)
    {
      apilar(p1,n1,sizeof(char));
      n1++;
    }

  while(*n2> 0)
    {
      apilar(p2,n2,sizeof(char));
      n2++;
    }


}


void sumar_pilas(t_pila *p1, t_pila *p2, t_pila *ptemp)
{
  int suma, resto = 0;
  char num_p1, num_p2;
  int suma_parcial;
  while(!pila_vacia(p1) && !pila_vacia(p2))
  {
    desapilar(p1,&num_p1,sizeof(char));
    desapilar(p2,&num_p2,sizeof(char));
    suma = (num_p1-48) + (num_p2 -48) + resto;
    if(suma + resto > 9)
    {
      resto = suma / 10;
      suma = suma % 10;
    }
    else
      {
        resto = 0;
      }
    apilar(ptemp,&suma,sizeof(int));

  }

  if(resto > 0 && pila_vacia(p1) && pila_vacia(p2))
    {
      apilar(ptemp,&resto,sizeof(int));
    }

  while(pila_vacia(p1) && !pila_vacia(p2))
    {
      desapilar(p2,&num_p2,sizeof(char));

      suma_parcial = (num_p2 - 48) + resto;
      if(suma_parcial > 9)
        {
          resto = suma_parcial / 10;
          suma_parcial = suma_parcial % 10;
        }
      else
        {
          resto = 0;
        }
      apilar(ptemp,&suma_parcial,sizeof(int));
    }

  while(pila_vacia(p2) && !pila_vacia(p1))
    {
      desapilar(p1,&num_p1,sizeof(char));

      suma_parcial = (num_p1 - 48) + resto;
      if(suma_parcial > 0)
        {
          resto = suma_parcial / 10;
          suma_parcial = suma_parcial % 10;
        }
      else
      {
        resto = 0;
      }
      apilar(ptemp,&suma_parcial,sizeof(int));
    }

  if(resto > 0)
    {
      apilar(ptemp,&resto,sizeof(int));
    }

}
