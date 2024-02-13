#include "funcPrincipais.h"
#include "lista.h"
#include "recGraficos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

// FUNÇÃO PARA DEFENDER A ENTRADA DOS CÓDIGOS

int defesaCodigo (char codigo[], char message[], int x, int y, PONT foundProduct){

    int loop = 0;

    while(loop != 1){

        if (codigo[0] == '\n'){

            textColor(BLACK, _BLACK);
            system("cls");
            return 0;}

        codigo[strlen(codigo)- 1] = '\0';   

        if(!ehNumero(codigo)){
                    
            textColor(RED, _WHITE);
            gotoxy(x, y); printf("                  ");
            gotoxy(x + 3, y); printf("Número inválido");
            delay(2);
            textColor(BLACK, _WHITE);
            gotoxy(x, y); printf("                     ");
            gotoxy(x, y); fgets(codigo, 20, stdin);
            if (codigo[0] == '\n') {
                
                textColor(BLACK, _BLACK);
                system("cls");
                return 0;}
            continue;}

        else if(!(foundProduct = buscaCodigo(&estoque, atoi(codigo)))) {   //VERIFICA SE ESTÁ NA LISTA

            textColor(RED, _WHITE);
            gotoxy(x, y); printf("                   ");
            gotoxy(x+1, y); printf("Código não encontrado");
            delay(2);
            textColor(BLACK, _WHITE);
            gotoxy(x, y); printf("                      ");
            gotoxy(x, y); fgets(codigo, 20, stdin);
            if (codigo[0] == '\n'){

                textColor(BLACK, _BLACK);
                system("cls");
                return 0;}
            continue; }
        
        loop = 1;}
    return 1;
}  

       
        
        
        

void delay(int segundos)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * segundos;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}




int ehNumero (char palavra[]){
    int res = 1;

    for (int i = 0; i < strlen(palavra); i++){

        if (palavra[0] == '-') return 0; 
        else if (!isdigit(palavra[i]) &&palavra[i] != ',' &&  palavra[i] != '.') res = 0;

    }

    return res;
}





int qntsDigitos(int x){
    int res = 1;

    while(x >= 10){
        x /= 10;
        res++;
    }
    return res;
}





int adicionarProdutos() {

            char codigo[20], preco[10], quantidade[10];
    //LIMPA A TELA DO CONSOLE
        textColor(WHITE, _BLACK);
        system("cls");
        
  
    //MONTA A BOX

        box(8, 30, 21, 80, WHITE, _BLUE);

    //PEGA O TEMPO PARA SER ECXPOSTO
        time(&segundos);
        hora_atual = localtime(&segundos); 

    //PRINTA AS PERGUNTAS E RECEBE AS RESPOSTAS

        gotoxy(31, 9);printf("Código do produto: ");
        gotoxy(31, 12);printf("Nome do produto: ");
        gotoxy(31, 15);printf("Preço do produto: ");
        gotoxy(31, 18);printf("Quantidade do produto: ");

        //

        textColor(WHITE, _BLACK);
        gotoxy(29, 22); printf("Para retornar ao menu deixe qualquer campo em branco.");

        textColor(WHITE, _BLUE);

        CONSOLE_CURSOR_INFO info;
        info.bVisible = true;
        info.dwSize = 100;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
            

    //RECEBE O CODIGO E FAZ A DEFESA

        gotoxy(50, 9); fgets(codigo, 20, stdin); 

        if(codigo[0] == '\n'){//PARA RETORNAR AO MENU PRINCIPAL
            textColor(WHITE, _BLACK);
            system("cls");
            return 0;

         }
            
        codigo[strlen(codigo) - 1] = '\0';

        while(1){

            if (ehNumero(codigo) ==0 || atoi(codigo) < 0) {
                gotoxy(50, 9);
                textColor(GREEN, _BLUE);
                printf("Número inválido");
                delay(2);
                textColor(WHITE, _BLUE);

                gotoxy(49, 9);  printf("                ");
                gotoxy(50, 9); fgets(codigo, 20, stdin); 

                if(codigo[0] == '\n') {//PARA RETORNAR AO MENU PRINCIPAL
                        textColor(WHITE, _BLACK);
                        system("cls");
                        return 0;
                    }       
                    codigo[strlen(codigo) - 1] = '\0';
                    continue;
                    }
            
                else if (buscaCodigo(&estoque, atoi(codigo))) {
                    gotoxy(50, 9);
                    textColor(GREEN, _BLUE);
                    printf("Código existente");
                    delay(2);
                    textColor(WHITE, _BLUE);

                    gotoxy(49, 9);  printf("                 ");
                    gotoxy(50, 9); fgets(codigo, 20, stdin);

                    if(codigo[0] == '\n') {//PARA RETORNAR AO MENU PRINCIPAL
                        textColor(WHITE, _BLACK);
                        system("cls");
                        return 0;
                    }

                    codigo[strlen(codigo) - 1] = '\0';
                    continue;
                    } 

                    break;
                }

            regist.codigo = atoi(codigo);                           //CONVERTE STRING P INT


        //NOME -- NÃƒO TEM DEFESA NO NOME POIS O NOME PODE SER ACOMPANHADO DA PESAGEM 'ARROZ 5KG'

            gotoxy(48, 12); fgets(regist.nome, 50, stdin);  

              if(regist.nome[0] == '\n'){//PARA RETORNAR AO MENU PRINCIPAL
                textColor(WHITE, _BLACK);
                system("cls");
                return 0;

            }      
            regist.nome[strlen(regist.nome) - 1] = '\0';
            

        //RECEBE O PRECO E FAZ A DEFESA

            gotoxy(50,15); fgets(preco, 10, stdin);
            
              if(preco[0] == '\n'){//PARA RETORNAR AO MENU PRINCIPAL
                textColor(WHITE, _BLACK);
                system("cls");
                return 0;

            }  
             preco[strlen(preco) - 1] = '\0';

            while (!ehNumero(preco) || atof(preco) <= 0) {
                gotoxy(50, 15);
                textColor(GREEN, _BLUE);
                printf("Número inválido");
                delay(2);
                textColor(WHITE, _BLUE);

                gotoxy(49, 15);  printf("                ");
                gotoxy(50, 15); fgets(preco, 10, stdin);

                if(preco[0] == '\n'){//PARA RETORNAR AO MENU PRINCIPAL
                    textColor(WHITE, _BLACK);
                    system("cls");
                    return 0;

            }
             preco[strlen(preco) - 1] = '\0';
                }

            regist.preco = atof(preco);

        //RECEBE QUANTIDADE E FAZ A DEFESA

            gotoxy(54,18); fgets(quantidade, 10, stdin);
            
            if(quantidade[0] == '\n'){//PARA RETORNAR AO MENU PRINCIPAL
                textColor(WHITE, _BLACK);
                system("cls");
                return 0;

            }   quantidade[strlen(quantidade) - 1] = '\0';


            while (!ehNumero(quantidade) || atoi(quantidade) < 0) {
                gotoxy(54, 18);
                textColor(GREEN, _BLUE);
                printf("Numero invalido");
                delay(2);
                textColor(WHITE, _BLUE);

                gotoxy(54, 18);  printf("                ");
                gotoxy(54, 18); fgets(quantidade, 10, stdin);

                if(quantidade[0] == '\n'){//PARA RETORNAR AO MENU PRINCIPAL
                    textColor(WHITE, _BLACK);
                    system("cls");
                    return 0;

            }   
                 quantidade[strlen(quantidade) - 1] = '\0';
                }
            
            regist.quantidade = atoi(quantidade);
            regist.vendido = 0;

        //SALVA O PRODUTO NA LISTA TEMPORï¿½RIA E NA LISTA .DAT

            inserirLista(&estoque, regist);
            salvarLista(&estoque);


        //DEIXA O MOUSE INVISï¿½VEL

            info.bVisible = false;
            info.dwSize = 100;
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

            textColor(WHITE, _BLACK);
            gotoxy(41, 5); 
            printf("Registrado as: %02d:%02d:%02d", hora_atual->tm_hour, hora_atual->tm_min, hora_atual->tm_sec);
            gotoxy(31, 22); 

            

            getchar();
            system("cls");
            return 1;

}










// FunÃ§Ã£o para exibir o estoque atual
void exibirEstoque() {

    //LIMPA A TELA DO CONSOLE
        textColor(WHITE, _BLACK);
        system("cls");

    //  DEFINE AS ESTRUTURAS
        box(6, 10, estoque.tam + 9 , 105, WHITE, _BLUE);
        mostrarLista(&estoque);
        textColor(WHITE, _BLACK);
        gotoxy(37, estoque.tam + 11);
        printf("Pressione enter para voltar ao menu...");
        getchar();
        textColor(WHITE, _BLACK);
        system("cls");













}

/*

            REALIZAR VENDA
            REALIZAR VENDA
            REALIZAR VENDA
 */


int realizarVenda() {


    CONSOLE_CURSOR_INFO info;
    char codigo [20], quantidade[20];
    PONT produtoAchado;
    LISTA carrinho;


//CONFERE SE TEM ALGO NO ESTOQUE OU NÃO

    if(estoque.tam == 0){ 
            gotoxy(49, 14);
            printf("Lista Vazia!");
            delay(4);
            textColor(WHITE, _BLACK);
            system("cls");} 

    else {


   //MONTAGEM DA INTERFACE
        
    while(1){

        mainBox_realizarVenda();
        carBox_realizarVendas(28);

    //DEIXA CURSOR VISï¿½VEL


        info.bVisible = true;
        info.dwSize = 100;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    //RECEBE O CODIGO E FAZ O PRIMEIRO CODIGO E JA FAZ A DEFESA

        textColor(BLACK, _WHITE);
        gotoxy(44, 15); fgets(codigo, 20, stdin); 


        if (defesaCodigo(codigo, "CÓDIGO DO PRODUTO", 44, 15, produtoAchado) == 0) return 0;

        else {
            
     
            while(1){

                textColor(BLACK, _WHITE);
                gotoxy(44, 22); fgets(quantidade, 20, stdin); quantidade[strlen(quantidade) - 1] = '\0';
                if (ehNumero(quantidade)) break;
                else {
                
                gotoxy(44,22); printf("                    ");

                textColor(RED, _WHITE);

                gotoxy(48, 22); printf("Número Inválido");
                delay(2);
                gotoxy(44,22); printf("                    ");

                }
                }
            
        } 
            break;
   
            }

    
     
    //DEIXA CURSOR INVISï¿½VEL

        CONSOLE_CURSOR_INFO info;
        info.bVisible = false;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
        textColor(WHITE, _BLACK);
        system("cls");

}}

    int alterarRegistro(){

        char codigo [20], preco[10], quantidade[10];
        char listaOpcoes[4][40] = {
            "ALTERAR CÓDIGO",
            "ALTERAR NOME",
            "ALTERAR PREÇO",
            "ALTERAR QUANTIDADE"
            
        }; PONT produtoAchado;

        int opcAlterarRegist;
        
    //MONTA A TELA ONDE IRÁ PEGAR O CÓDIGO

        
       
        if(estoque.tam == 0){ 
            gotoxy(49, 14);
            printf("Lista Vazia!");
            delay(4);
     
    
        } else {

        textColor(WHITE, _BLACK);
        system("cls");
        box(8, 37, 21, 75, WHITE, _BLUE);
        box(15, 44, 17, 68, WHITE, _WHITE);
      
        gotoxy(43, 12);
        textColor(WHITE, _BLUE);
        printf("DIGITE O CÓDIGO DO PRODUTO");
    

        textColor(WHITE, _BLACK);

        gotoxy(38, 21); printf("Para retornar ao menu aperte enter");

        textColor(WHITE, _BLUE);

        

    //DEIXA CURSOR VISï¿½VEL
        CONSOLE_CURSOR_INFO info;
        info.bVisible = true;
        info.dwSize = 100;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    
    //RECEBE O Cï¿½DIGO E FAZ A DEFESA

        textColor(BLACK, _WHITE);
        gotoxy(44, 15); fgets(codigo, 20, stdin); 
        
        if (codigo[0] == '\n')          //PARA VOLTAR AO MENU
        {
            textColor(WHITE, _BLACK);
            system("cls");
            return 0;
        }
        
        codigo[strlen(codigo)- 1] = '\0';
        
        while(1){
        
        if(!ehNumero(codigo)) {

            
            textColor(RED, _WHITE);
            gotoxy(44, 15); printf("                  ");
            gotoxy(48, 15); printf("Número inválido");
            delay(2);
            textColor(BLACK, _WHITE);
            gotoxy(44, 15); printf("                     ");
            gotoxy(44, 15); fgets(codigo, 20, stdin);
            
            if (codigo[0] == '\n') {
                textColor(WHITE, _BLACK);
                system("cls");
                return 0;
            }
         codigo[strlen(codigo)- 1] = '\0';
            continue;

        }
             if(!(produtoAchado = buscaCodigo(&estoque, atoi(codigo)))) {

            
            textColor(RED, _WHITE);
            gotoxy(44, 15); printf("                   ");
            gotoxy(45, 15); printf("Código não encontrado");
            delay(2);
            textColor(BLACK, _WHITE);
            gotoxy(44, 15); printf("                      ");
            gotoxy(44, 15); fgets(codigo, 20, stdin);

            if (codigo[0] == '\n') { //PARA RETORNAR AO MENU
                textColor(WHITE, _BLACK);
                system("cls");
                return 0;
            }
             codigo[strlen(codigo)- 1] = '\0';
            continue;

        }

        

        break;
        }
    //DEIXA CURSOR INVISï¿½VEL

        info.bVisible = false;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
        textColor(WHITE, _BLACK);
        system("cls");
             



         do {

    //MONTA A BOX DOS ATRIBUTOS DO PRODUTO
        box(10, 30, 20 , 70, WHITE, _BLUE);
    
    //RECEBE OS VALORES DO REGISTRO

        gotoxy(32,11);printf("Código: %d", produtoAchado->reg.codigo);
        gotoxy(32, 13); printf("Nome: %s", produtoAchado->reg.nome);
        gotoxy(32, 15); printf("Preço: %.2f", produtoAchado->reg.preco);
        gotoxy(32, 17); printf("Quantidade: %d", produtoAchado->reg.quantidade);
        
        opcAlterarRegist = menu(10, 70, 4, listaOpcoes, WHITE, _BLUE);
  
;

        switch (opcAlterarRegist) {
            case 1:
            
                textColor(WHITE, _GREEN);
                gotoxy(32,11);printf("Código: %d", produtoAchado->reg.codigo);
                delay(3);
                textColor(WHITE, _BLUE);
                gotoxy(32, 11); printf("Código:");
                for(int j = 0 ; j < qntsDigitos(produtoAchado->reg.codigo) + 1; j++) printf(" "); 
                gotoxy(40, 11); 
                info.bVisible = true;
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
                fgets(codigo, 20, stdin); codigo[strlen(codigo) - 1] = '\0';
                salvarLista(&estoque);

            while (ehNumero(codigo) ==0 || atoi(codigo) < 0) {
                gotoxy(40, 11);
                textColor(GREEN, _BLUE);
                printf("Número inválido");
                delay(2);
                textColor(WHITE, _BLUE);

                gotoxy(40, 11);  printf("                ");
                gotoxy(40, 11);
                info.bVisible = true;
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
                fgets(codigo, 20, stdin); codigo[strlen(codigo) - 1] = '\0';
                }
                info.bVisible = false;
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
                produtoAchado->reg.codigo = atoi(codigo);
                opcAlterarRegist = 0 ;
                textColor(WHITE, _BLACK);
                salvarLista(&estoque);
                system("cls");
        
                break; 
            case 2: //NOME

               textColor(WHITE, _GREEN);
                gotoxy(32,13);printf("Nome: %s", produtoAchado->reg.nome);
                delay(3);
                textColor(WHITE, _BLUE);
                gotoxy(32, 13); printf("Nome:");
                for(int j = 0 ; j < strlen(produtoAchado->reg.nome) + 1; j++) printf(" "); 
                gotoxy(38, 13); 
                info.bVisible = true;
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
                fgets(produtoAchado->reg.nome, 20, stdin); produtoAchado->reg.nome[strlen(produtoAchado->reg.nome) - 1] = '\0';

                salvarLista(&estoque);
                opcAlterarRegist = 0 ;
                textColor(WHITE, _BLACK);
                system("cls");
        
                break; 
            case 3:

                textColor(WHITE, _GREEN);
                gotoxy(32,15);printf("Preço: %.2f", produtoAchado->reg.preco);
                delay(3);
                textColor(WHITE, _BLUE);
                gotoxy(32, 15); printf("Preço:");
                for(int j = 0 ; j < qntsDigitos(produtoAchado->reg.preco) + 4; j++) printf(" "); 
                gotoxy(39, 15); 
                info.bVisible = true;
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
                fgets(preco, 20, stdin); preco[strlen(preco) - 1] = '\0';
                info.bVisible = false;
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

            while (ehNumero(preco) ==0 || atof(preco) < 0) {
                gotoxy(39, 15);
                textColor(GREEN, _BLUE);
                printf("Número inválido");
                delay(2);
                textColor(WHITE, _BLUE);

                gotoxy(40, 15);  printf("                ");
                gotoxy(40, 15);
                info.bVisible = true;
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
                fgets(preco, 20, stdin); preco[strlen(preco) - 1] = '\0';
                }
                info.bVisible = false;
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
                produtoAchado->reg.preco = atof(preco);
                opcAlterarRegist = 0 ;
                textColor(WHITE, _BLACK);
                salvarLista(&estoque);
                system("cls");

                break;
            case 4:

                textColor(WHITE, _GREEN);
                gotoxy(32,17);printf("Quantidade: %d", produtoAchado->reg.quantidade);
                delay(3);
                textColor(WHITE, _BLUE);
                gotoxy(32, 17); printf("Quantidade:");
                for(int j = 0 ; j < qntsDigitos(produtoAchado->reg.quantidade) + 1; j++) printf(" "); 
                gotoxy(44, 17); 
                info.bVisible = true;
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
                fgets(quantidade, 20, stdin); quantidade[strlen(quantidade) - 1] = '\0';
                info.bVisible = false;
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

            while (ehNumero(quantidade) == 0 || atoi(quantidade) < 0) {
                gotoxy(39, 17);
                textColor(GREEN, _BLUE);
                printf("Número inválido");
                delay(2);
                textColor(WHITE, _BLUE);

                gotoxy(40, 17);  printf("                ");
                gotoxy(40, 17);
                info.bVisible = true;
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
                fgets(preco, 20, stdin); preco[strlen(preco) - 1] = '\0';
                }
                info.bVisible = false;
                SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
                produtoAchado->reg.quantidade = atoi(quantidade);
                opcAlterarRegist = 0 ;
                textColor(WHITE, _BLACK);
                salvarLista(&estoque);
                system("cls");
                break;

            default:
                printf("Op??o inv?lida. Tente novamente.\n");
        }

    } while (opcAlterarRegist != 0);

}
}
