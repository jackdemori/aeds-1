#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 1000

float MediaElementosVetor (float v[], int n)
{
    float soma = 0;

    for (int i = 0; i < n; i++)
    {
        soma += v[i];
    }

    return soma / n;
}

int main ()
{
    float v[TAM_MAX];

    for (int i = 0; i < TAM_MAX; i++)
    {
        v[i] = rand() % 101;
    }

    printf("Media: %f", MediaElementosVetor(v, TAM_MAX));
}