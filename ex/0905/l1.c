#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
    int matricula;
    char nome[50];
    struct lista* prox;
};
typedef struct lista Lista;

Lista *linserei(Lista *l, int mat, char *nm){
    Lista *n = (Lista*)malloc(sizeof(Lista));
    n->matricula = mat;
    strcpy(n->nome, nm);
    n->prox = l;
    return n;
}

Lista *linseref(Lista *l, int mat, char *nm){
    Lista *p = l;
    while(p->prox != NULL){
        p = p->prox;
    }
    Lista *n = (Lista*)malloc(sizeof(Lista));
    n->matricula = mat;
    strcpy(n->nome, nm);
    p->prox = n;
    n->prox = NULL;
    return l;
}

void *limprime(Lista *l){
    Lista *p = l;
    while(p != NULL){
        printf("Matricula: %d\tNome: %s\n", p->matricula, p->nome);
        p = p->prox;
    }
}

int main(){
    Lista *l = NULL;
    l = linserei(l, 1, "jorginho");
    l = linserei(l, 2, "claudinho");
    l = linseref(l, 3, "buchecha");
    limprime(l);
    return 0;
}
