#include <stdlib.h>
#include <time.h>
#include "jogo.h"

//Rola N dados de 6 lados e retorna a soma dos resultados
int rolaDados (int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
        soma = 1 + rand() % 6;

    return soma;
}

void criaGuerreiro (Guerreiro *g, int id)
{
    srand((unsigned)time(NULL));

    g->id_jogador = id;
    g->ataque = rolaDados(1);
    g->defesa = rolaDados(1);
    g->carisma = rolaDados(1);
    g->pontos_vida = rolaDados(3);
}

int bonusCarisma (Guerreiro g)
{
    switch (g.carisma)
    {
        case 18:
            return 3;
        case 17: 
        case 16:
            return 2;
        case 15:
        case 14:
            return 1;
        case 7:
        case 6:
            return -1;
        case 5:
        case 4:
            return -2;
        case 3:
            return -3;
        default:
            return 0;
    }
}

void ataca (Guerreiro *a, Guerreiro *b)
{
    int golpe = rolaDados(3) + a->ataque + a->carisma;
    int escudo = rolaDados(3) + b->defesa + a->carisma;

    //Dano = golpe - escudo
    if (golpe - escudo > 0)
        b->pontos_vida -= golpe;
}