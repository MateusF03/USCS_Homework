/*
Contador de dias baseado em uma idade.

Mateus F. 09-02-2022
*/

#include <stdio.h>

int main()
{
    //Pegar o input do usuário
    int idade;
    printf("Digite sua idade em anos: ");
    scanf("%d", &idade);
    //Converter para dias
    int dias = idade * 365;
    //Mostrar o output
    printf("Você tem %d de vida em dias!", dias);

    return 0;
}
