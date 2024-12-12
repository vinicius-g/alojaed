#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int num;
    struct no *prox;
} cel;

void insere(cel **fila, int num) {
    cel *novaCel = (cel*)malloc(sizeof(cel));
    cel *celAtual = *fila;

    novaCel->num = num;
    novaCel->prox = NULL;

    while (celAtual->prox != NULL) celAtual = celAtual->prox;

    celAtual->prox = novaCel;
}

void imprime(cel *fila) {
    cel *celAtual = fila;

    while (celAtual != NULL) {
        celAtual = celAtual->prox;
        printf("%d ", celAtual->num);
    }
    printf("\n");
}

int main() {
    int num;
    cel *fila = (cel*)malloc(sizeof(cel));

    fila->num = 0;
    fila->prox = NULL;

    scanf("%d", &num);
    insere(&fila, num);
    scanf("%d", &num);
    insere(&fila, num);

    imprime(fila);
}
