/*
Contador de dias baseado em uma idade.

Mateus F. 09-02-2022
*/

#include <stdio.h>

int main()
{
    //Pegar o input do usuário
    int idade = 0;
    printf("Digite sua idade em anos: ");
    scanf("%d", &idade);
    //Ter certeza que a idade seja maior que positiva
    if (idade < 0) {
        printf("A idade tem que ser positiva");
        return 0;
    }
    //Converter para dias
    int dias = idade * 365;
    //Mostrar o output
    printf("Você tem %d de vida em dias!", dias);

    return 0;
}
