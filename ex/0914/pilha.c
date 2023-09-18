#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

void criaPilha(PilhaV *pv, PilhaL *pl){
    pv->n = 0;
    pl->topo = NULL;
}

void push(PilhaV *pv, PilhaL *pl, int valor){
    //insere no vetor
    pv->vetor[pv->n] = valor;
    pv->n++;
    //insere na lista
    Lista *n = (Lista*)malloc(sizeof(Lista));
    n->valor = valor;
    n->prox = pl->topo;
    pl->topo = n;
}

void pop(PilhaV *pv, PilhaL *pl){
    //remove do vetor
    pv->vetor[pv->n-1] = 0;
    pv->n--;
    //remove da lista
    pl->topo = pl->topo->prox;
}

void imprimePilha(PilhaV pv, PilhaL pl){
    printf("\nVetor: \n");
    for (int i = pv.n-1; i >= 0; i--){
        printf("%d\n", pv.vetor[i]);
    }
    printf("\nLista: \n");
    Lista *p = pl.topo;
    while(p != NULL){
        printf("%d\n", p->valor);
        p = p->prox;
    }
}

int ultimoObjV(PilhaV pv){
    return pv.vetor[pv.n-1];
}

int ultimoObjL(PilhaL pl){
    return pl.topo->valor;
}

int countV(PilhaV pv){
    return pv.n;
}

int countL(PilhaL pl){
    int c = 0;
    Lista *p = pl.topo;
    while(p != NULL){
        c++;
        p = p->prox;
    }
    return c;
}

void esvazie(PilhaV *pv, PilhaL *pl){
    //vetor
    for(int i = pv->n-1; i >= 0; i--){
        pv->vetor[i] = 0;
    }
    pv->n = 0;
    //lista
    pl->topo = NULL;
}

void concatenaV(PilhaV *p1, PilhaV *p2){
    for(int i = 0; i < p2->n; i++){
        p1->vetor[p1->n] = p2->vetor[i];
        p1->n++;
    }
    p2->n = 0;
}

void concatenaL(PilhaL *p1, PilhaL *p2){
    Lista *p = p2->topo;
    while(p->prox != NULL){
        p = p->prox;
    }
    p->prox = p1->topo;
    p1->topo = p2->topo;
    p2->topo = NULL;
}

bool palindromo(PilhaV *pv, PilhaL *pl){
    //vetor
    for(int i = 0; i < pv->n; i++){
        if(pv->vetor[i] != pv->vetor[pv->n-1-i]){
            return false;
        }
    }
    return true;

    //lista
    Lista *normal = pl->topo;
    Lista *reverso = pl->topo;
    Lista *ant = NULL;
    while(normal != NULL){
        reverso = pl->topo;
        while(reverso->prox != ant){
            reverso = reverso->prox;
        }
        ant = reverso;
        if(normal->valor != reverso->valor){
            return false;
        }
        normal = normal->prox;
    }
    return true;
}
