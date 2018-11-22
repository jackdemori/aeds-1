#include <stdio.h>

int ddd (unsigned int number)
{
    int n = (float)number / 100000000;
    return n;
}

int soma1SePar(unsigned int number)
{
    int n = (number + 1) % 2;
    return number + n;
}

int parOuImpar(unsigned int number)
{
    return (number + 1) % 2;
}

int main ()
{
    printf("DDD (31 34095858) %d", ddd(3134095858));
    printf("\nDDD (11 78076060) %d", ddd(1178076060));
    printf("\nDDD (21 15795830) %d", ddd(2115795830));

    printf("\nSoma 1 Se Par (5) %d", soma1SePar(5));
    printf("\nSoma 1 Se Par (2) %d", soma1SePar(2));
    printf("\nSoma 1 Se Par (14) %d", soma1SePar(14));

    printf("\nPar Ou Impar (2) %d", parOuImpar(2));
    printf("\nPar Ou Impar (13) %d", parOuImpar(13));
    printf("\nPar Ou Impar (11) %d", parOuImpar(11));
    return 0;
}