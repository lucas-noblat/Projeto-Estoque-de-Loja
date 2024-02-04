#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//FUNÇÕES PILHA

void inicializaLista(LISTA * l){
    l->inicio = NULL;
    l->tam = 0;
}

void mostrarLista(LISTA* l){
    PONT end = l->inicio;
    if (end) {
    printf("\n");

    while (end != NULL){

        printf("%d", end->reg.codigo);
        printf("\n");
        end = end -> prox;
    }
    printf("\n");}
    else{
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
        printf("Produto inserido com sucesso!\n");
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