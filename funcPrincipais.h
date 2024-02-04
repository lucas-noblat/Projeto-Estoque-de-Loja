#ifndef FUNCPRINCIPAIS_H_INCLUDED
#define FUNCPRINCIPAIS_H_INCLUDED
#include "lista.h"
#include <time.h>
#include <stdio.h>
   

    struct tm* hora_atual;
    time_t segundos;


    FILE *arquivoLista;
    int opcao, codigo;
    PONT removido;
    LISTA estoque;
    REGISTRO regist;

    void delay(int segundos);
    int ehNumero (char palavra[]);
    int qntsDigitos(int x);
    void adicionarProdutos ();
    void exibirEstoque ();
    void realizarVenda ();
    void alterarRegistro();



#endif