#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

Lista *linseref(Lista *l, int v){
    Lista *p = lultimo(l);
    Lista *n = lcria();
    n->valor = v;
    p->prox = n;
    return l;
}
