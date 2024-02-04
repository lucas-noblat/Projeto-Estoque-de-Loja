#include "funcPrincipais.h"
#include "lista.h"
#include "recGraficos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para adicionar produtos ao estoque

void adicionarProdutos() {

            system("cls");
            time(&segundos);
            hora_atual = localtime(&segundos); 
            printf("\n");
            printf("Digite o codigo do produto: ");
            scanf("%i", &regist.codigo);
            getchar();
            if(inserirLista(&estoque, regist))
                printf("Registrado as: %d:%d:%d\n", hora_atual->tm_hour, hora_atual->tm_min, hora_atual->tm_sec);

            printf("\n\n Pressione qualquer tecla para voltar ao menu...");
            getchar();
            system("cls");

}

// Função para exibir o estoque atual
void exibirEstoque() {
        system("cls");
        mostrarLista(&estoque);

        printf("\n\n Pressione qualquer tecla para voltar ao menu...");
        getchar();
        system("cls");
}

// Função para realizar uma venda
void realizarVenda() {
                system("cls");

                    printf("Digite o codigo do produto a ser removido: ");
                scanf("%d", &codigo);
                removido = excluirLista(&estoque, codigo);
                if (removido){
                    printf("Elemento removido: %d", removido->reg.codigo);
                    free(removido);
                } else {
                    printf("Elemento não esta na lista\n");
                }
                
}
