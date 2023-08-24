#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main(){
    Lista *l;
    l = lcria();
    l = linsere(l, 5);
    l = linsere(l, 6);
    l = linseref(l, 4);
    limprime(l);
    return 0;
}
