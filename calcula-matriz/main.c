#include <stdlib.h>

#include "sistema.h"

int main(int argc, char *argv[]) {

  Matriz m = cria_m();

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      set_valores_m(m, i, j, j+1);
    }
  }

  imprime_m(m);

  Matriz m_x = cria_m();

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      set_valores_m(m_x, i, j, 0);
    }
  }

  imprime_m(m_x);

  destroi_m(m);
  destroi_m(m_x);

  return EXIT_SUCCESS;
}
