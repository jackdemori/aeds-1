#include <stdio.h>
#include "jogo.h"

int main ()
{
    //Aloca memoria para os guerreiros
    Guerreiro a;
    Guerreiro b;

    //Inicializa os campos dos guerreiros
    criaGuerreiro(&a, 1);
    criaGuerreiro(&b, 2);

    int turn = 0;
    //Executa a batalha enquanto um dos guerreiros estiver vivo
    while (a.pontos_vida > 0 && b.pontos_vida > 0)
    {
        if (turn % 2 == 0)
        {
            ataca(&a, &b);
        }
        else
        {
            ataca(&b, &a);
        }
        turn++;
    }

    printf("O guerreiro %d venceu a luta apos %d rodadas", (a.pontos_vida > 0 ? a.id_jogador : b.id_jogador), turn);
}