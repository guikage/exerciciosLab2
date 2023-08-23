#include <stdio.h>
#include <stdlib.h>
#include "busca.h"

//direcoes:
//678
//591 0
//432

int pegastring(Palavra *p){
    printf("Digite o tamanho da string (0 para encerrar): ");
    scanf("%d", &(p->tam));
    if(p->tam == 0){
        return 1;
    }
    p->str = (char*)malloc(p->tam+1*sizeof(char));
    printf("Digite a palavra (sem espacos): ");
    scanf("%s", p->str);
    return 0;
}

int teste_horizontal(char **mat, int m, int n, int l, int c, Palavra *p){
    int i;
    char direta = 1, inversa = 1;
    for(i = 0; i < p->tam; i++){
        if(c+i < n){
            if(mat[l][c+i] != p->str[i]){
                direta = 0;
            }
        }
        else{
            direta = 0;
        }
        if(c-i > -1){
            if(mat[l][c-i] != p->str[i]){
                inversa = 0;
            }
        }
        else{
            inversa = 0;
        }
    }
    p->pfinal[0] = l;
    p->pfinal[1] = c+(i-1)*direta-(i-1)*inversa;
    return(direta+5*inversa);
}

int teste_vertical(char **mat, int m, int n, int l, int c, Palavra *p){
    int i;
    char direta = 1, inversa = 1;
    for(i = 0; i < p->tam; i++){
        if(l+i < m){
            if(mat[l+i][c] != p->str[i]){
                direta = 0;
            }
        }
        else{
            direta = 0;
        }
        if(l-i > -1){
            if(mat[l-i][c] != p->str[i]){
                inversa = 0;
            }
        }
        else{
            inversa = 0;
        }
    }
    p->pfinal[0] = l+(i-1)*direta-(i-1)*inversa;
    p->pfinal[1] = c;
    return(3*direta+7*inversa);
}

int teste_diag_primaria(char **mat, int m, int n, int l, int c, Palavra *p){
    int i;
    char direta = 1, inversa = 1;
    for(i = 0; i < p->tam; i++){
        if(l+i < m && c+i < n){
            if(mat[l+i][c+i] != p->str[i]){
                direta = 0;
            }
        }
        else{
            direta = 0;
        }
        if(l-i > -1 && c-i > -1){
            if(mat[l-i][c-i] != p->str[i]){
                inversa = 0;
            }
        }
        else{
            inversa = 0;
        }
    }
    p->pfinal[0] = l+(i-1)*direta-(i-1)*inversa;
    p->pfinal[1] = c+(i-1)*direta-(i-1)*inversa;
    return(2*direta+6*inversa);
}

int teste_diag_secundaria(char **mat, int m, int n, int l, int c, Palavra *p){
    int i;
    char direta = 1, inversa = 1;
    for(i = 0; i < p->tam; i++){
        if(l+i < m && c-i > -1){
            if(mat[l+i][c-i] != p->str[i]){
                direta = 0;
            }
        }
        else{
            direta = 0;
        }
        if(l-i > -1 && c+i < n){
            if(mat[l-i][c+i] != p->str[i]){
                inversa = 0;
            }
        }
        else{
            inversa = 0;
        }
    }
    p->pfinal[0] = l+(i-1)*direta-(i-1)*inversa;
    p->pfinal[1] = c-(i-1)*direta+(i-1)*inversa;
    return(4*direta+8*inversa);
}

int testa_tudo(char **mat, int m, int n, int l, int c, Palavra *p){
    int dir;
    dir = teste_horizontal(mat, m, n, l, c, p);
    if(dir != 0){
        return dir;
    }
    dir = teste_vertical(mat, m, n, l, c, p);
    if(dir != 0){
        return dir;
    }
    dir = teste_diag_primaria(mat, m, n, l, c, p);
    if(dir != 0){
        return dir;
    }
    dir = teste_diag_secundaria(mat, m, n, l, c, p);
    if(dir != 0){
        return dir;
    }
    return 0;
}

int determina_dir(char **mat, int m, int n, Palavra *p){
    int i, l, c;
    l = p->pini[0];
    c = p->pini[1];
    if(p->tam == 1){
        p->pfinal[0] = p->pini[0];
        p->pfinal[1] = p->pini[1];
        return 9;
    }
    else{
        return testa_tudo(mat, m, n, l, c, p);
    }
}

int procura_palavra(char **mat, int m, int n, Palavra *p){
    int i = 0, j, dir = 0;
    while (i < m && dir == 0){
        j = 0;
        while (j < n && dir == 0){
            if (mat[i][j] == p->str[0]){
                p->pini[0] = i;
                p->pini[1] = j;
                dir = determina_dir(mat, m, n, p);
            }
            j++;
        }
        i++;
    }
    p->dir = dir;
    return 0;
}
