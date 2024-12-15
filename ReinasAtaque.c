// Programa en C para resolver el problema de las N Reinas usando backtracking
#define N 8
#include <stdbool.h>
#include <stdio.h>

/* Función que imprime la solución */
void imprimeSolucion(int tablero[N][N])
{
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf(" %d ", tablero[i][j]);
        printf("\n");
    }
}

/* Verifica si es seguro colocar una reina en tablero[fila][columna] */
bool esSeguro(int tablero[N][N], int fila, int col)
{
    int i, j;

    // Verifica fila a la izquierda
    for (i = 0; i < col; i++)
        if (tablero[fila][i])
            return false;

    // Verifica diagonal superior izquierda
    for (i = fila, j = col; i >= 0 && j >= 0; i--, j--)
        if (tablero[i][j])
            return false;

    // Verifica diagonal inferior izquierda
    for (i = fila, j = col; j >= 0 && i < N; i++, j--)
        if (tablero[i][j])
            return false;

    return true;
}

/* Función recursiva para resolver el problema de las N Reinas */
bool resuelveNReinas(int tablero[N][N], int col)
{
    int i;
    // Caso base: si todas las reinas están colocadas, retorna true
    if (col >= N)
        return true;

    // Intenta colocar la reina en cada fila de esta columna
    for (i = 0; i < N; i++) {
        // Si es seguro, coloca la reina
        if (esSeguro(tablero, i, col)) {
            tablero[i][col] = 1;

            // Recursión para colocar las siguientes reinas
            if (resuelveNReinas(tablero, col + 1))
                return true;

            // Si no se encuentra solución, retrocede
            tablero[i][col] = 0; // BACKTRACK
        }
    }

    // Si no se puede colocar una reina en esta columna, retorna false
    return false;
}

/* Resuelve el problema de las N Reinas usando backtracking */
bool solucionNR()
{
    int tablero[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    // Si no hay solución, muestra un mensaje de error
    if (resuelveNReinas(tablero, 0) == false) {
        printf("No existe solución\n");
        return false;
    }

    // Muestra la solución encontrada
    imprimeSolucion(tablero);
    return true;
}

// Función principal para probar el código
int main()
{
    solucionNR();
    return 0;
}
