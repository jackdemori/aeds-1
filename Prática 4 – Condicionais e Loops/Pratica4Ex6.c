#include <stdio.h>
#include "Pratica4.h"

int main ()
{
    int height;
    float weight;
    char sex;

    scanf("%d %f %c", &height, &weight, &sex);

    float pesoIdeal = pesoIdeal(height, sex);

    if (pesoIdeal > weight)
    {
        printf("Voce precisa ganhar %f.2 KG", pesoIdeal - weight);
    }
    else
    {
        printf("Voce precisa perder %f.2 KG", weight - pesoIdeal);
    }
    
    return 0;
}