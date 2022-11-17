#include <stdio.h>
#include <stdlib.h>

char labirinto[11][11];
char ordem[] = { 'e', 'd', 'c', 'b' };

struct posicao {
    int linha;
    int coluna;
};

struct posicao pilha[121];
int topo = 0;

void imprimir_labirinto() {
    printf("------------------------------\n");
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < 11; j++) {
            printf("%c ", labirinto[i][j]);
        }
        printf("\n");
    }
}

void inicializar_labirinto() {
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < 11; j++) {
            labirinto[i][j] = '#';
        }
    }
}

void embaralhar_ordem() {
    for(int i = 3; i > 0; i--) {
        int escolhido = rand() % i;
        char temp = ordem[i];
        ordem[i] = ordem[escolhido];
        ordem[escolhido] = temp;
    }
}

void imprimir_ordem() {
    for(int i = 0; i < 4; i++) {
        printf("%c ", ordem[i]);
    }
    printf("\n");
}

void imprimir_pilha() {
    printf("[");
    for(int i = 0; i < topo; i++) {
        printf("(l=%d, c=%d); ", pilha[i].linha, pilha[i].coluna);
    }
    printf("]\n");
}

void gerar_labirinto() {
    // TODO
    // *    1. empilhar entrada e por espaço ' ' na matriz
    // *    2. enquanto pilha não-vazia
    // *        2.1 embaralhar `ordem`
    // *        2.2 olhar vizinhos do topo da pilha na ordem, um de cada vez
    // *            2.2.1 se pudermos andar para ele, empilhar e colocar espaço ' ' na matriz
    // *            2.2.2 ** imprimir o labirinto **
    // *            2.2.3 se não pudermos, ver próximo vizinho
    // *        2.3 se todos os vizinhos são proibidos, desempilhar
}

int main() {
    inicializar_labirinto();
    imprimir_labirinto();
    imprimir_pilha();
    return 0;
}