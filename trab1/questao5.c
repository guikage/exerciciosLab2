#include <stdio.h>

struct aluno
{
float nota1;
float nota2;
int aulasAssistidas;
float media;
char status;
};
typedef struct aluno Aluno;

struct disciplina
{
Aluno vet[5];
int aulasMinistradas;
};
typedef struct disciplina Disciplina;

Aluno leAluno(int aulasMinistradas);
void leAlunos(Disciplina *disc);
void imprimeStatus(Disciplina disc);

int main(){
    Disciplina labprog;
    printf("Digite o numero de aulas dessa disciplina: ");
    scanf("%d", &(labprog.aulasMinistradas));
    leAlunos(&labprog);
    imprimeStatus(labprog);

    return 0;
}

Aluno leAluno(int aulasMinistradas){
    Aluno aluno;
    float porcentAulas;
    printf("\nDigite a nota 1 do aluno: ");
    scanf("%f", &(aluno.nota1));
    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &(aluno.nota2));
    printf("Digite o numero de aulas assistidas do aluno: ");
    scanf("%d", &(aluno.aulasAssistidas));
    aluno.media = (aluno.nota1 + aluno.nota2)/2.0;
    porcentAulas = (float)aluno.aulasAssistidas/aulasMinistradas;
    if(aluno.media >= 6.0 && porcentAulas >= 0.75){
        aluno.status = 'a';
    }
    else{
        aluno.status = 'r';
    }
    return aluno;
}

void leAlunos(Disciplina *disc){
    for(int i = 0; i < 5; i++){
        disc->vet[i] = leAluno(disc->aulasMinistradas);
    }
}

void imprimeStatus(Disciplina disc){
    for (int i = 0; i < 5; i++){
        if(disc.vet[i].status == 'a'){
            printf("Aluno %d: Aprovado com media %f\n", i+1, disc.vet[i].media);
        }
        else{
            printf("Aluno %d: Reprovado com media %f\n", i+1, disc.vet[i].media);
        }
    }
}
