#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

Lista *lremoven(Lista *l, int n){
    Lista *p = l;
    Lista *ant = NULL;
    while(p != NULL){
        if(p->valor == n){
            if(ant == NULL){
                l = l->prox;
                p = l;
            }
            else{
                ant->prox = p->prox;
                p = p->prox;
            }
        }
        else{
            ant = p;
            p = p->prox;
        }
    }
    return l;
}

Lista *lsepara(Lista *l, int n){
    Lista *p = l;
    Lista *ant = NULL;
    while(p != NULL && p->valor != n){
        ant = p;
        p = p->prox;
    }
    ant->prox = NULL;
    return p;
}

Lista *lmerge(Lista *l1, Lista *l2){
    Lista *p = l1;
    if(p == NULL){
        return l2;
    }
    while(p->prox != NULL){
        p = p->prox;
    }
    p->prox = l2;
    return l1;
}

Lista *linverte(Lista *l){
    Lista *p = l;
    Lista *p2;
    Lista *ant = NULL;

    while(p != NULL){
        p2 = p->prox;
        p->prox = ant;
        ant = p;
        p = p2;
    }
    return ant;
}
