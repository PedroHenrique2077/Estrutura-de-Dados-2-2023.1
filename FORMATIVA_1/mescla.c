#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3) {
    celula *c1 = l1->prox;
    celula *c2 = l2->prox;
    celula *c3 = l3;
    
    while (c1 != NULL && c2 != NULL){
        if (c1->dado < c2->dado){
            c3->prox = c1;
            c1 = c1->prox;
        } else{
            c3->prox = c2;
            c2 = c2->prox;
        }
        c3 = c3->prox;
    }
    
    if (c1 != NULL){
        c3->prox = c1;
    } else{
        c3->prox = c2;
    }
    
    l1->prox = NULL;
    l2->prox = NULL;
}
