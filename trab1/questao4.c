#include <stdio.h>
#define TAM 50

struct usuario
{
char sexo;
int idade;
int qtdade;
};
typedef struct usuario Usuario;

Usuario leUsuario();
void leVetor (int tamanho, Usuario* vet);
int calculaQtidadeLivros (int tamanho, Usuario* vet);
int calculaQtidadeMulheres (int tamanho, Usuario* vet);

int main(){
    Usuario users[TAM];
    leVetor(TAM, users);
    int qtdLivros = calculaQtidadeLivros(TAM, users);
    int qtdMulheres = calculaQtidadeMulheres(TAM, users);
    printf("\nLivros lidos por menores de 10 anos: %d\nMulheres que leram 5 livros ou mais: %d\n", qtdLivros, qtdMulheres);
    return 0;
}

void leVetor (int tamanho, Usuario* vet){
    for (int i = 0; i < TAM; i++){
        vet[i] = leUsuario();
    }
}

Usuario leUsuario(){
    Usuario usr;
    printf("\nDigite o sexo (m = masculino, f = feminino): ");
    scanf(" %c", &(usr.sexo));
    printf("Digite a idade: ");
    scanf("%d", &(usr.idade));
    printf("Digite a quantidade de livros lidos: ");
    scanf("%d", &(usr.qtdade));
    return usr;
}

int calculaQtidadeLivros (int tamanho, Usuario* vet){
    int somaLivros = 0;
    for (int i = 0; i < tamanho; i++){
        if(vet[i].idade < 10){
            somaLivros += vet[i].qtdade;
        }
    }
    return somaLivros;
}

int calculaQtidadeMulheres (int tamanho, Usuario* vet){
    int qtdMulheres = 0;
    for (int i = 0; i < tamanho; i++){
        if(vet[i].sexo == 'f' && vet[i].qtdade >= 5){
            qtdMulheres++;
        }
    }
    return qtdMulheres;
}
