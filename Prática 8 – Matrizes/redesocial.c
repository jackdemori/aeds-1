#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"

int M[NUM_PESSOAS][NUM_PESSOAS];

void inicializar_rede() 
{
    for (int i = 0; i < NUM_PESSOAS; i++)
    {
        for (int j = 0; j < NUM_PESSOAS; j++)
        {
            M[i][j] = 0;
        }
    }
}

void adicionar_amizade(int i, int j) 
{
    if (i < NUM_PESSOAS && j < NUM_PESSOAS)
    {
        if (i == j)
        {
            M[i][j] = 0;
        }
        else
        {
            M[i][j] = 1;
            M[j][i] = 1;
        }
    }
}

float random_float() 
{
    return rand() / (float)RAND_MAX;
}

void popularRedeSocialAleatoriamente(float P) 
{
    inicializar_rede();
    for (int i = 0; i < NUM_PESSOAS; i++)
    {
        for (int j = i; j < NUM_PESSOAS; j++)
        {
            float r = random_float();

            if (r < P)
                adicionar_amizade(i, j);
        }
    }
}

void imprimirRedeSocial()
{
    printf("\n");
    for (int i = 0; i < NUM_PESSOAS; i++)
    {
        for (int j = 0; j < NUM_PESSOAS; j++)
        {
            printf("%d\t", M[i][j]);
        }
        printf("\n\n");
    }
}

int numAmigosEmComum(int v, int u) 
{
    int cont = 0;

    if (v < NUM_PESSOAS && u < NUM_PESSOAS)
    {
        for (int j = 0; j < NUM_PESSOAS; j++)
        {
            if (M[v][j] == 1 && M[u][j] == 1 && u != v)
            {
                cont++;
            }
        }
    }
    
    return cont;
}

//DESAFIO DOS FORTES
float coeficienteAglomeracao(int v)
{
    int n = 0;
    int count = 0;

    for (int j = 0; j < NUM_PESSOAS; j++)
    {
        if (M[v][j] == 1)
        {
            //Conta a qtd de amigos de V
            n++;
        }
    }

    for(int j = 0; j < NUM_PESSOAS; j++)
    {
        //Para cada amizade da pessoa V (vamos chamar de J)
        if(M[v][j] == 1 && v != j)
        {
            for(int k = j; k < NUM_PESSOAS; k++)
            {
                //Confere quais amigos de J tambem sao amigos de V
                if(M[v][k] == 1 && M[j][k] == 1 && v != k && k != j && v != j)
                {
                    count++;
                }
            }
        }
    }

    return count / ((float)n * (n - 1) / 2.0);
}