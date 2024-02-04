#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcPrincipais.h"
#include "lista.h"
#include "recGraficos.h"
#include <locale.h>

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
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}