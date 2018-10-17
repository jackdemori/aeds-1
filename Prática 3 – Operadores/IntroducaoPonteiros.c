#include <stdio.h>

void soma1 (int* n)
{
    *n = *n + 1;
}

int main ()
{
    int a = 0;
    float b = 3.14;
    char c = 'A';

    printf ("%p\n%p\n%p", &a, &b, &c);

    int x = 0;

    /*int* y = &x;
    *y = 3;*/

    soma1(&x);
    soma1(&x);
    soma1(&x);

    printf ("\n%d", x);

    int n = 2;
    soma1(&n);
    printf ("\n%d", n);

    return 0;
}