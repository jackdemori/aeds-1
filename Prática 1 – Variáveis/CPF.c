/*#include <stdio.h>
#include <math.h>

int getNumber (int n, int pos)
{
    int exp = (pos > 0 ? pos : 1);
    int value = (int)pow(10, exp);
    return n - ((n / value) * value);
}

int main ()
{
    int cpf = 123456789;

    /*int d1 = cpf - ((cpf / 10) * 10);
    int d2 = (cpf - ((cpf / 100) * 100)) / 10;
    int d3 = (cpf - ((cpf / 1000) * 1000)) / 100;
    int d4 = (cpf - ((cpf / 10000) * 10000)) / 1000;
    int d5 = (cpf - ((cpf / 100000) * 100000)) / 10000;
    int d6 = (cpf - ((cpf / 1000000) * 1000000)) / 100000;
    int d7 = (cpf - ((cpf / 10000000) * 10000000)) / 1000000;
    int d8 = (cpf - ((cpf / 100000000) * 100000000)) / 10000000;
    int d9 = (cpf - ((cpf / 1000000000) * 1000000000)) / 100000000;

    int soma = d1 * 2 + d2 * 3 + d3 * 4 + d4 * 5 + d5 * 6 + d6 * 7 + d7 * 8 + d8 * 9 + d9 * 10;
    
    printf("%d %d %d %d %d %d %d %d %d", d9, d8, d7, d6, d5, d4, d3, d2, d1);
    printf("\nSoma:  %d", soma);


    return 0;
}*/

#include <stdio.h>

int integerPow (int a, int b)
{
    int value = 1;
    for (int i = 0; i < b; i++)
    {
        value *= a;
    }
    return value;
}

int getNumber (int n, int pos)
{
    int exp = (pos > 0 ? pos : 1);
    int value = integerPow(10, exp);
    return (n - ((n / value) * value)) / (value / 10);
}

int main ()
{
    int cpf = 123456789;

    int d1 = getNumber(cpf, 1);
    int d2 = getNumber(cpf, 2);
    int d3 = getNumber(cpf, 3);
    int d4 = getNumber(cpf, 4);
    int d5 = getNumber(cpf, 5);
    int d6 = getNumber(cpf, 6);
    int d7 = getNumber(cpf, 7);
    int d8 = getNumber(cpf, 8);
    int d9 = getNumber(cpf, 9);
    
    int soma = d1 * 2 + d2 * 3 + d3 * 4 + d4 * 5 + d5 * 6 + d6 * 7 + d7 * 8 + d8 * 9 + d9 * 10;
    
    printf("%d %d %d %d %d %d %d %d %d", d9, d8, d7, d6, d5, d4, d3, d2, d1);
    printf("\nSoma:  %d", soma);
    
    return 0;
}