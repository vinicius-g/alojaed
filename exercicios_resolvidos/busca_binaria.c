#include <stdio.h>
#include <stdlib.h>

int buscaBin(int x, int tamanho, int vet[]) {
    int esq = -1, dir = tamanho, med;

    while (esq < dir - 1) {
        med = (esq + dir)/2;

        if (vet[med] < x) {
            esq = med;
        } else {
            dir = med;
        }
    }

    if (vet[dir] == x) return dir;
    else return -1;
}

void intercala(int inicio, int meio, int fim, int vet[]) {
    int contadorInicio, contadorMeio, contador, *vet_temp;

    vet_temp = (int*)malloc((fim - inicio) * sizeof(int));

    contadorInicio = inicio;
    contadorMeio = meio;
    contador = 0;

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

void mergeSort(int inicio, int fim, int vet[]) { {
    int meio;

    if (inicio < fim - 1) {
        meio = (inicio + fim) / 2;
        mergeSort(inicio, meio, vet);
        mergeSort(meio, fim, vet);
        intercala(inicio, meio, fim, vet);
    }
}}

int main() {
    int num, i, tamanho = 10, posx;
    int vet[tamanho];

    for (i = 0; i < tamanho; i++) {
        scanf("%d", &vet[i]);
    }

    printf("Pesquisar numero:\n");
    scanf("%d", &num);

    mergeSort(0, tamanho, vet);

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }

    posx = buscaBin(num, tamanho, vet);

    printf("\nPosicao: %d\n", posx);
}
