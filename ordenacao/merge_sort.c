#include <stdlib.h>

void merge(int vetor[], unsigned int p, unsigned int m, unsigned int q, int auxiliar[]) {
    // A ==> V[p..m]
    // B ==> V[m+1..q]
    unsigned int a = p, b = m+1;
    unsigned int qtd = q-p+1;

    // Preenchendo `auxiliar` com os alementos ordenados
    for(unsigned int k = 0; k < qtd; k++) {
        int elemento;

        if (b > q || (a <= m && vetor[a] < vetor[b])) {
            elemento = vetor[a];
            a++;
        } else {
            elemento = vetor[b];
            b++;
        }

        auxiliar[k] = elemento; // menor elemento entre A e B que ainda não desceu
    }

    // Trazendo de volta os elementos para `vetor`
    for(unsigned int k=0; k<qtd; k++) {
        // Lembrando que `vetor` começa de `p`, porém `auxiliar` começa de `0`.
        vetor[p+k] = auxiliar[k];
    }
}

void merge_sort_rec(int vetor[], unsigned int p, unsigned int q, int auxiliar[]) {
    if (q > p) { // Se tem pelo menos 2 elementos
        // unsigned int m = (p + q) / 2; // OBS: Necessário fazer diferente
        unsigned int m = p + (q - p) / 2; // OBS: Desta forma evitamos overflow no cálculo de `p + q`

        // Ordena primeira metade recursivamente
        merge_sort_rec(vetor, p, m, auxiliar);
        // Ordena segunda metade recursivamente
        merge_sort_rec(vetor, m+1, q, auxiliar);

        merge(vetor, p, m, q, auxiliar);
    } // caso contrário não precisamos fazer nada
}

void merge_sort(int vetor[], unsigned int tamanho) {
    // Alocamos vetor auxiliar para ser usado pelo `merge`
    int *auxiliar = malloc(sizeof(int)*tamanho);

    // `merge` é chamado pelo algoritmo recursivo, então passamos para ele repassar ao `merge`.
    merge_sort_rec(vetor, 0, tamanho-1, auxiliar);

    // Desalocamos, pois já não precisaremos mais
    free(auxiliar);
}

