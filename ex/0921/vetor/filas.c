#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filas.h"

Fila *fila_cria(void){
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->ini = 0;
    fila->n = 0;
    return fila;
}

void fila_insere(Fila *fila, int valor){
    if(fila->n < 50){
        fila->lista[(fila->ini + fila->n)%50] = valor;
        fila->n++;
    }
}

int fila_retira(Fila *fila){
    int v;
    if(fila->n > 0){
        v = fila->lista[fila->ini];
        fila->lista[fila->ini] = 0;
        fila->ini = (fila->ini+1)%50;
        fila->n--;
    }
    return v;
}

int fila_frente(Fila *fila){
    return fila->lista[fila->ini];
}

bool fila_vazia(Fila *fila){
    return(fila->n == 0);
}

void fila_imprime(Fila *fila){
    int i = fila->ini;
    putchar('\n');
    while(i != fila->ini + fila->n){
        printf("%d\n", fila->lista[i%50]);
        i++;
    }
}

void fila_combina(Fila* f1, Fila* f2, Fila* fres){
    fres->ini = 0;
    fres->n = 0;
    int i;
    i = f1->ini;
    while(i != f1->ini + f1->n && fres->n < 50){
        fres->lista[fres->n] = f1->lista[i%50];
        i++;
        fres->n++;
    }
    i = f2->ini;
    while(i != f2->ini + f2->n && fres->n < 50){
        fres->lista[fres->n] = f2->lista[i%50];
        i++;
        fres->n++;
    }
    f1->ini = 0;
    f1->n = 0;
    f2->ini = 0;
    f2->n = 0;
}
