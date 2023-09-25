#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
int cpf;
char *nome;
int fator;
struct lista* prox;
};
typedef struct lista Lista;

void printlist(Lista *l){
    Lista *p = l;
    putchar('\n');
    while(p != NULL){
        printf("%d %s %d\n", p->fator, p->nome, p->cpf);
        p = p->prox;
    }
}

Lista* lst_insere (Lista* l, int cpf, char *nome, int fator){
    Lista *p = l;
    Lista *ant = NULL;
    while(p != NULL && p->fator < fator){
        ant = p;
        p = p->prox;
    }
    Lista *n = (Lista*)malloc(sizeof(Lista));
    n->cpf = cpf;
    n->nome = nome;
    n->fator = fator;
    n->prox = p;
    if(ant == NULL){
        return n;
    }
    ant->prox = n;
    return l;
}

Lista* lst_remove (Lista* l, int fator){
    Lista *p = l;
    Lista *ant = NULL;
    while(p != NULL){
        if(p->fator == fator){
            if(ant == NULL){
                l = l->prox;
            }
            else{
                ant->prox = p->prox;
            }
        }
        else{
            ant = p;
        }
        p = p->prox;
    }
    return l;
}

//main copiada do mathias
int main(){
    Lista* teste = NULL;
    teste = lst_insere(teste, 123, "jorge augusto",1);
    teste = lst_insere(teste, 234, "jorge august", 4);
    teste = lst_insere(teste, 345, "jorge augus", 1);
    teste = lst_insere(teste, 456, "jorge augu", 3);
    teste = lst_insere(teste, 456, "jorge augu", 3);
    teste = lst_insere(teste, 456, "jorge augu", 3);
    teste = lst_insere(teste, 456, "jorge augu", 2);
    teste = lst_insere(teste, 567, "jorge aug", 1);

    printlist(teste);

    teste = lst_remove(teste, 4);

    printlist(teste);

    printf("hia");

    return 0;
}
