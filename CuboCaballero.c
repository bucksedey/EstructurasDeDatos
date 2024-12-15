#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int matrix[SIZE][SIZE][SIZE];

// Funcion que suma todos los elementos de un renglón
int sumRow(int x, int y)
{
    int i, sum = 0;
    for (i = 0; i < SIZE; i++)
        sum += matrix[x][y][i];
    return sum;
}

// Función que suma todos los elementos de una columna
int sumColumn(int x, int y)
{
    int i, sum = 0;
    for (i = 0; i < SIZE; i++)
        sum += matrix[x][i][y];
    return sum;
}

// Función que suma todos los elementos de una cara
int sumFace(int x)
{
    int i, j, sum = 0;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            sum += matrix[x][i][j];
    return sum;
}

// Función que suma todos los elementos de una diagonal
int sumDiagonal(int x, int y)
{
    int i, sum = 0;
    for (i = 0; i < SIZE; i++)
        sum += matrix[i][i][i];
    return sum;
}

// Función que muestra los valores del cubo
void displayCube()
{
    int i, j, k;
    for (i = 0; i < SIZE; i++) {
        printf("Face %d:\n", i + 1);
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++)
                printf("%d ", matrix[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
}

int main()
{
    int i, j, k;

    // Llena la matriz con valores aleatorios
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            for (k = 0; k < SIZE; k++)
                matrix[i][j][k] = rand() % 10;

    // Llama a las funciones para llevar a cabo varias operaciones
    int row_sum = sumRow(1, 1);
    int col_sum = sumColumn(1, 1);
    int face_sum = sumFace(1);
    int diagonal_sum = sumDiagonal(0, 0);

    printf("Sum of row: %d\n", row_sum);
    printf("Sum of column: %d\n", col_sum);
    printf("Sum of face: %d\n", face_sum);
    printf("Sum of diagonal: %d\n", diagonal_sum);
    printf("\n");

    // Display the values of the cube
    displayCube();

    return 0;
}
