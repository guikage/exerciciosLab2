#include <stdio.h>
#include <stdlib.h>
#include "lde.h"

ListaDE *ldecria(void){
    return NULL;
}

ListaDE *ldeprimeiro(ListaDE *l){
    ListaDE *p = l;
    if (p != NULL){
        while (p->ant != NULL){
            p = p->ant;
        }
    }
    return p;
}

ListaDE *ldeultimo(ListaDE *l){
    ListaDE *p = l;
    if (p != NULL){
        while (p->prox != NULL){
            p = p->prox;
        }
    }
    return p;
}

ListaDE *ldeinserei(ListaDE *l, int v){
    ListaDE *p = l;
    ListaDE *n = (ListaDE*)malloc(sizeof(ListaDE));
    n->valor = v;
    n->prox = p;
    if(p != NULL){
        p->ant = n;
    }
    return n;
}

ListaDE *ldeinseref(ListaDE *l, int v){
    ListaDE *p = ldeultimo(l);
    ListaDE *n = (ListaDE*)malloc(sizeof(ListaDE));
    n->valor = v;
    n->ant = p;
    n->prox = NULL;
    if(p != NULL){
        p->prox = n;
    }
    return l;
}

void ldeimprime(ListaDE *l){
    ListaDE *p = l;
    while(p != NULL){
        printf("Valor: %d\n", p->valor);
        p = p->prox;
    }
    putchar('\n');
}

ListaDE *lderemovev(ListaDE *l, int v){
    ListaDE *p = l;
    while(p != NULL){
        if(p->valor == v){
            if(p->ant == NULL){
                l = p->prox;
                l->ant = NULL;
            }
            else{
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
            }
        }
        p = p->prox;
    }
    return l;
}

ListaDE *lderemoveant(ListaDE *l, int v){
    ListaDE *p = l;
    while(p != NULL){
        if(p->valor == v){
            if(p->ant == NULL){
            }
            else if(p->ant->ant == NULL){
                l = l->prox;
                l->ant = NULL;
            }
            else{
                p->ant->ant->prox = p;
                p->ant = p->ant->ant;
            }
        }
        p = p->prox;
    }
    return l;
}
