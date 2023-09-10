#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datas.h"
#include "carros.h"
#include "clientes.h"

int main(){
    LClientes *lclientes = NULL;
    Cliente *clientea = NULL;
    for(int i = 0; i < 3; i++){
        lclientes = insereCliente(lclientes);
        listaClientes(lclientes);
    }
    int cnh;
    printf("\nDIGITE A CNH:\n");
    while(true){
        scanf("%d", &cnh);
        clientea = buscaCliente(lclientes, cnh);
        if(clientea != NULL){
            printf("%d\n", clientea->cnh);
        } else {
            printf("NAO ENCONTRADO\n");
        }
    }
    return 0;
}
