#include <stdio.h>
#include <stdlib.h>
#include "pilaDinamica.h"

int ejercicio(t_pila *p, const char *cad_postfija, int *res);
int es_digito(char d);
int operacion(int a, int b, char op, int *res);
int es_operando(char op);
int main()
{
    char expresion[] = "5 6 +";
    t_pila pila;
    int res;
    crear_pila(&pila);

    ejercicio(&pila,expresion,&res);
    printf("Resultado de cadena postfija: %d\n",res);

    return 0;
}


int ejercicio(t_pila *p, const char *cad_postfija, int *res)
{
  int n1,n2;
  int act;


  while(*cad_postfija)
    {
      if(es_digito(*cad_postfija))
        {
          act = *cad_postfija - 48;
          apilar(p,&act,sizeof(int));
        }

      if(es_operando(*cad_postfija))
        {
          desapilar(p,&n1,sizeof(int));
          desapilar(p,&n2,sizeof(int));
         if(!operacion(n2,n1,*cad_postfija,res)) //tengo que invertir los numeros si primero está el 80 y como tope un 2 tiene que ser 80 - 2 y no 2-80
          {
            printf("Error: operador invalido o division por cero\n");
            vaciar_pila(p);
            return 0;
          }

          apilar(p,res,sizeof(int));
        }
        cad_postfija++;
    }
    if(!desapilar(p,res,sizeof(int)))
      {
        //Si la pila está vacía (cadena vacía) hay un error
        printf("Expresion invalida o cadena vacia\n");
        return 0;
      }


    if(!pila_vacia(p))
      {
        printf("Error: Expresion mal formada, sobran operandos \n");
        vaciar_pila(p);
        return 0;
      }
    return 1;
}


int es_digito(char d)
{
  return (d >= '0' && d <= '9') ?1:0;

}
int operacion(int a, int b, char op, int *res)
{
    switch(op)
    {
        case '+':
            *res = a + b;
            return 1; // Éxito
        case '-':
            *res = a - b;
            return 1; // Éxito
        case '*':
            *res = a * b;
            return 1; // Éxito
        case '/':
            if (b == 0)
            {
                printf("Error: Division por cero.\n");
                return 0; // Error
            }
            *res = a / b;
            return 1; // Éxito
        default:
            // Operador no válido, no hacemos nada y devolvemos error
            return 0; // Error
    }
}

int es_operando(char op)
{
  return op == '+' || op == '-' || op == '*' || op == '/';
}
