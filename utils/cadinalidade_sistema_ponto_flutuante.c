#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int tamanho_base = 2;
    int expoente_max = 2;
    int expoente_min = 2;
    int precisao = 3;

    int cardinalidade = 2 * pow(tamanho_base, precisao - 1) * (tamanho_base - 1) * (expoente_max - expoente_min + 1) + 1;

    printf("Cardinalidade: %d\n", cardinalidade);

    return 0;
}
