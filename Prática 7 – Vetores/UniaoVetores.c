#include <stdio.h>
#include <stdlib.h>

#define TAM 60

//Conta quantas vezes o numero N aparece no vetor
int CountElemento (int v[], int n, int tam)
{
    int count = 0;
    for (int i = 0; i < tam; i++)
    {
        if (v[i] == n)
        {
            count++;
        }
    }
    return count;
}

int main ()
{
    int x[TAM];
    int y[TAM];

    int aux[TAM + TAM];

    for (int i = 0; i < TAM + TAM; i++)
    {
        aux[i] = -1;
    }

    for (int i = 0; i < TAM; i++)
    {
        x[i] = rand() % 366;
        y[i] = rand() % 366;
    }

    //Combina os 2 vetores em 1 com o dobro do tamanho
    for (int i = 0; i < TAM + TAM; i++)
    {
        //Adiciona Y
        if (i > TAM - 1)
        {
            aux[i] = y[i - TAM];
        }
        else
        {
            //Adiciona X
            aux[i] = x[i];
        }  
    }

    //Iniciamos J com o valor maximo (tamanho de X + tamanho de Y)
    int j = TAM + TAM;
    for (int i = 0; i < TAM + TAM; i++)
    {
        //Subtraimos de J a quantidade de vezes que um numero N aparace - 1.
        //Se um numero N aparece 3x, entao subtraimos 2, para que no vetor
        //Uniao o numero aparece uma unica vez.
        j -= (CountElemento(aux, aux[i], TAM + TAM) - 1);
    }

    const int k_tamanho = j;
    int u[k_tamanho];

    for (int i = 0, j = 0; i < TAM + TAM; i++)
    {
        if (CountElemento(u, aux[i], k_tamanho) == 0)
        {
            u[j] = aux[i];
            j++;
        }   
    }

    //Ordena no vertor U em ordem crescente
    for (int i = 0; i < k_tamanho; i++)
    {
        for (int j = 0; j < k_tamanho - 1; j++)
        {
            if (u[j] > u[j + 1])
            {
                int aux = u[j];
                u[j] = u[j + 1];
                u[j + 1] = aux;
            }
        }
    }

    //Imprime U (Uniao X com Y)
    printf("U = ");
    for (int i = 0; i < k_tamanho; i++)
    {
        printf("%d ", u[i]);
    }

    /*//DEBUG (QTS VEZES CADA ELEMENTO DE U APARECEU)
    printf("\n\n\n");
    for (int i = 0; i < k_tamanho; i++)
    {
        printf("\n%d apareceu %d vez no conjunto", u[i], CountElemento(u, u[i], k_tamanho));
    }*/
}