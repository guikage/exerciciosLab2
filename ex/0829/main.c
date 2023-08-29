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
    l = lcircular(l);
    limprimecirc(l);
    putchar('\n');
    l = linserecirc(l, 0, 10);
    l = linserecirc(l, -1, 1);
    l = linserecirc(l, 4, 10);
    limprimecirc(l);
    putchar('\n');
    l = lremovecirc(l, 0);
    l = lremovecirc(l, -1);
    l = lremovecirc(l, 3);
    limprimecirc(l);
    putchar('\n');

    return 0;
}
