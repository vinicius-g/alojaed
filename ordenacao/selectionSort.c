#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int tamanho, int vet[]) {
    int i, j, min, aux;

    for (i = 0; i < tamanho-1; i++) {
        min = i;

        for (j = i+1; j < tamanho; j++) {
            if (vet[j] < vet[min]) min = j;
        }

        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
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

    selectionSort(tamanho, vet);

    printf("\nVetor ordenado:\n");

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
}
