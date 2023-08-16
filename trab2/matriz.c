#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char** aloca_matriz (int m, int n){
    char **mat = (char**)malloc(m*sizeof(char*));
    for(int i = 0; i < m; i++){
        mat[i] = (char*)malloc(n*sizeof(char));
    }
    return mat;
}

void desaloca_matriz (int m, char** mat){
    for(int i = 0; i < m; i++){
        free(mat[i]);
    }
    free(mat);
}

void preenche_matriz (int m, int n, char **mat){
    int i = 0, j = 0, enter = 0;
    char aux;
    getchar();
    while(i < m){
        while(j < n){
            if(enter == 0){
                aux = getchar();
                putchar(aux);
                if(aux == '\n'){
                    enter = 1;
                } else if (aux != ' '){
                    mat[i][j] = aux;
                    j++;
                }
            } else {
                mat[i][j] = ' ';
                j++;
            }
        }
        i++;
    }
}

void mostra_matriz (int m, int n, char **mat){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%c ", mat[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
