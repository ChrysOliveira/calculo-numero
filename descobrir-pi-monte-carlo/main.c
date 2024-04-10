#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int gera_pontos_aleatorios(int precisao)
{
    int total_dentro_circulo = 0;

    printf("Pontos gerados: \n");
    for (int i = 0; i < precisao; i++)
    {
        double x = ((double)rand() / (double)RAND_MAX) * 2;
        double y = ((double)rand() / (double)RAND_MAX) * 2;
        printf("(%.4f,%.4f) ", x, y);

        if (sqrt(pow(x - 1.0, 2) + pow(y - 1.0, 2)) <= 1)
        {
            total_dentro_circulo += 1;
        }
    }
    printf("\n");

    return total_dentro_circulo;
}

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));

    int total_pontos_gerados = 9999;

    int total_pontos_dentro_circulo = gera_pontos_aleatorios(total_pontos_gerados);

    int total_pontos_fora_circulo = total_pontos_gerados - total_pontos_dentro_circulo;

    double valor_pi = 4 * ((double)total_pontos_dentro_circulo / (double)total_pontos_fora_circulo);

    printf("Valor final pi: %lf\n", valor_pi);

    return 0;
}
