#include <stdio.h>
#include <stdlib.h>

#define TAM 60

int main ()
{
    int x[TAM];
    int y[TAM];

    int u[TAM + TAM];

    for (int i = 0; i < TAM; i++)
    {
        x[i] = rand() % 366;
        y[i] = rand() % 366;
    }

    for (int i = 0; i < TAM + TAM; i++)
    {
        //Adiciona Y
        if (i > TAM - 1)
        {
            u[i] = y[i - TAM];
        }
        else
        {
            //Adiciona X
            u[i] = x[i];
        }
    }

    //Imprime U (Uniao X com Y)
    printf("U = ");
    for (int i = 0; i < TAM + TAM; i++)
    {
        printf("%d ", u[i]);
    }
}