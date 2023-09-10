#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "datas.h"
#include "carros.h"
#include "clientes.h"
#include "locacao.h"

Locacao *pegaLocacao(LCarros *lcarros, LClientes *lclientes){
    Locacao *locacao = (Locacao*)malloc(sizeof(Locacao));
    int cnh;
    char placa[8];
    do{
        printf("Digite a CNH do cliente:\n");
        scanf(" %d", &cnh);
        locacao->cliente = buscaCliente(lclientes, cnh);
    }while(locacao->cliente == NULL);
    do{
        printf("Digite a placa do carro:\n");
        scanf(" %s", placa);
        locacao->carro = buscaCarro(lcarros, placa);
    }while(locacao->carro == NULL);
    printf("Insira as informacoes da data de retirada:\n");
    locacao->dini = pegaData();
    locacao->carro->disponivel = false;
    return locacao;
}

LLocacoes *insereLocacao(LLocacoes *l, LCarros *lcarros, LClientes *lclientes){
    LLocacoes *n = (LLocacoes*)malloc(sizeof(LLocacoes));
    n->locacao = pegaLocacao(lcarros, lclientes);
    n->prox = l;
    return n;
}

Locacao *buscaLocacao(LLocacoes *l, char *placa){
    LLocacoes *p = l;
    while(p != NULL && strcmp(placa, p->locacao->carro->placa) != 0){
        p = p->prox;
    }
    if(p != NULL){
        return p->locacao;
    }
    return NULL;
}

void encerraLocacao(LLocacoes *l){
    char placa[8];
    printf("Digite a placa do carro que sera devolvido:\n");
    scanf(" %s", placa);
    Locacao *loc = buscaLocacao(l, placa);
    if(loc == NULL){
        printf("Carro nao existe e/ou nao foi locado.");
        return;
    }
    if(!loc->carro->disponivel){
        printf("Carro nao possui nenhuma locacao aberta.");
        return;
    }
    loc->carro->disponivel = false;
    loc->dfin = pegaData();
    loc->vtotal = difdata(loc->dini, loc->dfin) * loc->carro->valorDiaria;
}
