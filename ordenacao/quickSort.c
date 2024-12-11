#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int separaVetor(int inicio, int fim, int vet[]) {
    int pivo, contadorInicio, contador, aux;

    pivo = vet[fim];
    contadorInicio = inicio;

    for (contador = inicio; contador < fim; contador++) {
        if (vet[contador] <= pivo) {
            aux = vet[contadorInicio];
            vet[contadorInicio] = vet[contador];
            vet[contador] = aux;
            contadorInicio++;
        }
    }

    vet[fim] = vet[contadorInicio];
    vet[contadorInicio] = pivo;
    return contadorInicio;
}

void quickSort(int inicio, int fim, int vet[]) {
    int pivo;

    if (inicio < fim) {
        pivo = separaVetor(inicio, fim, vet);

        quickSort(inicio, pivo-1, vet);
        quickSort(pivo+1, fim, vet);
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

    quickSort(0, tamanho - 1, vet);

    printf("\nVetor ordenado:\n");

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
}
