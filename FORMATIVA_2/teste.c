#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101
#define MAX_KEY_LENGTH 16
#define MAX_OPERATIONS 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    int empty;
} HashTableEntry;

unsigned int hash(const char* key) {
    unsigned int sum = 0;
    int i;
    for (i = 0; i < strlen(key); i++) {
        sum += (i + 1) * key[i];
    }
    return (19 * sum) % TABLE_SIZE;
}

void insert(const char* key, HashTableEntry* table) {
    unsigned int h = hash(key);
    int j;
    for (j = 0; j < 20; j++) {
        int index = (h + j * j + 23 * j) % TABLE_SIZE;
        if (table[index].empty || strcmp(table[index].key, key) == 0) {
            strcpy(table[index].key, key);
            table[index].empty = 0;
            return;
        }
    }
    // Could not insert after examining 20 entries
    printf("Could not insert key: %s\n", key);
}

void removeKey(const char* key, HashTableEntry* table) {
    unsigned int h = hash(key);
    int j;
    for (j = 0; j < 20; j++) {
        int index = (h + j * j + 23 * j) % TABLE_SIZE;
        if (!table[index].empty && strcmp(table[index].key, key) == 0) {
            table[index].empty = 1;
            return;
        }
    }
}

int main() {
    int t, i;
    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        HashTableEntry* table = malloc(TABLE_SIZE * sizeof(HashTableEntry));
        int j, n;
        scanf("%d", &n);
        for (j = 0; j < TABLE_SIZE; j++) {
            table[j].empty = 1;
        }

        for (j = 0; j < n; j++) {
            char operation[5];
            char key[MAX_KEY_LENGTH];

            scanf("%s:%s", operation, key);

            if (strcmp(operation, "ADD") == 0) {
                insert(key, table);
            } else if (strcmp(operation, "DEL") == 0) {
                removeKey(key, table);
            }
        }

        // Count the number of keys and print the index:key pairs
        int keyCount = 0;
        for (j = 0; j < TABLE_SIZE; j++) {
            if (!table[j].empty) {
                keyCount++;
            }
        }

        printf("%d ", keyCount);
        for (j = 0; j < TABLE_SIZE; j++) {
            if (!table[j].empty) {
                printf("%d:%s ", j, table[j].key);
            }
        }
        printf("\n");

        free(table);
    }

    return 0;
}

char *recortarString(const char *string, char caractere)
{
    const char *inicio = strchr(string, caractere); // Encontra a primeira ocorrência do caractere

    if (inicio != NULL)
    {
        // Calcula o tamanho da nova string a ser criada
        size_t tamanho = strlen(inicio + 1) + 1;

        // Aloca memória para a nova string
        char *novaString = (char *)malloc(tamanho * sizeof(char));

        // Copia a porção desejada da string original para a nova string
        strcpy(novaString, inicio + 1);

        return novaString;
    }
    else
    {
        // Caractere não encontrado, retorna uma cópia da string original
        return strdup(string);
    }
}
