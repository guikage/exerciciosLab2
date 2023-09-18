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
            if(difdata(loc->dini, p->locacao->dini) >= 0 && (difdata(loc->dini, p->locacao->dfin) <= 0 || !loc->carro->disponivel)){
                return false;
            }
        }
        p->prox;
    }
    return true;
}

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
    if(!confereSolicitacao){
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
    n->locacao = pegaLocacao(lcarros, lclientes);
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
    loc->carro->disponivel = false;
    printf("Insira as informacoes da data de devolucao:\n");
    loc->dfin = pegaData();
    while(difdata(loc->dfin, loc->dini) < 0){
        printf("Data informada antecede a data de retirada.\n");
        loc->dfin = pegaData();
    }
    loc->vtotal = (difdata(loc->dini, loc->dfin) + 1) * loc->carro->valorDiaria;
    printf("Digite a quilometragem atual do carro:\n");
    scanf(" %f", loc->carro->quilometragem);
}

void listaLocacoes(LLocacoes *l){
    LLocacoes *p = l;
    while(p != NULL){
        printf("\nLOCACAO:\n");
        printf("\tPlaca do carro: %s\n", p->locacao->carro->placa);
        printf("\tCNH do cliente: %d\n", p->locacao->cliente->cnh);
        printf("\tData de retirada: %02d/%02d/%04d\n", p->locacao->dini.dia, p->locacao->dini.mes, p->locacao->dini.ano);
        if(p->locacao->vtotal != 0.0){
            printf("\tData de devolucao: %02d/%02d/%04d\n", p->locacao->dfin.dia, p->locacao->dfin.mes, p->locacao->dfin.ano);
            printf("\tValor final: %.2f\n", p->locacao->vtotal);
        }
        else{
            printf("\tCARRO NAO FOI DEVOLVIDO AINDA\n");
        }
        p = p->prox;
    }
}

