#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "busca.h"

int catch_exit(){
    char e;
    printf("Deseja continuar? (S/n) ");
    scanf(" %c", &e);
    if(e == 'n'){
        printf("Realmente deseja sair? (s/N) ");
        scanf(" %c", &e);
        if(e == 's'){
            return 1;
        }
        return 0;
    }
    return 0;
}

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
    while(!exit){
        pega_string(&p);
        procura_palavra(mat, m, n, &p);
        imprime_info(p);
        free(p.str);
        exit = catch_exit();
    }
    desaloca_matriz(m, mat);

    return 0;
}
