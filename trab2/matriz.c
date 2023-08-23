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
    int i, j, k, enter = 0;
    char c;
    char *aux;
    aux = (char*)malloc(2*n*m*sizeof(char));
    while ((c = getchar()) != '\n' && c != EOF) { }
    fgets(aux, 2*n*m, stdin);
    i = 0;
    k = 0;
    while(i < m){
        j = 0;
        while(j < n){
            if(aux[k] != ' '){
                mat[i][j] = aux[k];
                j++;
            }
            k++;
        }
        i++;
    }
    free(aux);
}

void mostra_matriz (int m, int n, char **mat){
    putchar('\n');
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%c ", mat[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
