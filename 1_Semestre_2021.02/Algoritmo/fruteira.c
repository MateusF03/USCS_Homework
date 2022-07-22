/******************************************************************************

Uma fruteira está vendendo frutas com a seguinte tabela de preços:

Até 5 Kg 
Morango R$ 2,50 por Kg
Maçã R$ 1,80 por Kg 

Acima de 5 Kg
Morango R$ 2,20 por Kg
Maçã R$ 1,50 por Kg

Se o cliente comprar mais de 8 Kg em frutas ou o valor total da compra ultrapassar R$ 25,00, receberá
ainda um desconto de 10% sobre este total. Escreva um algoritmo para ler a quantidade (em Kg) de
morangos e a quantidade (em Kg) de maças adquiridas e escreva o valor a ser pago pelo cliente.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float kgMorango;
    float kgMac;
    
    printf("Digite quantos kilos de morango você comprou:");
    scanf("%f", &kgMorango);
    printf("Digite quantos kilos de maça você comprou:");
    scanf("%f", &kgMac);
    
    float precMorango = kgMorango * 2.5f;
    float precMac = kgMac * 1.8f;
    if (kgMorango > 5) {
        precMorango = kgMorango * 2.2f;
    }
    if (kgMac > 5) {
        precMac = kgMac * 1.5f;
    }
    
    float kgTotal = kgMorango + kgMac;
    float precTotal = precMac + precMorango;
    if (kgTotal > 8 || precTotal > 25.0f) {
        precTotal -= precTotal * 0.1f;
    }
    printf("Você vai pagar: R$%.2f", precTotal);

    return 0;
}



