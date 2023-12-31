#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "datas.h"
#include "carros.h"
#include "clientes.h"
#include "locacao.h"

bool confereSolicitacao(LLocacoes *lista, Locacao *loc){
    LLocacoes *p = lista;
    while(p != NULL){
        if(p->locacao->carro == loc->carro){
            if(!loc->carro->disponivel){
                return false;
            }
            if(difdata(loc->dini, p->locacao->dini) <= 0 && difdata(loc->dini, p->locacao->dfin) >= 0){
                return false;
            }
        }
        p = p->prox;
    }
    return true;
}

Locacao *pegaLocacao(LLocacoes *lloc, LCarros *lcarros, LClientes *lclientes){
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
    if(!locacao->carro->disponivel){
        printf("Carro nao esta disponivel para locacao.\n");
        return NULL;
    }
    printf("Insira as informacoes da data de retirada:\n");
    locacao->dini = pegaData();
    if(!confereSolicitacao(lloc, locacao)){
        printf("Carro nao esta disponivel na data solicitada.\n");
        return NULL;
    }
    locacao->carro->disponivel = false;
    locacao->vtotal = 0.0;
    printf("Locacao realizada com sucesso!\n");
    return locacao;
}

LLocacoes *insereLocacao(LLocacoes *l, LCarros *lcarros, LClientes *lclientes){
    LLocacoes *n = (LLocacoes*)malloc(sizeof(LLocacoes));
    n->locacao = pegaLocacao(l, lcarros, lclientes);
    if(n->locacao == NULL){
        return l;
    }
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
        printf("Carro nao existe e/ou nao foi locado.\n");
        return;
    }
    if(loc->carro->disponivel){
        printf("Carro nao possui nenhuma locacao aberta.\n");
        return;
    }
    loc->carro->disponivel = true;
    printf("Insira as informacoes da data de devolucao:\n");
    loc->dfin = pegaData();
    while(difdata(loc->dfin, loc->dini) > 0){
        printf("Data informada antecede a data de retirada.\n");
        loc->dfin = pegaData();
    }
    loc->vtotal = difdata(loc->dini, loc->dfin) * loc->carro->valorDiaria;
    if(loc->vtotal < loc->carro->valorDiaria) loc->vtotal = loc->carro->valorDiaria;
    printf("Digite a quilometragem atual do carro:\n");
    scanf(" %f", &loc->carro->quilometragem);
}

void listaLocacao(Locacao *locacao){
    printf("\nLOCACAO:\n");
    printf("\tPlaca do carro: %s\n", locacao->carro->placa);
    printf("\tCNH do cliente: %d\n", locacao->cliente->cnh);
    printf("\tData de retirada: %02d/%02d/%04d\n", locacao->dini.dia, locacao->dini.mes, locacao->dini.ano);
    if(locacao->vtotal != 0.0){
        printf("\tData de devolucao: %02d/%02d/%04d\n", locacao->dfin.dia, locacao->dfin.mes, locacao->dfin.ano);
        printf("\tValor final: %.2f\n", locacao->vtotal);
    }
    else{
        printf("\tCARRO NAO FOI DEVOLVIDO AINDA\n");
    }
}

void listaLocacoes(LLocacoes *l){
    LLocacoes *p = l;
    while(p != NULL){
        listaLocacao(p->locacao);
        p = p->prox;
    }
}

