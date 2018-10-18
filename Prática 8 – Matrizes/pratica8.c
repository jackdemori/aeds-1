#include <stdio.h>
#include "redesocial.h"

int main() 
{
    popularRedeSocialAleatoriamente(0.6);
    imprimirRedeSocial();

    int n = numAmigosEmComum(2,4);
    printf("\nnumero de amigos em comum entre 2 e 4: %d", n);
    //gabarito: 2

    //se voce eh forte, remova o comentario da linha abaixo
    printf("\ncoef. de aglomeracao da pessoa 2 eh: %.2f", coeficienteAglomeracao(2));
    //gabarito: 0.67
}