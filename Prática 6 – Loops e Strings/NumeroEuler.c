#include <stdio.h>
#include <math.h>

int factorial (int n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

double e ()
{
    double threshold = pow(10, -6);
    double sum = 1;

    for (int i = 1; 1.0 / factorial(i) > threshold; i++)
    {
        sum += 1.0 / factorial(i);
    }

    return sum;
}

int main ()
{
    printf("%lf", e());

    return 0;
}