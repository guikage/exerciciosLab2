struct lista{
    int valor;
    struct lista *prox;
};
typedef struct lista Lista;

Lista* lcria(void);
Lista* linsere(Lista *l, int v);
int lcomp(Lista *l);
int lmaiores(Lista *l, int v);
Lista *lultimo(Lista *l);
Lista *lconcat(Lista *l1, Lista *l2);
void limprime(Lista *l);
Lista *linseref(Lista *l, int v);
