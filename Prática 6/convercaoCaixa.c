#include <stdio.h>
#include "tamanhoString"

int main ()
{
    char string[128];
    printf("Digite um texto: ");
    fgets(string, 128, stdin);

    for (int i = 0; i < stringLenght(string); i++)
    {
        if (string[i] > 96 && string[i] < 123)
            string[i] -= 32;
    }

    printf("\nCAPITAL LETTER: %s", string);

    return 0;
}