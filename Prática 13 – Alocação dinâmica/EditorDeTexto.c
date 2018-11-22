#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define BUFFER_TAM 5

int main ()
{
    char input;
    char *text;
    char *tempText;

    char buffer[BUFFER_TAM];
    int contBuffer = 0;
    int totalChars = 0;

    do
    {
        input = getche();

        //Caso o usuario pressione ENTER, troca a entrada por /n
        if (input == '\r')
        {
            input = '\n';
            printf("\n");
        }

        if (contBuffer < BUFFER_TAM)
            buffer[contBuffer++] = input;
            
        
        if (contBuffer == BUFFER_TAM || input == '#')
        {
            //Aloca memoria para o texto salvo + os novos caracteres
            tempText = (char *)malloc((totalChars + contBuffer) * sizeof(char));

            int j;
            int index = 0;

            //Copia o texto antigo
            for (j = 0; j < totalChars; j++)
            {
                *(tempText + index++) = *(text + j);
            }

            //Copia os novos caracteres
            for (j = 0; j < contBuffer; j++)
            {
                *(tempText + index++) = buffer[j];
            }

            //Atualiza o numero de caracteres no total
            totalChars += contBuffer;

            //Libera a memoria do texto antigo
            free(text);

            //Faz o texto apontar para o novo endereço de memoria com o novo texto
            text = tempText;
            contBuffer = 0;
        }
    }
    while (input != '#');

    text[totalChars - 1] = '\0';

    //Imprime o texto
    printf("\n\n");

    int i;
    for (i = 0; i < totalChars; i++)
        printf("%c", *(text + i));

    free(text);
    return 0;
}