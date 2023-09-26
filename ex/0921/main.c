#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vetor/filas.h"

Fila *ordena(Fila *f1, Fila *f2){
    Fila *fres = fila_cria();
    int v1;
    int v2;
    while(!fila_vazia(f1) && !fila_vazia(f2)){
        v1 = fila_frente(f1);
        v2 = fila_frente(f2);
        if(v1 < v2){
            fila_insere(fres, v1);
            fila_retira(f1);
        }
        else{
            fila_insere(fres, v2);
            fila_retira(f2);
        }
    }
    while(!fila_vazia(f1)){
        fila_insere(fres, fila_retira(f1));
    }
    while(!fila_vazia(f2)){
        fila_insere(fres, fila_retira(f2));
    }
    return fres;
}

int main(){
    Fila *f1 = fila_cria();
    Fila *f2 = fila_cria();
    Fila *f3 = fila_cria();

    for(int i = 1; i < 4; i++){
        fila_insere(f1, i);
    }
    for(int i = 2; i < 7; i+=2){
        fila_insere(f2, i);
    }
    fila_imprime(f1);
    fila_imprime(f2);
    fila_combina(f1, f2, f3);
    fila_imprime(f3);

    return 0;
}
