#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois (celula *p) {
    celula *q = p->prox;
    if (q == NULL) {
        return 0;
    }
    p->prox = q->prox;
    int x = q->dado;
    free(q);
    return x;
}


void remove_elemento (celula *le, int x) {
    celula *p = le->prox;
    celula *ant = le;
    
    while (p != NULL && p->dado != x) {
        ant = p;
        p = p->prox;
    }
    
    if (p == NULL) {
        return;
    }
    
    ant->prox = p->prox;
    free(p);
}

void remove_todos_elementos (celula *le, int x) {
    celula *p = le->prox;
    celula *ant = le;
    
    while (p != NULL) {
        if (p->dado == x) {
            ant->prox = p->prox;
            free(p);
            p = ant->prox;
        } else {
            ant = p;
            p = p->prox;
        }
    }
}