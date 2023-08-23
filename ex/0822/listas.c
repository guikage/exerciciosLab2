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
    while(l != NULL){
        i++;
        l = l->prox;
    }
    return i;
}

int lmaiores(Lista *l, int v){
    int i = 0;
    while(l != NULL){
        if(l->valor > v){
            i++;
        }
        l = l->prox;
    }
    return i;
}

Lista *lultimo(Lista *l){
    Lista *ultimo;
    while(l != NULL){
        ultimo = l;
        l = l->prox;
    }
    return ultimo;
}

Lista *lconcat(Lista *l1, Lista *l2){
    Lista *lc = l1;
    while(l1->prox != NULL){
        l1 = l1->prox;
    }
    return lc;
}
