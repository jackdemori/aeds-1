#include <stdio.h>

char toUpper (char c)
{
    if (c > 96 && c < 123)
        c -= 32;
}

int validLetter (char c)
{
    return ((c > 96 && c < 123) || (c > 64 && c < 91) || (c == ' ')) ? 1 : 0;
}

int main ()
{
    char string[128];
    printf("Digite seu nome: ");
    fgets(string, 128, stdin);

    char temp[128];
    int lastIndex = 0;
    int iterator = 0;
    int nameLenght = 0;

    //Atribui vazio ('\0') a todas as posicoes do array
    for (int i = 0; i < 128; i++)
    {
        temp[i] = '\0';
    }

    while (string[iterator] != '\0')
    {
        if (string[iterator] != ' ')
        {
            for (int i = iterator; validLetter(string[i]) > 0; i++)
            {
                if (string[i] == ' ' || string[i] == '.')
                    break;

                nameLenght++;
            }

            const int lenght = nameLenght;
            char name[lenght];

            for (int i = 0; i < lenght; i++)
            {
                name[i] = string[iterator + i];
            }

            if (lenght == 2)
            {
                if ((name[0] != 'd') && (name[1] != 'e' || name[1] != 'a' || name[1] != 'o'))
                {
                    temp[lastIndex++] = toUpper(name[0]);
                    temp[lastIndex++] = '.';
                    temp[lastIndex++] = ' ';
                }
            }
            else if (lenght == 3)
            {
                if ((name[0] != 'd') && (name[1] != 'a' || name[1] != 'o') && (name[2] != 's'))
                {
                    temp[lastIndex++] = toUpper(name[0]);
                    temp[lastIndex++] = '.';
                    temp[lastIndex++] = ' ';
                }
            }
            else if (lenght > 3)
            {
                temp[lastIndex++] = toUpper(name[0]);
                temp[lastIndex++] = '.';
                temp[lastIndex++] = ' ';
            }
            iterator += nameLenght;
            nameLenght = 0;
        }
        iterator++;
    }

    printf("%s", temp);
    return 0;
}