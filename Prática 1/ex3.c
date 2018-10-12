#include <stdio.h>

int main ()
{
    float imcBrutus = 122.0 / (1.84 * 1.84);
    float imcOlivia = 45.0 / (1.76 * 1.76);

    printf("IMC Brutus: %.2f", imcBrutus);
    printf("\nIMC Olivia: %.2f", imcOlivia);

    printf("\n\nBrutus precisa perder %.0f KG para chegar ao IMC saudavel", 122.0 - (25.0 * (1.84 * 1.84)));
    printf("\nOlivia precisa ganhar %.0f KG para chegar ao IMC saudavel", (18.5 * (1.76 * 1.76)) - 45.0);
    return 0;
}