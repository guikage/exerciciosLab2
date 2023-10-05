#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trees.h"

int main(){
    Tree *root = NULL;
    root = tinsert(0, NULL, NULL);
    root->r = tinsert(1, NULL, NULL);
    root->r->r = tinsert(2, NULL, NULL);
    root->r->r->l = tinsert(3, NULL, NULL);
    root->r->r->l->l = tinsert(4, NULL, NULL);
    root->r->r->l->r = tinsert(5, NULL, NULL);
    root->r->r->l->l->l = tinsert(6, NULL, NULL);
    root->r->r->l->r->r = tinsert(7, NULL, NULL);
    root->r->r->l->l->l->l = tinsert(8, NULL, NULL);
    root->r->r->l->r->r->l = tinsert(9, NULL, NULL);

    Tree *root2 = NULL;
    printf("%d\n", igual(root, root2));

    return 0;
}
