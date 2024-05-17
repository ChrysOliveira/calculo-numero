#include <stdio.h>
#include <stdlib.h>

#include "sistema.h"

struct matriz {
  int linha;
  int coluna;
  int **matriz;
};

struct vetor {
  int coluna;
  int *vetor;
};

Matriz cria_m() {

  Matriz temp = malloc(sizeof(Matriz));
  temp->linha = 3;
  temp->coluna = 3;
  temp->matriz = malloc(sizeof(int *));

  for (int i=0; i < temp->linha; i++) {
    temp->matriz[i] = malloc(sizeof(int *) * temp->coluna);
  }

  return temp;
}

void destroi_m(Matriz m){

  for (int i=0; i < m->linha; i++) {
    free(m->matriz[i]);
  }

  free(m);
  m = NULL;
}

void set_valores_m(Matriz m, int linha, int coluna, int v){
  if (linha < 0 || linha > 2){
    printf("Linha invalida: %d\n", linha);
    return;
  }

  if (coluna < 0 || coluna > 2){
    printf("Coluna invalida: %d\n", coluna);
    return;
  }

  m->matriz[linha][coluna] = v;
}

void imprime_m(Matriz m){
  for (int i = 0; i < m->linha; i++) {
    for (int j = 0; j < m->coluna; j++) {
      printf("%d ", m->matriz[i][j]);
    }
    printf("\n");
  }
}

Vetor cria_v() {
  
  Vetor temp = malloc(sizeof(Vetor));
  temp->coluna = 3;
  temp->vetor = malloc(sizeof(int) * temp->coluna);

  for (int i=0; i < temp->coluna; i++) {
    temp->vetor[i] = malloc(sizeof(int *) * temp->coluna);
  }

  return temp;
}

void destroi_m(Matriz m){

  for (int i=0; i < m->linha; i++) {
    free(m->matriz[i]);
  }

  free(m);
  m = NULL;
}

void set_valores_m(Matriz m, int linha, int coluna, int v){
  if (linha < 0 || linha > 2){
    printf("Linha invalida: %d\n", linha);
    return;
  }

  if (coluna < 0 || coluna > 2){
    printf("Coluna invalida: %d\n", coluna);
    return;
  }

  m->matriz[linha][coluna] = v;
}

void imprime_m(Matriz m){
  for (int i = 0; i < m->linha; i++) {
    for (int j = 0; j < m->coluna; j++) {
      printf("%d ", m->matriz[i][j]);
    }
    printf("\n");
  }
}
