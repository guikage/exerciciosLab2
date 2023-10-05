#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"

Tree *tinsert(int v, Tree* l, Tree* r){
    Tree *n = (Tree*)malloc(sizeof(Tree));
    n->v = v;
    n->l = l;
    n->r = r;
    return n;
}

Tree *tremove(Tree *node){
    if (node != NULL){
        tremove(node->l);
        tremove(node->r);
        free(node);
    }
    return NULL;
}

Tree *ttraverse(Tree *node, int v){
    Tree *treturn = NULL;
    if(node != NULL){
        if(node->v == v){
            return node;
        }
        treturn = ttraverse(node->l, v);
        if(treturn == NULL){
            treturn = ttraverse(node->r, v);
        }
    }
    return treturn;
}

void tprintnode(Tree *node){
    if(node != NULL){
        printf(" %d ", node->v);
    }
}

void tprint(Tree *root){
    printf("<");
    tprintnode(root);
    if(root != NULL){
        tprint(root->l);
        tprint(root->r);
    }
    printf(">");
}

void tpreorder(Tree *root){
    if(root != NULL){
        tprintnode(root);
        tpreorder(root->l);
        tpreorder(root->r);
    }
}

void tinorder(Tree *root){
    if(root != NULL){
        tinorder(root->l);
        tprintnode(root);
        tinorder(root->r);
    }
}

void tpostorder(Tree *root){
    if(root != NULL){
        tpostorder(root->l);
        tpostorder(root->r);
        tprintnode(root);
    }
}

int pares (Tree* a){
    int p = 0;
    if(a != NULL){
        if(a->v%2 == 0) p++;
        p += pares(a->l);
        p += pares(a->r);
    }
    return p;
}

Tree* copia (Tree* a){
    if(a == NULL){
        return NULL;
    }
    Tree *b = (Tree*)malloc(sizeof(Tree));
    b->v = a->v;
    b->l = copia(a->l);
    b->r = copia(a->r);
    return b;
}

int folhas (Tree* a){
    int f = 0;
    if(a->l == NULL && a->r == NULL) return 1;
    if(a->l != NULL) f += folhas(a->l);
    if(a->r != NULL) f += folhas(a->r);
    return f;
}

int um_filho (Tree* a){
    int f = 0;
    if(a->l == NULL && a->r == NULL) return 0;
    if(a->l == NULL || a->r == NULL) f++;
    if(a->l != NULL) f += um_filho(a->l);
    if(a->r != NULL) f += um_filho(a->r);
    return f;
}

bool igual (Tree* a, Tree* b){
    if(a == NULL && b == NULL) return 1;
    if(a == NULL || b == NULL) return 0;
    return (a->v == b->v && igual(a->l, b->l) && igual(a->r, b->r));
}
