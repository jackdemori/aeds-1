#include <stdio.h>
#define TAM_MAX 1000

int main ()
{
    int fib[TAM_MAX];
    int entrada = 0;

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < TAM_MAX; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    do
    {
        printf("\nTermo da serie de Fibonacci: ");
        scanf("%d", &entrada);

        if (entrada > -1 && entrada < 1001)
            printf("\nSaida: %d", fib[entrada - 1]);
    }
    while (entrada > -1 && entrada < 1001);

    return 0;
}