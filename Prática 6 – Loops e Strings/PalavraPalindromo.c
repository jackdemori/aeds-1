#include <stdio.h>
#include "TamanhoString"

#define true 1
#define false 0

int palindromo (char string[], char reversedString[], int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        if (string[i] != reversedString[i])
        {
            return false;
        }
    }
    return true;
}

int main ()
{
    char string[128];
    printf("Digite uma palavra: ");
    fgets(string, 128, stdin);

    const int k_lenght = stringLenght(string);
    char temp[k_lenght];

    for (int i = 0; i < k_lenght; i++)
    {
        temp[i] = string[(k_lenght - 1) - i];
    }

    if (palindromo(string, temp, k_lenght) == true)
        printf("\ne uma palavra palindromo.");
    else
        printf("\nnao e uma palavra palindromo.");

    return 0;
}