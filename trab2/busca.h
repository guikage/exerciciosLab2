#ifndef _busca_h_
#define _busca_h_

struct palavra{
    char *str;
    int tam, dir;
    int pini[2];
    int pfinal[2];
};
typedef struct palavra Palavra;

int pegastring(Palavra *p);
int determina_dir(char **mat, int m, int n, Palavra *p);
int procura_palavra(char **mat, int m, int n, Palavra *p);

#endif
