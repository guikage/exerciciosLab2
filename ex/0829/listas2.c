#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

Lista *laltera(Lista *l){
    Lista *p = l;
    while(p != NULL){
        p->valor *= -1;
        p = p->prox;
    }
    return l;
}

Lista *linseref(Lista *l, int v){
    Lista *u = lultimo(l);
    Lista *n = (Lista*)malloc(sizeof(Lista));
    n->valor = v;
    n->prox = NULL;
    u->prox = n;
    return l;
}

float lmedia(Lista *l){
    int soma = 0, i = 0;
    Lista *p = l;
    while(p != NULL){
        soma += p->valor;
        i++;
        p = p->prox;
    }
    float media = (float)soma / i;
    return media;
}

Lista *lremoveant(Lista *l, int v){
    Lista *p = l;
    Lista *ant = NULL;
    Lista *ant2 = NULL;
    while(p != NULL && p->valor != v){
        ant2 = ant;
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        return l; 
    }
    else if(ant == NULL){
        return l;
    }
    else if(ant2 == NULL){
        return l->prox;
    }
    else{
        ant2->prox = p;
        return l;
    }
}

Lista *linserei(Lista *l, int index, int v){
    int i = 0;
    Lista *n = (Lista*)malloc(sizeof(Lista));
    Lista *p = l;
    n->valor = v;
    if(index == 0){
        n->prox = l;
        return n;
    }
    else if(index == -1){
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = n;
        n->prox = NULL;
        return l;
    }
    else{
        while(p != NULL && i < index-1){
            p = p->prox;
            i++;
        }
        if(i == index-1){
            n->prox = p->prox;
            p->prox = n;
            return l;
        }
        else if(i < index-1){
            return l;
        }
    }
    return l;
}

Lista *lremovei(Lista *l, int index){
    int i = 0;
    Lista *p = l;
    Lista *ant = NULL;
    if(index == 0){
        p = p->prox;
        return p;
    }
    else if(index == -1){
        while(p->prox != NULL){
            ant = p;
            p = p->prox;
        }
        ant->prox = NULL;
        return l;
    }
    else{
        while(p->prox != NULL && i < index){
            ant = p;
            p = p->prox;
            i++;
        }
        if(i == index){
            ant->prox = p->prox;
            return l;
        }
        else if(i < index-1){
            return l;
        }
    }
    return l;
}
