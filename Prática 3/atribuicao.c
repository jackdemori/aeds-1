#include <stdio.h>

void troca (float* end_valor1, float* end_valor2)
{
    float aux = *end_valor1;
    *end_valor1 = *end_valor2;
    *end_valor2 = aux;
}

int main ()
{
    float x;
    float y;

    scanf ("%f %f", &x, &y);

    troca(&x, &y);

    /*float aux = x;
    x = y;
    y = aux;*/

    printf ("\nx = %f\ny = %f", x, y);
    return 0;
}