#ifndef _lde_
#define _lde_

struct listaDE{
    int valor;
    struct listaDE *prox;
    struct listaDE *ant;
};
typedef struct listaDE ListaDE;

ListaDE *ldecria(void);
ListaDE *ldeprimeiro(ListaDE *l);
ListaDE *ldeultimo(ListaDE *l);
ListaDE *ldeinserei(ListaDE *l, int v);
ListaDE *ldeinseref(ListaDE *l, int v);
void ldeimprime(ListaDE *l);
ListaDE *lderemovev(ListaDE *l, int v);
ListaDE *lderemoveant(ListaDE *l, int v);

#endif
