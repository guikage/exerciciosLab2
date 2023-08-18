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

Aluno calculaAluno(int aulasMinistradas);
Aluno leAluno(int aulasMinistradas);
void leAlunos(Disciplina *disc);
void imprimeStatus(Aluno aluno);

int main(){
    Disciplina labprog;
    printf("Digite o numero de aulas dessa disciplina: ");
    scanf("%d", &(labprog.aulasMinistradas));
    leAlunos(&labprog);

    return 0;
}

Aluno calculaAluno(int aulasMinistradas){
    Aluno aluno;
    float porcentAulas;
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

Aluno leAluno(int aulasMinistradas){
    Aluno aluno;
    float porcentAulas;
    do{
    	printf("\nDigite a nota 1 do aluno (0-10): ");
    	scanf("%f", &(aluno.nota1));
    }while(aluno.nota1 > 10 || aluno.nota1 < 0);
    do{
    printf("Digite a nota 2 do aluno (0-10): ");
    scanf("%f", &(aluno.nota2));
    }while(aluno.nota2 > 10 || aluno.nota2 < 0);
    do{
    printf("Digite o numero de aulas assistidas do aluno (0-%d): ", aulasMinistradas);
    scanf("%d", &(aluno.aulasAssistidas));
    }while(aluno.aulasAssistidas > aulasMinistradas || aluno.aulasAssistidas < 0);
    return aluno;
}

void leAlunos(Disciplina *disc){
    for(int i = 0; i < 5; i++){
        disc->vet[i] = leAluno(disc->aulasMinistradas);
        imprimeStatus(disc->vet[i]);
    }
}

void imprimeStatus(Aluno aluno){
	if(aluno.status == 'a'){
		printf("Aluno aprovado com media %f\n", aluno.media);
	}
	else{
		printf("Aluno reprovado com media %f\n", aluno.media);
	}
}
