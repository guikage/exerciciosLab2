#include <stdio.h>
#include <stdlib.h>

int pegastring(char **str){
    int tam;
    printf("Digite o tamanho da string: ");
    scanf("%d", &tam);
    *str = (char*)malloc(tam+1*sizeof(char));
    printf("Digite a palavra (sem espacos): ");
    scanf("%s", *str);
    return tam;
}

int procura_letra(int posinicial, char **mat, int m, int n, char *str, int tam){
    int i, j, posfinal, lini, cini;
    lini = posinicial/n;
    cini = posinicial%n;

    i = lini;
    j = cini;
    while (i < m){
        while (j < n){
            if (mat[i][j] == str[0]){
                return (5*i+j);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return -1;
}

int determina_dir(int pos, char **mat, int m, int n, char *str, int tam){
    int i, j, l, c;
    l = pos/n;
    c = pos%n;
    if(tam == 1){
        return 8;
    }
    //horizontal direta
    if(c != n-1){
        if(mat[l][c+1] == str[1]){
            return 0;
        }
    }
    //vertical direta
    if(l != m-1){
        if(mat[l+1][c] == str[1]){
            return 2;
        }
    }
    //horizontal inversa
    if(c != 0){
        if(mat[l][c-1] == str[1]){
            return 6;
        }
    }
    //vertical inversa
    if(l != 0){
        if(mat[l-1][c] == str[1]){
            return 8;
        }
    }
    //diagonal primaria direta
    if(l != n-1 && c != n-1){
        if(mat[l+1][c+1] == str[1]){
            return 1;
        }
    }
    //diagonal primaria inversa
    if(l != 0 && c != 0){
        if(mat[l-1][c-1] == str[1]){
            return 5;
        }
    }
    //diagonal secundaria direta
    if(l != 0 && c != n-1){
        if(mat[l-1][c+1] == str[1]){
            return 7;
        }
    }
    //diagonal secundaria inversa
    if(l != n-1 && c != 0){
        if(mat[l+1][c-1] == str[1]){
            return 3;
        }
    }
    return -1;
}
