#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "recGraficos.h"
#include <string.h>

//FUNÇÕES PILHA

void inicializaLista(LISTA * l){
    l->inicio = NULL;
    l->tam = 0;
}

void mostrarLista(LISTA* l){
    PONT end = l->inicio;
    int auxiliar = 0;
    if (end) {
    gotoxy(16, 6);
    textColor(LIGHTGREEN, _BLUE);
    printf("Nome"); gotoxy(41, 6);
    printf("Preco"); gotoxy(65, 6);
    printf("Estoque"); gotoxy(90, 6);
    printf("Codigo"); 
    textColor(WHITE, _BLUE);
    gotoxy(8, 8);

    while (end != NULL){
        //POSICIONANDO NOME NA TABELA
        if(strlen(end->reg.nome) >= 10 ) gotoxy(14, 8 + auxiliar);
        else gotoxy(16, 8 + auxiliar);
        printf("%s", end->reg.nome); 

        //POSICIONANDO PREÇO NA TABELA
        gotoxy(41, 8+auxiliar);
        printf("%.2f", end->reg.preco); 

        //POSICIONANDO QUANTIDADE NA TABELA

        
        if (end->reg.quantidade > 999) gotoxy(66, 8 + auxiliar);
        else gotoxy(67, 8 + auxiliar);
        printf("%d", end->reg.quantidade); 

        //POSICIONANDO O CODIGO
        if(end->reg.codigo > 999) gotoxy (91, 8 + auxiliar);
        else gotoxy(92, 8 + auxiliar);
        printf("%d", end->reg.codigo);


        printf("\n");
        end = end -> prox;
        auxiliar++;
    }
    printf("\n");}
    else{
        gotoxy(50, 7);
        printf("Lista vazia!\n");
    }
}

bool inserirLista( LISTA* l, REGISTRO reg){

    PONT novo = (PONT) malloc(sizeof(PRODUTO));

    if (novo) {
        novo->reg = reg;
        novo->prox = l->inicio;
        l->inicio = novo;
        l->tam++;
        return true;
    }
    else {
        printf("Erro de alocaçao de memoria\n");
        return false;
    }
}

PONT excluirLista(LISTA* l, int codigo){
    PONT excluir = NULL, aux;

    if(l->inicio){
        if(l->inicio->reg.codigo == codigo){
            excluir = l->inicio;
            l->inicio = excluir->prox;
            l->tam--;
        } else {
            aux = l->inicio;
            while(aux->prox && aux->prox->reg.codigo != codigo) aux = aux->prox;
            if (aux->prox){
                excluir = aux->prox;
                aux->prox = excluir->prox;
                l->tam--;
            }
        }
    }

   
    return excluir;
}

PONT buscaCodigo(LISTA * l, int codigo){

    PONT busca = l->inicio, aux = NULL;

    while(busca != NULL){

        if(busca->reg.codigo == codigo) aux = busca;
        busca = busca->prox;
    }

    return aux;
}