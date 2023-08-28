#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "listas2.h"

int main(){
    Lista *l;
    l = lcria();
    l = linsere(l, 5);
    l = linsere(l, 6);
    l = linsere(l, 7);
    l = linsere(l, 8);
    l = linseref(l, 4);
    l = linserei(l, 0, 9);
    l = linserei(l, -1, 3);
    l = linserei(l, 4, 10);
    l = linserei(l, 100, 11);
    limprime(l);
    putchar('\n');
    l = lremovei(l, 0);
    l = lremovei(l, -1);
    l = lremovei(l, 4);
    l = lremovei(l, 100);
    limprime(l);
    return 0;
}
