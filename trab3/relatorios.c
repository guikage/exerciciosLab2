#include <stdio.h>
#include <stdlib.h>
#include "carros.h"
#include "clientes.h"
#include "locacao.h"
#include "datas.h"

void r1(LLocacoes *l){
    printf("\nDigite a data:\n");
    Data d = pegaData();
    LLocacoes *p = l;
    while(p != NULL){
        if(difdata(d, p->locacao->dini) <= 0 && (difdata(d, p->locacao->dfin) >= 0 || p->locacao->vtotal == 0.0)){
            listaLocacao(p->locacao);
        }
        p = p->prox;
    }
}

void r2(LLocacoes *l){
    int cnh;
    printf("\nDigite a CNH:\n");
    scanf("%d", &cnh);
    LLocacoes *p = l;
    while(p != NULL){
        if(p->locacao->cliente->cnh == cnh){
            listaLocacao(p->locacao);
        }
        p = p->prox;
    }
}

void r3(LLocacoes *l){
    Data d;
    float faturamento = 0.0;
    printf("\nDigite o mes:\n");
    scanf("%d", &d.mes);
    printf("\nDigite o ano:\n");
    scanf("%d", &d.ano);
    LLocacoes *p = l;
    while(p != NULL){
        if(p->locacao->dfin.mes == d.mes && p->locacao->dfin.ano == d.ano){
            faturamento += p->locacao->vtotal;
        }
        p = p->prox;
    }
    printf("Faturamento do mes %02d/%04d: %.2f", d.mes, d.ano, faturamento);
}

void r4(LCarros *l){
    Carro *top3[3] = {NULL, NULL, NULL};
    LCarros *p = l;
    while(p != NULL){
        if(top3[0] == NULL || (top3[0])->quilometragem < p->carro->quilometragem){
            top3[2] = top3[1];
            top3[1] = top3[0];
            top3[0] = p->carro;
        }
        else if(top3[1] == NULL || (top3[1])->quilometragem < p->carro->quilometragem){
            top3[2] = top3[1];
            top3[1] = p->carro;
        }
        else if(top3[2] == NULL || (top3[2])->quilometragem < p->carro->quilometragem){
            top3[2] = p->carro;
        }
        p = p->prox;
    }
    for(int i = 0; i < 3; i++){
        if(top3[i] != NULL){
            printf("%s\n", top3[i]->placa);
        }
    }
}

void r5(LCarros *l){
    LCarros *p = l;
    while(p != NULL){
        if(p->carro->disponivel){
            printf("%s: %s %s\n", p->carro->placa, p->carro->marca, p->carro->modelo);
        }
        p = p->prox;
    }
}
