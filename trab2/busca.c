#include <stdio.h>
#include <stdlib.h>
#include "busca.h"

//direcoes:
//678
//591 0
//432

char *nome_dir(int dir){
    switch(dir){
        case 1:
            return "horizontal direta";
        case 2:
            return "diagonal primaria direta";
        case 3:
            return "vertical direta";
        case 4:
            return "diagonal secundaria direta";
        case 5:
            return "horizontal inversa";
        case 6:
            return "diagonal primaria inversa";
        case 7:
            return "vertical inversa";
        case 8:
            return "diagonal secundaria inversa";
        default:
            return "indefinido";
    }
}

void imprime_info(Palavra p){
    if(p.dir == 0){
        printf("A palavra %s nao foi encontrada.\n", p.str);
    }
    else if(p.dir == 9){
        printf("O caracter %s foi encontrado na posicao [%d,%d].\n", p.str, p.pini[0]+1, p.pini[1]+1);
    }
    else{
        char *nmdir = nome_dir(p.dir);
        printf("A palavra %s foi encontrada na %s.\nEla se inicia na posicao [%d,%d] e encerra na posicao [%d,%d].\n", p.str, nmdir, p.pini[0]+1, p.pini[1]+1, p.pfinal[0]+1, p.pfinal[1]+1);
    }
}

int pega_string(Palavra *p){
    printf("\nDigite a palavra (sem espacos): ");
    scanf("%ms", &(p->str));
    int t = 0;
    while(p->str[t] != '\0'){
        t++;
    }
    p->tam = t;
    return 0;
}

int teste_horizontal(char **mat, int m, int n, int l, int c, Palavra *p){
    int i, direta = 1, inversa = 1;
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
    if(direta){
        return direta;
    }
    return(5*inversa);
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
    if(direta){
        return (3*direta);
    }
    return(7*inversa);
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
    if(direta){
        return (2*direta);
    }
    return(6*inversa);
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
    if(direta){
        return (4*direta);
    }
    return(8*inversa);
}

int testa_tudo(char **mat, int m, int n, int l, int c, Palavra *p){
    int dir;
    dir = teste_horizontal(mat, m, n, l, c, p);
    if(dir == 0){
        dir = teste_vertical(mat, m, n, l, c, p);
        if(dir == 0){
            dir = teste_diag_primaria(mat, m, n, l, c, p);
            if(dir == 0){
                dir = teste_diag_secundaria(mat, m, n, l, c, p);
            }
        }
    }
    return dir;
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
