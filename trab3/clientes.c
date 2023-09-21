#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clientes.h"

Cliente *pegaCliente(void){
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));
    printf("Digite a CNH do cliente:\n");
    scanf(" %d", &(cliente->cnh));
    printf("Digite o nome do cliente:\n");
    scanf(" %ms", &(cliente->nome));
    printf("Digite o telefone do cliente:\n");
    scanf(" %d", &(cliente->telefone));
    return cliente;
}

LClientes *insereCliente(LClientes *l){
    LClientes *n = (LClientes*)malloc(sizeof(LClientes));
    n->cliente = pegaCliente();
    n->prox = l;
    return n;
}

void listaCliente(Cliente *cliente){
    printf("\n%s:\n", cliente->nome);
    printf("\tCNH: %d\n", cliente->cnh);
    printf("\tTelefone: %d\n", cliente->telefone);
}

void listaClientes(LClientes *l){
    LClientes *p = l;
    while(p != NULL){
        printf("\n%s:\n", p->cliente->nome);
        printf("\tCNH: %d\n", p->cliente->cnh);
        printf("\tTelefone: %d\n", p->cliente->telefone);
        p = p->prox;
    }
}

Cliente *buscaCliente(LClientes *l, int cnh){
    LClientes *p = l;
    while(p != NULL && cnh != p->cliente->cnh){
        p = p->prox;
    }
    if(p != NULL){
        return p->cliente;
    }
    return NULL;
}
