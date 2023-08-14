#include <stdio.h>

struct retangulo
{
float base;
float altura;
float perimetro;
float area;
};
typedef struct retangulo Retangulo;

void calculaPeriArea(Retangulo *ret);
void leBaseAltura(Retangulo *ret);

int main(){
    int i;
    Retangulo ret[5];
    for (i = 0; i < 5; i++){
        leBaseAltura(&(ret[i]));
        calculaPeriArea(&(ret[i]));
    }
    return 0;
}

void leBaseAltura(Retangulo *ret){
    printf("Digite a base: ");
    scanf("%f", &(ret->base));
    printf("Digite a altura: ");
    scanf("%f", &(ret->altura));
}

void calculaPeriArea(Retangulo *ret){
    ret->area = ret->base * ret->altura;
    ret->perimetro = 2*ret->base + 2*ret->altura;

    printf("Perimetro: %.2f\nArea: %.2f\n", ret->perimetro, ret->area);
}
