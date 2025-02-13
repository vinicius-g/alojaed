#include <stdio.h>
#include <stdlib.h>

double somaArestas(int **matriz, int vertices) {
    int i, j;
    double soma = 0;

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (matriz[i][j]) soma += matriz[i][j];
        }
    }

    return soma/vertices;
}

int main() {
    int **matriz, i, j;

    matriz = (int**)malloc(sizeof(int*) * 5);
    for (i = 0; i < 5; i++) {
        matriz[i] = (int*)malloc(sizeof(int) * 5);
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("%lf\n", somaArestas(matriz, 5));
}