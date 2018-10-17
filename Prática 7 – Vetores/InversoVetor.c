#include <stdio.h>

int main ()
{
    //Tamanho do vetor
    const int n;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);

    int x[n];
    int y[n];

    for (int i = 0; i < n; i++)
    {
        printf("Digite um valor para X%d : ", i);
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < n; i++)
    {
        y[(n - 1) - i] = x[i];
    }

    //Imprime Y (X invertido)
    printf("Y = ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", y[i]);
    }
}