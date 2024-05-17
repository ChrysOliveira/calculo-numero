#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double calcula_funcao(double x)
{
    return 2 * x - cos(x);
}

double calcula_derivada(double x)
{
    return 2 + sin(x);
}

double calcula_newton_rapson(double ponto_inicial, double erro)
{
    double ponto_anterior = ponto_inicial;
    double resultado_imagem = calcula_funcao(ponto_anterior);
    double resultado_derivada = calcula_derivada(ponto_anterior);
    double novo_ponto = ponto_anterior - (resultado_imagem / resultado_derivada);

    double erro_absoluto = abs(ponto_anterior - novo_ponto);

    int i = 0;

    printf("  i |     xi    |   f(xi)   |   f'(xi)  | e = |xi - xi+1|\n");
    printf("---------------------------------------------------------\n");
    printf(" %2d | %+lf | %+lf | %+lf | %+lf\n", i, ponto_anterior, resultado_imagem, resultado_derivada, erro_absoluto);

    while (erro > erro_absoluto && i < 10)
    {
        ponto_anterior = novo_ponto;
        resultado_imagem = calcula_funcao(ponto_anterior);
        resultado_derivada = calcula_derivada(ponto_anterior);
        novo_ponto = ponto_anterior - (resultado_imagem / resultado_derivada);

        i++;
        printf(" %2d | %+lf | %+lf | %+lf | %+lf\n", i, ponto_anterior, resultado_imagem, resultado_derivada, erro_absoluto);
    }

    return novo_ponto;
}

int main(int argc, char const *argv[])
{
    double epsilon = 10e-5;

    double *intervalo = malloc(2 * sizeof(double));
    intervalo[0] = 0.0;
    intervalo[1] = M_PI / 8;

    double ponto_inicial = (intervalo[0] + intervalo[1]) / 2;

    double resultado = calcula_newton_rapson(ponto_inicial, epsilon);

    printf("%+lf", resultado);

    return 0;
}
