#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insereHeap(int i, int vet[]) {
    int f = i+1;

    while (f > 1 && vet[f/2] < vet[f]) {
        int aux = vet[f/2];
        vet[f/2] = vet[f];
        vet[f] = aux;

        f = f/2;
    }
}

void rearranjaHeap(int i, int vet[]) {
    int aux, f = 2;

    while (f <= i) {
        if (f < i && vet[f] < vet[f+1]) ++f;
        if (vet[f/2] >= vet[f]) break;

        aux = vet[f/2];
        vet[f/2] = vet[f];
        vet[f] = aux;

        f *= 2;
    }
}

void heapSort(int tamanho, int vet[]) {
    int i;

    for (i = 1; i < tamanho; i++) {
        insereHeap(i, vet);
    }

    for (i = tamanho; i > 1; i--) {
        int aux = vet[1];
        vet[1] = vet[i];
        vet[i] = aux;
        rearranjaHeap(i-1, vet);
    }
}

int main() {
    int tamanho = 10;
    int vet[tamanho], i;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++) {
        vet[i] = rand() % 11;
    }

    printf("Vetor original:\n");

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }

    heapSort(tamanho - 1, vet);

    printf("\nVetor ordenado:\n");

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
}
