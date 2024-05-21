#include <stdio.h>
#include <stdlib.h>

#include "sistema.h"

struct matriz {
  int linha;
  int coluna;
  int **matriz;
};

struct vetor {
  int linha;
  int *vetor;
};

Matriz cria_m() {

  Matriz temp = malloc(sizeof(Matriz));
  temp->linha = 3;
  temp->coluna = 3;
  temp->matriz = malloc(sizeof(int *));

  for (int i = 0; i < temp->linha; i++) {
    temp->matriz[i] = malloc(sizeof(int *) * temp->coluna);
  }

  for (int i = 0; i < temp->linha; i++) {
    for (int j = 0; j < temp->coluna; j++) {
      temp->matriz[i][j] = 0;
    }
  }

  return temp;
}

void destroi_m(Matriz m) {

  for (int i = 0; i < m->linha; i++) {
    free(m->matriz[i]);
  }

  free(m);
  m = NULL;
}

void set_valores_m(Matriz m, int linha, int coluna, int v) {
  if (linha < 0 || linha > 2) {
    printf("Linha invalida: %d\n", linha);
    return;
  }

  if (coluna < 0 || coluna > 2) {
    printf("Coluna invalida: %d\n", coluna);
    return;
  }

  m->matriz[linha][coluna] = v;
}

void imprime_m(Matriz m) {
  for (int i = 0; i < m->linha; i++) {
    for (int j = 0; j < m->coluna; j++) {
      printf("%+.2d ", m->matriz[i][j]);
    }
    printf("\n");
  }
}

Vetor cria_v() {

  Vetor temp = malloc(sizeof(Vetor));
  temp->linha = 3;
  temp->vetor = malloc(sizeof(int) * temp->linha);

  for (int i = 0; i < temp->linha; i++) {
    temp->vetor[i] = 0;
  }

  return temp;
}

void destroi_v(Vetor v) {

  free(v);
  v = NULL;
}

void set_valores_v(Vetor v, int linha, int vl) {

  if (linha < 0 || linha > 2) {
    printf("linha invalida: %d\n", linha);
    return;
  }

  v->vetor[linha] = vl;
}

void imprime_v(Vetor v) {

  for (int i = 0; i < v->linha; i++) {
    printf("%+.2d\n", v->vetor[i]);
  }
  printf("\n");
}

// linha = linha + (linha - 1)
void static soma_linha(Matriz m, Vetor v, int linha) {
  for (int i = 0; i < m->coluna; i++) {
    m->matriz[linha][i] = m->matriz[linha][i] + m->matriz[linha - 1][i];
  }
}

void static mult_linha(Matriz m, Vetor v, int linha, int valor) {
  for (int i = 0; i < m->coluna; i++) {
    m->matriz[linha][i] = m->matriz[linha][i] * valor;
    v->vetor[linha] = v->vetor[linha] * valor;
  }
}

// zera o valor da casa informada atraves de uma combinacao linear com a casa
// superior
void static zera_casa(Matriz m, int linha, int coluna, Vetor v) {

  if (linha <= 0 || linha >= 3) {
    printf("Erro ao tentar zerar casa\n");
  }

  int v_casa = m->matriz[linha][coluna];
  int v_sup = m->matriz[linha - 1][coluna];

  mult_linha(m, v, linha, -v_sup);
  mult_linha(m, v, linha - 1, v_casa);
  soma_linha(m, v, linha);
}

void static calcula(Matriz vl, Matriz ig, Vetor r) {
  zera_casa(vl, 1, 0, r); 
  zera_casa(vl, 2, 0, r); 
  zera_casa(vl, 2, 1, r); 
}

void calcula_sistema(Matriz vl, Matriz ig, Vetor r) { calcula(vl, ig, r); }
