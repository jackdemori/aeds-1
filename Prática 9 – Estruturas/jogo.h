typedef struct
{
    int id_jogador;
    int ataque;
    int defesa;
    int carisma;
    int pontos_vida;
} Guerreiro;

int rolaDados (int dados);
void criaGuerreiro (Guerreiro *g, int id);
int bonusCarisma (Guerreiro g);
void ataca (Guerreiro *a, Guerreiro *b);