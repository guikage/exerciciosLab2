#ifndef _busca_h_
#define _busca_h_

int pegastring(char **str);
int procura_letra(int posinicial, char **mat, int m, int n, char *str, int tam);
int determina_dir(int pos, char **mat, int m, int n, char *str, int tam);

#endif
