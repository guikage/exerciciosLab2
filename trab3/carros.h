#ifndef _carros_
#define _carros_

#include <stdbool.h>
#include "datas.h"

struct carro{
    char placa[8];
    char *marca;
    char *modelo;
    int anoFabricacao;
    float quilometragem;
    float valorDiaria;
    bool disponivel;
};
typedef struct carro Carro;

struct lcarros{
    Carro *carro;
    struct lcarros *prox;
};
typedef struct lcarros LCarros;

LCarros *insereCarro(LCarros *l);
void *listaCarros(LCarros *l);
Carro *buscaCarro(LCarros *l, char *placa);

#endif
