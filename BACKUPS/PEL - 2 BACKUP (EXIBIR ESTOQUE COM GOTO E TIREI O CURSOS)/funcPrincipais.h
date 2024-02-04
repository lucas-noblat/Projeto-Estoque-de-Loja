#ifndef FUNCPRINCIPAIS_H_INCLUDED
#define FUNCPRINCIPAIS_H_INCLUDED
#include "lista.h"
#include <time.h>

    // Estrutura para representar um produto
    typedef struct {
        int codigo;
        char nome[50];
        int quantidade;
        float preco;
    } Produto;

   

    struct tm* hora_atual;
    time_t segundos;



    int opcao, codigo;
    PONT removido;
    LISTA estoque;
    REGISTRO regist;



    void adicionarProdutos ();
    void exibirEstoque ();
    void realizarVenda ();
    void sairPrograma();




#endif