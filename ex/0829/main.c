#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "listas2.h"
#include "listas3.h"

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
    l = linserei(l, lcomp(l), 2);
    l = linserei(l, 100, 7);
    limprime(l);
    putchar('\n');
    l = linverte(l);
    limprime(l);
    putchar('\n');
    return 0;
}
