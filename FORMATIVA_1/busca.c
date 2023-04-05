#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca_rec (celula *le, int x){
    if (le == NULL || le->dado == x){
        return le;
    }
    return busca_rec(le->prox, x);
}

celula *busca (celula *le, int x){
    celula *p = le->prox;
    while (p != NULL && p->dado != x){
        p = p->prox;
    }
    return p;
}
