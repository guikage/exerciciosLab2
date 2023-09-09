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

char **pega_matriz(int *m, int *n){
    printf("Digite as dimensoes da matriz: ");
    scanf("%d %d", m, n);
    char **mat = aloca_matriz(*m, *n);
    printf("Digite a frase da matriz: ");
    preenche_matriz(*m, *n, mat);
    printf("deu certo");
    return mat;
}

int mainloop(char **mat, int m, int n, Palavra *p){
    pega_string(p);
    procura_palavra(mat, m, n, p);
    imprime_info(*p);
    free(p->str);
    return catch_exit();
}

int main(){
    char **mat;
    Palavra p;
    int m, n, exit;
    mat = pega_matriz(&m, &n);
    mostra_matriz(m, n, mat);
    while(!exit){
        exit = mainloop(mat, m, n, &p);
    }
    desaloca_matriz(m, mat);
    return 0;
}
