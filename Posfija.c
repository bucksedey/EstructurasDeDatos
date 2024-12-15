//Este programa implementa una pila y realiza cálculos en notación posfija.
#include<stdio.h>
#include<math.h>

//La pila se define con un arreglo de 20 elementos 
//y un contador de "top" inicializado en -1.
int pila[20];
int top = -1;

//La función "push" agrega un elemento "x" en la cima de la pila y aumenta el contador de "top".
void push(int x)
{
    pila[++top] = x;
}

//La función "pop" devuelve el elemento en la cima de la pila y disminuye el contador de "top".
int pop()
{
    return pila[top--];
}

int main()
{
    char exp[20];
    char *e;
    int n1,n2,n3,num;

    //Se pide al usuario ingresar una expresión en notación posfija.
    printf("Ingresa la expresion: ");
    scanf("%s",exp);

    //Se crea un puntero "e" que apunta al inicio de la expresión.
    e = exp;

    //Se usa un ciclo "while" para recorrer la expresión carácter por carácter.
    while(*e != '\0')
    {
        //Si el carácter es un dígito, se convierte a un entero y se agrega a la pila con la función "push
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }//Si el carácter es un operador, se sacan dos elementos de la pila y se realiza la operación correspondiente con un "switch". 
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            case '^':
            {
                n3 = pow(n2,n1);
            }
            }
            push(n3); //El resultado se agrega de nuevo a la pila.
        }
        e++;
    }
    //Al final, se imprime el resultado de la expresión.
    printf("\nEl resultado de la expresion %s  =  %d\n\n",exp,pop());
    return 0;
}