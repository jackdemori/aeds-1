#include <stdio.h>
#include "tamanhoString"

int main ()
{
    char string[128];
    printf("Digite uma linha: ");
    fgets(string, 128, stdin);

    printf ("\nlenght: %d", stringLenght(string));
    return 0;
}