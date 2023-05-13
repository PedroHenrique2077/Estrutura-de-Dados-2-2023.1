#include <stdio.h>
#include <string.h>

typedef struct {
    char key[16];
    int empty;
} HashTable;

HashTable table[101];

int hash(char *key) {

    int h = 0;

    for (int i = 0; key[i]; i++) {
        h += (i + 1) * key[i];
    }

    return (19 * h) % 101;
}

int busca(char *key) {

    int h = hash(key);

    for (int j = 0; j < 20; j++) {
        int pos = (h + j * j + 23 * j) % 101;
        if (!table[pos].empty && strcmp(table[pos].key, key) == 0) {
            return pos;
        }
    }
    return -1;
}

void insere(char *key) {

    if (busca(key) != -1) return;
    int h = hash(key);

    for (int j = 0; j < 20; j++) {
        int pos = (h + j * j + 23 * j) % 101;
        if (table[pos].empty) {
            strcpy(table[pos].key, key);
            table[pos].empty = 0;
            return;
        }
    }
}

void removeChave(char *key) {

    int pos = busca(key);
    
    if (pos != -1) 
        table[pos].empty = 1;
}

char *recortarString(const char *string, char caractere)
{
    const char *inicio = strchr(string, caractere);

    if (inicio != NULL)
    {
        size_t tamanho = strlen(inicio + 1) + 1;

        char *novaString = (char *)malloc(tamanho * sizeof(char));

        strcpy(novaString, inicio + 1);

        return novaString;
    }
    else
    {
        return strdup(string);
    }
}

int main(void) {
    int i;
    scanf("%d", &i);

    while (i--) {

        memset(table, 1, sizeof(table));
        int n;
        scanf("%d", &n);

        while (n--) {
            char entrada[20];
            scanf("%s", entrada);
            char *chave = recortarString(entrada, ':');

            if (entrada[0] == 'A')
                insere(chave);
             else if(entrada[0] == 'D') 
                removeChave(chave);
        }

        int contador = 0;
        for (int i = 0; i < 101; i++) 
            if (!table[i].empty) contador++;

        printf("%d\n", contador);
        for (int i = 0; i < 101; i++)
            if (!table[i].empty) printf("%d:%s\n", i, table[i].key);
    }
}