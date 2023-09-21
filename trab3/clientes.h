#ifndef _clientes_
#define _clientes_

struct cliente{
    int cnh;
    char *nome;
    int telefone;
};
typedef struct cliente Cliente;

struct lclientes{
    Cliente *cliente;
    struct lclientes *prox;
};
typedef struct lclientes LClientes;

Cliente *pegaCliente(void);
LClientes *insereCliente(LClientes *l);
void listaClientes(LClientes *l);
void listaCliente(Cliente *cliente);
Cliente *buscaCliente(LClientes *l, int cnh);

#endif
