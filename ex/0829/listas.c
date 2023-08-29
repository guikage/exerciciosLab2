#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

Lista* lcria(void){
    return NULL;
}

Lista* linsere(Lista *l, int v){
    Lista* n = (Lista*)malloc(sizeof(Lista));
    n->valor = v;
    n->prox = l;
    return n;
}

int lcomp(Lista *l){
    int i = 0;
    Lista *p = l;
    while(p != NULL){
        i++;
        p = p->prox;
    }
    return i;
}

void limprime(Lista *l){
    Lista *p = l;
    while (p != NULL){
        printf("Valor: %d\n", p->valor);
        p = p->prox;
    }
}

int lmaiores(Lista *l, int v){
    int i = 0;
    Lista *p = l;
    while(p != NULL){
        if(p->valor > v){
            i++;
        }
        p = p->prox;
    }
    return i;
}

Lista *lultimo(Lista *l){
    Lista *p = l;
    Lista *u;
    while(p != NULL){
        u = p;
        p = p->prox;
    }
    return u;
}

Lista *lconcat(Lista *l1, Lista *l2){
    Lista *lc = l1;
    while(l1->prox != NULL){
        l1 = l1->prox;
    }
    l1->prox = l2;
    return lc;
}
