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
    printf("Digite a frase da matriz: ");
    preenche_matriz(m, n, mat);
    mostra_matriz(m, n, mat);
    for(;;){
        exit = pega_string(&p);
        if(exit){
            break;
        }
        procura_palavra(mat, m, n, &p);
        imprime_info(p);
        free(p.str);
    }
    desaloca_matriz(m, mat);

    return 0;
}
