#include <stdio.h>
#include <stdlib.h>

struct aluno{
char matricula[10];
char nome[100];
int anoIngresso;
};
typedef struct aluno Aluno;

Aluno** aloca_matriz (int m, int n){
    Aluno **alunos = (Aluno**)malloc(m * sizeof(Aluno*));
    for(int i = 0; i < m; i++){
        alunos[i] = (Aluno*)malloc(n * sizeof(Aluno));
    }
    return alunos;
}

void libera_matriz (Aluno** matriz, int m){
    for(int i = 0; i < m; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int main(){
    Aluno **matriz = aloca_matriz(2, 3);
    libera_matriz(matriz, 2);
}
