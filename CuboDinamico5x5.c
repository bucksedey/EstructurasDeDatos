//Cubo dinámico 5x5x5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definimos las dimensiones del cubo
#define DIM 5

//Esta función llena el cubo con valores aleatorios del 1 al 99.
void llena_cubo(int ***cubo, int dim) {
  int count = 1;
  int i,j,k;
  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      for (k = 0; k < dim; k++) {
        cubo[i][j][k] = 1 + rand() % 100;
      }
    }
  }
}

//Imprime una cara específica del cubo en forma de matriz.
void print_cubo_cara(int ***cubo, int dim, int cara) {

    int i,j;
  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      printf("%d\t", cubo[cara][i][j]);
    }
    printf("\n");
  }
}

//Calcula y muestra la suma de cada renglón de una cara específica del cubo.
void renglon_sums(int ***cubo, int dim, int cara) {
  int renglon_sum;
  int i, j;
  printf("Suma de renglones:\n");
  for (i = 0; i < dim; i++) {
    renglon_sum = 0;
    for (j = 0; j < dim; j++) {
      renglon_sum += cubo[cara][i][j];
    }
    printf("Renglon %d: %d\n", i + 1, renglon_sum);
  }
}

//Calcula y muestra la suma de cada columna de una cara específica del cubo.
void col_sums(int ***cubo, int dim, int cara) {
  int col_sum;
  int i,j;
  printf("Suma de columnas:\n");
  for (j = 0; j < dim; j++) {
    col_sum = 0;
    for (i = 0; i < dim; i++) {
      col_sum += cubo[cara][i][j];
    }
    printf("Columna %d: %d\n", j + 1, col_sum);
  }
}

/*
Main crea el cubo, lo llena con llena_cubo, imprime cada cara con print_cubo_cara, 
muestra las sumas de renglones y columnas de cada cara con renglon_sums y col_sums 
y libera la memoria al final.
*/
int main() {
  int ***cubo = (int ***)malloc(DIM * sizeof(int **));
  int i,j;
  for (i = 0; i < DIM; i++) {
    cubo[i] = (int **)malloc(DIM * sizeof(int *));
    for (j = 0; j < DIM; j++) {
      cubo[i][j] = (int *)malloc(DIM * sizeof(int));
    }
  }
  llena_cubo(cubo, DIM);
  int cara;
  for (cara = 0; cara < DIM; cara++) {
    printf("Cara %d:\n", cara + 1);
    print_cubo_cara(cubo, DIM, cara);
    renglon_sums(cubo, DIM, cara);
    col_sums(cubo, DIM, cara);
    printf("\n");
  }

  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      free(cubo[i][j]);
    }
    free(cubo[i]);
  }
  free(cubo);
  return 0;
}