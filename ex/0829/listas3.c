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

int ligual(Lista *l1, Lista *l2){
    Lista *p1 = l1;
    Lista *p2 = l2;
    while(p1 != NULL && p2 != NULL){
        if(p1->valor != p2->valor){
            return 0;
        }
        p1 = p1->prox;
        p2 = p2->prox;
    }
    if(p1 != NULL || p2 != NULL){
        return 0;
    }
    return 1;
}

Lista *lcopia(Lista *l){
    Lista *l2 = NULL;
    Lista *n = NULL;
    Lista *ant = NULL;
    Lista *p = l;
    if(l != NULL){
        l2 = (Lista*)malloc(sizeof(Lista));
        l2->valor = l->valor;
        l2->prox = NULL;
        ant = l2;
        p = p->prox;
    }
    while(p != NULL){
        n = (Lista*)malloc(sizeof(Lista));
        n->valor = p->valor;
        n->prox = NULL;
        ant->prox = n;
        ant = n;
        p = p->prox;
    }
    return l2;
}

Lista *lcircular(Lista *l){
    Lista *u = lultimo(l);
    u->prox = l;
    return l;
}

void limprimecirc(Lista *l){
    Lista *p = l;
    do{
        printf("Valor: %d\n", p->valor);
        p = p->prox;
    } while (p != l);
}

Lista *lultimocirc(Lista *l){
    Lista *p = l;
    do{
        p = p->prox;
    }while(p->prox != l);
    return p;
}

Lista *linserecirc(Lista *l, int index, int v){
    Lista *p = l;
    Lista *u = lultimocirc(l);

    Lista *n = (Lista*)malloc(sizeof(Lista));
    n->valor = v;
    int i = 0;
    if(index == 0 || index == -1){
        n->prox = l;
        u->prox = n;
        if(index == 0){
            return n;
        }
    }
    else{
        while(i < index-1){
            p = p->prox;
            i++;
        }
        n->prox = p->prox;
        p->prox = n;
    }
    return l;
}

Lista *lremovecirc(Lista *l, int index){
    Lista *p = l;
    Lista *u = lultimocirc(l);
    Lista *ant = u;

    int i = 0;
    if(index == 0){
        ant->prox = l->prox;
        return l->prox;
    }
    else if(index == -1){
        do{
            ant = p;
            p = p->prox;
        } while(p->prox != l);
        ant->prox = p->prox;
    }
    else{
        while(i < index){
            ant = p;
            p = p->prox;
            i++;
        }
        ant->prox = p->prox;
    }
    return l;
}
