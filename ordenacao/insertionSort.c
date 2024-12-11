#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int tamanho, int vetor[]) {
    int i, j, item;

    for (j = 1; j < tamanho; j++) {
        item = vetor[j];

        for (i = j-1; i >= 0 && vetor[i] > item; i--) {
            vetor[i+1] = vetor[i];
        }

        vetor[i+1] = item;
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

    insertionSort(tamanho, vet);

    printf("\nVetor ordenado:\n");

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
}
