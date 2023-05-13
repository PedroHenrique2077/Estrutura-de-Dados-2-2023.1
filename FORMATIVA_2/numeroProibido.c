#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 140000
#define MAX_SIZE 1000003

/* Definição da estrutura de um elemento da tabela hash */
typedef struct node {
    int chave;
    bool ocupado;
} Node;

/* Função hash */
int hash(int chave) {
    return chave % MAX_SIZE;
}

/* Função para inicializar a tabela hash */
void iniciaTabela(Node* tabela) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        tabela[i].chave = -1;
        tabela[i].ocupado = false;
    }
}

/* Função para inserir um elemento na tabela hash */
void insere(Node* tabela, int chave) {
    int index = hash(chave);
    while (tabela[index].ocupado) {
        index = (index + 1) % MAX_SIZE;
    }
    tabela[index].chave = chave;
    tabela[index].ocupado = true;
}

/* Função para buscar um elemento na tabela hash */
bool search(Node* tabela, int chave) {
    int index = hash(chave);
    while (tabela[index].ocupado) {
        if (tabela[index].chave == chave) {
            return true;
        }
        index = (index + 1) % MAX_SIZE;
    }
    return false;
}

int main(void) {
    Node tabela[MAX_SIZE];
    int n, p;
    
    /* Inicializa a tabela hash */
    iniciaTabela(tabela);
    
    /* Leitura dos números proibidos e inserção na tabela hash */
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &p);
        insere(tabela, p);
    }
    
    /* Leitura dos números de consulta e busca na tabela hash */
    while (scanf("%d", &p) != EOF) {
        if (search(tabela, p)) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }
    
    return 0;
}
