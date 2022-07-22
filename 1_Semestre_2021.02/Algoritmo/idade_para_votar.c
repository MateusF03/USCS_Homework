/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <time.h>

int main()
{
  int horas;
  float sal;
  printf("Digite as horas que você trabalhou: ");
  scanf("%d", &horas);
  printf("Digite o salário por hora: ");
  scanf("%f", &sal);
  float horaVal = horas * sal;
  if (horas > 40) {
      horaVal += horaVal * 0.5;
  }
  printf("Seu salário total é R$%0g", horaVal);
}

