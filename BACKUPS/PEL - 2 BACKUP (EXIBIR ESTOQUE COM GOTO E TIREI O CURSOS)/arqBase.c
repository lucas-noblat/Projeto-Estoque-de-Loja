#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcPrincipais.h"
#include "lista.h"
#include "recGraficos.h"
#include <locale.h>
#include <windows.h>

 char listaOpcoes[4][40] = {
            "ADICIONAR PRODUTO",
            "EXIBIR ESTOQUE",
            "REALIZAR VENDA",
            "SAIR"
    };

int main() {

    inicializaLista(&estoque);

    do {

        
        opcao = menu(10, 10, 4, listaOpcoes);


        switch (opcao) {
            case 1:
            
                adicionarProdutos();
                break;
            case 2:

                exibirEstoque();
                break;
            case 3:

                realizarVenda();
                break;
            case 4:
                system("cls");
                printf("\n\tSaindo do programa.\n");
                getchar();
                return 0;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}