#ifndef _filas_
#define _filas_

#include <stdbool.h>

struct fila{
    int lista[50];
    int ini;
    int n;
};
typedef struct fila Fila;

Fila *fila_cria(void);
void fila_insere(Fila *fila, int valor);
void fila_imprime(Fila *fila);
void fila_combina(Fila* f1, Fila* f2, Fila* fres);
int fila_retira(Fila *fila);
int fila_frente(Fila *fila);
bool fila_vazia(Fila *fila);

#endif
