#ifndef __SISTEMA_H
#define __SISTEMA_H

typedef struct matriz* Matriz;
typedef struct vetor* Vetor;

Matriz cria_m(void);
void destroi_m(Matriz);
void set_valores_m(Matriz, int linha, int coluna, int v);
void imprime_m(Matriz);

Vetor cria_v(void);
void destroi_v(Vetor);
void set_valores_v(Vetor, int linha, int v);
void imprime_v(Vetor);

void calcula_sistema(Matriz vl, Matriz ig, Vetor r);
#endif // !__SISTEMA_H
