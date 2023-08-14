#include <stdio.h>
#define PI 3.1415926

void calc_esfera (float r, float *area, float *volume){
    *area = 4.0*PI*r*r;
    *volume = 4.0/3.0*PI*r*r*r;
}

int main(){
    float r, area, volume;
    printf("Digite o raio: ");
    scanf("%f", &r);

    calc_esfera(r, &area, &volume);

    printf("Area: %f, Volume: %f", area, volume);
    return 0;
}
