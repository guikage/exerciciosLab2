#ifndef _locacoes_
#define _locacoes_

#include "datas.h"
#include "carros.h"
#include "clientes.h"

struct locacao{
    Cliente *cliente;
    Carro *carro;
    Data dini;
    Data dfin;
    float vtotal;
};
typedef struct locacao Locacao;

struct llocacoes{
    Locacao *locacao;
    struct llocacoes *prox;
};
typedef struct llocacoes LLocacoes;

Locacao *pegaLocacao(LLocacoes *lloc, LCarros *lcarros, LClientes *lclientes);
LLocacoes *insereLocacao(LLocacoes *l, LCarros *lcarros, LClientes *lclientes);
Locacao *buscaLocacao(LLocacoes *l, char *placa);
void encerraLocacao(LLocacoes *l);
void listaLocacoes(LLocacoes *l);
void listaLocacao(Locacao *locacao);

#endif
