#include <stdio.h>

int main ()
{
    float saldo = 789.54;

    //PRIMEIRO MES
    saldo *= 1.0056;

    //SEGUNDO MES
    saldo += 303.2;
    saldo *= 1.0056;

    //TERCEIRO MES
    saldo -= 58.25;
    saldo *= 1.0056;

    printf("Saldo em conta: %.2f", saldo);
    return 0;
}