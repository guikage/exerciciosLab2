#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datas.h"
#include "carros.h"
#include "clientes.h"
#include "locacao.h"

int main(){
    LCarros *lcarros = NULL;
    LClientes *lclientes = NULL;
    LLocacoes *llocacoes = NULL;
    for(int i = 0; i < 2; i++){
        lcarros = insereCarro(lcarros);
        listaCarros(lcarros);
    }
    for(int i = 0; i < 2; i++){
        lclientes = insereCliente(lclientes);
        listaClientes(lclientes);
    }
    for(int i = 0; i < 3; i++){
        llocacoes = insereLocacao(llocacoes, lcarros, lclientes);
        listaLocacoes(llocacoes);
    }
    for(int i = 0; i < 3; i++){
        encerraLocacao(llocacoes);
        listaLocacoes(llocacoes);
    }
    return 0;
}
