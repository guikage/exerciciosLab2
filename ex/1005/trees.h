#ifndef _trees_
#define _trees_
#include <stdbool.h>

struct node{
    int v;
    struct node *l;
    struct node *r;
};
typedef struct node Tree;

Tree *tinsert(int v, Tree *l, Tree *r);
Tree *tremove(Tree *node);
Tree *ttraverse(Tree *node, int v);
void tprintnode(Tree *node);
void tprint(Tree *root);
void tpreorder(Tree *root);
void tinorder(Tree *root);
void tpostorder(Tree *root);
int pares (Tree* a);
Tree* copia (Tree* a);
int folhas (Tree* a);
int um_filho (Tree* a);
bool igual (Tree* a, Tree* b);

#endif
