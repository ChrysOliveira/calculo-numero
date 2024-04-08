// A constante de Euler eh muito usada no BCC, geralmente a vemos no formato e^x. Nesse programa nos queremos descobrir o valor de e, ou seja, o valor de e quando x==1. Para isso, devemos ter em mente que o numero de euler eh igual ao somatorio de n=o ate +inf de x^n/n! (sendo x==1)
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long calcula_fatorial(int valor)
{
    long resultado = 1;

    for (int i = 1; i <= valor; i++)
    {
        resultado *= i;
    }

    return resultado;
}

double calcula_euler()
{
    double euler_valor_encontrado = 0.0;

    for (int i = 0; i < 10; i++)
    {
        euler_valor_encontrado += (pow(1, i) / calcula_fatorial(i));
    }

    return euler_valor_encontrado;
}

int main(int argc, char const *argv[])
{
    const double euler_valor_real = exp(1);
    printf("Valor real de Euler: %lf\n", euler_valor_real);

    // long teste_fatorial = calcula_fatorial(5);
    // printf("Teste fatorial: %ld\n", teste_fatorial);

    const double euler_valor_encontrado = calcula_euler();
    printf("Valor encontrado Euler: %lf\n", euler_valor_encontrado);

    const double erro_absoluto = euler_valor_real - euler_valor_encontrado;
    printf("Erro absoluto: %lf\n", erro_absoluto);

    const double erro_relativo = (euler_valor_real - euler_valor_encontrado)/euler_valor_real;
    printf("Erro relativo: %lf\n", erro_absoluto);

    return 0;
}
