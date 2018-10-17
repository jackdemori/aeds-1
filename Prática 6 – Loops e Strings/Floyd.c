#include <stdio.h>

int sum (int n)
{
    if (n <= 1)
        return 1;
    
    return n + sum (n - 1);
}

int main ()
{
    int n;
    int count = 1;

    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ", count++);
        }
        printf("\n");
    }

    // Desafio N-esima linha
    printf("\nN-esima linha\n");
    scanf("%d", &n);

    count = n > 1 ? sum(n - 1) + 1 : 1;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", count++);
    }

    return 0;
}