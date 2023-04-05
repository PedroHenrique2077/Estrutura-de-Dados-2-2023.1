#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula *nova = malloc(sizeof(celula));
    nova->dado = x;
    nova->prox = le->prox;
    le->prox = nova;
}

void insere_antes (celula *le, int x, int y){
    celula *p = le->prox;
    celula *antes = le;
    while (p != NULL && p->dado != y) {
        antes = p;
        p = p->prox;
    }
    celula *nova = malloc(sizeof(celula));
    nova->dado = x;
    nova->prox = p;
    antes->prox = nova;
}
