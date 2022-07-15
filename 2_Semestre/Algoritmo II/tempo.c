/*
Contagem regressiva 

Mateus F. 09-02-2022
*/
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <stdio.h>

int main()
{
    //Pegar input do usuário
    int num = 0;
    printf("Digite o número para eu contar em segundos: ");
    scanf("%d", &num);
    //Ter certeza que o número é positivo
    if (num < 0) {
        printf("O número tem que ser positivo");
        return 0;
    }
    //Contar em segundos
    while (num >= 0)
    {
        printf("\n%d...", num);
        num--;
        sleep(1);
    }
    return 0;
}
