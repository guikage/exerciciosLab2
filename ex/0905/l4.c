#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct professor
{
    int codigo;
    char nome[50];
    float salario;
};
typedef struct professor Professor;

struct aluno
{
    int matricula;
    char nome[50];
};
typedef struct aluno Aluno;

struct lista
{
    int tipo;
    void* info;
    struct lista* prox;
};
typedef struct lista Lista;

Aluno *criaaluno(int mat, char *nm){
    Aluno *info = (Aluno*)malloc(sizeof(Aluno));
    info->matricula = mat;
    strcpy(info->nome, nm);
    return info;
}

Professor *criaprof(int cod, char *nm, float sal){
    Professor *info = (Professor*)malloc(sizeof(Professor));
    info->codigo = cod;
    strcpy(info->nome, nm);
    info->salario = sal;
    return info;
}

Lista *linserealuno(Lista *l, int mat, char *nm){
    Lista *n = (Lista*)malloc(sizeof(Lista));
    n->tipo = 0;
    n->info = criaaluno(mat, nm);
    n->prox = l;
    return n;
}

Lista *linsereprof(Lista *l, int cod, char *nm, float sal){
    Lista *n = (Lista*)malloc(sizeof(Lista));
    n->tipo = 1;
    n->info = criaprof(cod, nm, sal);
    n->prox = l;
    return n;
}

void *limprime(Lista *l){
    Lista *p = l;
    while(p != NULL){
        if(p->tipo){
            Professor *prof = (Professor*)p->info;
            printf("Matricula: %d\tNome: %s\tSalario: %.2f\n", prof->codigo, prof->nome, prof->salario);
        }
        else{
            Aluno *aluno = (Aluno*)p->info;
            printf("Matricula: %d\tNome: %s\n", aluno->matricula, aluno->nome);
        }
        p = p->prox;
    }
}

int main(){
    Lista *l = NULL;
    l = linserealuno(l, 1, "jorginho");
    l = linserealuno(l, 2, "claudinho");
    l = linsereprof(l, 3, "benhur", 15000.0);
    limprime(l);
    return 0;
}
