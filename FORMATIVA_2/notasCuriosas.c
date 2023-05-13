#include <stdio.h>

int main(void) {

    int n;
    int *notas = calloc(1001, sizeof(int));
    scanf("%d", &n);
    
    int notaMaxima = 0;
    for (int i = 0; i < n; i++) {
        int nota;
        scanf("%d", &nota);
        notas[nota]++;
        
        if (notas[nota] > notas[notaMaxima]) {
            notaMaxima = nota;
        } else if (notas[nota] == notas[notaMaxima] && nota > notaMaxima) {
            notaMaxima = nota;
        }
    }
    
    printf("%d\n", notaMaxima);
    
    return 0;
}
