#ifndef _pilha_
#define _pilha_

#include <stdbool.h>
#define N 50

struct pilhav{
    int vetor[N];
    int n;
};
typedef struct pilhav PilhaV;

struct lista{
    int valor;
    struct lista *prox;
};
typedef struct lista Lista;

struct pilhal{
    Lista *topo;
};
typedef struct pilhal PilhaL;

void criaPilha(PilhaV *pv, PilhaL *pl);
void push(PilhaV *pv, PilhaL *pl, int valor);
void pop(PilhaV *pv, PilhaL *pl);
void imprimePilha(PilhaV pv, PilhaL pl);
int ultimoObjV(PilhaV pv);
int ultimoObjL(PilhaL pl);
int countV(PilhaV pv);
int countL(PilhaL pl);
void esvazie(PilhaV *pv, PilhaL *pl);
void concatenaV(PilhaV *p1, PilhaV *p2);
void concatenaL(PilhaL *p1, PilhaL *p2);
bool palindromo(PilhaV *pv, PilhaL *pl);

#endif
