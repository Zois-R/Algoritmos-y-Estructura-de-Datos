#include <stdio.h>
#include <stdlib.h>

#include "pilaEstatica.h"
int es_par_correspondiente(char a, char b);

/**
Casos borde tambien a tener en cuenta:
Que la cadena esté vacía
Que la cadena tenga caracteres inválidos
Tiene que tener un orden!
En cuanto a límite de espacio de cadena y eso no se considera en el problema así que no se hace.
*/

int main()
{
    t_pila pila1;


    crear_pila(&pila1);

    char c1;
    char cad[] = "[][][]";
    int i = 0;

    if(strlen(cad) == 0)
    {
      printf("Cadena vacía no parentizada\n");
      return -1;
    }

    if(strlen(cad) % 2 != 0)
      {
        printf("Cadena vacía no parentizada");
        return -1;
      }

    while(cad[i] != '\0')
      {
        char actual = cad[i];
        if(actual == '{' || actual == '[' || actual == '(')
            {
              apilar(&pila1,&actual,sizeof(char));
            }
        else if(actual == '}' || actual == ']' || actual == ')')
          {
            if(pila_vacia(&pila1))
              {
                printf("Cadena invalida, cierre sin apertura");
                return -1;
              }

              desapilar(&pila1,&c1,sizeof(char));

              if(!es_par_correspondiente(c1,actual))
                {
                  printf("Cadena invalida, pares no coinciden");
                  return -1;
                }

          }
          else
          {
            printf("Caracter no valido en la cadena\n");
            return -1;
          }
          i++;
      }

      if(pila_vacia(&pila1))
        {
          printf("Está parentizada\n");
          return 0;
        }
      else
        {
          //Si la pila no está vacía faltan cierres ())
          printf("No está parentizada apertura sin cierre\n");
          vaciar_pila(&pila1);
          return -1;
        }




    return 0;
}



int es_par_correspondiente(char a, char b)
{
  if( (a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'))
    return 1;
  return 0;
}
