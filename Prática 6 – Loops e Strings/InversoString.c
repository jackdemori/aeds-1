#include <stdio.h>
#include "TamanhoString"

#define MAX_SIZE 128

int main ()
{
    char string[MAX_SIZE];
    printf("Digite uma frase: ");

    for (int i = 0; i < MAX_SIZE; i++)
    {
        char c = getc(stdin);

        if (c != '.') 
        {
            string[i] = c;
        }
        else
           break;    
    }

    const int k_lenght = stringLenght(string);
    char temp[k_lenght];

    for (int i = 0; i < k_lenght; i++)
    {
        temp[i] = string[(k_lenght - 1) - i];
    }

    //print string invertida
    printf("%s", temp);

    return 0;
}