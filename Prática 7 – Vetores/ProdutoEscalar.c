#include <stdio.h>

float ProdutoEscalar (float u[], float v[], unsigned int n)
{
    float soma = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        soma += u[i] * v[i];
    }

    return soma;
}

int main ()
{
    float u[] = {1, 2, 3};
    float v[] = {3, 2, 1};

    printf("%.2f", ProdutoEscalar(u, v, 3));

    return 0;
}