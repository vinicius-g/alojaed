#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int num;
    struct no *prox;
} cel;

void insere(cel **pilha, int valor) {
    cel *novaCel = (cel*)malloc(sizeof(cel));
    cel *celAtual = *pilha;

    novaCel->num = valor;

    if (celAtual == NULL) novaCel->prox = NULL;
    else novaCel->prox = celAtual;

    *pilha = novaCel;
}

void removePilha(cel **pilha) {
    cel *celAtual = *pilha;
    cel *celAnterior = NULL;

    if (celAtual == NULL) return;

    celAnterior = celAtual;
    celAtual = celAtual->prox;
    *pilha = celAtual;

    free(celAnterior);
}

void buscaERemove(cel **pilha, int valor) {
    cel *celAtual = *pilha;
    cel *celAnterior = NULL;

    if (celAtual == NULL) return;

    while (celAtual->prox != NULL && celAtual->num != valor) {
        celAnterior = celAtual;
        celAtual = celAtual->prox;
    }

    if (celAtual->prox == NULL && celAtual->num != valor) return;
    if (celAnterior == NULL && celAtual->num == valor) {
        *pilha = celAtual->prox;
        return;
    }

    celAnterior->prox = celAtual->prox;
    free(celAtual);
    return;
}

void imprime(cel *pilha) {
    cel *celAtual = pilha;

    if (celAtual == NULL) return;

    while (celAtual != NULL) {
        printf("%d ", celAtual->num);
        celAtual = celAtual->prox;
    }

    printf("\n");
}

void liberaMemoria(cel **pilha) {
    cel *celAtual = *pilha;
    cel *celAnterior = NULL;

    if (celAtual == NULL) return;

    while (celAtual != NULL) {
        celAnterior = celAtual;
        celAtual = celAtual->prox;
        *pilha = celAtual;

        free(celAnterior);
    }
}

int main() {
    int tamanho = 10;
    int i, num_removido;
    cel *pilha = NULL;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++) {
        insere(&pilha, rand() % 11);
    }

    printf("Pilha original:\n");

    imprime(pilha);

    removePilha(&pilha);
    removePilha(&pilha);

    num_removido = rand() % 11;

    printf("\n\nNumero removido: %d\n\n", num_removido);
    buscaERemove(&pilha, num_removido);

    printf("\nPilha final:\n");

    imprime(pilha);
}
