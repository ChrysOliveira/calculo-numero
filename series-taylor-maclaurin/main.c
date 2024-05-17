#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int calcula_fatorial(int valor)
{
    if (valor == 0)
    {
        return 1;
    }
    else
    {
        return valor * calcula_fatorial(valor - 1);
    }
}

// sin x = \sum_0_inf {\frac{(-1)^n}_{(2n+1)!} * x^2n+1}
double calcula_sin_taylor(double valor, int precisao)
{
    double resultado = 0;

    for (int n = 0; n < precisao; n++)
    {
        resultado += ((pow(-1, n)) / calcula_fatorial(2 * n + 1)) * pow(valor, 2 * n + 1);
    }

    return resultado;
}

int main(int argc, char const *argv[])
{
    double valor = 4.32;

    // Obs: se variar muito o erro o resultado se perde
    int precisao = 6;

    double resultado_real = sin(valor);

    double resultado_taylor = calcula_sin_taylor(valor, precisao);

    printf("Resultado real: %lf\n", resultado_real);
    printf("Resultado Serie Taylor: %lf\n", resultado_taylor);

    double erro = resultado_real - resultado_taylor;

    printf("Erro: %lf\n", erro);

    return 0;
}
