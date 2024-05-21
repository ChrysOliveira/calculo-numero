#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sistema.h"

int main(int argc, char *argv[]) {

  srand(time(NULL));

  printf("Matriz valores: \n");
  Matriz m = cria_m();

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      set_valores_m(m, i, j, rand() % 10);
    }
  }

  imprime_m(m);

  printf("Matriz icognitas: \n");
  Matriz m_x = cria_m();
  imprime_m(m_x);

  printf("Vetor resultado: \n");
  Vetor r = cria_v();

  for (int i = 0; i < 3; i++) {
    set_valores_v(r, i, rand() % 10);
  }

  imprime_v(r);

  printf("\n");

  calcula_sistema(m, m_x, r);
  imprime_m(m);

  destroi_m(m);
  destroi_m(m_x);
  destroi_v(r);

  return EXIT_SUCCESS;
}
