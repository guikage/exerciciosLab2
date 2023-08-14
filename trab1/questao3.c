#include <stdio.h>
#include <string.h>

struct triangulo
{
int ladoA;
int ladoB;
int ladoC;
char ehTriangulo;
char tipo[20];
};
typedef struct triangulo Triangulo;

char verTriangulo(Triangulo tri){
    char check1 = tri.ladoA < tri.ladoB + tri.ladoC;
    char check2 = tri.ladoB < tri.ladoA + tri.ladoC;
    char check3 = tri.ladoC < tri.ladoB + tri.ladoA;
    return(check1 && check2 && check3);
}

void tipoTriangulo(Triangulo *tri){
    if(!(tri->ehTriangulo)){
        strcpy(tri->tipo, "nao eh");
    }
    else if(tri->ladoA == tri->ladoB && tri->ladoA == tri->ladoC){
        strcpy(tri->tipo, "equilatero");
    }
    else if(tri->ladoA != tri->ladoB && tri->ladoA != tri->ladoC){
        strcpy(tri->tipo, "escaleno");
    }
    else{
        strcpy(tri->tipo, "isosceles");
    }
}

int main(){
    Triangulo tri;
    scanf("%d %d %d", &(tri.ladoA), &(tri.ladoB), &(tri.ladoC));

    tri.ehTriangulo = verTriangulo(tri);
    printf("\n%d", tri.ehTriangulo);
    tipoTriangulo(&tri);
    printf("\n%s", tri.tipo);

    return 0;
}
