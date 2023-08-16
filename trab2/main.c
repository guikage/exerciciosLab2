#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){
    char **mat;
    int m, n;
    printf("Digite as dimensoes da matriz: ");
    scanf("%d %d", &m, &n);
    mat = aloca_matriz(m, n);
    preenche_matriz(m, n, mat);
    mostra_matriz(m, n, mat);
    desaloca_matriz(m, mat);

    return 0;
}
