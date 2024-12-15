#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISCOS 100

typedef struct {
    int data[MAX_DISCOS];
    int tope;
} Pila;

void inicializar(Pila *s) {
    s->tope = -1;
}

bool es_vacia(Pila *s) {
    return s->tope == -1;
}

bool esta_llena(Pila *s) {
    return s->tope == MAX_DISCOS - 1;
}

void push(Pila *s, int item) {
    if (!esta_llena(s)) {
        s->tope++;
        s->data[s->tope] = item;
    } else {
        printf("Error: esta llena\n");
        exit(1);
    }
}

int pop(Pila *s) {
    if (!es_vacia(s)) {
        int item = s->data[s->tope];
        s->tope--;
        return item;
    } else {
        printf("Error: Pila esta vacia\n");
        exit(1);
    }
}

void mueve_disco(int disco, char desde_palo, char hacia_palo, char aux_palo) {
    printf("Mueve el disco %d desde palo %c hacia palo %c\n", disco, desde_palo, hacia_palo);
}

void hanoi(int n, char desde_palo, char hacia_palo, char aux_palo, Pila *origen, Pila *destino, Pila *auxiliar) {
    int disco;
    if (n == 1) {
        disco = pop(origen);
        push(destino, disco);
        mueve_disco(disco, desde_palo, hacia_palo, aux_palo);
    } else {
        hanoi(n - 1, desde_palo, aux_palo, hacia_palo, origen, auxiliar, destino);
        disco = pop(origen);
        push(destino, disco);
        mueve_disco(disco, desde_palo, hacia_palo, aux_palo);
        hanoi(n - 1, aux_palo, hacia_palo, desde_palo, auxiliar, destino, origen);
    }
}

int main() {
    int n;
    Pila origen, destino, auxiliar;

    printf("Ingresa el numero de discos: ");
    scanf("%d", &n);

    inicializar(&origen);
    inicializar(&destino);
    inicializar(&auxiliar);

    int i;
    for (i = n; i >= 1; i--) {
        push(&origen, i);
    }

    hanoi(n, 'A', 'C', 'B', &origen, &destino, &auxiliar);

    return 0;
}
