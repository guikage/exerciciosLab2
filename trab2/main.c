#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "busca.h"

int main(){
    char **mat;
    Palavra p;
    int m, n, exit;
    printf("Digite as dimensoes da matriz: ");
    scanf("%d %d", &m, &n);
    mat = aloca_matriz(m, n);
    preenche_matriz(m, n, mat);
    for(;;){
        mostra_matriz(m, n, mat);
        clearbuffer();
        exit = pegastring(&p);
        if(exit){
            break;
        }
        procura_palavra(mat, m, n, &p);
        printf("\n[%d,%d] [%d,%d] %d\n", p.pini[0]+1, p.pini[1]+1, p.pfinal[0]+1, p.pfinal[1]+1, p.dir);
    }
    free(p.str);
    desaloca_matriz(m, mat);

    return 0;
}
