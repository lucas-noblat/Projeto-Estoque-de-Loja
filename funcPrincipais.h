#ifndef FUNCPRINCIPAIS_H_INCLUDED
#define FUNCPRINCIPAIS_H_INCLUDED
#include "lista.h"
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>


    struct tm* hora_atual;
    time_t segundos;


    FILE *arquivoLista;
    int opcao, codigo;
    PONT removido;
    LISTA estoque;
    REGISTRO regist;

//FUNÇÕES PRINCIPAIS
    int adicionarProdutos ();
    void exibirEstoque ();
    int realizarVenda ();
    int alterarRegistro();



//FUNÇÕES AUXILIARES

    int defesaCodigo (char codigo[], char message[], int x, int y, PONT foundProduct);
    void delay(int segundos);
    int ehNumero (char palavra[]);
    int qntsDigitos(int x);
    



#endif