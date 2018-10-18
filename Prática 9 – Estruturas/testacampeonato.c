#include <stdio.h>
#include "jogo.h"

//DESAFIO PARA OS FORTES
#define NUM_GUERREIROS 16

int main ()
{
    //Aloca memoria para os (n) guerreiros
    Guerreiro guerreiros[NUM_GUERREIROS];

    //Inicializa os guerreiros
    for (int i = 0; i < NUM_GUERREIROS; i++)
    {
        criaGuerreiro(&guerreiros[i], i + 1);
    }

    //Simula a batalha ate que so haja 1 sobrevivente
    int turn = 0;
    int guerreirosVivos = NUM_GUERREIROS;
    while (guerreirosVivos > 1)
    {
        for (int i = 0; i < NUM_GUERREIROS; i++)
        {
            //Guerreiro (i) ainda esta vivo, entao precisamos encontrar um oponente
            if (guerreiros[i].pontos_vida > 0)
            {
                for (int j = i + 1; j < NUM_GUERREIROS; j++)
                {
                    //Encontramos outro guerreiro vivo
                    if (i != j && guerreiros[j].pontos_vida > 0)
                    {
                        if (turn % 2 == 0)
                        {
                            printf("\n%2d ATACA %2d", guerreiros[i].id_jogador, guerreiros[j].id_jogador);
                            ataca(&guerreiros[i], &guerreiros[j]);
                        }
                        else
                        {
                            printf("\n%2d ATACA %2d", guerreiros[j].id_jogador, guerreiros[i].id_jogador);
                            ataca(&guerreiros[j], &guerreiros[i]);
                        }

                        if (guerreiros[i].pontos_vida < 1 || guerreiros[j].pontos_vida < 1)
                        {
                            printf("\t%2d MORREU!", (guerreiros[i].pontos_vida < 1 ? guerreiros[i].id_jogador : guerreiros[j].id_jogador));
                            guerreirosVivos--;
                        }
                            
                        // Impede que o guerreiro (i) lute com mais de 1 guerreiro ao mesmo tempo
                        break;
                    }
                }
            }
        }
        turn++;
        printf("\n\n----- NOVA RODADA! (%d) -----\n\n", turn);
    }

    int id_vencedor = 0;
    for (int i = 0; i < NUM_GUERREIROS; i++)
    {
        if (guerreiros[i].pontos_vida > 0)
        {
            id_vencedor = guerreiros[i].id_jogador;
        }
    }

    printf("O guerreiro %d venceu a luta apos %d rodadas", id_vencedor, turn);
}