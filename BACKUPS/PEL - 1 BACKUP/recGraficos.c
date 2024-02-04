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
    
}

void box(int lin1, int col1, int lin2, int col2){

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
}


void textColor(int letras, int fundo) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letras + fundo);
}

int menu (int lin1, int col1, int qtd, char lista[][40]){

    int lin2, col2, linha, i, tamMaxItem, tecla, opc=1, auxiliar;


    //CALCULA AS COORDENADAS

    tamMaxItem = strlen(lista[0]);
    for (i = 1; i<qtd; i++){
        if (strlen(lista[i]) > tamMaxItem) tamMaxItem = strlen(lista[i]);
    }

    lin2 = lin1 + (qtd*2 + 2);
    col2 = col1 + tamMaxItem + 4;

    //MONTA TELA

    textColor(WHITE, _BLUE);
    setlocale(LC_ALL, "C");
    box(lin1, col1, lin2, col2);
    setlocale(LC_ALL, "");

    //LAÇO DAS OPÇÕES

    while (1)
    {
        //RE-MONTA A TELA COM A OPÇÃO "ACESA"
       // printf("\n------------%d-------------\n", opc);
        linha = lin1 + 2;
        auxiliar = linha;
        for (i = 0; i<qtd; i++){
            if (i + 1 ==opc) {
                textColor(WHITE, _GREEN);
                }

            else {
                textColor(WHITE, _BLUE);
                }
            linhaCol(linha, col1+2);
            printf("%s", lista[i]);
            linha+=2;
        }

        linhaCol(auxiliar, col1+1);
        //AGUARDA A TECLA DO USUARIO

        tecla = getch();

        if (tecla == 27) { //ESC
        opc = 0; break;
        } 

        else if (tecla == 13){ //ENTER
            break;
        }

        else if(tecla ==72){ //SETA PRA CIMA
            if(opc>=1) opc--;
            auxiliar-=2;
            linhaCol(auxiliar, col1+1);
 
        }
        else if(tecla ==80){ //SETA PRA BAIXO
            if(opc<qtd) opc++;
            auxiliar+=2;
            linhaCol(auxiliar, col1+1);
        }    }
    


    textColor(WHITE, _BLACK);
    return opc;
}
