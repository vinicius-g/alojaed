#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int num;
    struct no *prox;
} cel;

void insere(cel **pilha, int num) {
    cel *novaCel = (cel*)malloc(sizeof(cel));
    cel *celAtual = *pilha;
    cel *head = *pilha;

    celAtual = celAtual->prox;

    novaCel->num = num;
    novaCel->prox = celAtual;

    head->prox = novaCel;
}

void removeCel(cel **pilha) {
    cel *celAtual = *pilha;
    cel *head = *pilha;

    celAtual = celAtual->prox;

    if (celAtual == NULL) return;

    head->prox = celAtual->prox;
    free(celAtual);
}

void buscaERemove(cel **pilha, int num) {
    cel *celAtual = *pilha;
    cel *celAnterior = *pilha;

    celAtual = celAtual->prox;

    if (celAtual == NULL) return;

    while (celAtual->prox != NULL && celAtual->num != num) {
        celAnterior = celAtual;
        celAtual = celAtual->prox;
    }

    if (celAtual->prox == NULL && celAtual->num != num) return;

    celAnterior->prox = celAtual->prox;
    free(celAtual);
}

void imprimePilha(cel *pilha) {
    cel *celAtual = pilha;
    celAtual = celAtual->prox;

    if (celAtual == NULL) return;

    while (celAtual != NULL) {
        printf("%d ", celAtual->num);
        celAtual = celAtual->prox;
    }
    printf("\n");
}

void liberarMemoria(cel **pilha) {
    cel *celAtual = *pilha;
    cel *celAnterior;

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
    cel *pilha = (cel*)malloc(sizeof(cel));

    pilha->num = 11;
    pilha->prox = NULL;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++) {
        insere(&pilha, rand() % 11);
    }

    printf("Pilha original:\n");
    imprimePilha(pilha);

    num_removido = rand() % 11;
    printf("\n\nNumero removido: %d\n\n", num_removido);

    removeCel(&pilha);
    removeCel(&pilha);

    buscaERemove(&pilha, num_removido);

    imprimePilha(pilha);

    liberarMemoria(&pilha);

    imprimePilha(pilha);
}
