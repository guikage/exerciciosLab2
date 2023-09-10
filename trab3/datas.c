#include <stdio.h>
#include "datas.h"

Data pegaData(void){
    Data data;
    printf("Digite o dia:\n");
    scanf("%d", &(data.dia));
    printf("Digite o mes:\n");
    scanf("%d", &(data.mes));
    printf("Digite o ano:\n");
    scanf("%d", &(data.ano));
    return data;
}

// codigo copiado do programa disponivel, porem alterando o formato de data

int difdata(Data data1, Data data2) {
    int dias1 = data1.ano * 365 + data1.dia;
    int dias2 = data2.ano * 365 + data2.dia;

    // Adicionar dias extras para os anos bissextos
    dias1 += data1.ano / 4 - data1.ano / 100 + data1.ano / 400;
    dias2 += data2.ano / 4 - data2.ano / 100 + data2.ano / 400;

    // Adicionar dias para os meses
    int mesDias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < data1.mes; i++) {
        dias1 += mesDias[i];
    }
    for (int i = 1; i < data2.mes; i++) {
        dias2 += mesDias[i];
    }

    // Considerar anos bissextos
    if (data1.mes <= 2 && (data1.ano % 4 == 0 && (data1.ano % 100 != 0 || data1.ano % 400 == 0))) {
        dias1--;
    }
    if (data2.mes <= 2 && (data2.ano % 4 == 0 && (data2.ano % 100 != 0 || data2.ano % 400 == 0))) {
        dias2--;
    }

    // Calcular a diferença em dias
    int diferenca = dias2 - dias1;
    return diferenca;
}

