#include <stdio.h>

unsigned long long fast_pow_2 (int expoente)
{
    unsigned long long a = 1 << expoente;
    
    return a;
}

int main ()
{
    int expoente;
    scanf("%d", &expoente);

    unsigned long long resultado = fast_pow_2 (expoente);

    printf ("%llu", resultado);
    return 0;
}