#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *dir;
    struct Node *esq;
} Node;

void pushValor(Node **arvoreBin, int valor) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    if (*arvoreBin == NULL) {
        *arvoreBin = novo;
        return;
    }

    Node *atual = *arvoreBin;
    Node *anterior = NULL;

    while (atual != NULL) {
        anterior = atual;
        if (valor < atual->valor) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    if (valor < anterior->valor) {
        anterior->esq = novo;
    } else {
        anterior->dir = novo;
    }
}

void imprimirArvore(Node* root) {
    if (root != NULL) {
        imprimirArvore(root->esq);
        printf("%d ", root->valor);
        imprimirArvore(root->dir);
    }
}

int somarArvore(Node *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return raiz->valor + somarArvore(raiz->esq) + somarArvore(raiz->dir);
}

int main() {
    Node *arvoreBin = NULL;

    pushValor(&arvoreBin, 5);
    pushValor(&arvoreBin, 1);
    pushValor(&arvoreBin, 3);
    pushValor(&arvoreBin, 4);
    pushValor(&arvoreBin, 9);

    imprimirArvore(arvoreBin);
    printf("\n");

    printf("%d\n", somarArvore(arvoreBin));
}