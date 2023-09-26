#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filas.h"

Fila *fila_cria(void){
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->ini = NULL;
    fila->fim = NULL;
    return fila;
}

void fila_insere(Fila *fila, int valor){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->valor = valor;
    l->prox = NULL;
    if(fila->ini == NULL){
        fila->ini = l;
        fila->fim = l;
    }
    else{
        fila->fim->prox = l;
        fila->fim = l;
    }
}

int fila_retira(Fila *fila){
    int v;
    if(fila->ini != NULL){
        v = fila->ini->valor;
        fila->ini = fila->ini->prox;
        if(fila->ini == NULL){
            fila->fim = NULL;
        }
    }
    return v;
}

int fila_frente(Fila *fila){
    if(fila->ini != NULL){
        return fila->ini->valor;
    }
    return 0;
}

bool fila_vazia(Fila *fila){
    return (fila->ini == NULL);
}

void fila_imprime(Fila *fila){
    Lista *p = fila->ini;
    putchar('\n');
    while(p != NULL){
        printf("%d\n", p->valor);
        p = p->prox;
    }
}

void fila_combina(Fila* f1, Fila* f2, Fila* fres){
    fres->ini = f1->ini;
    f1->fim->prox = f2->ini;
    fres->fim = f2->fim;
    f1->ini = NULL;
    f1->fim = NULL;
    f2->ini = NULL;
    f2->fim = NULL;
}
