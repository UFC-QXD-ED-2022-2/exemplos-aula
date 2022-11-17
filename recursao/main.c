#include <stdio.h>

void contar_de(int n) {
    if(n >= 0) {
        printf("%d ", n);
        contar_de(n-1);
    }
}

void contar_ate(int n) {
    if(n >= 0) {
        contar_ate(n-1);
        printf("%d ", n);
    }
}

void decr_cr(int n) {
    if(n >= 0) {
        printf("%d ", n);
        decr_cr(n-1);
        printf("%d ", n);
    }
}

void paresdecr_imparescr(int n) {
    if(n >= 0) {
        if(n % 2 == 0)
            printf("%d ", n);
        paresdecr_imparescr(n-1);
        if(n % 2 == 1)
            printf("%d ", n);
    }
}

int soma_ate(int n) {
    if(n >= 1) {
        return soma_ate(n-1) + n;
    }

    // * NOTE: Todos os "caminhos" de uma função que não seja `void` **precisam** determinar um valor de retorno,
    // *       caso contrário o C usará lixo como retorno.
    return 0;
}

void vetor_contrario(int vetor[], int indice) {
    if(indice >= 0) {
        printf("%d ", vetor[indice]);
        vetor_contrario(vetor, indice-1);
    }
}

int main() {
    int valor = 5;

    contar_de(valor); // 1.a
    printf("\n");
    contar_ate(valor); // 1.b
    printf("\n");
    decr_cr(valor); // 1.c
    printf("\n");
    paresdecr_imparescr(valor); // 1.d
    printf("\n");
    // soma_ate(valor); // 1.e
    // printf("\n");

    int vetor[] = { 10, 20, 30, 40, 50 };

    vetor_contrario(vetor, 4); // 2.a
    printf("\n");

    return 0;
}