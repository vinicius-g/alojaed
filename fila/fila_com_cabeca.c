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

    while (celAtual->prox != NULL) {
        celAtual = celAtual->prox;
    }

    celAtual->prox = novaCel;
}

void removeFila(cel **fila) {
    cel *celAtual = *fila;
    cel *proxCel;

    proxCel = celAtual->prox;
    celAtual->prox = proxCel->prox;

    free(proxCel);
}

void buscaERemove(cel **fila, int  num) {
    cel *celAtual = *fila;
    cel *celAnterior = *fila;

    celAtual = celAtual->prox;

    while (celAtual->prox != NULL && celAtual->num != num) {
        celAnterior = celAtual;
        celAtual = celAtual->prox;
    }

    if (celAtual->prox == NULL && celAtual->num != num) return;

    celAnterior->prox = celAtual->prox;
    free(celAtual);
}

void imprimeFila(cel *fila) {
    cel *celAtual = fila;

    celAtual = celAtual->prox;
    while (celAtual != NULL) {
        printf("%d ", celAtual->num);
        celAtual = celAtual->prox;
    }
    printf("\n");
}

void liberaMemoria(cel **fila) {
    cel *celAtual = *fila;
    cel *celAnterior;

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
    cel *fila = (cel*)malloc(sizeof(cel));

    fila->num = 11;
    fila->prox = NULL;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++) {
        insere(&fila, rand() % 11);
    }

    imprimeFila(fila);

    removeFila(&fila);
    removeFila(&fila);

    num_removido = rand() % 11;

    printf("\n\n%d\n\n", num_removido);

    buscaERemove(&fila, num_removido);

    imprimeFila(fila);

    liberaMemoria(&fila);
}
