#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "busca.h"

int main(){
    char **mat;
    char *str;
    int m, n, tam, pos, dir;
    printf("Digite as dimensoes da matriz: ");
    scanf("%d %d", &m, &n);
    mat = aloca_matriz(m, n);
    preenche_matriz(m, n, mat);
    mostra_matriz(m, n, mat);
    tam = pegastring(&str);
    pos = procura_letra(0, mat, m, n, str, tam);
    if(pos > -1){
        dir = determina_dir(pos, mat, m, n, str, tam);
    }
    printf("\n%d,%d %d", (pos/n), (pos%n), dir);
    desaloca_matriz(m, mat);

    return 0;
}
