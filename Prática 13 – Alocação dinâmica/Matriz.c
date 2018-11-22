#include <stdio.h>
#include <stdlib.h>

// DESAFIO: faça a alocação da matriz em uma função.
float ** Array2DAlloc (int n, int m)
{
    float **array = (float **)malloc(n * sizeof(float));

    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        *(array + i) = (float *)malloc(n * sizeof(float));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            *(*(array + i) + j) = 0.0; // Equivalente a m[i][j] = 0.0;
        }
    }

    return array;
}


int main ()
{
    //Tamanho da matriz
    int n = 5;

    int i;
    int j;

    float **m = Array2DAlloc(n, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.1f ", *(*(m + i) + j)); // Equivalente a printf("%.1f ", m[i][j]));
        }
        printf("\n");
    }

    return 0;
}