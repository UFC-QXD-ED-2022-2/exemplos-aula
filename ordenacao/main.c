#include <stdio.h>
#include "merge_sort.h"

int main() {
    int teste[] = { 5, 30, 20, 10, 25, 15 };

    merge_sort(teste, 6);

    printf("[ ");
    for(unsigned int i = 0; i < 6; i++) {
        printf("%d, ", teste[i]);
    }
    printf("]\n");
}