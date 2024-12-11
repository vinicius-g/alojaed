#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int num;
    struct no *prox;
} cel;

void insere(cel **fila, int num) {
    cel *celAtual = *fila;
    cel *novaCel = (cel*)malloc(sizeof(cel));
    novaCel->num = num;
    novaCel->prox = NULL;

    if (celAtual == NULL) {
        *fila = novaCel;
        return;
    }

    while (celAtual->prox != NULL) {
        celAtual = celAtual->prox;
    }

    celAtual->prox = novaCel;
}

void removeFila(cel **fila) {
    cel *celAtual = *fila;
    *fila = celAtual->prox;

    free(celAtual);
}

void buscaERemove(cel **fila, int num) {
    cel *celAtual = *fila;
    cel *celAnterior = NULL;

    if (celAtual == NULL) return;

    while (celAtual->prox != NULL && celAtual->num != num) {
        celAnterior = celAtual;
        celAtual = celAtual->prox;
    }

    if (celAtual->prox == NULL && celAtual->num != num) return;
    if (celAnterior == NULL && celAtual->num == num) {
        *fila = celAtual->prox;
        return;
    }

    celAnterior->prox = celAtual->prox;
    free(celAtual);
}

void imprimeFila(cel *fila) {
    cel *celAtual = fila;

    while (celAtual != NULL) {
        printf("%d ", celAtual->num);
        celAtual = celAtual->prox;
    }
    printf("\n");
}

void liberaMemoria(cel **fila) {
    cel *celAtual = *fila;
    cel *celAnterior;

    if (celAtual == NULL) return;

    while (celAtual != NULL) {
        celAnterior = celAtual;
        celAtual = celAtual->prox;
        *fila = celAtual;

        free(celAnterior);
    }
}

int main() {
    int tamanho = 10;
    int i, num_removido;
    cel *fila = NULL;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++) {
        insere(&fila, rand() % 11);
    }

    printf("Fila inicial:\n");

    imprimeFila(fila);

    removeFila(&fila);
    removeFila(&fila);

    imprimeFila(fila);

    num_removido = rand() % 11;
    printf("\n\n%d\n\n", num_removido);

    buscaERemove(&fila, num_removido);
    imprimeFila(fila);
}
