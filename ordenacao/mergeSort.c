#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercalaVetor(int inicio, int meio, int fim, int vet[]) {
    int contadorInicio, contadorMeio, contador = 0, *vet_temp;

    vet_temp = (int*)malloc((fim - inicio) * sizeof(int));
    contadorInicio = inicio;
    contadorMeio = meio;

    while (contadorInicio < meio && contadorMeio < fim) {
        if (vet[contadorInicio] <= vet[contadorMeio]) vet_temp[contador++] = vet[contadorInicio++];
        else vet_temp[contador++] = vet[contadorMeio++];
    }

    while (contadorInicio < meio) vet_temp[contador++] = vet[contadorInicio++];
    while (contadorMeio < fim) vet_temp[contador++] = vet[contadorMeio++];

    for (contadorInicio = inicio; contadorInicio < fim; contadorInicio++) {
        vet[contadorInicio] = vet_temp[contadorInicio - inicio];
    }

    free(vet_temp);
}

void mergeSort(int inicio, int fim, int vet[]) {
    int meio;

    if (inicio < fim - 1) {
        meio = (inicio + fim)/2;

        mergeSort(inicio, meio, vet);
        mergeSort(meio, fim, vet);
        intercalaVetor(inicio, meio, fim, vet);
    }
}

int main() {
    int tamanho = 10;
    int vet[tamanho];
    int i;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++) {
        vet[i] = rand() % 11;
    }

    printf("Vetor original:\n");

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }

    mergeSort(0, tamanho, vet);

    printf("\nVetor ordenado:\n");

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }

    printf("\n");
}
