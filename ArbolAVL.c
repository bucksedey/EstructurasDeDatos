//Árbol AVL
#include <stdio.h>
#include <stdlib.h>

//Definición de la estructura nodo
struct Nodo {
  int dato;
  int altura;
  struct Nodo* izq; //Hijo izquierdo
  struct Nodo* der; //Hijo derecho
};

//max devuelve el número más grande de dos números dados
int max(int a, int b) {
  return (a > b) ? a : b;
}

//altura devuelve la altura de un nodo dado o 0 en caso de ser nulo
int altura(struct Nodo* nodo) {
  if (nodo == NULL) {
    return 0;
  }
  return nodo->altura;
}

//nuevo_nodo crea un nuevo nodo y lo inicializa con los valores predeterminados
struct Nodo* nuevo_nodo(int dato) {
  struct Nodo* nodo = (struct Nodo*) malloc(sizeof(struct Nodo));
  nodo->dato = dato;
  nodo->altura = 1;
  nodo->izq = NULL;
  nodo->der = NULL;
  return nodo;
}

//Realiza la rotación derecha para mantener el equilibrio
struct Nodo* der_rota(struct Nodo* nodo) {
  struct Nodo* x = nodo->izq;
  struct Nodo* y = x->der;

  x->der = nodo;
  nodo->izq = y;

  nodo->altura = max(altura(nodo->izq), altura(nodo->der)) + 1;
  x->altura = max(altura(x->izq), altura(x->der)) + 1;

  return x;
}

//Realiza la rotación izquierda para mantener el equilibrio
struct Nodo* izq_rota(struct Nodo* nodo) {
  struct Nodo* x = nodo->der;
  struct Nodo* y = x->izq;

  x->izq = nodo;
  nodo->der = y;

  nodo->altura = max(altura(nodo->izq), altura(nodo->der)) + 1;
  x->altura = max(altura(x->izq), altura(x->der)) + 1;

  return x;
}


//Devuelve la diferencia entre la altura del hijo izquierdo y el hijo derecho de un nodo
int factor_balanceo(struct Nodo* nodo) {
  if (nodo == NULL) {
    return 0;
  }
  return altura(nodo->izq) - altura(nodo->der);
}

//Inserta un nuevo dato en el árbol y mantiene su equilibrio
struct Nodo* insert(struct Nodo* nodo, int dato) {
  if (nodo == NULL) { //Verifica si el nodo actual es nulo
    return nuevo_nodo(dato); //Si es así crea un nuevo nodo
  }

  if (dato < nodo->dato) { //Si el dato es menor que el nodo actual, se inserta el hijo izquierdo
    nodo->izq = insert(nodo->izq, dato);
  } else if (dato > nodo->dato) { //Si es mayor, se inserta en el hijo derecho
    nodo->der = insert(nodo->der, dato);
  } else { //Si el dato es igual al nodo actual, nose hace nada
    return nodo;
  }

  //La función actualiza la altura del nodo actual
  nodo->altura = 1 + max(altura(nodo->izq), altura(nodo->der));

  //Se verifica si el árbol está desequilibrado y se hace una de las 4 rotaciones para equilibrarlo
  int balance = factor_balanceo(nodo);

  if (balance > 1 && dato < nodo->izq->dato) {
    return der_rota(nodo);
  }

  if (balance < -1 && dato > nodo->der->dato) {
    return izq_rota(nodo);
  }

  if (balance > 1 && dato > nodo->izq->dato) {
    nodo->izq = izq_rota(nodo->izq);
    return der_rota(nodo);
  }

  if (balance < -1 && dato < nodo->der->dato) {
    nodo->der= der_rota(nodo->der);
return izq_rota(nodo);
}

return nodo; //devuelve el nodo actual
}

//Recorre el árbol en pre-orden e imprime los datos de cada nodo
void pre_order(struct Nodo* nodo) {
if (nodo != NULL) {
printf("%d ", nodo->dato);
pre_order(nodo->izq);
pre_order(nodo->der);
}
}

int main() {

//Creamos una lista de valores enteros
int lista[] = {12,4,5,52,89,74,63,67,90,33,56,78,70,11,1,32,35,88,20,15,100,130,150,200,250,300,350,400,450,500,550};
//Calculamos el número de elementos de la lista
int size = sizeof(lista) / sizeof(lista[0]);
////Se define un puntero a un nodo llamado "root" y representa un arbol vacío
struct Nodo* root = NULL;

int i;
//Insertaremos todos los elementos de la lista a nuestro arbol y mostraremos su evolución
for (i = 0; i < size; i++) {
printf("Insertando %d: ", lista[i]); //Mostramos el dato insertado
root = insert(root, lista[i]); //Insertamos el dato al árbol
pre_order(root); //Imprime el arbol en pre_orden
printf("\n");
}

return 0;
}
