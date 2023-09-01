#include <stdio.h>
#include <stdlib.h>
#include "lde.h"

int main(){
    ListaDE *l;
    l = NULL;
    l = ldeinserei(l, 2);
    l = ldeinserei(l, 1);
    l = ldeinseref(l, 3);
    l = ldeinseref(l, 4);
    ldeimprime(l);
    l = lderemoveant(l, 5);
    ldeimprime(l);
    return 0;
}
