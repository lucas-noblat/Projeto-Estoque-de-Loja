#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include "recGraficos.h"
#include "funcPrincipais.h"



void linhaCol (int lin, int col) {

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), 
        (COORD) {col-1, lin-1});
    
    //FUNÇÃO PRA DEIXAR O CURSOR INVISÍVEL

    CONSOLE_CURSOR_INFO info;
    info.bVisible = false;
    info.dwSize = 100;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    
}

void box(int lin1, int col1, int lin2, int col2, int cor_letra, int cor_fundo){


    textColor(cor_letra, cor_fundo);    //DEFINE COR DE FUNDO

    
    setlocale(LC_ALL, "C");
  
    
    int i, j, tamlin, tamcol;

    //Acha o tamanho da box;

    tamlin = lin2-lin1;
    tamcol = col2-col1;

    //Monta a box - EM CIMA E BAIXO

    for(i = col1; i<=col2; i++){
        linhaCol(lin1, i);
        printf("%c", 196);
        linhaCol(lin2, i);
        printf("%c", 196);

    }

    //LATERAIS
    for (i = lin1; i <=lin2; i++){
        linhaCol(i, col1);
        printf("%c", 179);
        linhaCol(i, col2);
        printf("%c", 179);

    }

    for (i = lin1+1; i <lin2; i++){
        for(j =col1+1; j<col2; j++){
            linhaCol(i,j); printf(" ");
        }
    }

    //CANTOS
    linhaCol(lin1, col1); printf("%c", 218);
    linhaCol(lin1, col2); printf("%c", 191);
    linhaCol(lin2, col1); printf("%c", 192);
    linhaCol(lin2, col2); printf("%c", 217);

   //PADR�O PROGRAMA
    setlocale(LC_ALL, "Portuguese_Brazil");

}


void textColor(int letras, int fundo) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letras + fundo);
}


int menu (int lin1, int col1, int qtd, char lista[][40], int cor_letra, int cor_fundo){

    int lin2, col2, linha, i, tamMaxItem, tecla, opc=1;
    textColor(cor_fundo, cor_fundo);


    //CALCULA AS COORDENADAS

    tamMaxItem = strlen(lista[0]);
    for (i = 1; i<qtd; i++){
        if (strlen(lista[i]) > tamMaxItem) tamMaxItem = strlen(lista[i]);
    }

    lin2 = lin1 + (qtd*2 + 2);
    col2 = col1 + tamMaxItem + 4;

    //MONTA TELA

    setlocale(LC_ALL, "C");
    box(lin1, col1, lin2, col2, cor_letra, cor_fundo);
    setlocale(LC_ALL, "Portuguese_Brazil");

    //LAÇO DAS OPÇÕES

    while (1)
    {
        //RE-MONTA A TELA COM A OPÇÃO "ACESA"

        linha = lin1 + 2;
        for (i = 0; i<qtd; i++){
            if (i + 1 ==opc) {
                textColor(WHITE, _GREEN);
                }

            else {
                textColor(cor_letra, cor_fundo);
                }
            linhaCol(linha, col1+2);
            printf("%s", lista[i]);
            linha+=2;
        }

        linhaCol(1, 1);
        //AGUARDA A TECLA DO USUARIO

        tecla = getch();


        if (tecla == 27) { //ESC
        opc = 0; break;
        } 

        else if (tecla == 13){ //ENTER
            break;
        }

        else if(tecla ==72){ //SETA PRA CIMA
             opc--;
            if (opc < 1) opc = qtd;
        }
        else if(tecla ==80){ //SETA PRA BAIXO
             opc++;
             if (opc>qtd) opc = 1;

        }            }
    

    setlocale(LC_ALL, "Portuguese_Brazil");
    return opc;
} 
void gotoxy(int x, int y){

    HANDLE h;
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, dwPos);


}