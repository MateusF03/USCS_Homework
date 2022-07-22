
//link https://onlinegdb.com/ScXRyHnkc
#include <stdio.h>

int main()
{
    float metroCubico;
    printf("Digite quantos metros cubicos de água a residência gastou: ");
    scanf("%f", &metroCubico);
    float valor = 13.77f;
    float valorExtra = 0.0f;
    if (metroCubico >= 11.0f && metroCubico <= 20.0f) {
        valorExtra = (metroCubico - 10) * 3.10f;
    } else if (metroCubico >= 21.0f && metroCubico <= 30.0f) {
        valorExtra = (metroCubico - 20) * 4.00f;
        valorExtra += 31.0f;
    } else if (metroCubico >= 31.0f && metroCubico <= 50.0f) {
        valorExtra = (metroCubico - 30) * 5.40f;
        valorExtra += 31.0f;
        valorExtra += 40.0f;
    } else if (metroCubico >= 51.0f && metroCubico <= 100.0f)  {
        valorExtra = (metroCubico - 50) * 7.54f;
        valorExtra += 31.0f;
        valorExtra += 40.0f;
        valorExtra += 108.0f;
    }
    valor += valorExtra;
    valor += valor * 0.8f;
    printf("O valor da conta é R$%.2f", valor);
    return 0;
}






