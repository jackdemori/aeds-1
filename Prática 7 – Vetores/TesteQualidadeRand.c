#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int main ()
{
    //Incializa o gerador de numeros aleatorio
    srand(88);

    //Arranjo para armazenar o numero de vezes que cada numero foi gerado
    int contagem[MAX];

    //Inicializa o arranjo com todas as posicoes = 0 (limpar o lixo de memoria)
    for (int i = 0; i < MAX; i++)
    {
        contagem[i] = 0;
    }

    int k = 0;
    for (int i = 0; i < 5000000; i++)
    {
        k = rand() % MAX;
        contagem[k]++;
    }

    //Inicializa com o primeiro valor da contagem
    int maior = contagem[0];
    int menor = contagem[0];

    for (int i = 0; i < MAX; i++)
    {
        if (maior < contagem[i])
        {
            maior = contagem[i];
        }

        if (menor > contagem[i])
        {
            menor = contagem[i];
        }
    }

    printf("Maior contagem (%d) - Menor contagem (%d) = %d", maior, menor, (maior - menor));

    // DESAFIO PARA OS FORTES
    float media = (float)(maior + menor) / 2;
    float somatorio = 0;
    float sigma = 0;

    for (int i = 0; i < MAX; i++)
    {
        somatorio += pow(contagem[i] - media, 2);
    }

    sigma = sqrt(somatorio / MAX);

    printf("\nDesvio padrao: %.2f", sigma);
}