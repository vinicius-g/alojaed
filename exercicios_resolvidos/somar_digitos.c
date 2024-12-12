#include <stdio.h>

int somarDigitos(int num) {
    int proxNum = num / 10, numAtual;

    if (proxNum < 1) {
        numAtual = num % 10;
        return numAtual;
    } else {
        numAtual = num % 10;
        return somarDigitos(proxNum) + numAtual;
    }
}

int main() {
    int num, soma;

    scanf("%d", &num);
    soma = somarDigitos(num);

    printf("soma: %d", soma);
}
