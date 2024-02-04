#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcPrincipais.h"
#include "lista.h"
#include "recGraficos.h"
#include <locale.h>
#include <windows.h>
#include <time.h>


 char listaOpcoes[5][40] = {
            "ADICIONAR PRODUTO",
            "ALTERAR REGISTRO",
            "EXIBIR ESTOQUE",
            "REALIZAR VENDA",
            "SAIR"
    };

int main() {

 
    


    // estoque = resgatarLista();
    
    restauraLista(&estoque);

    do {

        textColor(WHITE, _BLUE);
        opcao = menu(10, 45, 5, listaOpcoes);


        switch (opcao) {
            case 1:
            
                adicionarProdutos();

                break;
            case 2:

                alterarRegistro();
                break;

            case 3:

                exibirEstoque();
                break;
            case 4:
            
                salvarLista(&estoque);
               // realizarVenda();
                break;
            case 5:
                system("cls");
                textColor(WHITE, _BLUE);
                setlocale(LC_ALL, "C");
                box(12 ,43 , 16 , 69);
                for (int i = 4; i > 0; i--){
                gotoxy(43, 13);     
                printf("Fechando o programa em %d", i);
                delay(1);
                }
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}