#include "funcPrincipais.h"
#include "lista.h"
#include "recGraficos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

// Função para adicionar produtos ao estoque

void adicionarProdutos() {

            system("cls");
            time(&segundos);
            hora_atual = localtime(&segundos); 
            printf("\n");
            printf("Digite o codigo do produto: ");
            scanf("%i", &regist.codigo);
            getchar();
            printf("\nDigite o nome do produto: ");
            fgets(regist.nome, 100, stdin);
            regist.nome[strlen(regist.nome) - 1] = '\0';
            printf("Digite o preço do produto: ");
            scanf("%f", &regist.preco);
            getchar();
            printf("Digite a quantidade do produto: ");
            scanf("%i", &regist.quantidade);
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

        
        textColor(WHITE, _BLUE);
        setlocale(LC_ALL, "C");
        box(6, 10, 2*(estoque.tam+1) + 7 , 105);
        setlocale(LC_ALL, "");
        mostrarLista(&estoque);
        textColor(WHITE, _BLACK);
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

    void sairPrograma(){



    }