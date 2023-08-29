#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char** aloca_matriz (int m, int n){
    int i;
    char **mat = (char**)malloc(m*sizeof(char*));
    for(i = 0; i < m; i++){
        mat[i] = (char*)malloc(n*sizeof(char));
    }
    return mat;
}

void desaloca_matriz (int m, char** mat){
    int i;
    for(i = 0; i < m; i++){
        free(mat[i]);
    }
    free(mat);
}

void preenche_matriz (int m, int n, char **mat){
    int i = 0, j = 0, enter = 0;
    char c;
    while((c = getchar()) != '\n' && c != EOF) { }
    while(i < m){
        while(j < n){
            if(enter){
                mat[i][j] = ' ';
                j++;
            }
            else{
                c = getchar();
                if(c == '\n'){
                    enter = 1;
                }
                else if(c != ' '){
                    mat[i][j] = c;
                    j++;
                }
            }
        }
        j = 0;
        i++;
    }
    if(!enter){
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}

void mostra_matriz (int m, int n, char **mat){
    int i, j;
    putchar('\n');
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%c ", mat[i][j]);
        }
        putchar('\n');
    }
}
