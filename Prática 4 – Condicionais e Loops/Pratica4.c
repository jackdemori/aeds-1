#include <math.h>

float paraMetrosPorSegundo(float v)
{
    return v / 3.6;
}

float areaCirculo(float raio);
{
    return M_PI * raio * raio;
}

int ehPar(int n);
{
    return n % 2 == 0 ? 1 : 0;
}

int ehDivisivelPor3ou5(int n)
{
    return n % 3 == 0 ^ n % 5 == 0 ? 1 : 0;
}

float pesoIdeal(float h, char sexo)
{
    return sexo == 'M' ? 72.7 * h - 58 : sexo == 'F' ? 62.1 * h - 44.7 : 0;
}

int somaImpares(int N)
{
    int sigma = 0;
    for (int i = 1; i <= N % 2 == 1 ? N : N -1; i++)
    {
        sigma += i % 2 == 1 ? i : 0;
    }
    return sigma;
}

double fatorial(int N)
{
    if (n == 1 || n == 0)
        return 1;               
    else
        return fatorial(N - 1) * N;
}

int somaNumerosDiv3ou5(int N)
{
    int sigma = 0;
    for (int i = 1; i <= N; i++)
    {
        sigma += ehDivisivelPor3ou5(i) == 1 ? i : 0;
    }
    return sigma;
}

float calculaMedia(int x, int y, int z, int operacao)
{
    if (operacao == 1)
    {
        return pow(x * y * z, 1.0 / 3);
    }
    else if (operacao == 2)
    {
        return (float)(x + 2 * y + 3 * z) / 6;
    }
    else if (operacao == 3)
    {
        return (3 / 1.0 / x + 1.0 / y + 1.0 / z);
    }
    else if (operacao == 4)
    {
        return (float)(x + y + z) / 3;
    }
    return 0;
}

int numeroDivisores(int N)
{
    int sigma = 0;
    for (int i = 1; i <= N; i++)
    {
        sigma += n % i == 0 ? 1 : 0;
    }
    return sigma;
}

int enesimoFibonacci(int N)
{
    int a = 0;
    int b = 1;
    int temp;

    for(int i = 0; i < n; i++)
    {
        temp = a + b;
        a = b;
        b = temp;
    }

    return temp;
}