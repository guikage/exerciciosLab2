#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "carros.h"

Carro *pegaCarro(void){
    Carro *carro = (Carro*)malloc(sizeof(Carro));
    printf("Digite a placa do carro:\n");
    scanf(" %7s", carro->placa);
    printf("Digite a marca do carro:\n");
    while(getchar() != '\n'); //limpa o buffer
    fgets(carro->marca, 20, stdin);
    carro->marca[strcspn(carro->marca, "\n")] = 0; //remove '\n'
    printf("Digite o modelo do carro:\n");
    fgets(carro->modelo, 20, stdin);
    carro->modelo[strcspn(carro->modelo, "\n")] = 0; //remove '\n'
    printf("Digite o ano de fabricacao do carro:\n");
    scanf(" %d", &(carro->anoFabricacao));
    printf("Digite a quilometragem do carro:\n");
    scanf(" %f", &(carro->quilometragem));
    printf("Digite o valor da diaria do carro:\n");
    scanf(" %f", &(carro->valorDiaria));
    carro->disponivel = true;
    return carro;
}

LCarros *insereCarro(LCarros *l){
    LCarros *n = (LCarros*)malloc(sizeof(LCarros));
    n->carro = pegaCarro();
    n->prox = l;
    return n;
}

void listaCarro(Carro *carro){
    printf("\nPLACA %s:\n", carro->placa);
    printf("\tMarca: %s\n", carro->marca);
    printf("\tModelo: %s\n", carro->modelo);
    printf("\tAno de fab.: %d\n", carro->anoFabricacao);
    printf("\tQuilometragem: %.2f\n", carro->quilometragem);
    printf("\tValor da diaria: %.2f\n", carro->valorDiaria);
    if(carro->disponivel){
        printf("\tDISPONIVEL\n");
    } else {
        printf("\tINDISPONIVEL\n");
    }
}

void listaCarros(LCarros *l){
    LCarros *p = l;
    while(p != NULL){
        printf("\nPLACA %s:\n", p->carro->placa);
        printf("\tMarca: %s\n", p->carro->marca);
        printf("\tModelo: %s\n", p->carro->modelo);
        printf("\tAno de fab.: %d\n", p->carro->anoFabricacao);
        printf("\tQuilometragem: %.2f\n", p->carro->quilometragem);
        printf("\tValor da diaria: %.2f\n", p->carro->valorDiaria);
        if(p->carro->disponivel){
            printf("\tDISPONIVEL\n");
        } else {
            printf("\tINDISPONIVEL\n");
        }
        p = p->prox;
    }
}

Carro *buscaCarro(LCarros *l, char *placa){
    LCarros *p = l;
    while(p != NULL && strcmp(p->carro->placa, placa) != 0){
        p = p->prox;
    }
    if(p != NULL){
        return p->carro;
    }
    return NULL;
}
