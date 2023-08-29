#ifndef _listas_3_
#define _listas_3_

#include "listas.h"

Lista *lremoven(Lista *l, int n);
Lista *lsepara(Lista *l, int n);
Lista *lmerge(Lista *l1, Lista *l2);
Lista *linverte(Lista *l);
int ligual(Lista *l1, Lista *l2);
Lista *lcopia(Lista *l);
Lista *lcircular(Lista *l);
void limprimecirc(Lista *l);
Lista *lultimocirc(Lista *l);
Lista *linserecirc(Lista *l, int index, int v);
Lista *lremovecirc(Lista *l, int index);

#endif
