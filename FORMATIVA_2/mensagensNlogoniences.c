#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    unsigned chave;
    char valor;
} Item;

typedef struct TabelaHash {
    unsigned tamanho;
    Item *itens;
} TabelaHash;

TabelaHash inicializar(unsigned tamanho) {
    TabelaHash th;
    th.tamanho = tamanho;
    th.itens = (Item*)malloc(tamanho * sizeof(Item));
    return th;
}

int inserir(TabelaHash *th, Item item) {
    unsigned h = item.chave % th->tamanho;
    while (th->itens[h].chave != 0) {
        if (th->itens[h].chave == item.chave) {
            return 0;
        }
        h = (h + 1) % th->tamanho;
    }
    th->itens[h] = item;
    return 1;
}

int remover(TabelaHash *th, unsigned chave) {
    unsigned h = chave % th->tamanho;
    while (th->itens[h].chave != 0) {
        if (th->itens[h].chave == chave) {
            th->itens[h].chave = 0;
            return 1;
        }
        h = (h + 1) % th->tamanho;
    }
    return 0;
}

Item *buscar(TabelaHash th, unsigned chave) {
    unsigned h = chave % th.tamanho;
    while (th.itens[h].chave != 0) {
        if (th.itens[h].chave == chave) {
            return &th.itens[h];
        }
        h = (h + 1) % th.tamanho;
    }
    return NULL;
}

int main(void) {
    
    unsigned tamanho = 1572869u;
    TabelaHash th = inicializar(tamanho);
    Item item;
    unsigned mn = 1 << 31, mx = 0;
    
    while (scanf(" %u %c", &item.chave, &item.valor) == 2) {
        inserir(&th, item);
        mn = item.chave < mn ? item.chave : mn;
        mx = item.chave > mx ? item.chave : mx;
    }
    
    for (unsigned i = mn; i <= mx; i++) {
        Item *encontrado = buscar(th, i);
        if (encontrado != NULL) {
            printf("%c", encontrado->valor);
        }
    }
    printf("\n");
    
    free(th.itens);

    return 0;
}
