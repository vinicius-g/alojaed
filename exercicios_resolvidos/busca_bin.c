#include <stdio.h>
#include <stdlib.h>

int buscaBin(int vet[], int inicio, int tam, int busca) {
    int start = inicio, end = tam, mid = (start + end)/2;

    if (busca == vet[mid]) return mid;
    if (start >= end - 1 && busca != vet[(start+end)/2]) return tam;

    if (vet[mid] >= busca) {
        return buscaBin(vet, inicio, mid, busca);
    } else {
        return buscaBin(vet, (start+end)/2, tam, busca);
    }
}

int main() {
    int vet[8] = {1, 2, 3, 4, 5, 6, 7, 8}, num;

    scanf("%d", &num);

    printf("%d\n", buscaBin(vet, -1, 8, num));
}