#TIPS PARA CODEAR MEJOR QUE FUI ENCONTRANDO A MEDIDA QUE HACÍA EJERCICIOS

##1.Devolución de resultados

En una función donde tenía que devolver un entero que era producto de una operación que recibía como parámetro me di cuenta que siempre
devolvía un entero sin importar que. El problema de esto es que no sabes si la función devuelve un error o un resultado.
Esta era la función:

int operacion(int a, int b, char op)
{
  if(op == '+')
    return  a + b;
  else if(op == '-')
    return a - b;
  else if(op == '*')
    return a * b;
  else if(op == '/')
    return a/b;

  printf("Error de operación\n");
  exit(1);

}

Mas allá del exit(1); que es una práctica horrible porque termina el programa abruptamente y podría traer problemas, ¿Qué pasaba si el *char* op no
era ni + - * o /? Pensaba en retornar un 1 o 0 como verdadero o falso. Pero eso estaría mal ya que 1 o 0 podría ser resultado de una de esas operaciones
entre a y b. Entonces lo que se hace como buenas prácticas es manejar el resultado de esa operación como un puntero a un entero (en este caso porque son enteros) 
que se recibe como parámetro de la función. De esta manera entonces si puedo retornar un 1 o 0 indicando éxito en la operación. Además de que se cambia los if por un switch, si me da 1 en algúno de los casos del  switch salió todo bien. Si me da 0 al final es porque no entró a ningún caso y el operador puede ser cualquier otro carácter no válido.

int operacion(int a, int b, char op, *int \*res*)
{
    *switch(op)*
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