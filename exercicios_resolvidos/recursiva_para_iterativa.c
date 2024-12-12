#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no *prox;
} cel;

void insere(cel **pilha, int num) {
    cel *novaCel = (cel*)malloc(sizeof(cel));
    cel *celAtual = *pilha;

    novaCel->num = num;

    if (celAtual == NULL) novaCel->prox = NULL;
    else novaCel->prox = *pilha;

    *pilha = novaCel;
}

int main () {
    int num, i, tamanho = 10, soma = 0;
    cel *pilha = NULL;

    for (i = 0; i < tamanho; i++) {
        scanf("%d", &num);
        insere(&pilha, num);
    }

    while (pilha != NULL) {
        if (pilha->num > 0) {
            soma += pilha->num;
        }
        pilha = pilha->prox;
    }

    printf("Soma: %d", soma);
}
