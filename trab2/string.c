#include <stdio.h>

void pegamatriz(char **mat, int m, int n){
    int i = 0, j = 0, enter = 0;
    while(i < m){
        while(j < n){
            if(!enter){
                mat[i][j] = getchar();
                if(mat[i][j] == '\n'){
                    enter = 1;
                } else if(mat[i][j] != ' '){
                    j++;
                }
            } else {
                mat[i][j] = ' ';
            }
        }
        i++;
    }
}
