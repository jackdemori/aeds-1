#include <stdio.h>
#define TAM 10

int main ()
{
    int x[TAM];
    int y[TAM];
    int z[TAM + TAM];
    
    for (int i = 0; i < TAM; i++)
    {
        printf("Digite um valor para X%d : ", i);
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite um valor para Y%d : ", i);
        scanf("%d", &y[i]);
    }

    int j = 0;
    int k = 0;
    for (int i = 0; i < TAM + TAM; i++)
    {
        if (i % 2 == 0)
        {
            //Adiciona elemento de X
            z[i] = x[j];
            j++;
        }
        else
        {
            //Adiciona elemento de Y
            z[i] = y[k];
            k++;
        }
    }

    //Imprime Z
    printf("Z = ");
    for (int i = 0; i < TAM + TAM; i++)
    {
        printf("%d ", z[i]);
    }
}