#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le) {
    if (le->prox == NULL){
        printf("NULL\n");
    } else{
        celula *p = le->prox;
        while (p != NULL){
            printf("%d -> ", p->dado);
            p = p->prox;
        }
        printf("NULL\n");
    }
}

void imprime_rec (celula *le){
    if (le->prox == NULL){
        printf("NULL\n");
    } else{
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
    }
}
