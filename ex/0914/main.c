#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    PilhaV pv, pv2;
    PilhaL pl, pl2;
    criaPilha(&pv, &pl);
    criaPilha(&pv2, &pl2);
    for(int i = 0; i < 4; i++){
        push(&pv, &pl, i);
    }
    /*
    for(int i = 2; i >= 0; i--){
        push(&pv, &pl, i);
    }
    */
    imprimePilha(pv, pl);
    printf("\n\n%d\n", palindromo(&pv, &pl));
    return 0;
}
