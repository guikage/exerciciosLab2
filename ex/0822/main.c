#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main(){
    int comp, maiores, comp2;
    Lista *lista, *lista2, *listac;
    Lista *ultimo;
    lista = lcria();
    lista2 = lcria();
    listac = lcria();
    lista = linsere(lista, 10);
    lista = linsere(lista, 7);
    lista = linsere(lista, 11);
    lista2 = linsere(lista2, 2);
    lista2 = linsere(lista2, 3);
    lista2 = linsere(lista2, 4);
    comp = lcomp(lista);
    maiores = lmaiores(lista, 8);
    ultimo = lultimo(lista);
    listac = lconcat(lista, lista2);
    comp2 = lcomp(listac);
    printf("\n%d %d %d %d\n", comp, maiores, ultimo->valor, comp2);
    return 0;
}
