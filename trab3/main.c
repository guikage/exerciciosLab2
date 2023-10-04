#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datas.h"
#include "carros.h"
#include "clientes.h"
#include "locacao.h"
#include "relatorios.h"

bool menuRelatorios(LCarros *lcarros, LClientes *lclientes, LLocacoes *llocacoes){
    int opcao;
    printf("\nRELATORIOS:\n");
    printf("1. Listar locacoes ativas\n");
    printf("2. Listar locacoes por cliente\n");
    printf("3. Listar faturamento mensal\n");
    printf("4. Listar veiculos mais rodados\n");
    printf("5. Listar veiculos disponiveis\n");
    printf("0. Voltar\n");
    printf("\nDigite a opcao desejada: ");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            r1(llocacoes);
            break;
        case 2:
            r2(llocacoes);
            break;
        case 3:
            r3(llocacoes);
            break;
        case 4:
            r4(lcarros);
            break;
        case 5:
            r5(lcarros);
            break;
        default:
            return true;
    }
    return false;
}

bool menu(LCarros **lcarros, LClientes **lclientes, LLocacoes **llocacoes){
    int opcao;
    printf("\nMENU PRINCIPAL:\n");
    printf("1. Incluir veiculo\n");
    printf("2. Listar veiculos\n");
    printf("3. Incluir cliente\n");
    printf("4. Listar clientes\n");
    printf("5. Realizar locacao\n");
    printf("6. Devolver veiculo\n");
    printf("7. Listar locacoes\n");
    printf("8. Relatorios\n");
    printf("0. Sair\n");
    printf("\nDigite a opcao desejada: ");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            *lcarros = insereCarro(*lcarros);
            break;
        case 2:
            listaCarros(*lcarros);
            break;
        case 3:
            *lclientes = insereCliente(*lclientes);
            break;
        case 4:
            listaClientes(*lclientes);
            break;
        case 5:
            *llocacoes = insereLocacao(*llocacoes, *lcarros, *lclientes);
            break;
        case 6:
            encerraLocacao(*llocacoes);
            break;
        case 7:
            listaLocacoes(*llocacoes);
            break;
        case 8:
            while(!menuRelatorios(*lcarros, *lclientes, *llocacoes)){}
            break;
        default:
            return true;
    }
    return false;
}

int main(){
    LCarros *lcarros = NULL;
    LClientes *lclientes = NULL;
    LLocacoes *llocacoes = NULL;
    while(!menu(&lcarros, &lclientes, &llocacoes)){
    }
    return 0;
}
