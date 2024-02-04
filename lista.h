#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define true 1
#define false 0
#define MAX 100

typedef int bool;

typedef struct {

    int codigo;
    char nome [MAX];
    float preco;
    int quantidade;
    float vendido;

} REGISTRO;

typedef struct aux {

    REGISTRO reg;
    struct aux* prox;
 } PRODUTO;

 typedef PRODUTO* PONT;

 typedef struct {
    PONT inicio;
    int tam;
 } LISTA;

 void inicializaLista(LISTA* l);
 void salvarLista(LISTA* l);
 void mostrarLista(LISTA* l);
 void restauraLista (LISTA* l);
 bool inserirLista(LISTA* l, REGISTRO reg);
 PONT excluirLista(LISTA* l, int codigo);
 PONT buscaCodigo(LISTA* l, int codigo);






#endif