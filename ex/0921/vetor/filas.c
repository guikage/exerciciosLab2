#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filas.h"

Fila *fila_cria(void){
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->ini = 0;
    fila->fim = 0;
    return fila;
}

void fila_insere(Fila *fila, int valor){
    fila->lista[fila->fim] = valor;
    fila->fim = (fila->fim+1)%50;
}

int fila_retira(Fila *fila){
    int v;
    if(fila->fim != 0){
        v = fila->lista[fila->ini];
        fila->lista[fila->ini] = 0;
        fila->ini = (fila->ini+1)%50;
    }
    return v;
}

int fila_frente(Fila *fila){
    return fila->lista[fila->ini];
}

bool fila_vazia(Fila *fila){
    return(fila->fim == fila->ini);
}

void fila_imprime(Fila *fila){
    int i = fila->ini;
    putchar('\n');
    while(i != fila->fim){
        printf("%d\n", fila->lista[i%50]);
        i = (i+1)%50;
    }
}

void fila_combina(Fila* f1, Fila* f2, Fila* fres){
    fres->ini = 0;
    fres->fim = 0;
    int i;
    i = f1->ini;
    while(i != f1->fim){
        fres->lista[fres->fim] = f1->lista[i];
        i = (i+1)%50;
        fres->fim = (fres->fim+1)%50;
    }
    i = f2->ini;
    while(i != f2->fim){
        fres->lista[fres->fim] = f2->lista[i];
        i = (i+1)%50;
        fres->fim = (fres->fim+1)%50;
    }
    f1->ini = 0;
    f1->fim = 0;
    f2->ini = 0;
    f2->fim = 0;
}
