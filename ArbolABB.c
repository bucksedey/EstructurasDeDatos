//Arbol ABB
#include <stdio.h>
#include <stdlib.h>

/*Representa un Nodo en el árbol. 
"data" almacena los datos enteros del nodo, 
y tiene dos punteros a otros nodos "left" y "right", */
struct node {
  int data;
  struct node *left;
  struct node *right;
};

/*
newNode es una función auxiliar que se usa para crear un nuevo nodo en el árbol
Toma un entero data como entrada y devuelve un puntero al nodo recién creado.
*/
struct node *newNode(int data) {
  struct node *node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}


//insert es una función recursiva que se utiliza para insertar un nuevo nodo en el árbol.

struct node* insert(struct node* node, int data) //Toma dos argumentos, un puntero a un nodo y un entero
{
  if (node == NULL)  //Si el árbol es vacio, la función devuelve un nuevo nodo con los datos
    return newNode(data); 
  if (data < node->data) //Si el dato es menor que el dato del nodo actual, se inserta el nuevo nodo en el subárbol izquierdo del nodo actual. 
    node->left = insert(node->left, data);
  else if (data > node->data) //Si el dato es mayor, se inserta en el subárbol derecho.
    node->right = insert(node->right, data);
  return node; //devuelve un puntero al nodo raíz del árbol después de insertar el nuevo nodo.
}

//printInorder es una función recursiva que se utiliza para imprimir los datos en el árbol en orden.

void printInorder(struct node *root) //La función toma un puntero al nodo raíz del árbol
{
  if (root != NULL) 
  {
    //recorre el árbol en orden in-order,
    printInorder(root->left);
    printf("%d ", root->data); //imprime los datos de cada nodo en el orden correcto
    printInorder(root->right);
  }
}

int main() {
  //Se define un puntero a un nodo llamado "root" y representa un arbol vacío
  struct node *root = NULL;

  //Arreglo de enteros
  int arr[] = {12,4,5,52,89,74,63,67,90,33,56,78,70,11,1,32,35,88,20,15,100,130,150,200,250,300,350,400,450,500,550};
  //Calcula el numero de elementos en el arreglo
  int n = sizeof(arr)/sizeof(arr[0]);
  int i;
  
  //Insertar los elementos del arreglo en el árbol 
  for (i=0; i<n; i++) {
    root = insert(root, arr[i]); //Inserta los elementos
    printf("Insercion de %d: \n", arr[i]); //Imprime el elemento recién insertado
    printInorder(root); //Imprime la evolución del árbol
    printf("\n");
  }
  return 0;
}
