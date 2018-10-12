#include <stdio.h>

int main ()
{
    int nota;

    do
    {
        scanf("%d", &nota);
    }
    while (nota < 0);

    switch (nota)
    {
        case 0:
            printf("F");
        break;
        case 1:
            printf("F");
        break;
        case 2:
            printf("F");
        break;
        case 3:
            printf("F");
        break;
        case 4:
            printf("F");
        break;
        case 5:
            printf("E");
        break;
        case 6:
            printf("D");
        break;
        case 7:
            printf("C");
        break;
        case 8:
            printf("B");
        break;
        case 9:
            printf("A");
        break;
        default:
            printf("A");
    }
    
    return 0;
}