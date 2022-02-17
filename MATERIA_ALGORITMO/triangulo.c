/*
OBJETIVO:
Ler medidas de um triangulo e classificar ele
Mateus F. 16-02-2022
*/
#include <stdio.h>

int getDuplicates(int array[], int len);

int main ()
{
    //Declaração de variaveis
    int tamanho = 3;
    int lados[tamanho];
    char *tipo = "";
    //Entrada de dados
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o lado nº%d: ", i + 1);
        scanf("%d", &lados[i]);
    }
    // Processamento
    int dup = getDuplicates(lados, tamanho);
    printf("%d", dup);
    if (dup == 0) {
        tipo = "escaleno";
    } else if (dup == 1) {
        tipo = "isósceles";
    } else if (dup == 2) {
        tipo = "equilátero";
    }
    //Saída
    printf("O triangulo é do tipo %s", tipo);
    
    return 0;
}

int getDuplicates(int array[], int len) {
    int count = 0;
    int lastCount = 0;
    for (int i = 0; i < len; i++) {
        /*if (i + 1 == len) {
            break;
        }*/
        lastCount = array[i];
        if (lastCount == array[i + 1]) {
            count++;
        }
    }
    return count;
}
